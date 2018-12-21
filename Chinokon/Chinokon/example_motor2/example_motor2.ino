#include <nanaseg_led_control.h>
#include <photo_led_control.h>


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  r_motor(55);
  l_motor(55);
  delay(1000);
  r_motor(55);
  l_motor(-55);
  delay(1000);
  
  
  
}
