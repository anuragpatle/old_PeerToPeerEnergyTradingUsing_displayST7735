#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Solar Panel is connected to GPIO 34 (Analog ADC1_CH6)
const int solarPanelPin = 34;

// variable for storing the potentiometer value
int solarPanelValue = 0;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(921600);
  Serial.println("From Setup: Hello World!!");

  // Oled Display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;
  }
  delay(2000); // Pause for 2 seconds

  // Clear the buffer.
  // display.clearDisplay();
  //  // Display Text
  // display.setTextSize(1);
  // display.setTextColor(WHITE);
  // display.setCursor(0,28);
  // display.println("Hello world!");
  // display.display();
  // delay(2000);
  // display.clearDisplay();

  // // Display Inverted Text
  // display.setTextColor(BLACK, WHITE); // 'inverted' text
  // display.setCursor(0,28);
  // display.println("Hello world!");
  // display.display();
  // delay(2000);
  // display.clearDisplay();

  // // Changing Font Size
  // display.setTextColor(WHITE);
  // display.setCursor(0,24);
  // display.setTextSize(2);
  // display.println("Hello!");
  // display.display();
  // delay(2000);
  // display.clearDisplay();

  // // Display Numbers
  // display.setTextSize(1);
  // display.setCursor(0,28);
  // display.println(123456789);
  // display.display();
  // delay(2000);
  // display.clearDisplay();

  // // Specifying Base For Numbers
  // display.setCursor(0,28);
  // display.print("0x"); display.print(0xFF, HEX);
  // display.print("(HEX) = ");
  // display.print(0xFF, DEC);
  // display.println("(DEC)");
  // display.display();
  // delay(2000);
  // display.clearDisplay();

  // // Display ASCII Characters
  // display.setCursor(0,24);
  // display.setTextSize(2);
  // display.write(3);
  // display.display();
  // delay(2000);
  // display.clearDisplay();

  // // Scroll full screen
  // display.setCursor(0,0);
  // display.setTextSize(1);
  // display.println("Full");
  // display.println("screen");
  // display.println("scrolling!");
  // display.display();
  // display.startscrollright(0x00, 0x07);
  // delay(2000);
  // display.stopscroll();
  // delay(1000);
  // display.startscrollleft(0x00, 0x07);
  // delay(2000);
  // display.stopscroll();
  // delay(1000);
  // display.startscrolldiagright(0x00, 0x07);
  // delay(2000);
  // display.startscrolldiagleft(0x00, 0x07);
  // delay(2000);
  // display.stopscroll();
  // display.clearDisplay();

  // // Scroll part of the screen
  // display.setCursor(0,0);
  // display.setTextSize(1);
  // display.println("Scroll");
  // display.println("some part");
  // display.println("of the screen.");
  // display.display();
  // display.startscrollright(0x00, 0x00);
}

void loop()
{
  // put your main code here, to run repeatedly:
  delay(1000);
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("From Loop: Hello World!");
  // digitalWrite(LED_BUILTIN, LOW);

  solarPanelValue = analogRead(solarPanelPin);
  Serial.println(solarPanelValue);

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,28);
  display.println(solarPanelValue);
  display.display();
  delay(2000);

}
