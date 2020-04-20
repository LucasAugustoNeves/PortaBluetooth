#include <SoftwareSerial.h>
 
SoftwareSerial bt(6, 7); // RX  TX
const int rele = 13;
int led = 13;
int caractere;

void setup() {
bt.begin(9600);
pinMode(led,OUTPUT);
pinMode(rele, OUTPUT);
digitalWrite(rele, HIGH);
}

void loop() {
  if (bt.available()) {
  caractere = bt.read();
  
  if(caractere == '7') {
   digitalWrite(led, LOW);
   digitalWrite(rele, LOW);
  bt.println("OK, porta aberta.");
  delay(100);
  digitalWrite(led, HIGH);
   digitalWrite(rele, HIGH);
  bt.println("OK, porta fechada.");
 }
  }
   delay(100);
 }
