#include <ServoTimer2.h>
#include <VirtualWire.h>

ServoTimer2 rServo;
ServoTimer2 lServo;

void setup() {
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  rServo.attach(9);
  lServo.attach(8);
  rServo.write(1000);
  lServo.write(2000);
}

void loop() {

}

