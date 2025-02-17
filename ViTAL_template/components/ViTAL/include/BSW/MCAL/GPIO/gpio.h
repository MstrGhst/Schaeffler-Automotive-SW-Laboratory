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

/* ULTRASONIC_SENSOR_HW */
#define HC_SR04_TRIGGER_PIN 5
#define HC_SR04_TRIGGER_PIN_MASK (1 << HC_SR04_TRIGGER_PIN)
#define HC_SR04_ECHO_PIN 6
#define HC_SR04_ECHO_PIN_MASK (1 << HC_SR04_ECHO_PIN)

/* DHT11_HW */
#define DHT11_PIN 7
#define DHT11_PIN_MASK (1 << DHT11_PIN)

/* SHIFT_REGISTER_HW */
#define SN74HC595N_DS_PIN 2
#define SN74HC595N_DS_PIN_MASK (1 << SN74HC595N_DS_PIN)
#define SN74HC595N_ST_CP_PIN 3
#define SN74HC595N_ST_CP_PIN_MASK (1 << SN74HC595N_ST_CP_PIN)
#define SN74HC595N_SH_CP_PIN 4
#define SN74HC595N_SH_CP_PIN_MASK (1 << SN74HC595N_SH_CP_PIN)

/* Macros */
#define LOW_LEVEL 0
#define HIGH_LEVEL 1

#define DIR_INPUT 1
#define DIR_OUTPUT 2

#endif
