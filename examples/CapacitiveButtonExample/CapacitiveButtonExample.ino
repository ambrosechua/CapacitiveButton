#include "CapacitiveButton.h"

CapacitiveButton btn1 = CapacitiveButton(2, 5);
CapacitiveButton btn2 = CapacitiveButton(2, 6);

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (btn1.update() || btn2.update()) {
    Serial.print(btn1.getState());
    Serial.print("\t");
    Serial.println(btn2.getState());
  }
  delay(1); // if the looptime is less than one ms, fluctuations will be more sensetive
}