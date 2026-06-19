#include "HX711.h"

// HX711 circuit wiring
#define DT 3
#define SCK 2

HX711 scale;

void setup() {
  Serial.begin(9600);
  scale.begin(DT, SCK);

  Serial.println("Initializing the scale...");

  // Wait until the HX711 is ready
  while (!scale.is_ready()) {
    Serial.println("Waiting for HX711...");
    delay(500);
  }

  // Tare the scale to 0
  scale.set_scale(9910.0/500.0);      // set scale to 1 for now 
  //scale.set_scale();
  scale.tare();           // reset the scale to 0

  Serial.println("Scale initialized.");
}

void loop() {
  // Read raw value
  long reading = scale.get_units(10);  // average over 10 readings
  Serial.print("Weight: ");
  Serial.print(reading, 1);
  Serial.println(" g");

  delay(200);
}
