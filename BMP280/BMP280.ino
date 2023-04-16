#include <Wire.h>
#include <Adafruit_BMP280.h>

// creating sensor object to interact with it
Adafruit_BMP280 bmp;

void setup(){
  Serial.begin(9600);
  // initialize sensor
  bmp.begin();
  /* Default settings from datasheet. */
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */
}

void loop(){
  float T = bmp.readTemperature(); // °C
  float P = bmp.readPressure(); // Pa = 0.01 mbar (standard pressure = 1013 mbar)
  Serial.print( T );
  Serial.print(",");
  Serial.print(P);
  Serial.print("\n");
  
  delay(2000);// wait 2 sec
}