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

#include "BSW/MCAL/PWM/pwm.h"

#include "driver/mcpwm.h"

static const char *TAG = "MCAL PWM";

/* Default duty-cycles for each channel */
uint32_t g_u32Duties[PWM_CHANNELS] =
{ 1500, 0, 0 };

/* Pin numbers on board for each channel */
uint32_t g_u32PinNum[PWM_CHANNELS] =
{ SERVO_MOTOR_PWM_PIN, DC_MOTOR_PWM_PIN, BUZZER_PWM_PIN };

void PWM_vInit(void)
{

}

void PWM_vSetDutyCycle(uint8_t u8Channel, uint32_t u32DutyCycle)
{

}
