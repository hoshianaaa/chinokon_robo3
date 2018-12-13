#include "arduino.h"
#include "photo_led_control.h"


  int led_pin[8] = {53,51,49,47,45,39,37,35};

void photo_led_set(){
  for(int i=0;i<8;i++){
    pinMode(led_pin[i],OUTPUT);
  }
 
}

void photo_led_on(int x){

  digitalWrite(led_pin[x-1],HIGH); 
}
void photo_led_off(int x){
digitalWrite(led_pin[x-1],LOW);
}


void photo_led_alloff(){

  for(int i=0;i<8;i++){
	digitalWrite(led_pin[i],LOW);
  }
}


void photo_led_loop(int x){
  for(int i=0;i<8;i++){
    photo_led_alloff();
    photo_led_on(i+1);
    delay(x);
  }
}
