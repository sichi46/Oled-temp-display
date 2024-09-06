const int sensorPin =A2; // Temperature sensor connected to A2
 void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(sensorPin);
  float voltage = sensorValue * (5.0/1023.0);
  float temperatureC = (voltage - 0.5)*100.0;

  Serial.print("\nTemperature: ");
  Serial.print(temperatureC);
  Serial.print("°C");

  delay(1000);

}
