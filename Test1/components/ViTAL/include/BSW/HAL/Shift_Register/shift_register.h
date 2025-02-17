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

#ifndef COMPONENTS_VITAL_BSW_HAL_SHIFT_REGISTER_H
#define COMPONENTS_VITAL_BSW_HAL_SHIFT_REGISTER_H
#define SN74HC595N_DS_PIN 2
#define SN74HC595N_SH_CP_PIN 4
#define SN74HC595N_ST_CP_PIN 3
#include "global.h"

void SHIFTREG_vOutput8Bits(uint8_t u8Data);

#endif
