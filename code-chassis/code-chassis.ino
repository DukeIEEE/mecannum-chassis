/*
   Meccanum Drive RC Car Controller
   by Harvey Shi
   v1.0
*/

#include <VirtualWire.h>
#include <ServoTimer2.h>

#define recievePin 2
#define fl_pin 5
#define fr_pin 3
#define bl_pin 10
#define br_pin 9
ServoTimer2 front_left, front_right, back_left, back_right;

void setup() {
  Serial.begin(9600);
  vw_set_rx_pin(recievePin);
  vw_setup(2000);
  vw_rx_start();

  front_left.attach(fl_pin);
  front_right.attach(fr_pin);
  back_left.attach(bl_pin);
  back_right.attach(br_pin);

  fl(0); fr(0); bl(0); br(0);
}

void loop() {
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;

  vw_wait_rx();
  vw_get_message(buf, &buflen);

  for (int channel = 0; channel < buflen; channel++){
    float cmd = mapFloat(buf[channel],50, 150, -1.0, 1.0);
    Serial.println(String(channel+1) + ": " + cmd);

    switch (channel) {
      case 0:
        fl(cmd);
        break;
      case 1:
        fr(cmd);
        break;
      case 2:
        bl(cmd);
        break;
      case 3:
        br(cmd);
        break;
    }
  }
  Serial.println();
}

void fl(int dir){
  if(dir == 0){
    front_left.write(1500);
  } else{
    int cmd  = (int) mapFloat(dir, -1, 1, 1300, 1700);
    front_left.write(cmd);
  }
}

void fr(int dir){
  if(dir == 0){
    front_right.write(1500);
  } else{
    int cmd  = (int) mapFloat(dir, -1, 1, 1700, 1300);
    front_right.write(cmd);
  }
}

void bl(int dir){
  if(dir == 0){
    back_left.write(1500);
  } else{
    int cmd  = (int) mapFloat(dir, -1, 1, 1300, 1700);
    back_left.write(cmd);
  }
}

void br(int dir){
  if(dir == 0){
    back_right.write(1500);
  } else{
    int cmd  = (int) mapFloat(dir, -1, 1, 1700, 1300);
    back_right.write(cmd);
  }
}

float mapFloat(float x, float in_min, float in_max, float out_min, float out_max){
  return (float)(x - in_min) * (out_max - out_min) / (float)(in_max - in_min) + out_min;
}


/*
void setup() {
  front_left.attach(5);
  front_right.attach(3);
  back_left.attach(10);
  back_right.attach(9);
}

void loop() {
  left();
  delay(1000);
  right();
  delay(1000);
  forward();
  delay(1000);
}

void forward(){
  fl(1); fr(1);
  bl(1); br(1);
}

void backward(){
  fl(-1); fr(-1);
  bl(-1); br(-1);
}

void left(){
  fl(-1); fr(1);
  bl(1); br(-1);
}

void right(){
  fl(1); fr(-1);
  bl(-1); br(1);
}

void rotate(int dir){
if(dir == 1){ // clockwise
  fl(1);
  fr(-1);
  bl(1);
  br(-1);
}else{ // counterclockwise
  fl(-1);
  fr(1);
  bl(-1);
  br(1);
}
}
*/
 



