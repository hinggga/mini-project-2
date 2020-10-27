#include "DHT.h"
#define DHTPIN 4
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);
int LED1 = 2;
int LED2 = 5 ;
int LED3 = 18;
int statusbaru = 0;
int button = 15;

void setup() {
  Serial.begin(9600);

  dht.begin();
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  if(statusbaru == 1) {
  Serial.println("System Aktif");
  if(digitalRead(button) == 0){
    statusbaru = 0;
    delay(500);
  }
    long t = dht.readTemperature();
    if ( isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    }
        Serial.print("Temperature: " );
        Serial.print(t); 
        Serial.println("*C\t");
        delay(1000);
     if ( t <= 35 ) {
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);
      Serial.println("Level 1 : Aman");
    }
    else  if ( t > 35 && t < 50) {
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, HIGH);
      Serial.println("Level 2 : Siaga");
    }
    else{
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      Serial.println("Level 3 : Darurat!!!"); 
    }
  }else{
  Serial.println("System Nonaktif");
  if(digitalRead(button) == 0){
    statusbaru = 1;
    delay(500);
  }
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);
      delay(1000);
  }

}
