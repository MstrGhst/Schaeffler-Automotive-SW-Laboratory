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

#include "driver/ledc.h"

#include "BSW/MCAL/GPIO/gpio.h"

static const char *TAG = "MCAL PWM";

/* Default duty-cycles for each channel */
uint32_t g_u32Duties[PWM_CHANNELS] =
{ 1500, 0, 0, 0 };

/* Pin numbers on board for each channel */
uint32_t g_u32PinNum[PWM_CHANNELS] =
{ SERVO_MOTOR_PWM_PIN, DC_MOTOR_PWM_PIN, BUZZER_PWM_PIN, DC_MOTOR_PWM_REVERSE_PIN };


static ledc_channel_config_t ledc_channel[PWM_CHANNELS] = {		/*channel configuration parameters*/
	{
		.channel = SERVO_MOTOR_PWM_CHANNEL,  		/*channel*/
		.duty = 0,									/*initial duty*/ 
		.gpio_num = SERVO_MOTOR_PWM_PIN,			/*output pin for servo*/
		.speed_mode = LEDC_LOW_SPEED_MODE,			/*speed mode for the servo*/
		.hpoint = 0,								/*channel hpoint value*/
		.timer_sel = LEDC_TIMER_1},					/*timer source of channel*/		
	{
		.channel = DC_MOTOR_PWM_CHANNEL,			
		.duty = 0,
		.gpio_num = DC_MOTOR_PWM_PIN,
		.speed_mode = LEDC_LOW_SPEED_MODE,
		.hpoint = 0,
		.timer_sel = LEDC_TIMER_1},
	{
		.channel = BUZZER_PWM_CHANNEL,
		.duty = 0,
		.gpio_num = BUZZER_PWM_PIN,
		.speed_mode = LEDC_LOW_SPEED_MODE,
		.hpoint = 0,
		.timer_sel = LEDC_TIMER_1},
	{
		.channel = DC_MOTOR_PWM_REVERSE_CHANNEL,			
		.duty = 0,
		.gpio_num = DC_MOTOR_PWM_REVERSE_PIN,
		.speed_mode = LEDC_LOW_SPEED_MODE,
		.hpoint = 0,
		.timer_sel = LEDC_TIMER_1}};


void PWM_vInit(void)
{
	ESP_LOGI(TAG, " init");
    uint8_t channel = 0;

	ledc_timer_config_t ledc_timer = {		  // configuration parameters of LEDC TIMER 
		.duty_resolution = LEDC_TIMER_13_BIT, // resolution of PWM duty
		.freq_hz = PWM_FREQUENCY,			  // frequency of PWM signal
		.speed_mode = LEDC_LOW_SPEED_MODE,	  // timer mode
		.timer_num = LEDC_TIMER_1,			  // timer index
		.clk_cfg = LEDC_AUTO_CLK,			  // Auto select the source clock
	};

	ledc_timer_config(&ledc_timer); // setting the timer passing the data struct

	for (channel = 0; channel < PWM_CHANNELS; channel++) 
	{
		ledc_channel_config(&ledc_channel[channel]);	//configuration of each channel
	}

	ledc_fade_func_install(0);			//set LEDC fade function

}

void PWM_vSetDutyCycle(uint8_t u8Channel, uint32_t u32DutyCycle)
{	
	//uint32_t TotalPeriod = uint32_t (1000000 / PWM_FREQUENCY) 
    // Limit DutyCycle maximum period to 20ms
	if (u32DutyCycle > 20000) 
	{
		u32DutyCycle = 20000;
	}

	// Calculate DutyCycle
	u32DutyCycle = u32DutyCycle * 8192 / 20000;   // example duty= 50% -> 10000 * 8192 / 20000 ->  8192 / 2 -> 4096
	// 8192 because LED_TIMER_13_BIT is used so we have 2^13 which is 8192
	// Update DutyCycle
	if(u8Channel==1){
		GPIO_vSetLevel(DCM_PIN_1, LOW_LEVEL);
		ledc_set_duty(ledc_channel[u8Channel].speed_mode, ledc_channel[u8Channel].channel, u32DutyCycle); // set duty for the channel 
		ledc_update_duty(ledc_channel[u8Channel].speed_mode, ledc_channel[u8Channel].channel);	// update the duty 
		}
	else if(u8Channel==3){
		GPIO_vSetLevel(DCM_PIN_2, LOW_LEVEL);
		ledc_set_duty(ledc_channel[u8Channel].speed_mode, ledc_channel[u8Channel].channel, u32DutyCycle); // set duty for the channel 
		ledc_update_duty(ledc_channel[u8Channel].speed_mode, ledc_channel[u8Channel].channel);	// update the duty 
		}
	else {
		ledc_set_duty(ledc_channel[u8Channel].speed_mode, ledc_channel[u8Channel].channel, u32DutyCycle); // set duty for the channel 
		ledc_update_duty(ledc_channel[u8Channel].speed_mode, ledc_channel[u8Channel].channel);	// update the duty 
	}
}








