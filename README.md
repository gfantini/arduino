# arduino
Some example code to handle sensors

## SD card

Per leggere / scrivere su una scheda SD nuova, è necessario che sia formattata (cercando su google si impara come si fa)

## Dust Sensor

Questo sensore è in grado di rilevare il particolato (particelle di polvere in aria) PM10 con dimensioni < 10 um
E' importante che sia messo in verticale (SHINYEI PPD42 deve leggersi al dritto...) perché funziona per convezione
Qui un interessante progetto (avanzato) https://morresi.files.wordpress.com/2020/02/scheda-arduino-n_21.pdf

## BMP-280

Un sensore combinato di BOSCH che contiene barometro + termometro
Specifiche tecniche (e data-sheet): https://www.bosch-sensortec.com/products/environmental-sensors/pressure-sensors/bmp280/
Si può leggere tramite interfaccia I2C, il modo più semplice è usare una libreria (da installare!)
La libreria usata nell'esempio è Adafruit_BMP280, ma esiste anche BMx280I2C (ad esempio).