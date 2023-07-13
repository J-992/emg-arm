#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

void setup() {
  servo1.attach(9);  // Connect servo1 to pin 9
  servo2.attach(10); // Connect servo2 to pin 10
  servo3.attach(11); // Connect servo3 to pin 11
  servo4.attach(12); // Connect servo4 to pin 12
  servo5.attach(13); // Connect servo5 to pin 13
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    input.trim();
    int commaPos[5];
    int servoSignals[5];
    for (int i = 0; i < 5; i++) {
      commaPos[i] = input.indexOf(',');
      if (commaPos[i] == -1) {
        break;
      }
      servoSignals[i] = input.substring(0, commaPos[i]).toInt();
      input = input.substring(commaPos[i] + 1);
    }
    if (input.length() > 0) {
      servoSignals[4] = input.toInt();
    }
    if (commaPos[0] != -1 && commaPos[1] != -1 && commaPos[2] != -1 && commaPos[3] != -1 && commaPos[4] != -1) {
      servo1.write(servoSignals[0]);
      servo2.write(servoSignals[1]);
      servo3.write(servoSignals[2]);
      servo4.write(servoSignals[3]);
      servo5.write(servoSignals[4]);
    }
  }
}
