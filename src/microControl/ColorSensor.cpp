#include "ColorSensor.h"

ColorSensor::ColorSensor(){
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  digitalWrite(S0, HIGH); 
  digitalWrite(S1, LOW);
}
bool ColorSensor::withinRange(int input, int value){
  if(input + input * range > value && input - input*range < value)    
    return true;
  return false;
}

Color ColorSensor::getColor(){ 
  
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  redFrequency = pulseIn(sensorOut, LOW);

 
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  blueFrequency = pulseIn(sensorOut, LOW);

  
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  greenFrequency = pulseIn(sensorOut, LOW);
//
  if(calibrar){
    Serial.print("R= ");
    Serial.print(redFrequency);
    Serial.print(" G= ");
    Serial.print(greenFrequency);
    Serial.print(" B= ");
    Serial.println(blueFrequency);
  }

  if((withinRange(redFrequency, 17)&& withinRange(greenFrequency, 19))&& withinRange(blueFrequency, 6)){
    if(calibrar)
      Serial.print(" WHITE ");
    return White;
  }else if(((withinRange(redFrequency, 170)&& withinRange(greenFrequency, 160))&& withinRange(blueFrequency, 170)) ||((withinRange(redFrequency, 10)&& withinRange(greenFrequency, 10))&& withinRange(blueFrequency, 10)) ){
    if(calibrar)
      Serial.print(" BLACK ");
    return Black;
  }else if((withinRange(redFrequency, 283)&& withinRange(greenFrequency, 156))&& withinRange(blueFrequency, 233)){
    if(calibrar)
      Serial.print(" SILVER ");
    return Silver;
  }
}
