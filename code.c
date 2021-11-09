#include "Ultrasonic.h"
 
const int echoPino = 13;
const int trigPino = 12;
const int pinoBuzzer = 11;
int pin = 0;
int temperatura = 0;
int samples[8];
int i;

Ultrasonic ultrasonic(trigPino,echoPino);
 
int distancia;
 
void setup(){
pinMode(echoPino, INPUT);
pinMode(trigPino, OUTPUT);
pinMode(pinoBuzzer, OUTPUT); 
pinMode(10, OUTPUT);
pinMode(9, OUTPUT);
pinMode(8, OUTPUT);

Serial.begin(9600);
}
void loop(){

for(i = 0;i<=7;i++){
  samples[i] = ( 5.0 * analogRead(pin) * 100.0) / 1024.0;
  temperatura = temperatura + samples[i];
  delay(100);
}

temperatura = temperatura/8.0; 

if(temperatura > 35) 
  {
    digitalWrite(10, HIGH);
  }else{
    digitalWrite(10, LOW);
  }

Serial.print(temperatura, DEC);
Serial.println(" Cels ");
temperatura = 0;

funcao_trigger();

if(distancia <= 10){
tone(pinoBuzzer,1500);
}else{
noTone(pinoBuzzer);
}
}

void funcao_trigger(){
digitalWrite(trigPino, LOW); 
delayMicroseconds(11); 
digitalWrite(trigPino, HIGH);
delayMicroseconds(10); 
digitalWrite(trigPino, LOW);

distancia = (ultrasonic.Ranging(CM)); 
delay(500); 

}

