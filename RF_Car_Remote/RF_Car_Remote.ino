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

  vw_setup(2000);             // Bits per sec
  vw_set_tx_pin(12);           // We will be receiving on pin 4 i.e the RX pin from the module connects to this pin.

  vw_set_rx_pin(13);           // We will be receiving on pin 4 i.e the RX pin from the module connects to this pin.
  vw_rx_start();                      // Start the receiver

  Serial.begin(9600);
}

void loop() {
  if (digitalRead(forward_pin) == HIGH) {
    const char *msg = "Community of Robots";       // this is your message to send

    vw_send((uint8_t *)msg, strlen(msg));
    vw_wait_tx();                                          // Wait for message to finish
  }
  if (digitalRead(left_pin) == HIGH) {
    //Serial.println("left");
  }
  if (digitalRead(right_pin) == HIGH) {
    //Serial.println("right");
  }
  if (digitalRead(back_pin) == HIGH) {
    //Serial.println("back");
  }

  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;

  if (vw_get_message(buf, &buflen)) // check to see if anything has been received
  {
    int i; // Message with a good checksum received.

    for (i = 0; i < buflen; i++)
    {
      Serial.print(buf[i]);                     // the received data is stored in buffer
    }
    Serial.println("");
  }
}

