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

#ifndef COMPONENTS_VITAL_BSW_HAL_COM_H
#define COMPONENTS_VITAL_BSW_HAL_COM_H

#include "global.h"

typedef struct
{
	uint8_t u8Temperature;
	uint8_t u8Humidity;
	uint8_t u8Comfort;
	uint16_t u16PhotoRes;
	bool bIsLocked;
	bool bIsOccupied;
} COM_GET_struct;

typedef struct
{
	bool bButtonFan;
	bool bButtonTrunk;
	bool bButtonHeadlights;
	bool bButtonAmbientalLights;
	bool bButtonFindMyCar;
	bool bButtonHonk;
	bool bButtonSecurity;
	bool bButtonDoorLock;
	uint8_t u8UserTemperature;
} COM_POST_struct;

/*******************************************************************************
 *  Function name    : COM_vProcessGetRequest
 *
 *  Description      : Update the GET buffer
 *
 *  List of arguments: -
 *
 *  Return value     : -
 *
 *******************************************************************************/
void COM_vProcessGetRequest(void);

/*******************************************************************************
 *  Function name    : COM_vProcessPostRequest
 *
 *  Description      : Process the POST buffer
 *
 *  List of arguments: -
 *
 *  Return value     : -
 *
 *******************************************************************************/
void COM_vProcessPostRequest(void);

/*******************************************************************************
 *  Function name    : COM_vTaskProcessServer
 *
 *  Description      : Process POST/GET requests
 *
 *  List of arguments: -
 *
 *  Return value     : -
 *
 *******************************************************************************/
void COM_vTaskProcessServer(void);

#endif
