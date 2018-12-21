#include "arduino.h"
#include "photo_led_control.h"



int led_pin[8] = {53,51,49,47,45,39,37,35};
int photo_pin[5] = { 7,6,5,4,3};
int sphoto_pin[2] = {12,11};
int motor_pin[4] = {4,5,12,11};//right_foard,right_back,left_foard,left_back
int photo[8];

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

void photo_scan(){
 for(int i=0;i<5;i++){photo[i] = analogRead(photo_pin[i]);}
 for(int i=0;i<5;i++){if(photo[i] > 100)photo_led_on(i+1);else photo_led_off(i+1);}
}



void r_motor(int x){
 // Serial.println(abs(x));
  if (x > 0){
    analogWrite(motor_pin[0],x);
    analogWrite(motor_pin[1],0);
  //  Serial.println("aa");
  }
  if (x == 0){
    analogWrite(motor_pin[0],0);
    analogWrite(motor_pin[1],0);
  //  Serial.println("bb");
  }
  if (x < 0){
    analogWrite(motor_pin[0],0);
    analogWrite(motor_pin[1],x);
    //Serial.println("hh");
  }
}


void l_motor(int x){
 // Serial.println(abs(x));
  if (x > 0){
    analogWrite(motor_pin[2],x);
    analogWrite(motor_pin[3],0);
  //  Serial.println("aa");
  }
  if (x == 0){
    analogWrite(motor_pin[2],0);
    analogWrite(motor_pin[3],0);
  //  Serial.println("bb");
  }
  if (x < 0){
    analogWrite(motor_pin[2],0);
    analogWrite(motor_pin[3],x);
    //Serial.println("hh");
  }
}

int photoRead(int x){

  return analogRead(photo_pin[x-1]);

}

int sphotoRead(int x){
  return analogRead(sphoto_pin[x-1]);
}

void linetrace(int n_speed){
  static int y;
  if(photoRead(3)>100){
    
    if(photoRead(2)>photoRead(3))y=-n_speed/4;
    if(photoRead(4)>photoRead(3))y=n_speed/4;
    else y = 0;
  }else if(photoRead(2)>100){
    y = -n_speed/2;
  }else if(photoRead(1)>100){
    y = -n_speed;
  }else if(photoRead(4)>100){
    y = n_speed/2;
  }else if(photoRead(5)>100){
    y = n_speed;
  }
  r_motor(n_speed+y);
  l_motor(n_speed-y);
  //photo_scan();
}

int photoCount(int x){
  
return (photoRead(1)>x)+(photoRead(2)>x)+(photoRead(3)>x)+(photoRead(4)>x)+(photoRead(5)>x);
}


int sphotoCount(int x){

return ((sphotoRead(1)>x) +(sphotoRead(2)>x));
}



int lineCount(){
  static int count=0,flag=0;

  photo_led_on(count+1);

  if(flag == 0 && sphotoCount(500)   == 2){
    flag = 1;
    count++; 
   
  }

  if(flag == 1 && sphotoCount(500) != 2){
    flag = 0;
  }
  
return count;
}

int P(int n_speed){
  
  double n[3]={0.25,0.5,1};
  static int a;
  static int M,m=500;
  static int y;

 
  if(photoRead(3) > 50){
    if(photoRead(2) < photoRead(4))a = 1;else a = -1;//負号
    M = max(M,photoRead(3));
    Serial.print(1);Serial.print("  ");
    
    m = min(m,photoRead(3));
  //  Serial.print(m);Serial.print("  ");Serial.print(a);Serial.print("  ");*/

    //y =a * map(photoRead(3),0,1024,0,n_speed*n[0]);
    y = map2(photoRead(3),M,m,0,n_speed*n[0]);

    
  }else if(photoRead(2) > 50){
    //目標値:photo[2] = m
     a = -1;
     M = max(M,photoRead(2));
    Serial.print(2);Serial.print("  ");
    
    m = min(m,photoRead(2));
  //  Serial.print(m);Serial.print("  ");Serial.print(a);Serial.print("  ");*/

    //y =a * map(photoRead(3),0,1024,0,n_speed*n[0]);
    y = map2(photoRead(2),m,M,n_speed*n[0],n_speed*n[1]);

    
  }else if(photoRead(4) > 50){
    //目標値:photo[4] = m
     a = 1;
     M = max(M,photoRead(4));
    Serial.print(4);Serial.print("  ");
    
    m = min(m,photoRead(4));
  //  Serial.print(m);Serial.print("  ");Serial.print(a);Serial.print("  ");*/

    //y =a * map(photoRead(3),0,1024,0,n_speed*n[0]);
    y = map2(photoRead(4),m,M,n_speed*n[0],n_speed*n[1]);

    
  }else if(photoRead(1) > 50){
    //目標値:photo[1] = m
     a = -1;
     M = max(M,photoRead(1));
    Serial.print(1);Serial.print("  ");
    
    m = min(m,photoRead(1));
  //  Serial.print(m);Serial.print("  ");Serial.print(a);Serial.print("  ");*/

    //y =a * map(photoRead(3),0,1024,0,n_speed*n[0]);
    y = map2(photoRead(1),m,M,n_speed*n[1],n_speed*n[2]);

    
  }else if(photoRead(5) > 50){
    //目標値:photo[1] = m
     a = 1;
     M = max(M,photoRead(5));
    Serial.print(5);Serial.print("  ");
    
    m = min(m,photoRead(5));
  //  Serial.print(m);Serial.print("  ");Serial.print(a);Serial.print("  ");*/

    //y =a * map(photoRead(3),0,1024,0,n_speed*n[0]);
    y = map2(photoRead(5),m,M,n_speed*n[1],n_speed*n[2]);

    
  }
  return a*y;
}

int map2 (int x ,int m, int M, int m2, int M2){
  //欲しい値:mからMの範囲の中でのxという値はm2からM2の範囲でどの位置になるのか
  //mはセンサの最小値,Mはセンサの最大値,xはセンサの値
  return (M2-m2)*(x-m)/(M-m)+m2;
}


