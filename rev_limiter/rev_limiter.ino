#define MOSFET 5

int RPM = 0;
int CutRPM = 3000;
const float RPM_values[] = {0, 1000, 2000, 3000, 4000, 5000};
const float voltage_values[] = {0.00, 1.08, 1.36, 1.55, 1.85, 2.1};
const int num_data_points = 6;
unsigned long previousMillis = 0UL;
unsigned long interval = 300UL; //miliseconds

float interpolateRPM(float voltage) {
  // Find the appropriate range
  int i;
  for (i = 0; i < num_data_points - 1; i++) {
    if (voltage_values[i] <= voltage && voltage <= voltage_values[i + 1]) {
      break;
    }
  }
  
  // Perform linear interpolation
  float RPM = RPM_values[i] + ((voltage - voltage_values[i]) * (RPM_values[i + 1] - RPM_values[i])) / (voltage_values[i + 1] - voltage_values[i]);
  return RPM;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(MOSFET, OUTPUT);
  digitalWrite(MOSFET, HIGH);
  Serial.begin(115200);
}

void loop() {
  unsigned long currentMillis = millis();
  int raw = analogRead(A1);
  float voltage = raw * (5.0 / 1024.0);
  int RPM = interpolateRPM(voltage);
  Serial.print("RPM: ");
  Serial.println(RPM);
  if(currentMillis - previousMillis > interval)
  {
	  //The Arduino executes this code once every second
 	  //(interval = 1000 (ms) = 1 second).
    if (RPM >= CutRPM) {
      digitalWrite(MOSFET, LOW);
      Serial.println("Ignition Cut: ON");
    } else {
      digitalWrite(MOSFET, HIGH);
      Serial.println("Ignition Cut: OFF");
    }
    //Don't forget to update the previousMillis value
    previousMillis = currentMillis;
  }
}

