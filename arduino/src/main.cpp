#include <Arduino.h>
#include <AFMotor.h>

// Number of steps per output rotation
// Change this as per your motor's specification
const int stepsPerRevolution = 48;

// connect motor to port #1 (M1 and M2)
AF_Stepper motor1(stepsPerRevolution, 1);

// connect motor to port #2 (M3 and M4)
AF_Stepper motor2(stepsPerRevolution, 2);

// Variable to read incoming serial data
int incomingByte;

void setup() {
  Serial.begin(9600);
  Serial.println("Stepper test!");
  motor1.setSpeed(10);
  motor2.setSpeed(10);  // 10 rpm   
}

void loop() {
  // see if there's incoming serial data:
  if (Serial.available() > 0) {

    // read the oldest byte in the serial buffer:
    incomingByte = Serial.read();

    // if it's a capital H (ASCII 72), turn on the LED:
    if (incomingByte == 1) {
      motor1.step(100, FORWARD, SINGLE);
    }

    // if it's a capital H (ASCII 72), turn on the LED:
    if (incomingByte == 'H') {
      motor1.step(100, FORWARD, SINGLE);
    }

    // if it's an L (ASCII 76) turn off the LED:
    if (incomingByte == 'J') {
      motor2.step(100, FORWARD, SINGLE);
    }

    // if it's an L (ASCII 76) turn off the LED:
    if (incomingByte == 2) {
      motor2.step(100, FORWARD, SINGLE);
    }

  }
  
  // // Motor 1 Control
  // Serial.println("Single coil steps");
  // motor1.step(100, FORWARD, SINGLE); 
  // motor1.step(100, BACKWARD, SINGLE); 

  // Serial.println("Double coil steps");
  // motor1.step(100, FORWARD, DOUBLE); 
  // motor1.step(100, BACKWARD, DOUBLE);

  // Serial.println("Interleave coil steps");
  // motor1.step(100, FORWARD, INTERLEAVE); 
  // motor1.step(100, BACKWARD, INTERLEAVE); 

  // Serial.println("Micrsostep steps");
  // motor1.step(100, FORWARD, MICROSTEP); 
  // motor1.step(100, BACKWARD, MICROSTEP); 

  // // Motor 2 Control
  // Serial.println("Single coil steps");
  // motor2.step(100, FORWARD, SINGLE); 
  // motor2.step(100, BACKWARD, SINGLE); 

  // Serial.println("Double coil steps");
  // motor2.step(100, FORWARD, DOUBLE); 
  // motor2.step(100, BACKWARD, DOUBLE);

  // Serial.println("Interleave coil steps");
  // motor2.step(100, FORWARD, INTERLEAVE); 
  // motor2.step(100, BACKWARD, INTERLEAVE); 

  // Serial.println("Micrsostep steps");
  // motor2.step(100, FORWARD, MICROSTEP); 
  // motor2.step(100, BACKWARD, MICROSTEP); 
}