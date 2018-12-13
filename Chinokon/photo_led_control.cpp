#include "arduino.h"
#include "photo_led_control.h"


void photo_led_set(){
  int led_pin[8] = {53,51,49,47,45,39,37,35};
  for(int i=0;i<8;i++){
    pinMode(led_pin[i],OUTPUT);
  }
 
}

void photo_led_on(int x){

  int led_pin[8] = {53,51,49,47,45,39,37,35};
  digitalWrite(led_pin[x-1],HIGH);
  
}

void photo_led_off(int x){

  int led_pin[8] = {53,51,49,47,45,39,37,35};
  digitalWrite(led_pin[x-1],LOW);
  
}

void photo_led_loop(){
  int led_pin[8] = {53,51,49,47,45,39,37,35};
  for (int i=0;i<8;i++){
	digitalWrite(led_pin[i],HIGH);
	digitalWrite(led_pin[i-1],LOW);
	delay(1000); 
}
