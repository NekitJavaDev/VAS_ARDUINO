#include <LiquidCrystal_I2C.h>
#include <ArduinoJson.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);  // Для экрана 20х4 (четырехстрочный)

#define RS485_DIR 10  //отправка RS485

//#define GERKON_LED_PIN_DEVICE_1 A?  // slave1 
//#define SMOKE_LED_PIN_DEVICE_1 A?  // slave1
//#define VOLTAGE_LED_PIN_DEVICE_1 A?  // slave1
//
//#define GERKON_LED_PIN_DEVICE_2 A?  // slave2
//#define SMOKE_LED_PIN_DEVICE_2 A?  // slave2
//#define VOLTAGE_LED_PIN_DEVICE_2 A?  // slave2
//
//#define GERKON_LED_PIN_DEVICE_3 A?  // slave3
//#define SMOKE_LED_PIN_DEVICE_3 A?  // slave3
//#define VOLTAGE_LED_PIN_DEVICE_3 A?  // slave3

#define interval 10000  //5000

unsigned long previousMillis = 0;
int IDsend = 0;  // Счётчик для опроса устройств

StaticJsonDocument<200> slave;  // Пришедший JSON со slave устройства 

void setup()
{
    Serial3.begin(115200);  // UART port, which send and take from slave devices
    Serial.begin(115200);

    // pinMode(GERKON_LED_PIN_DEVICE_1, OUTPUT);
    // pinMode(SMOKE_LED_PIN_DEVICE_1, OUTPUT);
    // pinMode(VOLTAGE_LED_PIN_DEVICE_1, OUTPUT);
    // pinMode(GERKON_LED_PIN_DEVICE_2, OUTPUT);
    // pinMode(SMOKE_LED_PIN_DEVICE_2, OUTPUT);
    // pinMode(VOLTAGE_LED_PIN_DEVICE_2, OUTPUT);
    // pinMode(GERKON_LED_PIN_DEVICE_3, OUTPUT);
    // pinMode(SMOKE_LED_PIN_DEVICE_3, OUTPUT);
    // pinMode(VOLTAGE_LED_PIN_DEVICE_3, OUTPUT);
    
    pinMode(RS485_DIR, OUTPUT);
    digitalWrite(RS485_DIR, LOW);
    
    lcd.begin();
    lcd.setCursor(0, 0);  // Device 1
    lcd.print("1");
    lcd.setCursor(0, 1);  // Device 2
    lcd.print("2");
    lcd.setCursor(0, 2);  // Device 3
    lcd.print("3");
    lcd.setCursor(0, 3);  // Device 3
    lcd.print("4");
}

void loop()
{
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis > interval) {
        previousMillis = currentMillis;
        if (previousMillis > currentMillis) {
            previousMillis = 0;
        }

        IDsend++;
        Serial.print("ID send = ");
        Serial.println(IDsend);

        switch (IDsend) {
            case 1:
              lcd.setCursor(1, 0);
              lcd.print("                   ");  // Очистка 1-ой строки  
              lcd.setCursor(2, 0);
              lcd.print("Send to Device 1");
              sendCmdRS485(IDsend, 1);
            break;
            case 2:
              lcd.setCursor(1, 1);
              lcd.print("                   ");  // Очистка 2-ой строки  
              lcd.setCursor(2, 1);
              lcd.print("Send to Device 2");
              sendCmdRS485(IDsend, 1);
              IDsend = 0;
            break;
            /*
            case 3:
              lcd.setCursor(1, 2);
              lcd.print("                   ");  // Очистка 3-ой строки  
              lcd.setCursor(2, 2);
              lcd.print("Send to Device 3");
              sendCmdRS485(IDsend, 1);
            break;
            case 4:
              lcd.setCursor(1, 3);
              lcd.print("                   ");  // Очистка 4-ой строки  
              lcd.setCursor(2, 3);
              lcd.print("Send to Device 4");
              sendCmdRS485(IDsend, 1);
              IDsend = 0;
            break;
            */            
            default:
              Serial.println("DEFAULT HAPPENED");
            break;
        }
      
    }

    delay(10);

    /**
    *  Приём данных, обработка и вывод на LCD 
    */
    while (Serial3.available() > 0) {    
        DeserializationError error = deserializeJson(slave, Serial3);    
  //        if (error) {  // Test if parsing succeeds.
  //          Serial.print(F("deserializeJson() failed: "));
  //          Serial.println(error.f_str());
  //          return;
  //        }
        char outStrTemperature[4];
        char outStrVoltage[3];
          
        float temp = slave["temp"];
        String doorIs = slave["door_is"];
        float voltage = slave["voltage"];
        int smoke = slave["smoke"];
        int humidity = slave["humidity"];

        Serial.println("I recieved JSON:");
        int id = slave["id"];  

        switch (id) {
        case 0:
            Serial.println("Error deserialize Json!! ID = 0");
            return;          
        case 1:
            // turnOnOrOffLedGerkonPins(1, doorIs);
            // turnOnOrOffLedSmokePins(1, smoke);
            // turnOnOrOffLedVoltagePins(1, voltage);
            lcd.setCursor(0, 0);
            lcd.print("                    "); //Очистка 1-ой строки
            lcd.setCursor(0, 0);
            lcd.print("1 T:" + String(dtostrf(temp,2,1,outStrTemperature)) + " V:" + String(dtostrf(voltage,2,1,outStrVoltage)) + " H:" + humidity + "%"); 
        break;
        case 2:
            // turnOnOrOffLedGerkonPins(2, doorIs);
            // turnOnOrOffLedSmokePins(2, smoke);
            // turnOnOrOffLedVoltagePins(2, voltage);
            lcd.setCursor(0, 1);
            lcd.print("                    "); //Очистка 2-ой строки
            lcd.setCursor(0, 1);
            lcd.print("2 T:" + String(dtostrf(temp,2,1,outStrTemperature)) + " V:" + String(dtostrf(voltage,2,1,outStrVoltage)) + " H:" + humidity + "%"); 
        break;
        /*
        case 3:
            // turnOnOrOffLedGerkonPins(3, doorIs);
            // turnOnOrOffLedSmokePins(3, smoke);
            // turnOnOrOffLedVoltagePins(3, voltage);
            lcd.setCursor(0, 2);
            lcd.print("                    "); //Очистка 3-ей строки
            lcd.setCursor(0, 2);
            lcd.print("3 T:" + String(dtostrf(temp,2,1,outStrTemperature)) + " V:" + String(dtostrf(voltage,2,1,outStrVoltage)) + " H:" + humidity + "%"); 
        break;
        case 4:
            // turnOnOrOffLedGerkonPins(4, doorIs);
            // turnOnOrOffLedSmokePins(4, smoke);
            // turnOnOrOffLedVoltagePins(4, voltage);
            lcd.setCursor(0, 3);
            lcd.print("                    "); //Очистка 4-ой строки
            lcd.setCursor(0, 3);
            lcd.print("4 T:" + String(dtostrf(temp,2,1,outStrTemperature)) + " V:" + String(dtostrf(voltage,2,1,outStrVoltage)) + " H:" + humidity + "%"); 
        break;
        */
        default:
            Serial.print("Incorrect input ID from slave device = ");
            Serial.println(id);
        break;
        }
        delay(10);
        
        Serial.println("After parsing JSON:");
        Serial.print("Slave ID: ");
        Serial.println(id);
        Serial.print("Temperature: ");
        Serial.println(temp, 1);
        Serial.print("Door is: ");
        Serial.println(doorIs);
        Serial.print("Voltage: ");
        Serial.println(voltage);
        Serial.print("Smoke: ");
        Serial.println(smoke);
        Serial.print("Humidity: ");
        Serial.println(humidity);   
    }
  
}

/**
   Метод для отправки запроса по RS485
*/
void sendCmdRS485(int id, int cmd)
{
    digitalWrite(RS485_DIR, HIGH);
    delay(10);
    
    Serial.println("SENDING to device with ID = " + String(id) + "cmd = " + String(cmd));    
    Serial3.print(id);   //последовательно передаем ID slave устройства через шину RS-485 на UART

    delay(10);
    digitalWrite(RS485_DIR, LOW);
}

/*

void turnOnOrOffLedGerkonPins(int deviceId, String doorIs) {
    switch (deviceId) {
        case 1:
            if (doorIs == "open") {
              digitalWrite(GERKON_LED_PIN_DEVICE_1, HIGH);
            } else if (doorIs == "close") {
              digitalWrite(GERKON_LED_PIN_DEVICE_1, LOW);
            } else {
              Serial.print("Error turning on/off LED GERKON pin with ID device = ");
              Serial.print(deviceId);
              Serial.print(" and door's GERKON value = "); 
              Serial.println(doorIs);                   
            }
        break;      
        case 2:
            if (doorIs == "open") {
              digitalWrite(GERKON_LED_PIN_DEVICE_2, HIGH);
            } else if (doorIs == "close") {
              digitalWrite(GERKON_LED_PIN_DEVICE_2, LOW);
            } else {
              Serial.print("Error turning on/off LED GERKON pin with ID device = ");
              Serial.print(deviceId);
              Serial.print(" and door's GERKON value = "); 
              Serial.println(doorIs);            
            }
        break;
        case 3:
            if (doorIs == "open") {
              digitalWrite(GERKON_LED_PIN_DEVICE_3, HIGH);
            } else if (doorIs == "close") {
              digitalWrite(GERKON_LED_PIN_DEVICE_3, LOW);
            } else {
              Serial.print("Error turning on/off LED GERKON pin with ID device = ");
              Serial.print(deviceId);
              Serial.print(" and door's GERKON value = "); 
              Serial.println(doorIs);            
            }
        break;
        default:
            Serial.print("Error turning on/off LED GERKON pin with ID device = ");
            Serial.println(deviceId);  
        break;
    }
}

void turnOnOrOffLedSmokePins(int deviceId, int smoke) {
    switch (deviceId) {
        case 1:
            if (smoke > 700) {
              digitalWrite(SMOKE_LED_PIN_DEVICE_1, HIGH);
            } else {
              digitalWrite(SMOKE_LED_PIN_DEVICE_1, LOW);
            }
        break;      
        case 2:
          if (smoke > 700) {
            digitalWrite(SMOKE_LED_PIN_DEVICE_2, HIGH);
          } else {
            digitalWrite(SMOKE_LED_PIN_DEVICE_2, LOW);
          }
        break;
        case 3:
          if (smoke > 700) {
            digitalWrite(SMOKE_LED_PIN_DEVICE_3, HIGH);
          } else {
            digitalWrite(SMOKE_LED_PIN_DEVICE_3, LOW);
          }
        break;
        default:
            Serial.print("Error turning on/off SMOKE GERKON pin with ID device = ");
            Serial.println(deviceId);  
        break;
    }
}

void turnOnOrOffLedVoltagePins(int deviceId, float voltage) {
    switch (voltage) {
        case 0:
            Serial.print("Battery not connected or voltage = 0 on ID device = ");
            Serial.println(deviceId); 
        break;
        case 1:
            if (voltage < 0.9f) {
              digitalWrite(SMOKE_LED_PIN_DEVICE_1, HIGH);
            } else {
              digitalWrite(SMOKE_LED_PIN_DEVICE_1, LOW);
            }
        break;      
        case 2:
          if (voltage < 0.9f) {
            digitalWrite(SMOKE_LED_PIN_DEVICE_2, HIGH);
          } else {
            digitalWrite(SMOKE_LED_PIN_DEVICE_2, LOW);
          }
        break;
        case 3:
          if (voltage < 0.9f) {
            digitalWrite(SMOKE_LED_PIN_DEVICE_3, HIGH);
          } else {
            digitalWrite(SMOKE_LED_PIN_DEVICE_3, LOW);
          }
        break;
        default:
            Serial.print("Error turning on/off VOLTAGE GERKON pin with ID device = ");
            Serial.println(deviceId);  
        break;
    }
}

*/
