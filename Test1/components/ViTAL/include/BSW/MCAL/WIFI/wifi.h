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

#ifndef COMPONENTS_VITAL_BSW_MCAL_WIFI_H
#define COMPONENTS_VITAL_BSW_MCAL_WIFI_H

#include "global.h"

/*
 * Set max URI length to 1024, instead of 512! CONFIG_HTTPD_MAX_REQ_HDR_LEN in sdkconfig.
 * */

#include "esp_http_server.h"

/*******************************************************************************
 *  Function name    : WIFI_vInit
 *
 *  Description      : Initial configuration of MCAL WIFI
 *
 *  List of arguments: -
 *
 *  Return value     : -
 *
 *******************************************************************************/
void WIFI_vInit();

/* WIFI credentials */
#define ESP_SSID_AP "Lab_Edy_Vital" 
#define ESP_PASS_AP "17080123"
/*Password for WPA2-PSK has a minimum of 8 chars*/

#endif
