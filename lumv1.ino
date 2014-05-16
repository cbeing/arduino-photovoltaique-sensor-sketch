
int lumPin = A0; // lumPin refer 4 analog 0 Pin
int lumReading;  // lumReading will get the analog value of the analog 0 Pin
void setup() {
  
  Serial.begin(9600);       // start serial communication at 9600bps
}
void loop(){
  lumReading = analogRead(lumPin);
  if(lumReading < 70)
  {
    Serial.write('S');
  }else{
    Serial.write('E');
  }
  
  delay(2000);
}
