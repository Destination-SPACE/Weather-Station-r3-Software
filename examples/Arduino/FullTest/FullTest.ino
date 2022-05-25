/*
  Full Test

  Displays data from BME280 weather sensor and photoresistor on an OLED display
  and stores it on a microSD card on the Destination Weather Station.

  modified 22 May 2022
  by DeepSpace00

  This example code is licensed under the MIT License
  © Destination SPACE Inc. 2022
*/
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_BME280.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define LED 0
#define sdModule 3
#define lightSensor A2

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
Adafruit_BME280 bme;

float timeS;
float tempData;
float presData;
float humData;
int lightData;

File myFile;

void setup() {
  pinMode(LED, OUTPUT);
  
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
  if (!SD.begin(sdModule)){
    display.print("SD failure");
    display.display();
    while(1);
  }
  
  myFile = SD.open("datalog.csv", FILE_WRITE);
  if(myFile){
    myFile.print("--------");
    myFile.print(",");
    myFile.print("--------");
    myFile.print(",");
    myFile.print("--------");
    myFile.print(",");
    myFile.print("--------");
    myFile.print(",");
    myFile.println("--------");
    myFile.close();
  }
}
void loop() {
  digitalWrite(LED, HIGH);

  timeS = millis() / 1000.00;
  tempData = bme.readTemperature();
  presData = bme.readPressure() / 100.00;
  humData = bme.readHumidity();
  lightData = analogRead(lightSensor);
  
  myFile = SD.open("datalog.csv", FILE_WRITE);
  if(myFile){
    myFile.print(timeS, 2);
    myFile.print(",");
    myFile.print(tempData, 2);
    myFile.print(",");
    myFile.print(presData, 2);
    myFile.print(",");
    myFile.print(humData, 2);
    myFile.print(",");
    myFile.println(lightData);
    myFile.close();    
  }
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
  
  display.setCursor(0,50);
  display.print("Light Level: ");
  display.print(lightData);
  display.display();
  
  digitalWrite(LED, LOW);
  
  delay(500);
}
