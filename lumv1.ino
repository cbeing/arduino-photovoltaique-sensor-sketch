#include <Stepper.h>
char serialin;
const int stepsPerRevolution = 200;
int lumPin = A0; // lumPin refer 4 analog 0 Pin
int lumReading;  // lumReading will get the analog value of the analog 0 Pin
int relayL=3;
int relayDS=5;
Stepper myStepper(stepsPerRevolution, 8,9,10,11);
void setup() {
  myStepper.setSpeed(60);
  Serial.begin(9600);       // start serial communication at 9600bps
  pinMode(relayL, OUTPUT);
  pinMode(relayDS, OUTPUT);
}


void loop(){
  while (Serial.available() > 0) {
    //Read Serial data and alocate on serialin
    serialin = Serial.read();
    if(serialin == 'A')
    {
      lumReading = analogRead(lumPin);
      if(lumReading < 70)
      {
        Serial.write('S');
      }else{
        Serial.write('E');
      }
    }
    else if(serialin == 'B')
    {
      digitalWrite(relayL,LOW);
    }
    else if(serialin == 'C')
    {
      digitalWrite(relayL,HIGH);
    }
    else if(serialin == 'D')
    {
      digitalWrite(relayDS,LOW);
    }
    else if(serialin == 'E')
    {
      digitalWrite(relayDS,HIGH);
    }
    else if(serialin == 'F')
    {
      myStepper.step(4000);
      
    }
    else if(serialin == 'G')
    {
      myStepper.step(-4000);
     
    }
    delay(500);
  
}
}
