#
# "main" pseudo-component makefile.
#
# (Uses default behaviour of compiling all source files in directory, adding 'include' to include path.)

COMPONENT_SRCDIRS += 	BSW/MCAL/ADC \
						BSW/MCAL/GPIO \
						BSW/MCAL/PWM \
						BSW/MCAL/WIFI \
						 \
						BSW/HAL/Buzzer \
						BSW/HAL/Com \
						BSW/HAL/DC_Motor \
						BSW/HAL/Photo_Resistor \
						BSW/HAL/Proximity_Sensor \
						BSW/HAL/Servo_Motor \
                        BSW/HAL/Shift_Register \
						BSW/HAL/Temp_Sensor \
						 \
						RTE \
						 \
						ASW/Ambient_Light \
						ASW/Climate_Control_System \
						ASW/Headlights \
						ASW/Horn \
						ASW/Locking_System \
						ASW/Security \
                        ASW/Trunk \
						 \
						SRVL/SCHEDULER \
						