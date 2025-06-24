#ifndef BRAT_ROBOTIC_H
#define BRAT_ROBOTIC_H
#include <Servo.h>
#include <ArduinoJson.h>

/*Declarare Functii*/
float easeInOutCubic(float t);
void moveServoMotor(Servo& servo, int fromPos, int toPos);
void sendSequence();
void initSetup();
void controlComenzi();

/*Secțiunea de Define-uri*/
#define MAX_STEPS       50

/*Variabile globale*/
extern Servo servo1, servo2, servo3, servo4, servo5, servo6;

extern int s1Unghi, s2Unghi, s3Unghi, s4Unghi, s5Unghi, s6Unghi;
extern int s1Actual, s2Actual, s3Actual, s4Actual, s5Actual, s6Actual;

extern int seqBuffer_s1[MAX_STEPS], seqBuffer_s2[MAX_STEPS], seqBuffer_s3[MAX_STEPS];
extern int seqBuffer_s4[MAX_STEPS], seqBuffer_s5[MAX_STEPS], seqBuffer_s6[MAX_STEPS];

extern int seq1_len;
extern int viteza;
extern bool recording;
extern String input;


#endif