#define relay 5

float sensorInput = (analogRead(A0) / 1024) * 5;
int RPM = 0;
int CutRPM = 3000;
unsigned long previousMillis = 0UL;
unsigned long interval = 1000UL; //miliseconds

void setup() {
  // put your setup code here, to run once:
  pinMode(relay, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  unsigned long currentMillis = millis();

  if(currentMillis - previousMillis > interval)
  {
	  //The Arduino executes this code once every second
 	  //(interval = 1000 (ms) = 1 second).
    if (RPM > CutRPM) {
    digitalWrite(relay, HIGH);
    Serial.println("Ignition Cut: OFF");
    RPM = 0;
    } else {
    digitalWrite(relay, LOW);
    Serial.println("Ignition Cut: ON");
    RPM = 4000;
    }
    Serial.println(sensorInput);
    //Don't forget to update the previousMillis value
 	  previousMillis = currentMillis;
  }
}

