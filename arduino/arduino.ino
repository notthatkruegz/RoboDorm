// arduino.ino

String command = "";
char character;
int floorLampPin = 13;

void setup() {
	Serial.begin(9600);
	pinMode(floorLampPin, OUTPUT);
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
   
}
asdf