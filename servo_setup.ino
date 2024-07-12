#include <Servo.h>

// Create a class that reads in signals from EMG band

class EMGSensor {
private:
    int pin;

public:
    EMGSensor(int analogPin) : pin(analogPin) {}

    //reads EMG signal and converts into a raw analog signal that is readable by arduino
    int readSignal() {
        return analogRead(pin);
    }

    //normalizes signal data for arduino servo range 0-180 is motor degree range)
    //0-1023 is due to Arduinos 10-bit ADC because the analogread() is kinda retarded.
    //takes in EMG and normalizes it in terms of a motor angle
    int getNormalizedSignal() {
        int rawSignal = readSignal(); 
        return map(rawSignal, 0, 1023, 0, 180);  // Map to servo angle range
    }
};

// Setup for the servo motors
const int NUM_SERVOS = 5;
const int servoPins[NUM_SERVOS] = {3, 5, 6, 9, 10};
Servo servos[NUM_SERVOS];
int positions[NUM_SERVOS] = {90, 90, 90, 90, 90};

// MyoWare sensor setup
MyoWareSensor myoSensor(A0);  // MyoWare sensor connected to analog pin A0

void setup() {
    for (int i = 0; i < NUM_SERVOS; i++) {
        servos[i].attach(servoPins[i]);
        servos[i].write(positions[i]);
    }
}

void loop() {
    //int muscleSignal = myoSensor.getNormalizedSignal();

    // Use the signal to control one or more servos (example for servo1)
    servos[0].write(muscleSignal);

    delay(100);
}
