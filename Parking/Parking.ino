
// list of digital pins
const uint8_t pinECHO  = 8;
const uint8_t pinTRG   = 9;
const uint8_t pinRED   = 10;
const uint8_t pinYELLOW= 11;
const uint8_t pinGREEN = 12;

double getDistanceCm()
{
  // pulse TRG for 10 us
  digitalWrite(pinTRG, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTRG, LOW);
  // read echo time
  unsigned long echoTime = pulseIn(pinECHO, HIGH);
  return 100. * echoTime * 340.*1e-6 / 2.; 
}

void operateTrafficLight(double dist,double distDangerCm, double distWarnCm)
{
  if( dist < distDangerCm )
    digitalWrite(pinRED, HIGH);
  else
    digitalWrite(pinRED, LOW);

  if( dist > distDangerCm && dist < distWarnCm )
    digitalWrite(pinYELLOW, HIGH);
  else
    digitalWrite(pinYELLOW, LOW);
  
  if( dist > distWarnCm )
    digitalWrite(pinGREEN, HIGH);
  else
    digitalWrite(pinGREEN, LOW);
}

void setup() {
  Serial.begin(9800);
  // set distance sensor pins
  pinMode(pinECHO, INPUT);
  pinMode(pinTRG, OUTPUT);
  digitalWrite(pinTRG,LOW);
  // set LED pins as output
  pinMode(pinRED, OUTPUT);
  pinMode(pinYELLOW, OUTPUT);
  pinMode(pinGREEN, OUTPUT);

  // turn LEDs all on, wait 1s, then off
  digitalWrite(pinRED, HIGH);
  digitalWrite(pinYELLOW, HIGH);
  digitalWrite(pinGREEN, HIGH);
  delay(1000);
  digitalWrite(pinRED, LOW);
  digitalWrite(pinYELLOW, LOW);
  digitalWrite(pinGREEN, LOW);
}

void loop() {
  double distCm = getDistanceCm();
  Serial.println( distCm );
  operateTrafficLight( distCm, 15.0, 50.0 );
  delay(50);

}
