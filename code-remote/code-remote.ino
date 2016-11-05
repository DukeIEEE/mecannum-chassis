#include <VirtualWire.h>
#undef int
#undef abs
#undef double
#undef float
#undef round

int forward_pin = 5;
int left_pin = 2;
int right_pin = 3;
int back_pin = 4;

void setup() {
  pinMode(5, INPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);

  pinMode(6, OUTPUT);
  digitalWrite(6, HIGH);
  vw_set_tx_pin(6);
  vw_setup(2000); // Bits per sec

  Serial.begin(9600);
}

void loop() {
  if (digitalRead(forward_pin) == HIGH) {
    const char *msg = "F";
    vw_send((uint8_t *)msg, strlen(msg));
    delay(400);
  }
  if (digitalRead(left_pin) == HIGH) {
    const char *msg = "L";
    vw_send((uint8_t *)msg, strlen(msg));
    delay(400);
  }
  if (digitalRead(right_pin) == HIGH) {
    const char *msg = "R";
    vw_send((uint8_t *)msg, strlen(msg));
    delay(400);
  }
  if (digitalRead(back_pin) == HIGH) {
    const char *msg = "B";
    vw_send((uint8_t *)msg, strlen(msg));
    delay(400);
  }  
}

