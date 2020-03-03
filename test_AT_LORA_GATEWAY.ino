#include <SPI.h>              // include libraries
#include <LoRa.h>

const long frequency = 915E6;  // LoRa Frequency

const int csPin = 17;          // LoRa radio chip select
const int resetPin = 16;        // LoRa radio reset
const int irqPin = 27;        // change for your board; must be a hardware interrupt pin

  
  #define RXD1 13
  #define TXD1 14

unsigned curTime, oldTime;
void setup() {
    // put your setup code here, to run once:
  Serial.begin(115200);
  Serial1.begin(19200, SERIAL_8N1, RXD1, TXD1);
  pinMode(19, OUTPUT);
  digitalWrite(19, LOW); delay(1000);
  digitalWrite(19, HIGH); delay(1000);

  LoRa.setPins(csPin, resetPin, irqPin);
  if (!LoRa.begin(frequency)) {
    Serial.println("LoRa init failed. Check your connections.");
    while (true);                       // if failed, do nothing
  }
  Serial.println("LoRa init succeeded.");


}

void loop() {
  // put your main code here, to run repeatedly:
    Serial.println("kirim AT");
    Serial1.println("AT");
    tunggu(2000);    
    delay(2000);
}

void tunggu(unsigned long wkt){
  curTime = millis();
  oldTime = curTime;
  while(curTime - oldTime < wkt){
    curTime = millis();
    while(Serial1.available()>0){
      Serial.println(Serial1.readString());
    }
  }
}
