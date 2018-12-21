#ifndef photo_led_control.h
#define photo_led_control.h
#include "arduino.h"

void photo_led_set();
void photo_led_on(int);
void photo_led_off(int);
void photo_led_alloff();
void photo_led_loop(int x);
void photo_scan();
void r_motor(int);
void l_motor(int);
int photoRead(int x);
int sphotoRead(int x);
void linetrace(int n_speed);//n_speedを基準の速度にして、ライントレースをする
int photoCount(int x);//返値：フォトリフレクタの値がxを超えた個数　引数：ボーダーライン
int sphotoCount(int x);
int lineCount();//ラインを横切った回数を戻す
int P(int n_speed);
int map2 (int x ,int m, int M, int m2, int M2);
#endif