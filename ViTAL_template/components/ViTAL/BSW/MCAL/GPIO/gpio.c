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

#include "BSW/MCAL/GPIO/gpio.h"

#include "driver/gpio.h"

static const char *TAG = "MCAL GPIO";

/* GPIO structure */
static gpio_config_t sg_gpio_config;

void GPIO_vInit(void)
{
	/* ULTRASONIC_SENSOR_HW */
	sg_gpio_config.pin_bit_mask = (uint32_t) HC_SR04_TRIGGER_PIN_MASK;
	sg_gpio_config.mode = GPIO_MODE_OUTPUT;
	sg_gpio_config.pull_up_en = GPIO_PULLUP_DISABLE;
	sg_gpio_config.pull_down_en = GPIO_PULLDOWN_DISABLE;
	sg_gpio_config.intr_type = GPIO_INTR_DISABLE;
	ESP_ERROR_CHECK(gpio_config(&sg_gpio_config));

	sg_gpio_config.pin_bit_mask = (uint32_t) HC_SR04_ECHO_PIN_MASK;
	sg_gpio_config.mode = GPIO_MODE_INPUT;
	sg_gpio_config.pull_up_en = GPIO_PULLUP_DISABLE;
	sg_gpio_config.pull_down_en = GPIO_PULLDOWN_DISABLE;
	sg_gpio_config.intr_type = GPIO_INTR_DISABLE;
	ESP_ERROR_CHECK(gpio_config(&sg_gpio_config));

	/* SHIFT_REGISTER_HW */
	sg_gpio_config.pin_bit_mask = (uint32_t) SN74HC595N_DS_PIN_MASK;
	sg_gpio_config.mode = GPIO_MODE_OUTPUT;
	sg_gpio_config.pull_up_en = GPIO_PULLUP_DISABLE;
	sg_gpio_config.pull_down_en = GPIO_PULLDOWN_DISABLE;
	sg_gpio_config.intr_type = GPIO_INTR_DISABLE;
	ESP_ERROR_CHECK(gpio_config(&sg_gpio_config));

	sg_gpio_config.pin_bit_mask = (uint32_t) SN74HC595N_ST_CP_PIN_MASK;
	sg_gpio_config.mode = GPIO_MODE_OUTPUT;
	sg_gpio_config.pull_up_en = GPIO_PULLUP_DISABLE;
	sg_gpio_config.pull_down_en = GPIO_PULLDOWN_DISABLE;
	sg_gpio_config.intr_type = GPIO_INTR_DISABLE;
	ESP_ERROR_CHECK(gpio_config(&sg_gpio_config));

	sg_gpio_config.pin_bit_mask = (uint32_t) SN74HC595N_SH_CP_PIN_MASK;
	sg_gpio_config.mode = GPIO_MODE_OUTPUT;
	sg_gpio_config.pull_up_en = GPIO_PULLUP_DISABLE;
	sg_gpio_config.pull_down_en = GPIO_PULLDOWN_DISABLE;
	sg_gpio_config.intr_type = GPIO_INTR_DISABLE;
	ESP_ERROR_CHECK(gpio_config(&sg_gpio_config));
}

void GPIO_vSetDirection(uint8_t u8PinNumber, uint8_t u8Direction)
{
	ESP_ERROR_CHECK(gpio_set_direction(u8PinNumber, u8Direction));
}

void GPIO_vSetLevel(uint8_t u8PinNumber, uint32_t u32Level)
{
	ESP_ERROR_CHECK(gpio_set_level(u8PinNumber, u32Level));
}

int GPIO_iGetLevel(uint8_t u8PinNumber)
{
	return gpio_get_level(u8PinNumber);
}
