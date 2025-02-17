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

#ifndef COMPONENTS_VITAL_BSW_HAL_DC_MOTOR_H
#define COMPONENTS_VITAL_BSW_HAL_DC_MOTOR_H

#include "global.h"

void DCMOT_vChangeSpeed(uint32_t u32DCMotorSpeed);

/* Motor PWMs for speeds */
#define DC_MOTOR_STOP 0
#define DC_MOTOR_LOW_SPEED 15000       // 15 ms
#define DC_MOTOR_FULL_SPEED 20000      // 20 ms

#endif
