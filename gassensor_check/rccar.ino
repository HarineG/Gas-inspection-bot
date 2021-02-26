#include <ESP8266WiFi.h>
int Pin_D7 = 13; //pin D7
int Pin_D8 = 15; //pin D8
WiFiServer server(80);

String  i;
void setup()
{
  Serial.begin(115200);

  i = "";

  pinMode(16, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(0, OUTPUT);
  pinMode(Pin_D7,OUTPUT);
  pinMode(Pin_D8,OUTPUT); 
  pinMode(A0,INPUT);
  
    WiFi.disconnect();
  delay(300);
  Serial.println("Start Connection");
   WiFi.begin("vanamamalai","Harrypotter");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.print("...");

  }
  Serial.println("Connected");
  Serial.println((WiFi.localIP()));
  server.begin();

}


void loop()
{

    WiFiClient client = server.available();
    if (!client) { return; }
    while(!client.available()){  delay(1); }
    i = (client.readStringUntil('\r'));
    i.remove(0, 5);
    i.remove(i.length()-9,9);
    
    if (i == "W") {
      digitalWrite(16,LOW);
      digitalWrite(5,HIGH);
      digitalWrite(4,LOW);
      digitalWrite(0,HIGH);

    }
    if (i == "A") {
      digitalWrite(5,LOW);
      digitalWrite(16,LOW);
      digitalWrite(0,HIGH);
      digitalWrite(4,LOW);

    }
    if (i == "S") {
      digitalWrite(5,LOW);
      digitalWrite(16,HIGH);
      digitalWrite(0,LOW);
      digitalWrite(4,HIGH);

    }
    if (i == "D") {
      digitalWrite(5,HIGH);
      digitalWrite(16,LOW);
      digitalWrite(0,LOW);
      digitalWrite(4,LOW);

    }
     if (i == "X") {
      digitalWrite(16,LOW);
      digitalWrite(5,LOW);
      digitalWrite(4,LOW);
      digitalWrite(0,LOW);
    }
 
    if (i == "R") {
      digitalWrite(16,LOW);
      digitalWrite(5,HIGH);
      digitalWrite(4,HIGH);
      digitalWrite(0,LOW);
    }
    if (i == "L") {
      digitalWrite(16,HIGH);
      digitalWrite(5,LOW);
      digitalWrite(4,LOW);
      digitalWrite(0,HIGH);
    }
    if (i == "T") {
      digitalWrite(Pin_D7, HIGH);
      delay(100);
      Serial.println("Analog senssor value 1 : ");  
      Serial.println(analogRead(A0));
      digitalWrite(Pin_D7, LOW);
      delay(100);
    } 
    if (i == "H") {
      digitalWrite(Pin_D8, HIGH);
      delay(200);
      Serial.println("Analog senssor value 2 : ");  
      Serial.println(analogRead(A0));
      digitalWrite(Pin_D8, LOW);
      delay(100);
    } 
}
