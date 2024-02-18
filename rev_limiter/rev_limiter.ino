#define relay 5

int sensorInput = analogRead(A1);
int RPM = 0;
int CutRPM = 2500;
unsigned long previousMillis = 0UL;
unsigned long interval = 300UL; //miliseconds

void setup() {
  // put your setup code here, to run once:
  pinMode(relay, OUTPUT);
  digitalWrite(relay, HIGH);
  Serial.begin(9600);
}

void loop() {
  unsigned long currentMillis = millis();
  int raw = analogRead(A1);
  float value = raw * (5.0 / 1024.0);
  int RPM = value * 800 / 1.1;
  Serial.println(RPM);
  if(currentMillis - previousMillis > interval)
  {
	  //The Arduino executes this code once every second
 	  //(interval = 1000 (ms) = 1 second).
    if (RPM > CutRPM) {
      digitalWrite(relay, LOW);
      Serial.println("Ignition Cut: ON");
    } else {
      digitalWrite(relay, HIGH);
      Serial.println("Ignition Cut: OFF");
    }
    //Don't forget to update the previousMillis value
    previousMillis = currentMillis;
  }
}

