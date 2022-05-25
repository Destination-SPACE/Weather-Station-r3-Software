/*
  OLED Test

  Displays Hello World! on an OLED display on the Destination Weather Station

  modified 22 May 2022
  by DeepSpace00

  This example code is licensed under the MIT License
  © Destination SPACE Inc. 2022
*/
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(57600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.clearDisplay();
  Wire.begin();
}

void loop() {
  display.clearDisplay();
  display.setCursor(0,0);
  display.print("Hello World!");
  display.display();
}
