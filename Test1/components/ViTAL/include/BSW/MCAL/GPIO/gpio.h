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

#ifndef COMPONENTS_VITAL_BSW_MCAL_GPIO_H
#define COMPONENTS_VITAL_BSW_MCAL_GPIO_H

#include "global.h"

/*******************************************************************************
 *  Function name    : GPIO_vInit
 *
 *  Description      : Initial configuration of MCAL GPIO
 *
 *  List of arguments: -
 *
 *  Return value     : -
 *
 *******************************************************************************/
void GPIO_vInit(void);

/*******************************************************************************
 *  Function name    : GPIO_vSetDirection
 *
 *  Description      : Set direction of specific GPIO pin
 *
 *  List of arguments: u8PinNumber -> Digital pin number
 *  				   u8Direction -> Direction of pin
 *
 *  Return value     : -
 *
 *******************************************************************************/
void GPIO_vSetDirection(uint8_t u8PinNumber, uint8_t u8Direction);

/*******************************************************************************
 *  Function name    : GPIO_vSetLevel
 *
 *  Description      : Set level of specific GPIO pin
 *
 *  List of arguments: u8PinNumber -> Digital pin number
 *  				   u32Level -> Logic level of pin's output
 *
 *  Return value     : -
 *
 *******************************************************************************/
void GPIO_vSetLevel(uint8_t u8PinNumber, uint32_t u32Level);

/*******************************************************************************
 *  Function name    : GPIO_iGetLevel
 *
 *  Description      : Get level of specific GPIO pin
 *
 *  List of arguments: u8PinNumber -> Digital pin number
 *
 *  Return value     : int -> Pin level
 *
 *******************************************************************************/
int GPIO_iGetLevel(uint8_t u8PinNumber);

/*******************************************************************************
 *  Function name    : GPIO_bCheck
 *
 *  Description      : Check if signal level is equal to a value, during a time interval.
 *
 *  List of arguments: u8PinNumber - pin, u8Level - level to check; u32Limit_us - time interval in us
 *
 *  Return value     : false (over limit) / true (signal level duration is under limit)
 *
 *******************************************************************************/
bool GPIO_bCheck(uint8_t u8PinNumber, uint8_t u8Level, uint32_t u32Limit_us);

/* ULTRASONIC_SENSOR */
#define HC_SR04_TRIGGER_PIN 5
#define HC_SR04_TRIGGER_PIN_MASK (1 << HC_SR04_TRIGGER_PIN)
#define HC_SR04_ECHO_PIN 6
#define HC_SR04_ECHO_PIN_MASK (1 << HC_SR04_ECHO_PIN)

/* DHT11 */
#define DHT11_PIN 7
#define DHT11_PIN_MASK (1 << DHT11_PIN)

/* SHIFT_REGISTER */
#define SER 2
#define SER_MASK (1 << SER)
#define SRCLK 3
#define SRCLK_MASK (1 << SRCLK)
#define RCLK 4
#define RCLK_MASK (1 << RCLK)

/* DC MOTOR */
#define DCM_PIN_1 13
#define DCM_PIN_1_PIN_MASK (1 << DCM_PIN_1)
#define DCM_PIN_2 14
#define DCM_PIN_2_PIN_MASK (1 << DCM_PIN_2)

/* Macros */
#define LOW_LEVEL 0
#define HIGH_LEVEL 1

#define DIR_INPUT 1
#define DIR_OUTPUT 2

#endif
