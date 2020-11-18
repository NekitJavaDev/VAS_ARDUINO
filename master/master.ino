#include <EasyTransfer.h>
#include <SoftEasyTransfer.h>
#include <SoftwareSerial.h>
#include <PCD8544.h>
#include <iarduino_GSM.h>

#define DIR 10
#define interval 10000
SoftwareSerial softSerial(12, 11); //tx rx
SoftwareSerial RS485Serial(8, 9);

iarduino_GSM gsm;
EasyTransfer ET;
SoftEasyTransfer ETtx, ETrx;
PCD8544 lcd;

/**
  SMStxt - содержимое сообщения
  SMSnum - номер отправителя
  SMStim - дата получения сообщения
*/
char SMStxt[161];
char SMSnum[13];
char SMStim[18];

/**
   Хранение состояния устройств
   Для отправки на мобильные устройства
*/
String stateDevices[10];

/**
   Номера телефонов
   Список доверенных пользователей
*/
String phonesAllowed[] = {"79111587263", "79029117792"};

/**
   Структуры для обмена данными между устройствами
*/
struct RECEIVE_DATA_RS485
{
  int ID;
  float temp;
  int isOpen;
};

struct SEND_DATA_RS485
{
  int ID;
  int cmd;
};

RECEIVE_DATA_RS485 rxdata;
SEND_DATA_RS485 txdata;

unsigned long previousMillis = 0;

/**
   Счётчик для опроса устройств
*/
int IDsend = 0;

void setup()
{
  lcd.begin(84, 48);
  Serial.begin(4800);

  ETrx.begin(details(rxdata), &RS485Serial);
  ETtx.begin(details(txdata), &RS485Serial);

  pinMode(DIR, OUTPUT);
  digitalWrite(DIR, LOW);

  lcd.setCursor(0, 0);
  lcd.print("Devices:");
  lcd.setCursor(0, 1);
  lcd.print("");
}

void loop()
{
  //Инициализация RS485 для работы на скорости 4800
  RS485Serial.begin(4800);

  //Опрос устройств
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis > interval)
  {
    previousMillis = currentMillis;
    if (previousMillis > currentMillis)
      previousMillis = 0;

    IDsend++;

    switch (IDsend)
    {
    case 1:
      sendCmdRS485(IDsend, 1);
      break;
    case 2:
      sendCmdRS485(IDsend, 1);
      break;
    case 3:
      //Инициализация GSM для работы на скорости 4800
      gsm.begin(softSerial);

      if (gsm.SMSavailable())
      {
        gsm.SMSread(SMStxt, SMSnum, SMStim);

        Serial.println("NEW MESSAGE");
        Serial.println("Date: " + String(SMStim));
        Serial.println("Phone: " + '+' + String(SMSnum));
        Serial.println("Body: " + String(SMStxt));

        if (String(SMStxt) == "00")
        {
          if (gsm.status() != GSM_OK)
          {
            Serial.print("GSM_ERROR");
            delay(1000);
          }
          else
          {
            //Очиска предыдущего сообщения
            lcd.setCursor(0, 5);
            lcd.print("              ");

            //Устанавливаем тип запрашиваемой команды
            //RD (Request Device) | RDA (All, 1, 2 etc)
            lcd.setCursor(0, 5);
            lcd.print("RDA");

            //Установка кириллицы
            gsm.TXTsendCodingDetect("п");

            //Обработка и отправка исходящего СМС
            if (gsm.SMSsend(String(stateDevices[0]) + " " + String(stateDevices[1]), "79111587263"))
            {
              Serial.println("MESSAGE SENT");

              //Включение RS485 на скорости 4800
              RS485Serial.begin(4800);

              //Очистка экрана от сообщения
              lcd.setCursor(0, 5);
              lcd.print("              ");
            }
            else
            {
              Serial.println("ERROR");
            }
          }
        }
      }

      //Отключения GSM модуля для восстановления работы RS485
      softSerial.end();

      //Сброс счётчика опроса устройств
      IDsend = 0;
      break;

    default:
      Serial.println("DEFAULT HAPPENED");
      //sendCmdRS485(IDsend, 1);
      break;
    }
  }

  delay(10);

/**
  Приём данных и вывод на LCD 
*/
  if (ETrx.receiveData())
  {
    char outstr[4];
    switch (rxdata.ID)
    {
    case 1:
      lcd.setCursor(0, 2);
//      lcd.print("D:" + String(rxdata.ID) + " T:" + String(rxdata.temp));
//      lcd.print("D:" + String(rxdata.ID) + " T:" + dtostrf(rxdata.temp,2,1,outstr));
        lcd.print("D:" + String(rxdata.ID) + " T:" + dtostrf(rxdata.temp,2,1,outstr) + " G:" + String(rxdata.isOpen));
      
      Serial.println("Device 1 ID: " + String(rxdata.ID));
      Serial.println("Temp: " + String(rxdata.temp));
      Serial.println("Door is open ?: " + String(rxdata.isOpen));

      changeStateDevices(rxdata.ID, String(rxdata.temp), rxdata.isOpen);
      break;

    case 2:
      lcd.setCursor(0, 3);
//      lcd.print("D:" + String(rxdata.ID) + " T:" + dtostrf(rxdata.temp,2,1,outstr));
      lcd.print("D:" + String(rxdata.ID) + " T:" + dtostrf(rxdata.temp,2,1,outstr) + " G:" + String(rxdata.isOpen));
  
      Serial.println("Device 2 ID: " + String(rxdata.ID));
      Serial.println("Temp: " + String(rxdata.temp));
      Serial.println("Door is open ?: " + String(rxdata.isOpen));

      changeStateDevices(rxdata.ID, String(rxdata.temp), rxdata.isOpen);
      break;

    default:
      break;
    }
  }
}

/**
   Метод для отправки СМС
*/
void sendCmdRS485(int id, int cmd)
{
  digitalWrite(DIR, HIGH);
  delay(10);
  txdata.ID = id;
  txdata.cmd = cmd;
  Serial.println("SENDING");
  ETtx.sendData();
  delay(10);
  digitalWrite(DIR, LOW);
}

/**
   Метод для записи показателей устройств
*/
void changeStateDevices(int id, String temp, int isOpen)
{
  String isOpenStrValue;
  if(isOpen==1){
    isOpenStrValue="is open";
  }else{
    isOpenStrValue="is close";
  }
  switch (id)
  {
  case 1:
    stateDevices[0] = "D" + String(id) + " " + "temp: " + temp + "Door : " + isOpenStrValue;
    break;

  case 2:
    stateDevices[1] = "D" + String(id) + " " + "temp: " + temp + "Door : " + isOpenStrValue;
    break;

  default:
    break;
  }
}

int isAllowedPhone(String phone){
  

  return 0;
}
