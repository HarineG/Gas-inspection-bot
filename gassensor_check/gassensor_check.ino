#include <ESP8266WiFi.h>
int Pin_D7 = 13;
int Pin_D8 = 15;
void setup() {
Serial.begin(9600);
pinMode(Pin_D7,OUTPUT);
pinMode(A0,INPUT);
}

void loop() {
digitalWrite(Pin_D7, HIGH);
delay(100);
Serial.println("Analog senssor value 1 : ");  
Serial.println(analogRead(A0));
digitalWrite(Pin_D7, LOW);
delay(100);
delay(3000);
digitalWrite(Pin_D8, HIGH);
delay(200);
Serial.println("Analog senssor value 2 : ");  
Serial.println(analogRead(A0));
digitalWrite(Pin_D8, LOW);
delay(3000);
}
