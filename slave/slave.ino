#include <EasyTransfer.h>
#include <SoftwareSerial.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define RS485ID 2 //номер устройства
#define DIR 10 //RS485
#define ONE_WIRE_BUS 5 //датчик температуры (цифровой вход)
#define GERKON_PIN 4  //геркон (цифровой вход)

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensor(&oneWire);

SoftwareSerial RS485Serial(8, 9);

EasyTransfer ETtx, ETrx;

struct SEND_DATA_STRUCTURE {
  int ID;
  float temp;
  int isOpen;
};

struct RECEIVE_DATA_STRUCTURE {
  int ID;
  int cmd;
};

RECEIVE_DATA_STRUCTURE rxdata;
SEND_DATA_STRUCTURE txdata;

void setup() {
  RS485Serial.begin(4800);
  Serial.begin(4800);
  ETrx.begin(details(rxdata), &RS485Serial);
  ETtx.begin(details(txdata), &RS485Serial);
  pinMode(DIR, OUTPUT);
  digitalWrite(DIR, LOW);
  pinMode(GERKON_PIN, INPUT);
  digitalWrite(GERKON_PIN, HIGH);
  
  sensor.begin();
  sensor.setResolution(12);
}

void loop() {  
  sensor.requestTemperatures();  
  float temperature = sensor.getTempCByIndex(0);
  int isOpen = digitalRead(GERKON_PIN);
  Serial.print("temperature = ");
  Serial.println(temperature);
  Serial.print("isOpen = ");
  Serial.println(isOpen);
  
  delay(100);
  
  if (ETrx.receiveData()) {    
    txdata.ID = RS485ID;
    txdata.temp = temperature;
    txdata.isOpen = isOpen;
    
    digitalWrite(DIR, HIGH); // включаем передачу
    delay(500);
    ETtx.sendData(); //отправляем на управляющее устройство
    delay(50);
    digitalWrite(DIR, LOW);
  }
}
