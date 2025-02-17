/*******************************************************************************
 * COPYRIGHT (C) VITESCO TECHNOLOGIES
 * ALL RIGHTS RESERVED.
 *
 * The reproduction, transmission or use of this document or its
 * contents is not permitted without express written authority.
 * Offenders will be liable for damages. All rights, including rights
 * created by patent grant or registration of a utility model or design,
 * are reserved.
 ******************************************************************************/

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

void COM_vProcessGetRequest(void);

void COM_vProcessPostRequest(void);

void COM_vTaskProcessServer(void);

#endif
