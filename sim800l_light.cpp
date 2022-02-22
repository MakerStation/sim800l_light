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
// #include <SoftwareSerial.h>	// passing the serial object to function, the serial definition must be done in main code, so #include is not needed
#include "sim800l_light.h"
#include <avr/sleep.h>

// SoftwareSerial SIM(RX_PIN, TX_PIN);	// passing the serial object to function, the serial definition must be done in main code

/**
 * @brief Enable the showing of result code of any command
 *
 * @param serobj The serial object to use to communicate with SIM800L
 * @return true The command completed successfully
 * @return false Something goes wrong with the command
 */
bool sim800l_light::_enableResultCode(SoftwareSerial &serobj)
{
	serobj.println(F("ATQ0"));
	if (serobj.available())
	{
		if (serobj.readString().indexOf("OK") != -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

/**
 * @brief Set returned message format
 *
 * @param format 0/1 - 0 = PDU format (hex) / 1 = Clear Text
 * @param serobj The serial object to use to communicate with SIM800L
 * @return true
 * @return false
 */
bool sim800l_light::_setMessageFormat(int format, SoftwareSerial serobj)
{
	serobj.println(F("AT+CMGF=") + format);
	if (serobj.available())
	{
		if (serobj.readString().indexOf("OK") != -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

/**
 * @brief Try to connect to SIM800L module
 *
 * @param serobj The serial object to use to communicate with SIM800L
 * @return true Connect ok
 * @return false Connect not ok
 */
bool sim800l_light::_tryToConnect(SoftwareSerial &serobj)
{

	for (_iConnectTest = 0; _iConnectTest < 3; _iConnectTest++)
	{
		delay(10000);
		serobj.println(F("AT"));
		if (serobj.available())
		{
			if (serobj.readString().indexOf("OK") != -1)
			{
				_bInitDone = true;
			}
			else
			{
				_bInitDone = false;
			}
		}

		switch (_bInitDone)
		{
		case true:
			// doing all SIM800L init procedure needed to work correctly
			if (_enableResultCode(serobj))
			{
				if (_setMessageFormat(1, serobj))
				{
					return true;
				}
			}
			else
			{
				return false;
			}
			break;
		case false:
			// do SIM800L reset through the dedicated pin
			pinMode(RESET_PIN, OUTPUT);
			digitalWrite(RESET_PIN, LOW);
			delay(500);
			digitalWrite(RESET_PIN, HIGH);
		default:
			break;
		}
	}

	/* the following code will "stop" the execution of the code, preventing function to return the false state */
	if (_iConnectTest > 2)
	{
		Serial.println("   ****** W A R N I N G ******");
		Serial.println("There was a problem during SIM800L Module init procedure.");
		Serial.println("Module didn't respond after 10 sec and it has been already resetted 2 times...");
		Serial.println("Check SIM800L Module, power and connection.");
		Serial.println("");
		Serial.println("=== PROGRAM HALTED ===");
		// as a very HALT state doesn't exist in arduino (you can only power off it), we use deep sleep so to reduce drastically power consumption
		sleep_enable();						 // enabling sleep function
		set_sleep_mode(SLEEP_MODE_PWR_DOWN); // setting sleep mode
		delay(1000);						 // time wait 1 sec - could be removed or reduced
		power_all_disable();				 // disabling all (btw it will disable also interrupts!)
		sleep_mode();						 // going to sleep
	}
}

/**
 * @brief 
 * 
 * @param commandToSearch 
 * @param serobj 
 * @param changeMe 
 * @return string 
 */
string _readSMS(cmdType commandToSearch, SoftwareSerial &serobj, bool changeMe);	//TODO richiamata da checkMessageForCommand
{

}


/**
 * @brief Initialization of SIM800 Serial comm and first mandatory setup
 *
 * @param speed Speed of serial (max 19200 to avoid packet loss)
 */
void sim800l_light::begin(long speed, SoftwareSerial &serobj)
{
	switch (speed)
	{
	case 300:
		speed = 300;
		break;
	case 600:
		speed = 600;
		break;
	case 1200:
		speed = 1200;
		break;
	case 2400:
		speed = 2400;
		break;
	case 4800:
		speed = 4800;
		break;
	case 9600:
		speed = 9600;
		break;
	case 19200:
		speed = 19200;
		break;
	default:
		speed = 19200;
		bPrintSerialWarning = true;
		break;
	}

	serobj.begin(speed);
	while (!serobj)
	{
		;
	}
	// qui ci andrebbe funzione di controllo se entro 10 sec il modulo gsm ha risposto oppure no.
	// si potrebbe usare la lib elapsedMillis https://github.com/pfeerick/elapsedMillis
	// perchè se dopo 10 sec il moulo gsm non risponde occorre fargli un reset hw con il suo pin
	// oppure fargli un power cycle.
	// però mettere un delay() fa schifo perchè il programma si blocca per il tempo della delay()
	// e non è bellissimo....
	if (_tryToConnect(serobj))
	{
		_buffer.reserve(255); // reserve memory to prevent intern fragmention
	}
¯
#if (LED)
	pinMode(OUTPUT, LED_PIN);
#endif
}

/**
 * @brief Get the Message Count By Type object
 * 
 * @param stat 
 * @param changeMe 
 * @param serobj 
 * @return int 
 */
int getMessageCountByType(messageStatus stat, bool changeMe, SoftwareSerial &serobj);	// TODO
{

}

/**
 * @brief 
 * 
 * @param delType 
 * @param serobj 
 * @return true 
 * @return false 
 */
bool deleteMessage(deleteType delType, SoftwareSerial &serobj);		// TODO
{

}

/**
 * @brief 
 * 
 * @param command 
 * @param serobj 
 */
void checkMessageForCommand(cmdType command, SoftwareSerial & serobj);	// TODO
{

}

/**
 * @brief 
 * 
 * @param dest 
 * @param text 
 * @param Serobj 
 * @return true 
 * @return false 
 */
bool sendSMS(string dest, string text, SoftwareSerial &Serobj);		//TODO - Ricordarsi il CTRL+Z alla fine (ASCII 26) altrimenti il messaggio non va via
{

}

/**
 * @brief 
 * 
 * @param serobj 
 * @return int 
 */
int checkForMessage(SoftwareSerial &serobj);	// TODO - controlla il +CMTI sulla seriale
{

}