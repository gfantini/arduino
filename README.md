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

## AnalogSensor

Un esempio di lettura di sensore analogico.
Il sensore di CO2 è un sensore analogico. https://store.arduino.cc/products/gravity-analog-co2-gas-sensor-mg-811-sensor
Il sensore di rumore (microfono) è digitale, il pin di output produce HIGH se il rumore è superiore a una certa soglia, LOW altrimenti. La soglia è settabile ruotando la vite a stella presente sul sensore.
https://www.amazon.it/Youmile-rilevamento-sensore-microfono-sensibilit%C3%A0/dp/B07Q1BYDS7/ref=sr_1_4_sspa