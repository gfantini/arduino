int pin = 8; // digital pin where Dust Sensor is connected
unsigned long duration;
unsigned long starttime;
unsigned long sampletime_ms = 30000;//30s ;
unsigned long lowpulseoccupancy_us = 0;
float ratio = 0;
float concentration = 0;

void setup() 
{
    Serial.begin(9600);
    pinMode(pin,INPUT);
    starttime = millis();//get the current time;
}

void loop() 
{
    // read how much time (microseconds = us) the digital pin has been LOW
    duration = pulseIn(pin, LOW);
    // add such time to the occupancy
    lowpulseoccupancy_us = lowpulseoccupancy_us+duration;

    if ((millis()-starttime) > sampletime_ms)//if sampling time has passed...
    {
        ratio = lowpulseoccupancy_us/(sampletime_ms*10.0);  // Integer percentage 0=>100
        // concentration is pcs/0.01cf == particles in 1/100 of a cubic foot
        concentration = 1.1*pow(ratio,3)-3.8*pow(ratio,2)+520*ratio+0.62; // using spec sheet curve (calibration)

        // print output to screen as 3 numbers, separated by comma
        // time LOW (us), time ratio LOW / TOTAL (0-100%), dust concentration (pcs/0.01cf)
        Serial.print(lowpulseoccupancy_us);
        Serial.print(",");
        Serial.print(ratio);
        Serial.print(",");
        Serial.println(concentration);
        // reset occupancy to 0
        lowpulseoccupancy = 0;
        // reset starttime to current time
        starttime = millis();
    }
    // otherwise go for another loop
}