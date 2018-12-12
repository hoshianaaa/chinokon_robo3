#include "arduino.h"
#include "nanaseg_led_control.h"

void nanaseg_led_set(){
  pinMode(52,OUTPUT);
  pinMode(50,OUTPUT);
  pinMode(48,OUTPUT);
  pinMode(46,OUTPUT);
  pinMode(44,OUTPUT);
  pinMode(42,OUTPUT);
  pinMode(40,OUTPUT);
  pinMode(38,OUTPUT);
  pinMode(34,OUTPUT);
  pinMode(32,OUTPUT);
}

void nanaseg_led_loop(){
  for (int i = 0;i< 9;i++){
     nanaseg_led_on(i);
     delay(1000);
  }
}

void nanaseg_led_on(int x){
  int dig2 = 50;
  int dig1 = 44;
  int A = 48;
  int B = 46;
  int C = 38;
  int D = 34;
  int E = 32;
  int F = 52;
  int G = 40;
  int DP = 42;

  if (x == 0){
      digitalWrite(dig1,LOW);
      digitalWrite(dig2,HIGH);
      digitalWrite(A,LOW);
      digitalWrite(B,LOW);
      digitalWrite(C,LOW);
      digitalWrite(D,LOW);
      digitalWrite(E,LOW);
      digitalWrite(F,LOW);
      digitalWrite(G,HIGH);
      digitalWrite(DP,HIGH);
  }
 
  if (x == 1){
      digitalWrite(dig1,LOW);
      digitalWrite(dig2,HIGH);
      digitalWrite(A,HIGH);
      digitalWrite(B,LOW);
      digitalWrite(C,LOW);
      digitalWrite(D,HIGH);
      digitalWrite(E,HIGH);
      digitalWrite(F,HIGH);
      digitalWrite(G,HIGH);
      digitalWrite(DP,HIGH);
  }

  if (x == 2){
      digitalWrite(dig1,LOW);
      digitalWrite(dig2,HIGH);
      digitalWrite(A,LOW);
      digitalWrite(B,LOW);
      digitalWrite(C,HIGH);
      digitalWrite(D,LOW);
      digitalWrite(E,LOW);
      digitalWrite(F,HIGH);
      digitalWrite(G,LOW);
      digitalWrite(DP,HIGH);
  }

    if (x == 3){
      digitalWrite(dig1,LOW);
      digitalWrite(dig2,HIGH);
      digitalWrite(A,LOW);
      digitalWrite(B,LOW);
      digitalWrite(C,LOW);
      digitalWrite(D,LOW);
      digitalWrite(E,HIGH);
      digitalWrite(F,HIGH);
      digitalWrite(G,LOW);
      digitalWrite(DP,HIGH);
  }

  if (x == 4){
      digitalWrite(dig1,LOW);
      digitalWrite(dig2,HIGH);
      digitalWrite(A,HIGH);
      digitalWrite(B,LOW);
      digitalWrite(C,LOW);
      digitalWrite(D,HIGH);
      digitalWrite(E,HIGH);
      digitalWrite(F,LOW);
      digitalWrite(G,LOW);
      digitalWrite(DP,HIGH);
  }

  if (x == 5){
      digitalWrite(dig1,LOW);
      digitalWrite(dig2,HIGH);
      digitalWrite(A,LOW);
      digitalWrite(B,HIGH);
      digitalWrite(C,LOW);
      digitalWrite(D,LOW);
      digitalWrite(E,HIGH);
      digitalWrite(F,LOW);
      digitalWrite(G,LOW);
      digitalWrite(DP,HIGH);
  }
  if (x == 6){
      digitalWrite(dig1,LOW);
      digitalWrite(dig2,HIGH);
      digitalWrite(A,LOW);
      digitalWrite(B,HIGH);
      digitalWrite(C,LOW);
      digitalWrite(D,LOW);
      digitalWrite(E,LOW);
      digitalWrite(F,LOW);
      digitalWrite(G,LOW);
      digitalWrite(DP,HIGH);
  }

  if (x == 7){
      digitalWrite(dig1,LOW);
      digitalWrite(dig2,HIGH);
      digitalWrite(A,LOW);
      digitalWrite(B,LOW);
      digitalWrite(C,LOW);
      digitalWrite(D,HIGH);
      digitalWrite(E,HIGH);
      digitalWrite(F,HIGH);
      digitalWrite(G,HIGH);
      digitalWrite(DP,HIGH);
  }

  if (x == 8){
      digitalWrite(dig1,LOW);
      digitalWrite(dig2,HIGH);
      digitalWrite(A,LOW);
      digitalWrite(B,LOW);
      digitalWrite(C,LOW);
      digitalWrite(D,LOW);
      digitalWrite(E,LOW);
      digitalWrite(F,LOW);
      digitalWrite(G,LOW);
      digitalWrite(DP,HIGH);
  }

  if (x == 9){
      digitalWrite(dig1,LOW);
      digitalWrite(dig2,HIGH);
      digitalWrite(A,LOW);
      digitalWrite(B,LOW);
      digitalWrite(C,LOW);
      digitalWrite(D,LOW);
      digitalWrite(E,HIGH);
      digitalWrite(F,LOW);
      digitalWrite(G,LOW);
      digitalWrite(DP,HIGH);
  }
}