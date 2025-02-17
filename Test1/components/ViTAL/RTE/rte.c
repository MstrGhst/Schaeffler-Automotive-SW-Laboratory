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

#include "RTE/rte.h"

#include "BSW/HAL/Buzzer/buzzer.h"
#include "BSW/HAL/Com/com.h"
#include "BSW/HAL/DC_Motor/dc_motor.h"
#include "BSW/HAL/Proximity_Sensor/proximity_sensor.h"
#include "BSW/HAL/Servo_Motor/servo_motor.h"
#include "BSW/HAL/Shift_Register/shift_register.h"

static const char *TAG = "RTE";

extern COM_GET_struct g_GET_DataStructure;
extern COM_POST_struct g_POST_DataStructure;

void RTE_vSetAmbientalLightsState(bool bState)
{
	//The function will render the R-G-B color sequence.
	// bState will be the button status from WebApp

	static uint8_t s_u8ColorState = STATE_RED;

	if (bState == ON)
	{
		switch (s_u8ColorState)
		{
		case STATE_RED:
			RTE_vSetShiftRegisterOutput(ALL_COLORS, LOW);
			RTE_vSetShiftRegisterOutput(RED, HIGH);
			s_u8ColorState = STATE_RED_GREEN;
			break;
		case STATE_GREEN:
			RTE_vSetShiftRegisterOutput(ALL_COLORS, LOW);
			RTE_vSetShiftRegisterOutput(GREEN, HIGH);
			s_u8ColorState = STATE_GREEN_BLUE;
			break;
		case STATE_BLUE:
			RTE_vSetShiftRegisterOutput(ALL_COLORS, LOW);
			RTE_vSetShiftRegisterOutput(BLUE, HIGH);
			s_u8ColorState = STATE_RED_BLUE;
			break;
		default:
			ESP_LOGI(TAG, "RGB ERROR");
			break;
		}
	}
	else if (bState == OFF)
	{
		RTE_vSetShiftRegisterOutput(ALL_COLORS, LOW);
		s_u8ColorState = STATE_RED;
	}
	else
	{
		ESP_LOGI(TAG, "AMBIENTAL LIGHTS ERROR");
	}
}

void RTE_vSetShiftRegisterOutput(shift_register_positions_t u8ComponentMask, bool bLevel)
{
	//this function will send to the shift register to render the color sequence
	static uint8_t s_u8CurrentData = 0;

	if (bLevel == HIGH)
	{
		s_u8CurrentData |= u8ComponentMask;
	}
	else if (bLevel == LOW)
	{
		s_u8CurrentData &= ~(u8ComponentMask);
	}
	else
	{
		ESP_LOGI(TAG, "Invalid level for shift register");
	}

	SHIFTREG_vOutput8Bits(s_u8CurrentData);
}
