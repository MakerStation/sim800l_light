/**
 * @file sim800l_light.cpp
 * @author MakerStation (info@makerstation.it)
 * @brief A light version of SIM800L communication library using AT commands through serial
 * @version 0.1
 * @date 2022-01-16
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "Arduino.h"
#include <SoftwareSerial.h>
#include "sim800l_light.h" // dichiarazione della classe

SoftwareSerial SIM(RX_PIN, TX_PIN);

/**
 * @brief Set if display or not the result code of any command
 *
 */
void sim800l_light::_setResultCode()
{
	SIM.println("ATQ1");
}

/**
 * @brief Set retourned message format
 *
 * @param format 0 = PDU format (hex) / 1 = clear text format
 *
 */
void sim800l_light::_setMessageFormat(int format)
{
	SIM.println("AT+CMGF=" + format);
}

/**
 * @brief Initialization of SIM800 Serial comm and first mandatory setup
 * 
 * @param speed Speed of serial (max 19200 to avoid packet loss)
 */
void sim800l_light::begin(int speed)
{
	if (speed > 19200)
	{
		speed = 19200;
	}
	
	SIM.begin(speed);
#if (LED)
	pinMode(OUTPUT, LED_PIN);
#endif
	_buffer.reserve(255); // reserve memory to prevent intern fragmention
}


// }