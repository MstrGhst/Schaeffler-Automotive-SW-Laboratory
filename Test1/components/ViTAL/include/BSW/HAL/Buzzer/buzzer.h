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

#ifndef COMPONENTS_VITAL_BSW_HAL_BUZZER_H
#define COMPONENTS_VITAL_BSW_HAL_BUZZER_H

#include "global.h"

#define _20 1000
#define _40 4000
#define _80 5000

void BUZZER_vChangeDutyCycle(uint32_t u32BuzzerDutyCycle);

#endif
