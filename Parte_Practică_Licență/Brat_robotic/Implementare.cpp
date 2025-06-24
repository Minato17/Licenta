#include "Implementare.h"


/*Functia de Initializare*/
void initSetup()
{
  Serial.begin(115200);
  Serial.setTimeout(300);

  servo1.attach(5);
  servo2.attach(11);
  servo3.attach(7);
  servo4.attach(8);
  servo5.attach(9);
  servo6.attach(10);

  servo1.write(s1Unghi);
  servo2.write(s2Unghi);
  servo3.write(s3Unghi);
  servo4.write(s4Unghi);
  servo5.write(s5Unghi);
  servo6.write(s6Unghi);

  delay(50);
}

// Funcția pentru trimiterea secvenței ca JSON
void sendSequence() {
  for (int i = 0; i < seq1_len; i++) {
    String json = "{";
    json += "\"s1\":" + String(seqBuffer_s1[i]) +
            ",\"s2\":" + String(seqBuffer_s2[i]) +
            ",\"s3\":" + String(seqBuffer_s3[i]) +
            ",\"s4\":" + String(seqBuffer_s4[i]) +
            ",\"s5\":" + String(seqBuffer_s5[i]) +
            ",\"s6\":" + String(seqBuffer_s6[i]) + "}";
    Serial.println(json);
    delay(50);  
  }
  Serial.println("END");
}


/*Functii miscare brat robotic*/
float easeInOutCubic(float t) {
  if (t <= 0.0f) return 0.0f;
  if (t >= 1.0f) return 1.0f;
  return t < 0.5f ? 4.0f * t * t * t : 1.0f - pow(-2.0f * t + 2.0f, 3.0f) / 2.0f;
}
void moveServoMotor(Servo& servo, int fromPos, int toPos) {
 fromPos = constrain(fromPos, 0, 180);
  toPos = constrain(toPos, 0, 180);

  if (fromPos == toPos) return;

  int delta = toPos - fromPos;
  int steps = max(abs(delta), viteza);
  for (int i = 0; i <= steps; i++) {
    float t = (float)i / (float)steps;
    float eased = easeInOutCubic(t);
    int pos = fromPos + round(eased * delta);

    servo.write(pos);
    delay(max(1, 20 - viteza));
  }
}


/*Functia principala de control a bratului robotic*/
void controlComenzi()
{
  if (Serial.available() > 0) {
    input = Serial.readStringUntil("\n");

    if (input.startsWith("s1")) {
      s1Actual = constrain(input.substring(2).toInt(), 0, 180);
      servo1.write(s1Actual);
      s1Unghi = s1Actual;
    }

    if (input.startsWith("s2")) {
      s2Actual = constrain(input.substring(2).toInt(), 0, 180);
      servo2.write(s2Actual);
      s2Unghi = s2Actual;
    }

    if (input.startsWith("s3")) {
      s3Actual = constrain(input.substring(2).toInt(), 0, 180);
      servo3.write(s3Actual);
      s3Unghi = s3Actual;
    }

    if (input.startsWith("s4")) {
      s4Actual = constrain(input.substring(2).toInt(), 0, 180);
      servo4.write(s4Actual);
      s4Unghi = s4Actual;
    }

    if (input.startsWith("s5")) {
      s5Actual = constrain(input.substring(2).toInt(), 0, 180);
      servo5.write(s5Actual);
      s5Unghi = s5Actual;
    }

    if (input.startsWith("s6")) {
      s6Actual = constrain(input.substring(2).toInt(), 0, 180);
      servo6.write(s6Actual);
      s6Unghi = s6Actual;
    }

    if (input.startsWith("RECORD1")) {
      seq1_len = 0;
      recording = true;
    }

    if (input.startsWith("STOPREC")) {
      recording = false;
    }

    if (input.startsWith("SAVE")) {
      if (recording && seq1_len < MAX_STEPS) {
        seqBuffer_s1[seq1_len] = s1Unghi;
        seqBuffer_s2[seq1_len] = s2Unghi;
        seqBuffer_s3[seq1_len] = s3Unghi;
        seqBuffer_s4[seq1_len] = s4Unghi;
        seqBuffer_s5[seq1_len] = s5Unghi;
        seqBuffer_s6[seq1_len] = s6Unghi;
        seq1_len++;
      }
    }

    if (input.startsWith("STEP:")) {
      int s1, s2, s3, s4, s5, s6;
      sscanf(input.c_str(), "STEP:%d,%d,%d,%d,%d,%d", &s1, &s2, &s3, &s4, &s5, &s6);
      if (seq1_len < MAX_STEPS) {
        seqBuffer_s1[seq1_len] = s1;
        seqBuffer_s2[seq1_len] = s2;
        seqBuffer_s3[seq1_len] = s3;
        seqBuffer_s4[seq1_len] = s4;
        seqBuffer_s5[seq1_len] = s5;
        seqBuffer_s6[seq1_len] = s6;
        seq1_len = seq1_len+1;
      }
    }

    if (input.startsWith("RESET")) {
      seq1_len=0;
      for (int i = 0; i < MAX_STEPS; i++) {
        seqBuffer_s1[i] = 0;
        seqBuffer_s2[i] = 0;
        seqBuffer_s3[i] = 0;
        seqBuffer_s4[i] = 0;
        seqBuffer_s5[i] = 0;
        seqBuffer_s6[i] = 0;
      }
    }
    if (input.startsWith("PLAY1")) {
      for (int i = 0; i < seq1_len - 1; i++) {
        //buffer[64] = {0};
        moveServoMotor(servo1, seqBuffer_s1[i], seqBuffer_s1[i + 1]);
        moveServoMotor(servo2, seqBuffer_s2[i], seqBuffer_s2[i + 1]);
        moveServoMotor(servo3, seqBuffer_s3[i], seqBuffer_s3[i + 1]);
        moveServoMotor(servo4, seqBuffer_s4[i], seqBuffer_s4[i + 1]);
        moveServoMotor(servo5, seqBuffer_s5[i], seqBuffer_s5[i + 1]);
        moveServoMotor(servo6, seqBuffer_s6[i], seqBuffer_s6[i + 1]);
        Serial.print("TRIMIS,");
        Serial.print(seqBuffer_s1[i]); Serial.print(",");
        Serial.print(seqBuffer_s2[i]); Serial.print(",");
        Serial.print(seqBuffer_s3[i]); Serial.print(",");
        Serial.print(seqBuffer_s4[i]); Serial.print(",");
        Serial.print(seqBuffer_s5[i]); Serial.print(",");
        Serial.print(seqBuffer_s6[i]);
        Serial.println();   
        delay(viteza);       
        
      }
    }
    if (input.startsWith("SENDSEQ")) {
      sendSequence();
    }
  }
}