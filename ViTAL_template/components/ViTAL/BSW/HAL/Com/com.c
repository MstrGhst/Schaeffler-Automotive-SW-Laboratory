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

#include "BSW/HAL/Com/com.h"

#include "BSW/MCAL/WIFI/wifi.h"

static const char *TAG = "HAL COM";

extern char g_cGETBuffer[100];
extern char g_cPOSTBuffer[100];

extern bool g_bGETRequestInProcess;
extern bool g_bPOSTRequestInProcess;

/* Assign some default values to GET buffer */
COM_GET_struct g_GET_DataStructure =
{ .u8Temperature = 27, .u8Humidity = 50, .u8Comfort = 24, .bIsLocked = true,
		.bIsOccupied = false };

/* Assign some default values to POST buffer */
COM_POST_struct g_POST_DataStructure =
{ .bButtonFan = false, .bButtonTrunk = false, .bButtonHeadlights = false,
		.bButtonAmbientalLights = false, .bButtonFindMyCar = false,
		.bButtonHonk = false, .bButtonSecurity = false, .bButtonDoorLock = false,
		.u8UserTemperature = 27 };

void COM_vProcessGetRequest(void)
{
	if (g_bGETRequestInProcess)
	{
		char dataBuffer[6];

		sprintf(dataBuffer, "%d", g_GET_DataStructure.u8Temperature);
		/* First string to be copied to buffer */
		strcpy(g_cGETBuffer, dataBuffer);
		strcat(g_cGETBuffer, "\n");

		sprintf(dataBuffer, "%d", g_GET_DataStructure.u8Humidity);
		strcat(g_cGETBuffer, dataBuffer);
		strcat(g_cGETBuffer, "\n");

        /* Confort string */

		sprintf(dataBuffer, "%d", g_GET_DataStructure.u16PhotoRes);
		strcat(g_cGETBuffer, dataBuffer);
		strcat(g_cGETBuffer, "\n");

		if (g_GET_DataStructure.bIsLocked)
		{
			strcat(g_cGETBuffer, "locked\n");
		}
		else
		{
			strcat(g_cGETBuffer, "unlocked\n");
		}

        /* isOccupied string (if-else) */

		g_bGETRequestInProcess = false;
	}
}

void COM_vProcessPostRequest(void)
{
	if (g_bPOSTRequestInProcess)
	{
		if (strcmp(g_cPOSTBuffer, "button=Fan+On") == 0)
		{
			g_POST_DataStructure.bButtonFan = true;
		}
		else if (strcmp(g_cPOSTBuffer, "button=Fan+Off") == 0)
		{
			g_POST_DataStructure.bButtonFan = false;
		}

        /* Trunk response */

		else if (strcmp(g_cPOSTBuffer, "button=Head+Lights+On") == 0)
		{
			g_POST_DataStructure.bButtonHeadlights = true;
		}
		else if (strcmp(g_cPOSTBuffer, "button=Head+Lights+Off") == 0)
		{
			g_POST_DataStructure.bButtonHeadlights = false;
		}

		else if (strcmp(g_cPOSTBuffer, "button=Ambiental+Lights+On") == 0)
		{
			g_POST_DataStructure.bButtonAmbientalLights = true;
		}
		else if (strcmp(g_cPOSTBuffer, "button=Ambiental+Lights+Off") == 0)
		{
			g_POST_DataStructure.bButtonAmbientalLights = false;
		}

		else if (strcmp(g_cPOSTBuffer, "button=Find+My+Car") == 0)
		{
			g_POST_DataStructure.bButtonFindMyCar = true;
		}

		else if (strcmp(g_cPOSTBuffer, "button=Honk") == 0)
		{
			g_POST_DataStructure.bButtonHonk = true;
		}

		else if (strcmp(g_cPOSTBuffer, "button=Security+On") == 0)
		{
			g_POST_DataStructure.bButtonSecurity = true;
		}
		else if (strcmp(g_cPOSTBuffer, "button=Security+Off") == 0)
		{
			g_POST_DataStructure.bButtonSecurity = false;
		}

		else if (strcmp(g_cPOSTBuffer, "button=Unlock+Door") == 0)
		{
			g_POST_DataStructure.bButtonDoorLock = false;
		}
		else if (strcmp(g_cPOSTBuffer, "button=Lock+Door") == 0)
		{
			g_POST_DataStructure.bButtonDoorLock = true;
		}

		else if (strstr(g_cPOSTBuffer, "user-temp=") != NULL)
		{
			g_POST_DataStructure.u8UserTemperature = (g_cPOSTBuffer[10] - '0')
					* 10;
			g_POST_DataStructure.u8UserTemperature += g_cPOSTBuffer[11] - '0';
		}

		else
		{
			ESP_LOGI(TAG, "Not known");
		}

		g_bPOSTRequestInProcess = false;
	}
}

void COM_vTaskProcessServer(void)
{
	COM_vProcessGetRequest();
	COM_vProcessPostRequest();
}
