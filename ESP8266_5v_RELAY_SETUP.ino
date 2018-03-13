#include "Arduino.h"
#include <SoftwareSerial.h>

#define TxPin 7
#define RxPin 6

SoftwareSerial ESPrelay(RxPin, TxPin);

void setup() {
	Serial.begin(9600);
	ESPrelay.begin(9600);

	readRx();

	Serial.println("-- Send AT Commands");
	delay(1000);

	ESPrelay.println("AT+CIPCLOSE=5");
	readRx();

	ESPrelay.println("AT+RST");
	readRx();
	delay(2000);

	ESPrelay.println("AT+CIPMUX=1");
	readRx();

	ESPrelay.println("AT+CIPSERVER=1,80");
	readRx();

	Serial.println("Setup completed.");
}

void loop() {

}

void readRx() {

	String msg = "";
	while (ESPrelay.available()) {
		char rxByte = ESPrelay.read();
		msg+=rxByte;
	}
	Serial.println(msg);
	delay(500);
}
