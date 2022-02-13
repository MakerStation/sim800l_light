#ifndef SIM800L_LIGHT_H
#define SIM800L_LIGHT_H

#include "Arduino.h"

#define RX_PIN 10
#define TX_PIN 11	
#define RESET_PIN 2   // pin to the reset pin sim800l

#define LED true // used for indicator led, in case that you don want set to false . 
#define LED_PIN 13 //pin to indicate states. 

enum messageStatus
{
	"REC UNREAD",
	"REC READ",
	"ALL"
};

enum deleteType
{
	"DEL READ",		// delete all messages that have been READ
	"DEL UNREAD",	// delete all messages that are still TO BE READ
	"DEL SENT",		// delete all messages that have been sent
	"DEL UNSENT",	// delete all messages that are still TO BE SEND (draft)
	"DEL INBOX",	// delete all received messages
	"DEL ALL"		// delete ALL messages from any storage
};

enum cmdType
{
	"L0GIN",
	"Reset",
	"Dati",
	"Orario"
};

const int iMsg_PDU_Hex_Format = 0;
const int iMsg_Text_Format = 1;

class sim800l_light
{
   private:
		// qui ci va tutto quello che è private e quindi non visibile da fuori la libreria
		String _buffer;
		bool _bPrintSerialWarning;
		bool _bInitDone;
		int _iConnectionTest;
		
		bool _enableResultCode(SoftwareSerial &serobj);
		bool _setMessageFormat(int format, SoftwareSerial &serobj);
		bool _tryToConnect(SoftwareSerial &serobj);
		string _readSMS(cmdType commandToSearch, SoftwareSerial &serobj, bool changeMe);	//TODO richiamata da checkMessageForCommand


	public:
		// qui ci va tutto quello che deve essere VISIBILE DA FUORI, compreso eventuali variabili di ritorno o tipi di ritorno
		void begin(long speed, SoftwareSerial &serobj);
		int getMessageCountByType(messageStatus stat, bool changeMe, SoftwareSerial &serobj);	// TODO
		bool deleteMessage(deleteType delType, SoftwareSerial &serobj);		// TODO
		void checkMessageForCommand(cmdType command, SoftwareSerial & serobj);	// TODO
		bool sendSMS(string dest, string text, SoftwareSerial &Serobj);		//TODO - Ricordarsi il CTRL+Z alla fine (ASCII 26) altrimenti il messaggio non va via
		int checkForMessage(SoftwareSerial &serobj);	// TODO - controlla il +CMTI sulla seriale
};

#endif