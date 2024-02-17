#define relay 5

int sensorInput = analogRead(A0);
float voltage = sensorInput * (5.0 / 1023.0);
int RPM = 0;
int CutRPM = 3000;
int duration = 5000; //miliseconds

void setup() {
  // put your setup code here, to run once:
  pinMode(relay, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (RPM > CutRPM) {
    digitalWrite(relay, HIGH);
    Serial.println("Ignition Cut: OFF");
    RPM = 0;
  } else {
    digitalWrite(relay, LOW);
    Serial.println("Ignition Cut: ON");
    RPM = 4000;
  }
  delay(duration);
}
