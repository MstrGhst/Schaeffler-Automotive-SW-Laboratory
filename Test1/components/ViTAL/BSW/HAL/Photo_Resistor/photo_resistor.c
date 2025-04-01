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

#include "BSW/HAL/Photo_Resistor/photo_resistor.h"

#include "BSW/MCAL/ADC/adc.h"

#include "BSW/HAL/Com/com.h"

extern COM_GET_struct g_GET_DataStructure;

static const char *TAG = "HAL PHOTO RESISTOR";

uint16_t PHRES_u16Read(void)
{
    return ADC_u16Read();
}

void PHRES_vTaskCalculate(void)
{
    uint16_t x=PHRES_u16Read();
    g_GET_DataStructure.u16PhotoRes=x;
    ESP_LOGI(TAG,"Valoarea este: %d",PHRES_u16Read());
}