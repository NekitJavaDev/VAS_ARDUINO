#include <EasyTransfer.h>
#include <SoftwareSerial.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define RS485ID 1 //номер устройства
#define DIR 10 //RS485
#define ONE_WIRE_BUS 5 //датчик температуры (цифровой вход)
#define GERKON_PIN 4 //геркон (цифровой вход)
#define VOLTAGE_PIN A4 //датчик измерения напряжения (Voltage Sensor)
#define SMOKE_SENSOR_PIN A0 //датчик дыма
#define R1_VOLTAGE 30000.0 //R1(Voltage Sensor)
#define R2_VOLTAGE 7500.0 //R2(Voltage Sensor) 
//#define U_REF 5.0 //опорное напряжение (Voltage Sensor) 
//float Uin = U_REF * ((R1_VOLTAGE + R2_VOLTAGE) / R2_VOLTAGE); //вычисление входного напряжения (max) (Voltage Sensor) 
float Uin = HIGH * ((R1_VOLTAGE + R2_VOLTAGE) / R2_VOLTAGE); //вычисление входного напряжения (max) (Voltage Sensor) 

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensor(&oneWire);

SoftwareSerial RS485Serial(8, 9);

EasyTransfer ETtx, ETrx;

struct SEND_DATA_STRUCTURE {
    int ID;
    float temp;
    int isOpen;
    float voltage;
    int smoke;
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
  pinMode(VOLTAGE_PIN, INPUT);
  pinMode(SMOKE_SENSOR_PIN, INPUT);
  
  sensor.begin();
  sensor.setResolution(12);
}

int smoke = 0;

void loop() {  
  sensor.requestTemperatures();  
  float temperature = sensor.getTempCByIndex(0);
  int isOpen = digitalRead(GERKON_PIN);
  float voltage = (analogRead(VOLTAGE_PIN) * Uin) / 1024.0;
  smoke = analogRead(SMOKE_SENSOR_PIN); // <1000 нормальная концентрация, >2000 - WARNING!
  
  delay(50);
  
  if (ETrx.receiveData()) {    
    txdata.ID = RS485ID;
    txdata.temp = temperature;
    txdata.isOpen = isOpen;
    txdata.voltage = voltage;
    txdata.smoke = smoke;
    
    digitalWrite(DIR, HIGH); // включаем передачу
    delay(100);
    Serial.println("----------------");
    Serial.print("Before send by RS485");
    Serial.print("Device ID = ");
    Serial.println(RS485ID);
    Serial.print("Temperature = ");
    Serial.println(temperature);
    Serial.print("Door is open = ");
    String convertIsOpenDoorValue = isOpen ? "Yes" : "No";
    Serial.println(convertIsOpenDoorValue);
    Serial.print("Smoke value = ");
    Serial.println(txdata.smoke);
    Serial.println("----------------");

    ETtx.sendData(); //отправляем на управляющее устройство
    delay(50);
    digitalWrite(DIR, LOW);
  }
}
