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

#include "BSW/HAL/DC_Motor/dc_motor.h"

#include "BSW/MCAL/PWM/pwm.h"

static const char *TAG = "HAL DC MOTOR";

/*******************************************************************************
 *  Function name    : DCMOT_vChangeSpeed
 *
 *  Description      : Change the DC Motor speed
 *
 *  List of arguments: u32DCMotorSpeed -> PWM duty cycle for speed
 *
 *  Return value     : -
 *
 ******************************************************************************/
void DCMOT_vChangeSpeed(uint32_t u32DCMotorSpeed)
{
    if(u32DCMotorSpeed==DC_MOTOR_STOP)
    {
        PWM_vSetDutyCycle(DC_MOTOR_PWM_CHANNEL,DC_MOTOR_STOP);
    }
    else if(u32DCMotorSpeed==DC_MOTOR_FULL_SPEED)
    {
        PWM_vSetDutyCycle(DC_MOTOR_PWM_CHANNEL,DC_MOTOR_FULL_SPEED);
    }
    else if(u32DCMotorSpeed==DC_MOTOR_LOW_SPEED)
    {
        PWM_vSetDutyCycle(DC_MOTOR_PWM_CHANNEL,DC_MOTOR_LOW_SPEED);
    }
    else
    {
        printf("Eroare");
    }
}
