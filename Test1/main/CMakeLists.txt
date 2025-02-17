idf_component_register(SRCS "main.c"
                        "../components/ViTAL/BSW/MCAL/ADC/adc.c"
                        "../components/ViTAL/BSW/MCAL/GPIO/gpio.c"
                        "../components/ViTAL/BSW/MCAL/PWM/pwm.c"
                        "../components/ViTAL/BSW/MCAL/WIFI/wifi.c"


                        "../components/ViTAL/BSW/HAL/Buzzer/buzzer.c"
                        "../components/ViTAL/BSW/HAL/Com/com.c"
                        "../components/ViTAL/BSW/HAL/DC_Motor/dc_motor.c"
                        "../components/ViTAL/BSW/HAL/Photo_Resistor/photo_resistor.c"
                        "../components/ViTAL/BSW/HAL/Proximity_Sensor/proximity_sensor.c"
                        "../components/ViTAL/BSW/HAL/Servo_Motor/servo_motor.c"
                        "../components/ViTAL/BSW/HAL/Shift_Register/shift_register.c"
                        "../components/ViTAL/BSW/HAL/Temp_Sensor/temp_sensor.c"

                        "../components/ViTAL/RTE/rte.c"

                        "../components/ViTAL/ASW/Ambient_Light/ambient_light.c"
                        "../components/ViTAL/ASW/Climate_Control_System/climate_control_system.c"
                        "../components/ViTAL/ASW/Headlights/headlights.c"
                        "../components/ViTAL/ASW/Horn/horn.c"
                        "../components/ViTAL/ASW/Locking_System/locking_system.c"
                        "../components/ViTAL/ASW/Security/security.c"
                        "../components/ViTAL/ASW/Trunk/trunk.c"

                        "../components/ViTAL/SRVL/SCHEDULER/scheduler.c"

                    EMBED_FILES "../components/ViTAL/index.html"

                    INCLUDE_DIRS "include" "../components/ViTAL/include")
