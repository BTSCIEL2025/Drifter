/*
 Name:		Drifter.ino
 Created:	19/04/2024 09:43:12
 Author:	gab
*/

// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(9600);
	pinMode(6, INPUT);
	digitalWrite(6, LOW);
}

void loop() {
	if (digitalRead(6) == HIGH) {
		Serial.println("1");
	}
	else {
		Serial.println("0");
	}
	delay(1000);

}

