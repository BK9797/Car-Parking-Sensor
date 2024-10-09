/******************************************************************************
 *
 * Module: LEDS
 *
 * File Name: leds.c
 *
 * Description: source file for the AVR LED driver
 *
 * Author: BISHOY KAMEL
 *
 *******************************************************************************/

/************************Libraries and inclusions*******************************/

#include "leds.h"

/**********************************Functions************************************/

/*
 * Description :
 * A function to initialize the LEDS
 */
void LEDS_init(void)
{
    /* Make the RED LED pin an output pin */
    GPIO_setupPinDirection(RED_LED_PORT, RED_LED_PIN, PIN_OUTPUT);

    /* Turn off the RED LED */
    #if LED_LOGIC_TYPE == LED_LOGIC_TYPE_POSITIVE
        GPIO_writePin(RED_LED_PORT, RED_LED_PIN, LOGIC_LOW); // Off state for Positive Logic
    #else
        GPIO_writePin(RED_LED_PORT, RED_LED_PIN, LOGIC_HIGH); // Off state for Negative Logic
    #endif

    /* Make the Green LED pin an output pin */
    GPIO_setupPinDirection(GREEN_LED_PORT, GREEN_LED_PIN, PIN_OUTPUT);

    /* Turn off the Green LED */
    #if LED_LOGIC_TYPE == LED_LOGIC_TYPE_POSITIVE
        GPIO_writePin(GREEN_LED_PORT, GREEN_LED_PIN, LOGIC_LOW); // Off state for Positive Logic
    #else
        GPIO_writePin(GREEN_LED_PORT, GREEN_LED_PIN, LOGIC_HIGH); // Off state for Negative Logic
    #endif

    /* Make the BLUE LED pin an output pin */
    GPIO_setupPinDirection(BLUE_LED_PORT, BLUE_LED_PIN, PIN_OUTPUT);

    /* Turn off the BLUE LED */
    #if LED_LOGIC_TYPE == LED_LOGIC_TYPE_POSITIVE
        GPIO_writePin(BLUE_LED_PORT, BLUE_LED_PIN, LOGIC_LOW); // Off state for Positive Logic
    #else
        GPIO_writePin(BLUE_LED_PORT, BLUE_LED_PIN, LOGIC_HIGH); // Off state for Negative Logic
    #endif
}

/*
 * Description :
 * A function to turn on the LED
 */
void LED_on(LED_ID id)
{
    if (id == red) {
        /* Turn on the RED_LED */
        #if LED_LOGIC_TYPE == LED_LOGIC_TYPE_POSITIVE
            GPIO_writePin(RED_LED_PORT, RED_LED_PIN, LOGIC_HIGH); // On state for Positive Logic
        #else
            GPIO_writePin(RED_LED_PORT, RED_LED_PIN, LOGIC_LOW); // On state for Negative Logic
        #endif
    } else if (id == green) {
        /* Turn on the GREEN_LED */
        #if LED_LOGIC_TYPE == LED_LOGIC_TYPE_POSITIVE
            GPIO_writePin(GREEN_LED_PORT, GREEN_LED_PIN, LOGIC_HIGH); // On state for Positive Logic
        #else
            GPIO_writePin(GREEN_LED_PORT, GREEN_LED_PIN, LOGIC_LOW); // On state for Negative Logic
        #endif
    } else if (id == blue) {
        /* Turn on the BLUE_LED */
        #if LED_LOGIC_TYPE == LED_LOGIC_TYPE_POSITIVE
            GPIO_writePin(BLUE_LED_PORT, BLUE_LED_PIN, LOGIC_HIGH); // On state for Positive Logic
        #else
            GPIO_writePin(BLUE_LED_PORT, BLUE_LED_PIN, LOGIC_LOW); // On state for Negative Logic
        #endif
    }
}

/*
 * Description :
 * A function to turn off the LED
 */
void LED_off(LED_ID id)
{
    if (id == red) {
        /* Turn off the RED_LED */
        #if LED_LOGIC_TYPE == LED_LOGIC_TYPE_POSITIVE
            GPIO_writePin(RED_LED_PORT, RED_LED_PIN, LOGIC_LOW); // Off state for Positive Logic
        #else
            GPIO_writePin(RED_LED_PORT, RED_LED_PIN, LOGIC_HIGH); // Off state for Negative Logic
        #endif
    } else if (id == green) {
        /* Turn off the GREEN_LED */
        #if LED_LOGIC_TYPE == LED_LOGIC_TYPE_POSITIVE
            GPIO_writePin(GREEN_LED_PORT, GREEN_LED_PIN, LOGIC_LOW); // Off state for Positive Logic
        #else
            GPIO_writePin(GREEN_LED_PORT, GREEN_LED_PIN, LOGIC_HIGH); // Off state for Negative Logic
        #endif
    } else if (id == blue) {
        /* Turn off the BLUE_LED */
        #if LED_LOGIC_TYPE == LED_LOGIC_TYPE_POSITIVE
            GPIO_writePin(BLUE_LED_PORT, BLUE_LED_PIN, LOGIC_LOW); // Off state for Positive Logic
        #else
            GPIO_writePin(BLUE_LED_PORT, BLUE_LED_PIN, LOGIC_HIGH); // Off state for Negative Logic
        #endif
    }
}
