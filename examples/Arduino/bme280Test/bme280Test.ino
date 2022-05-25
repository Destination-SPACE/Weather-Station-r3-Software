/*
  BME280 Test

  Display tempreture, pressure, and humidity on an 
  OLED display on the Destination Weather Station.

  modified 22 May 2022
  by DeepSpace00

  This example code is licensed under the MIT License
  © Destination SPACE Inc. 2022
*/
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_BME280.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
Adafruit_BME280 bme;

float tempData;
float presData;
float humData;

void setup() {
  Serial.begin(57600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.clearDisplay();

  Wire.begin();

  if(!bme.begin()){
    display.print("BME failure");
    display.display();
    while(1);
  }
}

void loop() {
  tempData = bme.readTemperature();
  presData = bme.readPressure() / 100.00;
  humData = bme.readHumidity();

  display.clearDisplay();
  display.setCursor(0,0);
  display.print("DS Weather Station");
  
  display.setCursor(0, 20);
  display.print("Temperature: ");
  display.print(tempData, 2);
  display.print(" C");
  
  display.setCursor(0, 30);
  display.print("Pressure: ");
  display.print(presData, 2);
  display.print(" hPa");
  
  display.setCursor(0, 40);
  display.print("Humidity: ");
  display.print(humData, 2);
  display.print(" %");
  display.display();
  
  delay(500);
}
