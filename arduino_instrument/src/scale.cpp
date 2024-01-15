#include <Arduino.h>
#include <HX711.h>

#include "../include/scale.h"
#include "../include/motor.h"

HX711 scale;
long scaleMock = 400;

long targetWeight = 0; 
long maxWeight = 650;

uint8_t scaleTolerance = 5;
float scaleFactor = 742.752312;

void setScalePins() {
  scale.begin(dataPin, clockPin);
}


void tareScale() {
  scale.set_scale(scaleFactor); // Establecemos la escala  ATENCIÓN 
  scale.tare(20);  //El peso actual es considerado Tara.
}

bool isWeightReached(long scaleValue) {
  if (scaleValue >= targetWeight - scaleTolerance && scaleValue <= targetWeight + scaleTolerance) {
    return true;
  } 
  return false;
}

void debugScale() {
    Serial.print("ScaleValue ");
    Serial.println(scale.get_units()); 
    Serial.print("PinIN1 vaciado: ");
    Serial.println(digitalRead(PinIN1));
    Serial.print("PinIN2 vaciado: ");
    Serial.println(digitalRead(PinIN2));
    Serial.print("PinIN3 llenado: ");
    Serial.println(digitalRead(PinIN3));
    Serial.print("PinIN4 llenado: ");
    Serial.println(digitalRead(PinIN4));
}

