//  white --> big
//  black --> small




#include <FlexiTimer2.h>

#include <nanaseg_led_control.h>
#include <photo_led_control.h>

#define DELTA_T 5
#define KP 0.0
#define KI 0.0
#define KD 0.0
static int diff[2];
static int integral;

int n_speed = 50;
 int x = 0;

void flash()
{
 
  x = (photoRead(2) - photoRead(4))/20;
  r_motor(n_speed+x);
  l_motor(n_speed-x);
}

void setup() {
  // put your setup code here, to run once:
  photo_led_set();
 // FlexiTimer2::set(500, 1.0/1000, flash); // call every 500 1ms "ticks"
  FlexiTimer2::set(5, flash); // MsTimer2 style is also supported
  FlexiTimer2::start();

}

void loop() {

  photo_scan();
  
 
  
}
