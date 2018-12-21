#include <nanaseg_led_control.h>
#include <photo_led_control.h>

void setup() {
  // put your setup code here, to run once:
  photo_led_set();
}

void loop() {
  // put your main code here, to run repeatedly:
  photo_scan();
  
}
