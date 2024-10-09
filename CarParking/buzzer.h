/******************************************************************************
 *
 * Module: BUZZER
 *
 * File Name: buzzer.h
 *
 * Description: Header file for the Buzzer driver.
 *
 * Author: BISHOY KAMEL
 *
 *******************************************************************************/

#ifndef BUZZER_H
#define BUZZER_H

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

// Configuration for the buzzer pin
#define BUZZER_PORT    PORTC_ID // Change as needed
#define BUZZER_PIN     PIN5_ID   // Change as needed

#include "gpio.h"

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
/*
 * Description :
 * A function to initialize the buzzer pin
 */
void Buzzer_init(void);

/*
 * Description :
 * A function to activate the buzzer
 */
void Buzzer_on(void);

/*
 * Description :
 * A function to deactivate the buzzer
 */
void Buzzer_off(void);

#endif /* BUZZER_H */
