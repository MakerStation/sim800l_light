#ifndef SIM800L_LIGHT_H
#define SIM800L_LIGHT_H

#include "Arduino.h"

#define RX_PIN 10
#define TX_PIN 11	
#define RESET_PIN 2   // pin to the reset pin sim800l

#define LED true // used for indicator led, in case that you don want set to false . 
#define LED_PIN 13 //pin to indicate states. 

#define SMS_CMD_STATUS_UNREAD	"REC UNREAD"
#define SMS_CMD_STATUS_READ		"REC READ"
#define SMS_CMD_STATUS_ALL		"ALL"

#define SMS_CMD_DELETE_READ		"DEL READ"		// delete all messages that have been READ
#define SMS_CMD_DELETE_UNREAD	"DEL UNREAD"	// delete all messages that are still TO BE READ
#define SMS_CMD_DELETE_SENT		"DEL SENT"		// delete all messages that have been sent
#define SMS_CMD_DELETE_UNSENT	"DEL UNSENT"	// delete all messages that are still TO BE SEND (draft)
#define SMS_CMD_DELETE_INBOX	"DEL INBOX"		// delete all received messages
#define SMS_CMD_DELETE_ALL		"DEL ALL"		// delete ALL messages from any storage	

#define SCALE_CMD_TYPE_LOGIN	"L0GIN"
#define SCALE_CMD_TYPE_RESET	"Reset"
#define SCALE_CMD_TYPE_DATA		"Dati"
#define SCALE_CMD_TYPE_CLOCK	"Orario"

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
		string _readSMS(string commandToSearch, SoftwareSerial &serobj, bool changeMe);	//TODO richiamata da checkMessageForCommand


	public:
		// qui ci va tutto quello che deve essere VISIBILE DA FUORI, compreso eventuali variabili di ritorno o tipi di ritorno
		void begin(long speed, SoftwareSerial &serobj);
		int getMessageCountByType(string stat, bool changeMe, SoftwareSerial &serobj);	// TODO
		bool deleteMessage(string delType, SoftwareSerial &serobj);		// TODO
		void checkMessageForCommand(string command, SoftwareSerial & serobj);	// TODO
		bool sendSMS(string dest, string text, SoftwareSerial &Serobj);		//TODO - Ricordarsi il CTRL+Z alla fine (ASCII 26) altrimenti il messaggio non va via
		int checkForMessage(SoftwareSerial &serobj);	// TODO - controlla il +CMTI sulla seriale
};

#endif