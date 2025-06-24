#include "Implementare.h"

/*Secțiunea de Define-uri*/
#define MAX_STEPS       50

/*Variabile globale*/
Servo servo1, servo2, servo3, servo4, servo5, servo6;

int s1Unghi = 0, s2Unghi = 75, s3Unghi = 85, s4Unghi = 95, s5Unghi = 30, s6Unghi = 140;
int s1Actual, s2Actual, s3Actual, s4Actual, s5Actual, s6Actual;

int seqBuffer_s1[MAX_STEPS], seqBuffer_s2[MAX_STEPS], seqBuffer_s3[MAX_STEPS];
int seqBuffer_s4[MAX_STEPS], seqBuffer_s5[MAX_STEPS], seqBuffer_s6[MAX_STEPS];
int seq1_len = 0;

int viteza = 1;
bool recording = false;
String input;

void setup() {
  initSetup();
}

void loop() {
  controlComenzi();
}
