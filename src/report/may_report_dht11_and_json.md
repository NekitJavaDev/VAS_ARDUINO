<h1 align="center">ОТЧЁТ <br> о результатах работы за май 2021 года</h1>
 
#### За отчётный период было выполнено следующее:
#### 1. Расширение элементной базы для совершенствования аппаратного модуля в части управления состоянием температуры и влажности воздуха на объектах.

Для расширения элементной базы в части управления состоянием температуры и влажности воздуха на объектах для аппаратной части был выбран и закуплен Arduino модуль DHT11. Датчик состоит из двух частей – емкостного датчика температуры и гигрометра. Первый используется для измерения температуры, второй – для влажности воздуха. Находящийся внутри чип может выполнять аналого-цифровые преобразования и выдавать цифровой сигнал, который считывается посредством микроконтроллера (Рис. 1). 
<p align="center">
  <img src="https://github.com/NekitJavaDev/VAS_ARDUINO/blob/master/src/img/may/1_%D0%92%D0%BD%D0%B5%D1%88%D0%BD%D0%B8%D0%B9_%D0%B2%D0%B8%D0%B4_%D0%BC%D0%BE%D0%B4%D1%83%D0%BB%D1%8F_Arduino_DHT11.jpg"/>
</p>
<p align="center">Рисунок 1 – Внешний вид модуля Arduino DHT11</p>

Все характеристики данных модулей представлены в таблицах 1,2.
<p align="right">Таблица 1.</p>
<p align="center">Характеристики модуля DHT11</p>

| Наименование | Значение  |
| :----------------- | :-------------: |
| Рабочее напряжение  | 3-5 В |
| Потребляемый ток  | 2.5 мА |
| Диапазон измерения влажности  | 20-80 % |
| Диапазон измерения температуры  | от 0 °C до 50 °C |
| Частота измерения  | 1 Гц (1 измерение за 1 секунду) |
| Размеры  | 15.5мм x 12 мм x 5.5мм |

<p align="right">Таблица 2.</p>
<p align="center">Характеристики модуля DHT22</p>

| Наименование | Значение  |
| :----------------- | :-------------: |
| Рабочее напряжение  | 3-5 В |
| Потребляемый ток  | 2.5 мА |
| Диапазон измерения влажности  | 0-100 % |
| Диапазон измерения температуры  | от -50 °C до 125 °C |
| Частота измерения  | 0.5 Гц (1 измерение за 2 секунды) |
| Размеры  | 15.1мм x 25 мм x 5.5мм |

Для расширения элементной базы в рамках разрабатываемого программно-аппаратного комплекса был выбран модуль DHT11, который заменил ранее интегрированный в систему датчик температуры DS18B20.

Схема подключения датчика DHT11 к плате Arduino UNO изображена на рисунке 2.
<p align="center">
  <img src="https://github.com/NekitJavaDev/VAS_ARDUINO/blob/master/src/img/may/2_%D0%A1%D1%85%D0%B5%D0%BC%D0%B0_%D0%BF%D0%BE%D0%B4%D0%BA%D0%BB%D1%8E%D1%87%D0%B5%D0%BD%D0%B8%D1%8F_%D0%B4%D0%B0%D1%82%D1%87%D0%B8%D0%BA%D0%B0_DHT11_%D0%BA_Arduino.jpg"/>
</p>
<p align="center">Рисунок 2 – Схема подключения датчика DHT11 к Arduino</p>


#### 2. Оптимизация алгоритма опроса удалённых объектов.

Для дальнейшего расширения функций программно-аппаратного комплекса было заменено управляющее устройство с Arduino NANO на Arduino Mega 2560 (Рис. 3), которое имеет большое количество элементов на плате, особенно, большое количество подключаемых контактов (пинов) (Рис. 4). Все управляемые устройства были замены на единую плату – Arduino Uno. 
<p align="center">
  <img src="https://github.com/NekitJavaDev/VAS_ARDUINO/blob/master/src/img/may/3_%D0%92%D0%BD%D0%B5%D1%88%D0%BD%D0%B8%D0%B9_%D0%B2%D0%B8%D0%B4_Arduino_Mega_2560.jpg"/>
</p>
<p align="center">Рисунок 3 –  Внешний вид Arduino Mega 2560</p>

<p align="center">
  <img src="https://github.com/NekitJavaDev/VAS_ARDUINO/blob/master/src/img/may/4_%D0%A0%D0%B0%D1%81%D0%BF%D0%BE%D0%BB%D0%BE%D0%B6%D0%B5%D0%BD%D0%B8%D0%B5_%D1%8D%D0%BB%D0%B5%D0%BC%D0%B5%D0%BD%D1%82%D0%BE%D0%B2_%D0%BD%D0%B0_%D0%BF%D0%BB%D0%B0%D1%82%D0%B5_Arduino_Mega_2560.png"/>
</p>
<p align="center">Рисунок 4 –  Расположение элементов на плате Arduino Mega 2560</p>

Все характеристики платы Arduino Mega 2560 описаны в таблице 3.
<p align="right">Таблица 3.</p>
<p align="center">Характеристики платы Arduino Mega 2560</p>

| Наименование | Значение  |
| :----------------- | :-------------: |
| Микроконтроллер  | ATmega2560 |
| Ядро  | 8-битный AVR |
| Тактовая частота  | 16 МГц |
| Объём Flash-памяти  | 256 КБ (8 КБ занимает загрузчик) |
| Объём SRAM-памяти  | 8 КБ |
| Объём EEPROM-памяти  | 4 КБ |
| Портов ввода-вывода всего  | 54 |
| Портов с АЦП  | 16 |
| Портов с ШИМ  | 15 |
| Аппаратных интерфейсов SPI  | 1 |
| Аппаратных интерфейсов I²C / TWI  | 1 |
| Аппаратных интерфейсов UART / Serial  | 4 |
| Рабочее напряжение  | 5 В |
| Габариты  | 101мм x 53мм |

Для опроса удалённых устройств посредством RS-485 протокола, теперь на плате Arduino Mega задействован UART, а именно Serial3 порт. Отладка и тестирование ПО управляющего модуля осуществляется по первому Serial порту, который выводит данные в монитор последовательного порта на ПК. Для Serial и Serial3 порта была повышена скорость обмена данными, а именно 115200 бод (максимальная скорость обмена данными с ПК):
```C++  
    void setup() {
      …………………….
            Serial3.begin (115200);
            Serial.begin (115200);
      …………………….
    }
```
Для управляемых устройств ПО также требует оптимизации, а именно, для обмена данными с управляющим устройством требуется такая же скорость обмена данными – 115200 бод. На Arduino Uno имеется единственный UART порт. Теперь Arduino Uno считывает данные с датчиков не каждую секунду, а только по запросу управляющего устройства (и только если совпадает идентификатор устройства), тем самым исключает перегрев сенсоров и повышает точность передаваемых с них данных:
```C++  
    void loop() 
    {                                                 
        while (Serial.available() > 0) {//Если есть данные в последовательном порту и ID=2
          String strId = Serial.readString();      
          if (strId == "2") { // Проверям, что запрос пришёл на нужное slave устройство
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
```


#### 2. Разработка новой структуры данных для дальнейшего расширения программно-аппаратного комплекса в части передачи данных по Ethernet каналу. Разработка, тестирование и отладка программного обеспечения для разрабатываемого модуля и новой структуры данных.

В качестве новой структуры данных был выбран единый формат обмены данными в Интернете – JSON (Java Script Object Notation). Он представляет из себя текстовый формат, основанный на JavaScript, но независим от него, а может использоваться в любом языке программирования. В качестве JSON могут использоваться:
1.  JSON-объект – неупорядоченное множество пар «ключ:значение»  
2.  Массив.
3.  Число (целое или вещественное).
4.  Литералы true (логическое значение «истина»), false (логическое значение «ложь») и null.
5.  Строка.

Для работы с JSON на платах Arduino использовалась библиотека ArduinoJson, содержащая в себе все допустимые типы данных, а также методы для чтения, записи и сериализации (отправке, передаче) данных. Чтение данных с датчиков и сенсоров и их последующая запись теперь происходит в заранее объявленный JSON-объект, а именно в функции startPollingSensors():
```C++  
    #include <ArduinoJson.h>
    #include "DHT.h"
    …………………………..
    #define DHT_PIN 2  // датчик температуры и влажности (DHT11)
    …………………………..
    DHT dht(DHT_PIN, DHT11);
    StaticJsonDocument<200> slave;
    …………………………..
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
        
         int smoke = analogRead(SMOKE_SENSOR_PIN);  // 100-500 – OK, > 700 - WARNING!
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
```
Пример ответа в виде JSON-объекта, отправляемого с управляемого устройства на управляющее:
```JSON  
    {"id":2,"temp":23.6,"humidity":37,"door_is":"open","voltage":1.196289,"smoke":881}
```
Модули успешно прошли тестирование и была доказана работоспособность и корректность показаний с датчика температуры и влажности DHT11, а также приём и передача данных между всеми устройствами программно-аппаратного комплекса (Рис. 5) (Рис. 6).
<p align="center">
  <img src="https://github.com/NekitJavaDev/VAS_ARDUINO/blob/master/src/img/may/5_%D0%9C%D0%BE%D0%BD%D0%B8%D1%82%D0%BE%D1%80_%D0%BF%D0%BE%D1%81%D0%BB%D0%B5%D0%B4%D0%BE%D0%B2%D0%B0%D1%82%D0%B5%D0%BB%D1%8C%D0%BD%D0%BE%D0%B3%D0%BE_Serial_%D0%BF%D0%BE%D1%80%D1%82%D0%B0_%D0%BD%D0%B0_%D1%83%D0%BF%D1%80%D0%B0%D0%B2%D0%BB%D1%8F%D0%B5%D0%BC%D0%BE%D0%BC_%D1%83%D1%81%D1%82%D1%80%D0%BE%D0%B9%D1%81%D1%82%D0%B2%D0%B5.JPG"/>
</p>
<p align="center">Рисунок 5 –  Монитор последовательного (Serial) порта на управляемом устройстве</p>

<p align="center">
  <img src="https://github.com/NekitJavaDev/VAS_ARDUINO/blob/master/src/img/may/6_%D0%BC%D0%BE%D0%BD%D0%B8%D1%82%D0%BE%D1%80_%D0%BF%D0%BE%D1%81%D0%BB%D0%B5%D0%B4%D0%BE%D0%B2%D0%B0%D1%82%D0%B5%D0%BB%D1%8C%D0%BD%D0%BE%D0%B3%D0%BE_(Serial)_%D0%BF%D0%BE%D1%80%D1%82%D0%B0_%D0%BD%D0%B0_%D1%83%D0%BF%D1%80%D0%B0%D0%B2%D0%BB%D1%8F%D1%8E%D1%89%D0%B5%D0%BC_%D1%83%D1%81%D1%82%D1%80%D0%BE%D0%B9%D1%81%D1%82%D0%B2%D0%B5.JPG"/>
</p>
<p align="center">Рисунок 6 –  Монитор последовательного (Serial) порта на управляющем устройстве</p>