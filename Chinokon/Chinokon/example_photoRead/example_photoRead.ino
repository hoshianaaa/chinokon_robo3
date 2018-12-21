#include <nanaseg_led_control.h>
#include <photo_led_control.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(photoRead(4));
}
