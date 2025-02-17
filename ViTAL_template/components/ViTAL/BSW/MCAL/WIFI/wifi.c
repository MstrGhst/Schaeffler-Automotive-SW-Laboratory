/*******************************************************************************
 * COPYRIGHT (C) VITESCO TECHNOLOGIES
 * ALL RIGHTS RESERVED.
 *
 * The reproduction, transmission or use of this document or its
 * contents is not permitted without express written authority.
 * Offenders will be liable for damages. All rights, including rights
 * created by patent grant or registration of a utility model or design,
 * are reserved.
 *******************************************************************************/

#include "BSW/MCAL/WIFI/wifi.h"

#include "esp_wifi.h"
#include "esp_wifi_types.h"

#include "tcpip_adapter.h"

#include "sys/param.h"

static const char *TAG = "MCAL WIFI";

/* Import the html binary files to be used for the request */
extern const char index_html_start[] asm("_binary_index_html_start");
extern const char index_html_end[] asm("_binary_index_html_end");

char g_cGETBuffer[100];
char g_cPOSTBuffer[100];

bool g_bGETRequestInProcess = false;
bool g_bPOSTRequestInProcess = false;

/* Page configuration structure */
httpd_uri_t myPage_get =
{ .uri = "/index.html", .method = HTTP_GET, .handler = WebPageGetHandler,
		.user_ctx = NULL };

/* Page configuration structure */
httpd_uri_t myData_get =
{ .uri = "/data.txt", .method = HTTP_GET, .handler = DataGetHandler, .user_ctx =
NULL };

httpd_uri_t myPage_post =
{ .uri = "/index.html", .method = HTTP_POST, .handler = WebPagePostHandler,
		.user_ctx = NULL };

esp_err_t WebPageGetHandler(httpd_req_t *req)
{
	/* Send the request response to the user */
	ESP_ERROR_CHECK(
			httpd_resp_send(req, index_html_start,
					index_html_end - index_html_start));

	return ESP_OK;
}

esp_err_t DataGetHandler(httpd_req_t *req)
{
	/* Deactivate the GET process from scheduler */
	g_bGETRequestInProcess = false;

	/* Send the request response to the user */
	ESP_ERROR_CHECK(httpd_resp_send(req, g_cGETBuffer, sizeof(g_cGETBuffer)));

	/* Reactivate the GET process from scheduler */
	g_bGETRequestInProcess = true;

	return ESP_OK;
}

esp_err_t WebPagePostHandler(httpd_req_t *req)
{
	/* Deactivate the POST */
	g_bPOSTRequestInProcess = false;

	int ret, remaining = req->content_len;

	uint8_t u8Index = 0;

	/* Clear the buffer */
	for (; u8Index < 100; u8Index++)
	{
		g_cPOSTBuffer[u8Index] = 0;
	}

	while (remaining > 0)
	{
		/* Read the data for the request */
		if ((ret = httpd_req_recv(req, g_cPOSTBuffer,
				MIN(remaining, sizeof(g_cPOSTBuffer)))) <= 0)
		{
			if (ret == HTTPD_SOCK_ERR_TIMEOUT)
			{
				/* Retry receiving if timeout occurred */
				continue;
			}
			return ESP_FAIL;
		}

		/* Send back the same data */
		ESP_ERROR_CHECK(
				httpd_resp_send(req, index_html_start,
						index_html_end - index_html_start));
		remaining -= ret;

		for (; ret < 100; ret++)
		{
			g_cPOSTBuffer[ret] = 0;
		}
	}

	/* Reactivate the POST process in scheduler */
	g_bPOSTRequestInProcess = true;

	return ESP_OK;
}

httpd_handle_t WebPageStart(void)
{
	httpd_handle_t server = NULL;
	httpd_config_t config = HTTPD_DEFAULT_CONFIG();

	// Start the HTTPD server
	ESP_LOGI(TAG, "Starting server on port: '%d'", config.server_port);

	if (httpd_start(&server, &config) == ESP_OK)
	{
		// Set URI handlers
		ESP_LOGI(TAG, "Registering URI handlers");
		ESP_ERROR_CHECK(httpd_register_uri_handler(server, &myPage_get));
		ESP_ERROR_CHECK(httpd_register_uri_handler(server, &myData_get));
		ESP_ERROR_CHECK(httpd_register_uri_handler(server, &myPage_post));

		ESP_LOGI(TAG, "URI handlers registered");

		return server;
	}

	ESP_LOGI(TAG, "Error starting server!");

	return NULL;
}

static esp_err_t event_handler(void *ctx, system_event_t *event)
{
	httpd_handle_t *server = (httpd_handle_t*) ctx;

	/* Start the web server */
	if (*server == NULL)
	{
		*server = WebPageStart();
	}

	return ESP_OK;
}

void WIFI_vInit(void *arg)
{
	/* TCPIP stack to handle IPs */
	tcpip_adapter_init();

	/* Initialize the server events */
	ESP_ERROR_CHECK(esp_event_loop_init(event_handler, arg));

	/* WIFI structure */
	wifi_init_config_t wifi_config = WIFI_INIT_CONFIG_DEFAULT()
	;

	/* Default configuration */
	ESP_ERROR_CHECK(esp_wifi_init(&wifi_config));
	ESP_ERROR_CHECK(esp_wifi_set_storage(WIFI_STORAGE_RAM));

	/* Configure AP structure */
	wifi_config_t wifi_ap_config =
	{ .ap =
	{ .ssid = ESP_SSID_AP, .password = ESP_PASS_AP, .ssid_len = strlen(
	ESP_SSID_AP), .channel = 1, .authmode = WIFI_AUTH_WPA2_PSK,
			.ssid_hidden = 0, .max_connection = 1, .beacon_interval = 100 }, };

	/* Password validation */
	if (strlen(ESP_PASS_AP) == 0)
	{
		wifi_ap_config.ap.authmode = WIFI_AUTH_OPEN;
	}
	if (strlen(ESP_PASS_AP) < 8)
	{
		ESP_LOGI(TAG, "Password %s is too short", ESP_PASS_AP);
	}

	/* Set mode to AP */
	ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_AP));
	/* Apply AP settings */
	ESP_ERROR_CHECK(esp_wifi_set_config(ESP_IF_WIFI_AP, &wifi_ap_config));
	/* Start the WIFI protocol */
	ESP_ERROR_CHECK(esp_wifi_start());

	ESP_LOGI(TAG, "WiFi initialize AP finished. SSID: %s password: %s",
			ESP_SSID_AP, ESP_PASS_AP);
}
