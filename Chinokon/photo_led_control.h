#ifndef photo_led_control.h
#define photo_led_control.h
#include "arduino.h"

void photo_led_set();
void photo_led_on(int);
void photo_led_off(int);
void photo_led_alloff();
void photo_led_loop(int x);

#endif