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

#ifndef COMPONENTS_VITAL_BSW_MCAL_ADC_H
#define COMPONENTS_VITAL_BSW_MCAL_ADC_H

#include "global.h"

/*******************************************************************************
 *  Function name    : ADC_vInit
 *
 *  Description      : Initial configuration of MCAL ADC
 *
 *  List of arguments: -
 *
 *  Return value     : -
 *
 *******************************************************************************/
void ADC_vInit(void);

/*******************************************************************************
 *  Function name    : ADC_u16Read
 *
 *  Description      : Read of ADC value
 *
 *  List of arguments: -
 *
 *  Return value     : uint16_t -> ADC value
 *
 *******************************************************************************/
uint16_t ADC_u16Read(void);

#endif
