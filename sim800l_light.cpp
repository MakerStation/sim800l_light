/*
  sim800l-light.cpp - Libreria per gestire
  il modulo SIMCom SIM800L tramite
  comandi AT via seriale.
*/

#include "Arduino.h"
#include <SoftwareSerial.h>
#include "sim800l_light.h"  // dichiarazione della classe

SoftwareSerial SIM(RX_PIN,TX_PIN);

/* funzione di inizializzazione */
void sim800l_light::begin(){
	SIM.begin(9600);
	#if (LED) 
		pinMode(OUTPUT,LED_PIN);
	#endif
	_buffer.reserve(255); //reserve memory to prevent intern fragmention
}

// void sim800l_light::ddd(){
	
// }