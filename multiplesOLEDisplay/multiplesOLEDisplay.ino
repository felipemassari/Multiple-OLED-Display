/**************************************************************************
 This is an example for ue two OLEDs based on SSD1306 drivers
The address was changed by resoldering the SMD resistor from position 0x7B to 0x7A
 **************************************************************************/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "icons.h"

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)

#define SCREEN_1_ADDRESS 0x3D ///< See datasheet for Address; 0x3C for 128x64, 0x3C for 0x7B
#define SCREEN_2_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3D for 0x7A
Adafruit_SSD1306 display1(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
Adafruit_SSD1306 display2(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);




void setup() {
  Serial.begin(9600);
  display1.begin(SSD1306_SWITCHCAPVCC, SCREEN_1_ADDRESS);
  display2.begin(SSD1306_SWITCHCAPVCC, SCREEN_2_ADDRESS);


  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display1.display();
  display2.display();
  delay(2000); // Pause for 2 seconds

  // Clear the buffer
  display1.clearDisplay();
  display2.clearDisplay();
  
  // Draw a single pixel in white
  display1.drawPixel(10, 10, SSD1306_WHITE);
  display2.drawPixel(10, 10, SSD1306_WHITE);
  display1.display();
  delay(200);
  display2.display();
  delay(2000);

  telaInicial();   
 
}

void loop() {
}

void telaInicial(void) {
  display1.clearDisplay();

  display1.drawBitmap(1,1,brasa, 66, 14, 1);
  display1.drawBitmap(105,1,graus,18, 12, 1);
  
  display1.drawBitmap(8,22,fan,24, 24, 1);
  display1.drawBitmap(46,22,fan,24, 24, 1);
  display1.drawBitmap(93,22,exaustor,24, 24, 1);
  
  display1.drawBitmap(11,26,frame_fan_1,18, 16, 1);
  display1.drawBitmap(49,25,frame_fan_1,17, 18, 1);
  display1.drawBitmap(96,25 ,frame_exaustor_1,18, 18, 1);

  //display1.drawBitmap(2,50 ,barra,71, 12, 1);
  display1.drawBitmap(18,50,off,42, 14, 1);
  display1.drawBitmap(85,50,off,42, 14, 1);

  display2.drawBitmap(8,22,fan,24, 24, 1);
  display2.drawBitmap(46,22,fan,24, 24, 1);
  
  display1.display();
  delay(200);
  display2.display();
}
