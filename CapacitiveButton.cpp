#include "CapacitiveButton.h"

// This is a fast capacitive touch library that aims to have low response time for activation

CapacitiveButton::CapacitiveButton(uint8_t sendPin, uint8_t receivePin, uint16_t nthreshold) : sensor(sendPin, receivePin) {
  threshold = nthreshold;
}

bool CapacitiveButton::getState() {
  return state;
}

uint16_t CapacitiveButton::getRaw() {
  return average;
}

bool CapacitiveButton::update() {
  uint16_t reading = sensor.capacitiveSensor(1);
  uint16_t last_cycletime = millis() - last_time;
  last_cycletime += last_cycletime ? 0 : 1; // prevent divide by zero
  last_time = millis();
  // average = (reading + average * SMOOTHING_CYCLES) / (SMOOTHING_CYCLES + 1);
  float cycletime_factor = SMOOTHING_TIME / (float) last_cycletime;
  average = (reading + average * cycletime_factor) / (cycletime_factor + 1);
  if (state != (average > threshold)) { // if state of button has changed
    if (!state) { // if new state is active
      average += TIMEOUT_FACTOR * threshold;
      state = true;
    }
    else {
      state = false;
    }
    return true;
  }
  return false;
}

