#include "DHT.h"
#define DHTPIN 4
#define Button 15
#define DHTTYPE DHT11   // DHT 11


DHT dht(DHTPIN, DHTTYPE);
int LED1 = 2;
int LED2 = 5 ;
int LED3 = 18;



void setup() {
  Serial.begin(9600);

  dht.begin();
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(Button, INPUT_PULLUP);
}

void loop() {
  int Push_button_state = digitalRead(Button);
  delay(500); // delay 0.5 detik
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Gagal membaca sensor!");
    return;
  }
  float hic = dht.computeHeatIndex(t, h, false);


  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C\t ");
  Serial.print("Heat index: ");
  Serial.print(hic);
  Serial.println(" *C ");
  Serial.println(Push_button_state);

  if ( Push_button_state == 1  ) {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    }
  else if ( Push_button_state == 0  )
  {
    
    if ( t < 35 ) {
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
    }
    if ( t > 35 && t <  50) {
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, LOW);
    }
    if  ( t > 50){
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);
      }

  }


}
