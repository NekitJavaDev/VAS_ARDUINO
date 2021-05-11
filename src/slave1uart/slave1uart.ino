#include <ArduinoJson.h>
#include "DHT.h"

#define RS485_ID 1  // ID slave устройства (уникальный номер, чтобы различать устройства системы)
#define RS485_DIR 10  // переключение RS485 приёмника/передатчика: LOW - "приём данных", HIGH - "передача" (RS-485 to TTL MAX)

#define GERKON_PIN 4  // геркон (values: 1 = "open", 0 = "close")

#define DHT_PIN 2  // датчик температуры и влажности (DHT11)

#define SMOKE_SENSOR_PIN A0  // датчик дыма (MQ-2)

#define VOLTAGE_PIN A4  // датчик измерения входного напряжения (Voltage Sensor)
#define R1_VOLTAGE 30000.0  // R1(Voltage Sensor)
#define R2_VOLTAGE 7500.0  // R2(Voltage Sensor) 
float U_REF = R2_VOLTAGE / (R1_VOLTAGE + R2_VOLTAGE);  // вычисление входного напряжения (max) (Voltage Sensor)
float U_HIGH = 5.0;

DHT dht(DHT_PIN, DHT11);

StaticJsonDocument<200> slave;

void setup() 
{  
    Serial.begin(115200);  // UART на 115200 бод (max скорость обмена с ПК)
    while (!Serial) {
        ;  // wait for serial port to connect. Needed for native USB
    }
    
    dht.begin();
    
    pinMode(GERKON_PIN, INPUT);
    digitalWrite(GERKON_PIN, HIGH);
    
    pinMode(RS485_DIR, OUTPUT);
    digitalWrite(RS485_DIR, LOW); 
}

void loop() 
{                                                 
    while (Serial.available() > 0) {  // Если есть какие либо данные в последовательном порту и ID = 2
      String strId = Serial.readString();      
      if (strId == String(RS485_ID)) {  // Проверям, что запрос пришёл на нужное slave устройство
          digitalWrite(RS485_DIR, HIGH);
          delay(10);

          startPollingSensors();
          serializeJson(slave, Serial);
          
          delay(10);      
          digitalWrite(RS485_DIR, LOW);      
      } else {
          return;  // Иначе выходи из loop() и просто ждём новых данных   
      }          
    }
}

/**
*  Example response to send to MASTER device
*  {"id":1,"temp":23.6,"humidity":37,"door_is":"open","voltage":1.196289,"smoke":881}
*/
void startPollingSensors()
{
    slave["id"] = RS485_ID;  
    slave["temp"] = 0.0;
    slave["humidity"] = 0;
    slave["door_is"] = "error";
    slave["voltage"] = 0.0;
    slave["smoke"] = 0;

    int doorIsOpen = digitalRead(GERKON_PIN);
    String convertIsOpenDoorValue = doorIsOpen ? "open" : "close";
    slave["door_is"] = convertIsOpenDoorValue;   
    
    float uOut = (analogRead(VOLTAGE_PIN) * U_HIGH) / 1024.0;
    float voltage = uOut / U_REF;
    slave["voltage"] = voltage;
    
    int smoke = analogRead(SMOKE_SENSOR_PIN);  // 100-500 - OK, > 700 - WARNING!
    slave["smoke"] = smoke;

    int humidity = dht.readHumidity();  
    float temp = dht.readTemperature();  
    if (isnan(humidity) || isnan(temp)) {  
        slave["temp"] = 0.0;
        slave["humidity"] = 0;    
    } else {
        slave["temp"] = temp;
        slave["humidity"] = humidity;   
    }
}
