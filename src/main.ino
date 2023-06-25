/*
 Font draw speed and flicker test, draws all numbers 0-999 in each font
 (0-99 in font 8)
 Average time in milliseconds to draw a character is shown in red
 A total of 2890 characters are drawn in each font (190 in font 8)

 Needs fonts 2, 4, 6, 7 and 8

 Make sure all the display driver and pin connections are correct by
 editing the User_Setup.h file in the TFT_eSPI library folder.

 Note that yield() or delay(0) must be called in long duration for/while
 loops to stop the ESP8266 watchdog triggering.

 #########################################################################
 ###### DON'T FORGET TO UPDATE THE User_Setup.h FILE IN THE LIBRARY ######
 #########################################################################
 */


#include <TFT_eSPI.h> // Graphics and font library for ILI9341 driver chip
#include <SPI.h>
#include "Ucglib.h"

TFT_eSPI tft = TFT_eSPI();  // Invoke library, pins defined in User_Setup.h
Ucglib_ST7735_18x128x160_HWSPI ucg(/*cd=*/ 2, /*cs=*/ 5, /*reset=*/ 4);

unsigned long drawTime = 0;

void setup(void)
{
  delay(1000);
  ucg.begin(UCG_FONT_MODE_TRANSPARENT);
  ucg.clearScreen();
  ucg.setRotate90();


  // ucg.setColor(0, 120, 0, 0);
  // ucg.setColor(2, 0, 120, 0);
  // ucg.setColor(1, 120, 0, 120);
  // ucg.setColor(3, 0, 120, 120);

  // ucg.drawGradientBox(0, 0, ucg.getWidth(), ucg.getHeight());
}

void loop(void)
{

  // Set the background color to white
  // To set a white background, we use ucg.drawBox() to draw a filled rectangle
  // that covers the entire display area. We set the background color to white
  // using ucg.setColor(255, 255, 255) before drawing the rectangle.
  ucg.setPrintPos(0, 0);
  ucg.setColor(255, 255, 255);
  ucg.drawBox(0, 0, ucg.getWidth(), ucg.getHeight());

  // ucg.begin(UCG_FONT_MODE_TRANSPARENT);
  // Set the text color to black
  ucg.setColor(0, 153, 76);

  // Set the font and print the text
  ucg.setFont(ucg_font_ncenB10_tf);
  // ucg.setFont(ucg_font_6x10_tf);
  ucg.setPrintPos(90, 20);
  ucg.print("Capacity");

  delay(10000);  // Delay to observe the display

  // // get a random value between 0 and 255
  // uint8_t rnd = 4455;
  // ucg_int_t y = 0;
  // ucg_int_t h = 14;


  // // You can not overwrite the previous number with a transparent font
  // y += h;
  // ucg.setColor(0, 255, 255, 255);		// use white as main color for the font
  // ucg.setFontMode(UCG_FONT_MODE_TRANSPARENT);
  // ucg.setPrintPos(4,y);
  // ucg.setFont(ucg_font_helvB08_tr);
  // ucg.print("Does not work:");
  // ucg.setFontMode(UCG_FONT_MODE_TRANSPARENT);
  // ucg.setFont(ucg_font_helvB08_tr);
  // ucg.setColor(0, 255, 255, 255);		// use white as main color for the font
  // ucg.setPrintPos(80,y);
  // ucg.print(rnd);

  // // Using the same transparent font in solid mode works better,
  // // but still some pixel are not overwritten
  // y += h;
  // ucg.setFontMode(UCG_FONT_MODE_TRANSPARENT);
  // ucg.setPrintPos(4,y);
  // ucg.setFont(ucg_font_helvB08_tr);
  // ucg.print("Pixel errors:");
  // ucg.setFontMode(UCG_FONT_MODE_SOLID);
  // ucg.setFont(ucg_font_helvB08_tr);
  // ucg.setColor(0, 255, 255, 255);		// use white as main color for the font
  // ucg.setColor(1, 64, 64, 255);			// use blue as background for SOLID mode
  // ucg.setPrintPos(80,y);
  // ucg.print(rnd);

  // // Using the "h" or "m" type of font in solid mode will almost work
  // // however, if the number changes from 100 to 99, the last number
  // // will not be overwritten.
  // y += h;
  // ucg.setFontMode(UCG_FONT_MODE_TRANSPARENT);
  // ucg.setPrintPos(4,y);
  // ucg.setFont(ucg_font_helvB08_tr);
  // ucg.print("Value errors:");
  // ucg.setFontMode(UCG_FONT_MODE_SOLID);
  // ucg.setFont(ucg_font_helvB08_hr);
  // ucg.setColor(0, 255, 255, 255);		// use white as main color for the font
  // ucg.setColor(1, 64, 64, 255);			// use blue as background for SOLID mode
  // ucg.setPrintPos(80,y);
  // ucg.print(rnd);

  // // Using the "h" or "m" type of font in solid mode will work fine, if
  // // there are extra spaced after the string to overwrite the previous value.
  // // As long as a "h" font is used, the number of spaces is not fixed.
  // // This means, even two spaced my not be sufficent. Better use a monospace font.
  // y += h;
  // ucg.setFontMode(UCG_FONT_MODE_TRANSPARENT);
  // ucg.setPrintPos(4,y);
  // ucg.setFont(ucg_font_helvB08_tr);
  // ucg.print("Almost ok:");
  // ucg.setFontMode(UCG_FONT_MODE_SOLID);
  // ucg.setFont(ucg_font_helvB08_hr);
  // ucg.setColor(0, 255, 255, 255);		// use white as main color for the font
  // ucg.setColor(1, 64, 64, 255);			// use blue as background for SOLID mode
  // ucg.setPrintPos(80,y);
  // ucg.print(rnd);
  // ucg.print("  ");  // two extra spaces (not sufficient here)

  // // The transparent font and mode can be used, if the previous content
  // // is fully erased or overwritten
  // y += h;
  // ucg.setFontMode(UCG_FONT_MODE_TRANSPARENT);
  // ucg.setPrintPos(4,y);
  // ucg.setFont(ucg_font_helvB08_tr);
  // ucg.print("Manual erase:");
  // ucg.setColor(0, 255, 40, 80);
  // ucg.setColor(1, 0, 255, 0);
  // ucg.setColor(2, 255, 0, 0);
  // ucg.setColor(3, 65, 255, 40);
  // ucg.drawGradientBox(80-2, y-10, 22, 12);  // red to green bar will erase the previous value
  // ucg.setFontMode(UCG_FONT_MODE_TRANSPARENT);
  // ucg.setFont(ucg_font_helvB08_tr);
  // ucg.setColor(0, 255, 255, 255);		// use white as main color for the font
  // ucg.setPrintPos(80,y);
  // ucg.print(rnd);

  // // The is will use the solid font with the extra spaces to erase the previous value
  // // A monospaced 8x8 pixel font is used (here: ucg_font_amstrad_cpc_8r).
  // y += h;
  // ucg.setFontMode(UCG_FONT_MODE_TRANSPARENT);
  // ucg.setPrintPos(4,y);
  // ucg.setFont(ucg_font_helvB08_tr);
  // ucg.print("8x8 font:");
  // ucg.setFontMode(UCG_FONT_MODE_SOLID);
  // ucg.setFont(ucg_font_amstrad_cpc_8r);
  // ucg.setColor(0, 255, 255, 255);		// use white as main color for the font
  // ucg.setColor(1, 64, 64, 255);			// use blue as background for SOLID mode
  // ucg.setPrintPos(80,y);
  // ucg.print(rnd);
  // ucg.print("  ");  // extra spaces

  // // The is will use the solid font with the extra spaces to erase the previous value
  // // Any monospaced font can be used (here: ucg_font_7x13_mr).
  // y += h;
  // ucg.setFontMode(UCG_FONT_MODE_TRANSPARENT);
  // ucg.setPrintPos(4,y);
  // ucg.setFont(ucg_font_helvB08_tr);
  // ucg.print("_mr font:");
  // ucg.setFontMode(UCG_FONT_MODE_SOLID);
  // ucg.setFont(ucg_font_7x13_mr);
  // ucg.setColor(0, 255, 255, 255);		// use white as main color for the font
  // ucg.setColor(1, 64, 64, 255);			// use blue as background for SOLID mode
  // ucg.setPrintPos(80,y);
  // ucg.print(rnd);
  // ucg.print("  ");  // extra spaces


  delay(100);
}
