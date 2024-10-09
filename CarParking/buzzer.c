/******************************************************************************
 *
 * Module: BUZZER
 *
 * File Name: buzzer.c
 *
 * Description: Source file for the Buzzer driver.
 *
 * Author: BISHOY KAMEL
 *
 *******************************************************************************/

/************************Libraries and inclusions*******************************/

#include "buzzer.h"

/**********************************Functions************************************/

/*
 * Description :
 * A function to initialize the buzzer pin
 */
void Buzzer_init(void)
{
    /* Set the BUZZER_PIN as an output pin */
    GPIO_setupPinDirection(BUZZER_PORT, BUZZER_PIN, PIN_OUTPUT);

    /* Turn off the buzzer initially */
    GPIO_writePin(BUZZER_PORT, BUZZER_PIN, LOGIC_LOW);
}

/*
 * Description :
 * A function to activate the buzzer
 */
void Buzzer_on(void)
{
    /* Activate the buzzer */
    GPIO_writePin(BUZZER_PORT, BUZZER_PIN, LOGIC_HIGH); // Turn on the buzzer
}

/*
 * Description :
 * A function to deactivate the buzzer
 */
void Buzzer_off(void)
{
    /* Deactivate the buzzer */
    GPIO_writePin(BUZZER_PORT, BUZZER_PIN, LOGIC_LOW); // Turn off the buzzer
}
