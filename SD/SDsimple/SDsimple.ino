#include <SPI.h>
#include <SD.h>

/* Wiring instructions for SD card:
 * MOSI - pin 11
 * MISO - pin 12
 * CLK  - pin 13
 * CS   - pin 4
 * ANALOG SENSOR - pin A3
 */
 CS pin of SD card board
const int chipSelect = 4;

void setup() {
  // open serial communication
  Serial.begin(9600);
  // start talking to SD object (defined in library SD)
  SD.begin(chipSelect);
}

void loop() {
  // read sensor on analog pin A3
  int sensor = analogRead(A3);
  // open file in write mode and write analog value (0-1023)
  File dataFile = SD.open("simplelog.txt", FILE_WRITE);
  dataFile.println( String(sensor) );
  dataFile.close();
  // print to Serial Monitor
  Serial.println(sensor);
  // wait 1s
  delay(1000);
}