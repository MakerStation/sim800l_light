#ifndef SIM800L_LIGHT_H
#define SIM800L_LIGHT_H

#include "Arduino.h"

#define RX_PIN 10
#define TX_PIN 11	
#define RESET_PIN 2   // pin to the reset pin sim800l

#define LED true // used for indicator led, in case that you don want set to false . 
#define LED_PIN 13 //pin to indicate states. 

class sim800l_light
{
   private:
		// qui ci va tutto quello che è private e quindi non visibile da fuori la libreria
		String _buffer;

	public:
		// qui ci va tutto quello che deve essere VISIBILE DA FUORI, compreso eventuali variabili di ritorno o tipi di ritorno
		void begin (void);
};

#endif