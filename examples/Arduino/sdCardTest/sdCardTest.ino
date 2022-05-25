/*
  SDcard Test

  Reads and writes to the SD card on the Destination Weather Station

  modified 22 May 2022
  by DeepSpace00

  This example code is licensed under the MIT License
  © Destination SPACE Inc. 2022
*/
#include <SPI.h>
#include <SD.h>

File myFile;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.print("Initializing SD card...");

  if (!SD.begin(3)){
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");

  myFile = SD.open("test.txt", FILE_WRITE);

  if (myFile){
    Serial.print("Writing to test.txt...");
    myFile.println("testing 1, 2, 3.");
    myFile.close();
    Serial.println("done.");
  } 
  else{
    Serial.println("error opening test.txt");
  }

  myFile = SD.open("test.txt");
  if (myFile){
    Serial.println("test.txt:");
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    myFile.close();
  }
  else{
    Serial.println("error opening test.txt");
  }
}

void loop() {
  
}
