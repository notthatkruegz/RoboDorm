String command = "";
char character;
int floorLampPin = 13;
int deskLampPin = 12;
int bedLampPin = 11;

void setup() {
	Serial.begin(9600);
	pinMode(floorLampPin, OUTPUT);
        pinMode(deskLampPin, OUTPUT);
        pinMode(bedLampPin, OUTPUT);
}

void getCommand() {
        command = "";
  
	while (Serial.available()) {
                character = Serial.read();
                command.concat(character);
                delay(10);
        }
        
        if (command != "")
                Serial.println(command);
}

void loop() {
	getCommand();

	if (command == "floorLampOn")
		digitalWrite(floorLampPin, HIGH);
        else if (command == "floorLampOff")
                digitalWrite(floorLampPin, LOW);
        else if (command == "deskLampOn")
                digitalWrite(deskLampPin, HIGH);
        else if (command == "deskLampOff")
                digitalWrite(deskLampPin, LOW);
        else if (command == "bedLampOn")
                digitalWrite(bedLampPin, HIGH);
        else if (command == "bedLampOff")
                digitalWrite(bedLampPin, LOW);
}