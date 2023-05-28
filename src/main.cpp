#include <Arduino.h>

// Solar Panel is connected to GPIO 34 (Analog ADC1_CH6)
const int solarPanelPin = 34;

// variable for storing the potentiometer value
int solarPanelValue = 0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(921600);
  Serial.println("From Setup: Hello World!");
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("From Loop: Hello World!");
  // digitalWrite(LED_BUILTIN, LOW);

  solarPanelValue = analogRead(solarPanelPin);
  Serial.println(solarPanelValue);
}


