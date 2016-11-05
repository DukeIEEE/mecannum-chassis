/*
 * Meccanum Drive RC Car Controller
 * by Harvey Shi
 * v1.0
 */
 

#include <VirtualWire.h>
/*
#include <Servo.h>
#include <ServoTimer2.h>
ServoTimer2 rServo;
ServoTimer2 lServo;

Servo front_left, front_right, back_left, back_right;

*/

#define ledPin 13        //Onboard LED = digital pin 13

 unsigned int data = 0;   // variable used to store received data

 void setup(){
   pinMode(ledPin, OUTPUT);
   Serial.begin(9600);
   vw_set_rx_pin(2);
   vw_setup(2000);
   vw_rx_start();
   
 }

 void loop(){
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;

    vw_wait_rx();
    vw_get_message(buf, &buflen);
    
    for (int i = 0; i < buflen; i++)
    {
       Serial.print(buf[i], HEX);
       Serial.print(' ');
    }
    Serial.println();
        digitalWrite(ledPin, LOW);
    
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

void fl(int dir){
  if(dir == 1){
    front_left.writeMicroseconds(1700); 
  }else if (dir == -1){
    front_left.writeMicroseconds(1300); 
  }else{
    front_left.writeMicroseconds(1500); 
  }
}

void fr(int dir){
  if(dir == 1){
    front_right.writeMicroseconds(1300); 
  }else if (dir == -1){
    front_right.writeMicroseconds(1700); 
  }else{
    front_right.writeMicroseconds(1500); 
  }
}

void bl(int dir){
  if(dir == 1){
    back_left.writeMicroseconds(1700); 
  }else if (dir == -1){
    back_left.writeMicroseconds(1300); 
  }else{
    back_left.writeMicroseconds(1500); 
  }
}

void br(int dir){
  if(dir == 1){
    back_right.writeMicroseconds(1300); 
  }else if (dir == -1){
    back_right.writeMicroseconds(1700); 
  }else{
    back_right.writeMicroseconds(1500); 
  }
}
*/

