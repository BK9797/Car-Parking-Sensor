/*
 ============================================================================
 Name        : app.c
 Author      : BISHOY KAMEL
 Date        : 9-10-2024
 Description : Car Parking Sensor
 Author		 : BISHOY KAMEL
 ============================================================================
 */

/*******************************************************************************
 *                             Main Function definition                         *
 *******************************************************************************/

#include "buzzer.h"
#include "lcd.h"
#include "leds.h"
#include "Ultrasonic_sensor.h"
#include <util/delay.h>

int main(void) {
	/* Enable global interrupt by setting the I-bit in the status register */
	SREG |= (1 << 7);

	/* Initialize all necessary peripherals */
	Ultrasonic_init();   /* Initialize Ultrasonic sensor */
	LCD_init();          /* Initialize LCD display */
	LEDS_init();         /* Initialize LED driver */
	Buzzer_init();       /* Initialize Buzzer driver */

	/* Variable to store the measured distance */
	uint16 Distance =(Ultrasonic_readDistance() / 2) + 1;

	/* Display the initial message on the LCD */
	LCD_displayString("Distance=     cm");

	/* Infinite loop to continuously monitor the distance and control LEDs & Buzzer */
	while (1) {
		/* Read the distance from the Ultrasonic sensor and divide by 2 to correct the reading */
		Distance = (Ultrasonic_readDistance() / 2)+1;

		/* Move cursor to the position where the distance value will be displayed on the LCD */
		LCD_moveCursor(0, 10);

		/* Display the distance on the LCD screen */
		LCD_intgerToString(Distance);

		/* Clear extra characters for distances less than 100 cm */
		if (Distance < 100) {
			LCD_displayCharacter(' ');
		}

		/* Clear extra characters for distances less than 10 cm */
		else if (Distance < 10) {
			LCD_displayString("  ");
		}

		/* Control LEDs and buzzer based on the distance */
		if (Distance <= 5) {
			Buzzer_on();
			/* Turn on all LEDs (Red, Green, Blue) and sound the buzzer if the object is too close */
			LED_on(0);  /* Red LED ON */
			LED_on(1);  /* Green LED ON */
			LED_on(2);  /* Blue LED ON */
			_delay_ms(100);
			LED_off(0); /* Red LED OFF */
			LED_off(1); /* Green LED OFF */
			LED_off(2); /* Blue LED OFF */

			/* Display STOP message on the LCD */
			LCD_moveCursor(1, 0);
			LCD_displayString("     STOP!!     ");
		}
		else if (Distance <= 10) {
			/* Turn on all LEDs but turn off the buzzer if the object is a bit farther */
			LED_on(0);  /* Red LED ON */
			LED_on(1);  /* Green LED ON */
			LED_on(2);  /* Blue LED ON */
			if(Distance == 6){
				Buzzer_off();
				LCD_moveCursor(1, 0);
				LCD_displayString("               ");
			}

		}
		else if (Distance <= 15) {
			/* Turn on Red and Green LEDs, turn off the Blue LED */
			LED_on(0);  /* Red LED ON */
			LED_on(1);  /* Green LED ON */
			LED_off(2); /* Blue LED OFF */
		}
		else if (Distance <= 20) {
			/* Turn on Red LED, turn off Green and Blue LEDs */
			LED_on(0);  /* Red LED ON */
			LED_off(1); /* Green LED OFF */
			LED_off(2); /* Blue LED OFF */
		}
		else if (Distance > 20) {
			/* Turn off all LEDs if the object is farther away */
			LED_off(0); /* Red LED OFF */
			LED_off(1); /* Green LED OFF */
			LED_off(2); /* Blue LED OFF */
		}
	}
}

