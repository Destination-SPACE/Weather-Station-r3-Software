# Examples Index
- [Hello World!](https://github.com/Destination-SPACE/Weather-Station-r3-Software/blob/main/examples/Arduino/dsWeatherStationR3FullTest_1/dsWeatherStationR3FullTest_1.ino): The first example. Used to familiarize with IDE and uploading code
- [Blink](https://github.com/Destination-SPACE/Weather-Station-r3-Software/blob/main/examples/uf2/blink.uf2): Used for learning digital write and controlling the LED on the weather station
- [OLED Test](https://github.com/Destination-SPACE/Weather-Station-r3-Software/blob/main/examples/uf2/oledTest.uf2): Testing the OLED display on the weather station by making it say Hello World!
- [Light Sensor](https://github.com/Destination-SPACE/Weather-Station-r3-Software/blob/main/examples/uf2/lightSensorTest.uf2): Using a photoresistor to measure ambient light. An example application is measuring how high the sun is in the sky.
- [SD Card Test](https://github.com/Destination-SPACE/Weather-Station-r3-Software/blob/main/examples/uf2/sdCardTest.uf2): A modified version of the Arduino SD Read/Write script. Used to write data to the onboard microSD card.
- [BME280 Test](https://github.com/Destination-SPACE/Weather-Station-r3-Software/blob/main/examples/uf2/bme280Test.uf2): Testing the BME280 tempreture, pressure, and humidity sensor
- [Full Test](https://github.com/Destination-SPACE/Weather-Station-r3-Software/blob/main/examples/uf2/FullTest.uf2): Combines all the sensors onboard the weather station and prints the data to the OLED display as well as saving it to the microSD card.
# Uploading Code with UF2 Bootloader
The UF2 Bootloader supported by SAMD microcontrollers among others is an easy way to upload pre-compiled code to an Arduino. All that is required to use this method is a device that supports a file management program, which comes standard on many devices including Chromebooks and Apple iPads/iPhones. Follow the steps below to upload code to your Weather Station.

- Double tap the **Reset** button
- Navigate to the file management program
- A device called **Arduino** should appear in the devices/drivers section of the program
- Drag / copy the .uf2 file into the Arduino device. The Weather Station should automatically disconnect from the device.
