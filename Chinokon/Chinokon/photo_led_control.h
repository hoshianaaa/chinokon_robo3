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
void linetrace(int n_speed);//n_speed����̑��x�ɂ��āA���C���g���[�X������
int photoCount(int x);//�Ԓl�F�t�H�g���t���N�^�̒l��x�𒴂������@�����F�{�[�_�[���C��
int sphotoCount(int x);
int lineCount();//���C�������؂����񐔂�߂�
int P(int n_speed);
int map2 (int x ,int m, int M, int m2, int M2);
#endif