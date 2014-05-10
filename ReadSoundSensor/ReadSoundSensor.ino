/*
  AnalogReadSerial
 Reads an analog input on pin 0, prints the result to the serial monitor 
 
 This example code is in the public domain.
 */

const int threshold = 500;
int i;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(A0);
  if (sensorValue >= threshold) {
    Serial.println("Noise!");
  } else if (++i == 1000) {
    Serial.println(sensorValue);
    i = 0;
  }
}
