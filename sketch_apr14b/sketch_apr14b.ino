#include <SoftwareSerial.h>
SoftwareSerial RFID(2, 3); // RX and TX
int data1 = 0;
int ok = -1;
// LEDs
int unlockedLED = 12;
int lockedLED = 11;
int insideLED = 13;
// Motor
int enable = 8;
int var1 = 9;
int var2 = 10;
// If the door is unlocked or not
boolean unlocked = true;

// use first sketch in http://wp.me/p3LK05-3Gk to get your tag numbers
int tag1[14] = {2, 48, 50, 48, 48, 51, 49, 70, 55, 67, 55, 48, 51, 3};
int tag2[14] = {2, 48, 50, 48, 48, 51, 49, 70, 52, 54, 53, 65, 50, 3};
int tag3[14] = {2, 49, 48, 48, 48, 53, 69, 52, 54, 57, 57, 57, 49, 3};

int newtag[14] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // used for read comparisons

void setup() {
  RFID.begin(9600); // start serial to RFID reader
  Serial.begin(9600); // start serial to PC
  // for status LEDs
  pinMode(unlockedLED, OUTPUT);
  pinMode(lockedLED, OUTPUT);
  pinMode(insideLED, OUTPUT);
  // for motor controller
  pinMode(enable, OUTPUT);
  pinMode(var1, OUTPUT);
  pinMode(var2, OUTPUT);
}

boolean comparetag(int aa[14], int bb[14]) {
  boolean ff = false;
  int fg = 0;
  for (int cc = 0 ; cc < 14 ; cc++) {
    if (aa[cc] == bb[cc]) {
      fg++;
    }
  }
  if (fg == 14) {
    ff = true;
  }
  return ff;
}

// compares each tag against the tag just read
void checkmytags() {
  ok = 0; // this variable helps decision-making,
  // if it is 1 we have a match, zero is a read but no match,
  // -1 is no read attempt made
  if (comparetag(newtag, tag1) == true) {
    ok++;
  }
  if (comparetag(newtag, tag2) == true) {
    ok++;
  }
  if (comparetag(newtag, tag3) == true) {
    ok++;
  }
}

void readTags() {
  ok = -1;
  if (RFID.available() > 0) {
    // read tag numbers
    delay(100); // needed to allow time for the data to come in from the serial buffer.
    for (int z = 0 ; z < 14 ; z++) { // read the rest of the tag
      data1 = RFID.read();
      newtag[z] = data1;
    }
    RFID.flush(); // stops multiple reads
    // do the tags match up?
    checkmytags();
  }
  // now do something based on tag type
  // if we had a match
  if (ok > 0) {
    
    if (unlocked) {
      digitalWrite(lockedLED, HIGH);
      digitalWrite(unlockedLED, LOW);
      digitalWrite(insideLED, HIGH);
      digitalWrite(enable, HIGH);
      digitalWrite(var1, HIGH);
      digitalWrite(var2, LOW);
      delay(600);
    }
    else {
      digitalWrite(lockedLED, LOW);
      digitalWrite(unlockedLED, HIGH);
      digitalWrite(insideLED, LOW);
      digitalWrite(enable, HIGH);
      digitalWrite(var1, LOW);
      digitalWrite(var2, HIGH);
      delay(500);
    }
    digitalWrite(enable, LOW);
    digitalWrite(var1, LOW);
    digitalWrite(var2, LOW);
    ok = -1;
    unlocked = !unlocked;
  }
  // if we didn't have a match
  else if (ok == 0) {
    flashLED(unlockedLED, 5);
    ok = -1;
  }
}

void flashLED(int ledPort, int num) {
  for (int i = 0; i < num; i++) {
    digitalWrite(ledPort, HIGH);
    delay(50);
    digitalWrite(ledPort, LOW);
    delay(50);
  }
}
  


void loop() {
  readTags();
  delay(250);
}
