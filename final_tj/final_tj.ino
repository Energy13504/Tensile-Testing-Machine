#include "HX711.h"

// HX711 circuit wiring
#define DT 3
#define SCK 2

HX711 scale;

#define dirPin_1 12 //motor 1
#define stepPin_1 13

#define dirPin_2 6 //motor 2
#define stepPin_2 7

#define stepsPerRevolution 800  // adjust this for your microstep setting
// 3200 is 180 degree = 0.5 cm
// 1600 = 0.25 cm 
// 800 = 0.125 cm

float elongation = 0.0000;
int No = 0;

void setup() {
  pinMode(stepPin_1, OUTPUT);
  pinMode(dirPin_1, OUTPUT);

  pinMode(stepPin_2, OUTPUT);
  pinMode(dirPin_2, OUTPUT);

  digitalWrite(dirPin_1, HIGH); // Set motor direction
  digitalWrite(dirPin_2, HIGH);
//************************************************//

  Serial.begin(9600);
  scale.begin(DT, SCK);

  Serial.println("Initializing the scale...");

  // Wait until the HX711 is ready
  while (!scale.is_ready()) {
    Serial.println("Waiting for HX711...");
    delay(500);
  }

  // Tare the scale to 0
  scale.set_scale(9900.0/500.0);      // set scale to 1 for now 
  //scale.set_scale();
  scale.tare();           // reset the scale to 0

  Serial.println("Scale initialized.");
}

void loop() {
  // 0 for up
  // 1 for down


  digitalWrite(dirPin_1, 0); // up 
  digitalWrite(dirPin_2, 0); 
  for (int i = 0; i < stepsPerRevolution; i++) {
    digitalWrite(stepPin_1, HIGH);
    digitalWrite(stepPin_2, HIGH);
    delayMicroseconds(500);  // Controls speed
    
    digitalWrite(stepPin_1, LOW);
    digitalWrite(stepPin_2, LOW);
    delayMicroseconds(500);
  }

  elongation += 1.250;
  No += 1;

  long reading = scale.get_units(10);  // average over 10 readings
   
  Serial.print(reading, 1);
  //Serial.print(" g");
  Serial.print(",");
  Serial.print(elongation, 3);
  //Serial.print(" mm");
  Serial.println();

  delay(1000);

}
