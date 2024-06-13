#pragma once

#include <Arduino.h>

class VibrationMotor {
  private:
    int8_t motorPin;

  public:
    VibrationMotor(int8_t motorPin);
    void begin();
    void on(uint8_t intensity = 255);       // Turn the motor on with a specified intensity.
    void off();
    void pulse();
};

VibrationMotor::VibrationMotor(int8_t motorPin) {
  this->motorPin = motorPin;
}

void VibrationMotor::begin() {
  pinMode(this->motorPin, OUTPUT);
  off();
}

// Turn the motor on with a specified intensity.
void VibrationMotor::on(uint8_t intensity) {
  analogWrite(this->motorPin, intensity);
}

// Turn the motor off.
void VibrationMotor::off() {
  analogWrite(this->motorPin, 0);
}

void VibrationMotor::pulse() {
  on(50);
  delay(500);
  off();
}
