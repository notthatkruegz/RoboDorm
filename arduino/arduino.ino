String command = "";
char character;
int floorLampPin = 13;
int deskLampZPin = 12;
int deskLampZPin = 14;
int bedLampPin = 11;

void setup() {
	Serial.begin(9600);
	pinMode(floorLampPin, OUTPUT);
        pinMode(deskLampZPin, OUTPUT);
        pinMode(deskLampBPin, OUTPUT);
        pinMode(bedLampPin, OUTPUT);
}
//Perhaps consider changing structure of this in the future, so as to not deal with globals
//Instead return the command String (unknown how this works with Aruduino)
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
