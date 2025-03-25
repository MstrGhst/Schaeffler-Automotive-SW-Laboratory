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

#include "BSW/HAL/Proximity_Sensor/proximity_sensor.h"

#include "BSW/MCAL/GPIO/gpio.h"

static const char *TAG = "HAL PROXIMITY SENSOR";
void PROX_vRequest(void)
{
    GPIO_vSetLevel(HC_SR04_TRIGGER_PIN,LOW_LEVEL);
    ets_delay_us(2);
    GPIO_vSetLevel(HC_SR04_TRIGGER_PIN,HIGH_LEVEL);
    ets_delay_us(10);
    GPIO_vSetLevel(HC_SR04_TRIGGER_PIN,LOW_LEVEL);

}

 uint16_t PROX_u16Read(void)
{
    PROX_vRequest();
    while(GPIO_iGetLevel(HC_SR04_ECHO_PIN)==0);
    int time_start=esp_timer_get_time();
    while(GPIO_iGetLevel(HC_SR04_ECHO_PIN)==1);
    int time_stop=esp_timer_get_time();
    int distanta=time_stop-time_start;
    ESP_LOGI(TAG,"Distanta este: %d",distanta);
    return(uint16_t)(distanta*0.0343)/2;
}