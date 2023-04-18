/*  
 *  Esempio di lettura
 *  sensore analogico (sensore CO2)
 *  
 */

int pinSensore = 0;
int lettura = -1;

void setup() {
  // apro comunicazione seriale tra Arduino e PC
  Serial.begin(9600);
}

// esegui ripetutamente
void loop() {
  // leggo la tensione sul pinSensore come un numero da 0 a 1023
  lettura = analogRead(pinSensore);
  // la scrivo a schermo sul PC
  Serial.println(lettura);
  // aspetto 500 ms
  delay(500);
}
