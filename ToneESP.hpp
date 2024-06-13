#pragma once

#include "Arduino.h"
#include "Tones.hpp"

class ToneESP32 { 
  private:
    uint8_t pin; 
    uint32_t frequency;
    uint8_t resolution;

  public:    
    // Constructor
    ToneESP32(uint8_t pin, uint32_t frequency, uint8_t resolution) {	
      this->pin = pin;
      this->frequency = frequency;  
      this->resolution = resolution;
      ledcAttach(pin, frequency, resolution);
    }

    // Function to play tone
    void tone(int note, uint16_t duration) {     
      static uint16_t previousTime = 0;
      if(millis() - previousTime > duration) {
        ledcWriteTone(pin, note);
        previousTime = millis();
      }
    }

    // Function to stop tone
    void noTone() {
      ledcWriteTone(pin, 0);
      ledcDetach(pin);
    }    
};