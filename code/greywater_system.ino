#define PH_PIN A0
#define RELAY1 7
#define RELAY2 8
#define RELAY3 9
float voltage;
float phValue;
void setup() {
Serial.begin(9600);
pinMode(RELAY1, OUTPUT);
pinMode(RELAY2, OUTPUT);
pinMode(RELAY3, OUTPUT);
}
void loop() {
int sensorValue = analogRead(PH_PIN);
voltage = sensorValue * (5.0 / 1023.0);
phValue = 7 + ((2.5 - voltage) / 0.18);
Serial.print("pH Value: ");
Serial.println(phValue);
if(phValue >= 6 && phValue <= 8){
digitalWrite(RELAY1, HIGH); // valve to filtration
digitalWrite(RELAY2, LOW);
digitalWrite(RELAY3, HIGH); // pump ON
}
else{
digitalWrite(RELAY1, LOW);
digitalWrite(RELAY2, HIGH); // waste valve
digitalWrite(RELAY3, LOW);
}
delay(2000);
}
