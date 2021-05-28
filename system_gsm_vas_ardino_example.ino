/**
  Библиотека програмной реализации обмена по UART-протоколу
*/
#include <SoftwareSerial.h>

/**
  Инициализация RS485
*/
#define SerialTxControl 2
#define RS485Transmit HIGH
#define RS485Receive LOW

char buffer[100];
byte state = 0;

/**
  Массив для хранения показателей приборов
*/

String devices[6];

/**
  Расположение RX, TX для SIM-модуля
*/
SoftwareSerial SIM800(12, 13);


String _response = "";      // Переменная для хранения ответа модуля
long lastUpdate = millis(); // Время последнего обновления
long updatePeriod = 10000;  // Проверка каждые 60 секунд

/**
  Список разрешённых номеров абонентов
  +79111587263
*/
String phones = "+79111587263";

void setup()
{
  /**
    Установка скорости портов для обмена данными
  */
  Serial.begin(9600);
  SIM800.begin(9600);

  /**
    Установка режима работы RS485
  */
  pinMode(SerialTxControl, OUTPUT);
  digitalWrite(SerialTxControl, RS485Receive); // переводим устройство в режим приёмника

  /**
    Команды для первоначальной настройки модема при запуске
  */
  Serial.println("Настройка модуля. Пожалуйста, подождите");
  sendATCommand("AT", true);
  sendATCommand("AT+CMGF=1;&W", true);
  sendATCommand("AT+CMGDA=\"DEL ALL\"", true);
  sendATCommand("AT+CMGR=2", true);

  lastUpdate = millis(); // Обнуляем таймер

  //sendATCommand("ATD+79131816542;",false); //Голосовой вызов абонента
}

/**
    Метод для удобной отправки AT-команд
*/
String sendATCommand(String cmd, bool waiting)
{
  String _resp = "";   // Переменная для хранения результата
  Serial.println(cmd); // Дублируем команду в монитор порта
  SIM800.println(cmd); // Отправляем команду модулю
  if (waiting)
  {
    _resp = waitResponse();
    if (_resp.startsWith(cmd))
    {
      _resp = _resp.substring(_resp.indexOf("\r", cmd.length()) + 2);
    }
    Serial.println(_resp);
  }
  return _resp;
}

/**
    Метод ожидания ответа от модуля после выполнения AT-команд
*/
String waitResponse()
{
  String _resp = "";
  long _timeout = millis() + 10000;
  while (!SIM800.available() && millis() < _timeout)
  {};
  if (SIM800.available())
  {
    _resp = SIM800.readString();
  }
  else
  {
    Serial.println("Превышено время ожидания");
  }
  return _resp;
}

bool hasmsg = false;

void loop()
{
  devices_check();
  /**
     AT-команда ATA принимает любой входящий вызов

     sendATCommand("ATA", true);

     AT-команда ATD посылает голосовой вызов абоненту
     sendATCommand("ATD+79111587263;", true);
  */

  delay(10000);
  if (lastUpdate + updatePeriod < millis())
  {
    do
    {
      _response = sendATCommand("AT+CMGL=\"REC UNREAD\",1", true);
      if (_response.indexOf("+CMGL: ") > -1)
      {
        int msgIndex = _response.substring(_response.indexOf("+CMGL: ") + 7, _response.indexOf("\"REC UNREAD\"", _response.indexOf("+CMGL: "))).toInt();
        char i = 0; // Объявляем счетчик попыток
        do
        {
          i++;
          _response = sendATCommand("AT+CMGR=" + (String)msgIndex + ",1", true);
          _response.trim();
          if (_response.endsWith("OK"))
          {
            if (!hasmsg)
              hasmsg = true;
            sendATCommand("AT+CMGR=" + (String)msgIndex, true);
            sendATCommand("\n", true);
            parseSMS(_response);
            break;
          }
          else
          {
            Serial.println("Error answer");
            sendATCommand("\n", true);
          }
        } while (i < 10);
        break;
      }
      else
      {
        lastUpdate = millis();
        if (hasmsg)
        {
          sendATCommand("AT+CMGDA=\"DEL READ\"", true);
          hasmsg = false;
        }
        break;
      }
    } while (1);
  }

  if (SIM800.available())
  { // Если модем, что-то отправил...
    _response = waitResponse();
    _response.trim();
    Serial.println(_response);
    if (_response.indexOf("+CMTI:") > -1)
    {
      lastUpdate = millis() - updatePeriod;
    }
  }
  if (Serial.available())
  {
    SIM800.write(Serial.read());
  };
}

/**
  Метод получения ответа по RS45
*/
void devices_check() {
  int count = 0;
  if ( Serial.available() ) {
    delay(6);
    while ( Serial.available() ) {
      buffer[count++] = Serial.read();
    }
  }

  if (count > 0) {
    buffer[count++] = '\0';
    String deviceResponse = buffer;
    String deviceTemp = "";
    if (deviceResponse.indexOf("ID_1_") != -1) {
      devices[0] = deviceResponse;
      Serial.print("Устройство 1: " + devices[0]);

      //Получение уникального значения
      //deviceResponse.replace("ID_1_", "");
      //Serial.println("Значение: " + deviceTemp);
    } else if (deviceResponse.indexOf("ID_2_") != -1) {
      devices[1] = deviceResponse;
      Serial.print("Устройство 2: " + devices[1]);
      
      //Получение уникального значения
      //deviceResponse.replace("ID_2_", "");
    } else if (deviceResponse.indexOf("ID_3_") != -1) {
      devices[2] = deviceResponse;
      Serial.print("Устройство 3: " + devices[2]);
      
      //Получение уникального значения
      //deviceResponse.replace("ID_3_", "");
    } else {
      Serial.print("Устройство не определено");
    }
  }
}

/**
  Метод определяющий содердимое сообшения от абонента
*/
void parseSMS(String msg)
{
  String msgheader = "";
  String msgbody = "";
  String msgphone = "";

  msg = msg.substring(msg.indexOf("+CMGR: "));
  msgheader = msg.substring(0, msg.indexOf("\r"));

  msgbody = msg.substring(msgheader.length() + 2);
  msgbody = msgbody.substring(0, msgbody.lastIndexOf("OK"));
  msgbody.trim();

  int firstIndex = msgheader.indexOf("\",\"") + 3;
  int secondIndex = msgheader.indexOf("\",\"", firstIndex);
  msgphone = msgheader.substring(firstIndex, secondIndex);

  Serial.println("Phone: " + msgphone);
  Serial.println("Message: " + msgbody);

  if (msgbody == "01")
  {
    Serial.println("SMS true");
    sendATCommand("ATD+79111587263;",false);
    //SIM800.println("AT+CMGS=\"+79111587263\">" + devices[0]);
  }

  if (msgphone.length() > 6 && phones.indexOf(msgphone) > -1)
  {
  }
  else
  {
    Serial.println("Неизвестный номер телефона");
  }
}
