//  white --> small
//  black --> big
//制御目標値:photo[3]が黒。photo[3]<100

#include <FlexiTimer2.h>
#include <nanaseg_led_control.h>
#include <photo_led_control.h>
int y = 0;
#define n_speed 40



void setup() {
  // put your setup code here, to run once:
  photo_led_set();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(photoRead(3)>100){
    y = 0;
  }else if(photoRead(2)>100){
    y = -20;
  }else if(photoRead(1)>100){
    y = -40;
  }else if(photoRead(4)>100){
    y = 20;
  }else if(photoRead(5)>100){
    y = 40;
  }
  r_motor(n_speed+y);
  l_motor(n_speed-y);
  photo_scan();
  Serial.print(n_speed-y);
  Serial.print("  ");
  Serial.print(n_speed+y);
  Serial.print("  ");
  Serial.print(photoRead(5));
  Serial.print("  ");
  Serial.print(photoRead(4));
  Serial.print("  ");
  Serial.print(photoRead(3));
  Serial.print("  ");
  Serial.print(photoRead(2));
  Serial.print("  ");
  Serial.println(photoRead(1));
  
}
