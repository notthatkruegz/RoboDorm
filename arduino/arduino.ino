int floorLampPin = 13;
int deskLampZPin = 12;
int deskLampZPin = 10;
int bedLampPin = 11;

void setup() {
	Serial.begin(9600);
	pinMode(floorLampPin, OUTPUT);
        pinMode(deskLampZPin, OUTPUT);
        pinMode(deskLampBPin, OUTPUT);
        pinMode(bedLampPin, OUTPUT);
}

String getCommand() {
        String command = "";
        char character;

	while (Serial.available()) {
                character = Serial.read();
                command.concat(character);
                delay(10);
        }

        return command;
}

void loop() {
	String command = getCommand();
        
	//Floor Lamp
	if (command == "floorLampOn")
		digitalWrite(floorLampPin, HIGH);
        else if (command == "floorLampOff")
                digitalWrite(floorLampPin, LOW);
        //Zach Desk Lamp
        else if (command == "deskLampZOn")
                digitalWrite(deskLampZPin, HIGH);
        else if (command == "deskLampZOff")
                digitalWrite(deskLampZPin, LOW);
        //Bridger Desk Lamp
        else if (command == "deskLampBOn")
                digitalWrite(deskLampBPin, HIGH);
        else if (command == "deskLampBOff")
                digitalWrite(deskLampBPin, LOW);
        //Zach Bed Lamp
        else if (command == "bedLampOn")
                digitalWrite(bedLampPin, HIGH);
        else if (command == "bedLampOff")
                digitalWrite(bedLampPin, LOW);
}
