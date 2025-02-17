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

#ifndef COMPONENTS_VITAL_BSW_MCAL_PWM_H
#define COMPONENTS_VITAL_BSW_MCAL_PWM_H

#include "global.h"

/*******************************************************************************
 *  Function name    : PWM_vInit
 *
 *  Description      : Initial configuration of MCAL PWM
 *
 *  List of arguments: -
 *
 *  Return value     : -
 *
 *******************************************************************************/
void PWM_vInit(void);

/*******************************************************************************
 *  Function name    : PWM_vSetDutyCycle
 *
 *  Description      : Set duty cycle for a specific channel
 *
 *  List of arguments: u8Channel -> Channel where to change duty cycle
 *                     u32DutyCycle -> Period of duty cycle
 *
 *  Return value     : -
 *
 *******************************************************************************/
void PWM_vSetDutyCycle(uint8_t u8Channel, uint32_t u32DutyCycle);


/* Configuration */
#define PWM_PERIOD 20000 /* T = 1000us -> F = 1KHz */
#define PWM_CHANNELS 4 /* Total number of channels */
#define PWM_FREQUENCY 50 /* F = 50Hz -> T = 20,000us*/
/* Channels */
#define SERVO_MOTOR_PWM_CHANNEL 0
#define DC_MOTOR_PWM_CHANNEL 1
#define BUZZER_PWM_CHANNEL 2
#define DC_MOTOR_PWM_REVERSE_CHANNEL 3

/* Pins */
#define SERVO_MOTOR_PWM_PIN 12
#define DC_MOTOR_PWM_REVERSE_PIN 13
#define DC_MOTOR_PWM_PIN 14
#define BUZZER_PWM_PIN 15

#endif
