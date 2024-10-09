/******************************************************************************
 *
 * Module: LEDS
 *
 * File Name: leds.h
 *
 * Description: source file for the AVR LED driver
 *
 * Author: BISHOY KAMEL
 *
 *******************************************************************************/

#ifndef LEDS_H
#define LEDS_H

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define RED_LED_PIN  PIN0_ID
#define RED_LED_PORT PORTC_ID

#define GREEN_LED_PIN  PIN1_ID
#define GREEN_LED_PORT PORTC_ID

#define BLUE_LED_PIN  PIN2_ID
#define BLUE_LED_PORT PORTC_ID

typedef enum{
	red,green,blue
}LED_ID;

#define LED_LOGIC_TYPE_POSITIVE 1
#define LED_LOGIC_TYPE_NEGATIVE 0

// Configuration option
#define LED_LOGIC_TYPE LED_LOGIC_TYPE_POSITIVE // Change to LED_LOGIC_TYPE_NEGATIVE as needed

#include"common_macros.h"
#include<avr/io.h>
#include"gpio.h"

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
/*
 * Description :
 * A function to initialize the LEDS
 */
void LEDS_init(void);

/*
 * Description :
 * A function to turn on the LED
 */
void LED_on(LED_ID id);

/*
 * Description :
 * A function to turn off the LED
 */
void LED_off(LED_ID id);

#endif /* LEDS_H */
