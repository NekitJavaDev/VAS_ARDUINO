<h1 align="center">ОТЧЁТ <br> о результатах работы за декабрь 2020 года</h1>
 
#### За отчётный период было выполнено следующее:
#### 1. Расширение элементной базы для совершенствования аппаратного модуля в части управления состоянием задымлённости на объектах.

Для расширения элементной базы в части управления состоянием задымлённости на объектах для аппаратной части был выбран и закуплен Arduino модуль MQ-2.
Он представляет собой аналогово-цифровой датчик газа для своевременного обнаружения газа или дыма. Данный модуль позволяет выявлять 
в воздухе минимальную концентрацию водорода и углеводородных газов (пропан, метан, бутан). Сама плата датчика состоит из чувствительного 
газоанализатора (детектор), потенциометра и 4 пинов для подключения датчика к микроконтроллеру семейства Arduino (Рис. 1). 
<p align="center">
  <img src="https://github.com/NekitJavaDev/VAS_ARDUINO/blob/master/src/img/december/1_%D0%B2%D0%BD%D0%B5%D1%88%D0%BD%D0%B8%D0%B9_%D0%B2%D0%B8%D0%B4_%D0%BC%D0%BE%D0%B4%D1%83%D0%BB%D1%8F_%D0%B3%D0%B0%D0%B7%D0%B0_Arduino_MQ_2.jpg"/>
</p>
<p align="center">Рисунок 1 – Внешний вид модуля газа Arduino MQ-2</p>

Существует множество датчиков серии MQ, таких как датчик углекислого газа, датчик угарного газа, датчик паров спирта, датчик чистоты воздуха и другие. 
Для расширения элементной базы в рамках разрабатываемого программно-аппаратного комплекса был выбран именно датчик газа MQ-2, 
так как он позволяет регистрировать концентрацию таких газов как водород, дым, и горючие углеводородные газы (метан, пропан, бутан), 
а также он прост в подключении, имеет высокую чувствительность и малое время отклика. Он применяется в системах IoT (Internet of Things – «умный дом»), 
в системах обнаружения газа или дыма на промышленных или частных объектах, в автомобильных вентиляционных фильтрах и других сферах деятельности.

Принцип работы датчика основан на чувствительном детекторе из смеси оксидов алюминия и олова, в котором за счет нагревания 
происходит химическая реакция. Именно поэтому в процессе работы газоанализатор существенно нагревается. В результате химической реакции, 
происходящей при попадании молекул углеводородных газов на чувствительный элемент, изменяется сопротивление элемента и передается сигнал. 
В зависимости от чувствительности элемента к определенным газам достигается эффект их обнаружения.

Концентрация газа измеряется в ppm. Она расшифровывается, как parts per million (частей на миллион). Таким образом 1ppm соответствует концентрации в 0,0001%. 
Чтобы получить точное значение измеренной концентрации газа ppm, необходимо выполнить сложное нелинейное преобразование напряжения 
на аналоговом выходе датчика по таблицам преобразования из документации на датчик, с учетом температуры окружающего воздуха.

С помощью потенциометра можно изменять порог чувствительности цифрового выхода датчика. Но для разных по составу газов порог 
чувствительности будет разным. Индикаторы, расположенные на датчике, уведомляют о подключенном питании и превышении порога чувствительности цифрового выхода.

Детектор газа на модуле представляет собой 6-пиновый датчик, который для точных показаний должен некоторое время быть включенным 
и нагреться до необходимой температуры, то есть провести его калибровку. Потенциометр на плате установлен для измерения чувствительности датчика.

Закупленный модуль Arduino MQ-2 собран на небольшой плате, габариты которой всего 32 мм х 20 мм. Все характеристики данного модуля представлены в таблице 1.
<p align="right">Таблица 1.</p>
<p align="center">Характеристики модуля газа MQ-2</p>

| Наименование | Значение  |
| :----------------- | :-------------: |
| Рабочее напряжение  | 5 В |
| Потребляемый ток (нагревателя)  | 180 мА |
| Диапазон чувствительности  | 300-10000 ppm |
| Газ, для которого нормируется датчик  | изобутан, 1000 ppm |
| Интерфейс  | аналоговый и цифровой |
| Время отклика  | менее 10 с |
| Размеры  | 32 мм x 20 мм |
| Рабочая температура  | от -10 до +50 °C |
| Рабочая влажность воздуха  | не более 95% RH |

Распиновка всех контактов на датчике газа MQ-2 изображена на рисунке 2.
<p align="center">
  <img src="https://github.com/NekitJavaDev/VAS_ARDUINO/blob/master/src/img/december/2_%D1%80%D0%B0%D1%81%D0%BF%D0%B8%D0%BD%D0%BE%D0%B2%D0%BA%D0%B0_%D0%BA%D0%BE%D0%BD%D1%82%D0%B0%D0%BA%D1%82%D0%BE%D0%B2_%D0%BD%D0%B0_%D0%B4%D0%B0%D1%82%D1%87%D0%B8%D0%BA%D0%B5_%D0%B3%D0%B0%D0%B7%D0%B0_MQ-2_%D0%B4%D0%BB%D1%8F_%D0%B8%D0%BD%D1%82%D0%B5%D0%B3%D1%80%D0%B0%D1%86%D0%B8%D0%B8_%D1%81_Arduino.jpg"/>
</p>
<p align="center">Рисунок 2 – Распиновка контактов на датчике газа MQ-2 для интеграции с Arduino</p>

Напряжение аналогового выхода изменяется пропорционально концентрации дыма или газа. Чем выше концентрация газа, тем выше выходное напряжение. 
Логический сигнал калибруется путём нахождения датчика рядом с дымом, который необходимо обнаружить. Далее необходимо вращать 
потенциометр по часовой стрелке (для увеличения чувствительности сенсора), пока не загорится красный светодиод на модуле.

Подключить датчик можно двумя способами: к плате Arduino или напрямую к модулю реле. В первом случае используется аналоговый выход А0 датчика, 
который подключают к любому аналоговому входу на плате Arduino. В случае с реле используют цифровой выход Do на датчике.

В рамках разрабатываемого программно-аппаратного комплекса подключение датчика газа MQ-2 осуществляется напрямую к плате Arduino с помощью аналогового выхода. 
Схема подключения датчика к плате изображена на рисунке 3.
<p align="center">
  <img src="https://github.com/NekitJavaDev/VAS_ARDUINO/blob/master/src/img/december/3_%D1%81%D1%85%D0%B5%D0%BC%D0%B0_%D0%BF%D0%BE%D0%B4%D0%BA%D0%BB%D1%8E%D1%87%D0%B5%D0%BD%D0%B8%D1%8F_%D0%B4%D0%B0%D1%82%D1%87%D0%B8%D0%BA%D0%B0_%D0%B3%D0%B0%D0%B7%D0%B0_MQ-2_%D0%BA_Arduino.jpg"/>
</p>
<p align="center">Рисунок 3 – Схема подключения датчика газа MQ-2 к Arduino/p>

#### 2. Разработка, тестирование и отладка программного обеспечения для разрабатываемого модуля.

После подключения Arduino модуля с герконом остаётся реализовать программную часть для данного модуля и убедиться в её правильной работоспособности. 
Так как все управляемые устройства должны быть взаимозаменяемыми, необходимо разработать универсальную прошивку, работающую на всех устройствах одинаково. 
Первым делом подключаем аналоговый вывод модуля к аналоговому входу 0 (пин A0) на плате. В прошивке указываем препроцессору об 
объявлении переменной SMOKE_SENSOR_PIN:
```C++
    #define SMOKE_SENSOR_PIN A0
```
В функции setup() добавляем, что аналоговый пин A0 работает на вход, то есть будет считывать показания с датчика дыма:
```C++  
    void setup() {
    ------------------------------------------------------------
    pinMode(SMOKE_SENSOR_PIN, INPUT);
    ------------------------------------------------------------
    }
```
Следующим этапом следует добавить считывание показаний в функции loop(), объявив в другой области видимости переменную smoke, 
чтобы не создавать её каждый раз при входе в функцию:
```C++  
    ------------------------------------------------------------
    int smoke = 0;
    void loop() {
    sensor.requestTemperatures();  
    float temperature = sensor.getTempCByIndex(0);
    ------------------------------------------------------------
    smoke = analogRead(SMOKE_SENSOR_PIN);
    delay(50);
    ------------------------------------------------------------
```
Для проверки правильности преобразования показаний, необходимо добавить поле smoke в отправляемую по RS485 объявленную структуру данных:
```C++
    struct SEND_DATA_STRUCTURE {
        int ID;
      	float temp;
      	float voltage;
        int isOpen;
        int smoke;
    };
```
Завершающим этапом отправляем показания, считанные из цепи и записанные в переменную smoke, предварительно записав значение в саму структуру данных:
```C++
    if (ETrx.receiveData()) {    
            txdata.ID = RS485ID;
            txdata.temp = temperature;
            txdata.voltage = voltage;
            txdata.isOpen = isOpen;
            txdata.isOpen = isOpen;
        
            digitalWrite(DIR, HIGH); // включаем передачу
            delay(100);
            Serial.println("----------------");
            Serial.print("Before send by RS485");
            Serial.print("Door is open = ");
            String convertIsOpenDoorValue = isOpen ? "Yes" : "No";
            Serial.println(convertIsOpenDoorValue);
            Serial.println("----------------");
            Serial.print("Smoke value = ");
            Serial.println(txdata.smoke);
            ETtx.sendData(); //отправляем на управляющее устройство
            delay(50);
            digitalWrite(DIR, LOW);  

    }
```
ДДля тестирования работоспособности модуля, нужно поднести магнит к одному из модулей с герконом на расстояние от 1см до 2см, 
и добавить следующие строчки кода в функции loop() сразу после считывания показаний, для их вывода в последовательный монитор порта:
```C++
    Serial.println("----------------");
    Serial.print("isOpen int value = ");
    Serial.println(isOpen);
    Serial.print("After read value");
    String convertIsOpenDoorValue = isOpen ? "Yes" : "No";
    Serial.print("Door is open = ");
    Serial.println(convertIsOpenDoorValue);
    Serial.println("----------------");
```
Тестирование работоспособности модуля осуществляется с помощью имитации утечки газа в помещении. Нормальные значения содержания газа 
в воздухе – 200-300ppm, а значение больше 700ppm означает утечку или задымление. Это возможно реализовать с помощью обычной зажигалки, 
внутри которой содержится сниженный бутан (C4 H10). Для мониторинга показателей газа в текущий момент в систему необходимо добавить 
2 строчки кода в функции loop() сразу после считывания показаний и записи в переменную smoke:
```C++
    Serial.print("Smoke value = ");
    Serial.println(smoke);
```
Модуль успешно прошёл тестирование и была доказана работоспособность и корректность показаний (Рис. 4) (Рис. 5).
<p align="center">
  <img src="https://github.com/NekitJavaDev/VAS_ARDUINO/blob/master/src/img/december/4_%D0%BC%D0%BE%D0%BD%D0%B8%D1%82%D0%BE%D1%80_Serial_(%D0%BF%D0%BE%D1%81%D0%BB%D0%B5%D0%B4%D0%BE%D0%B2%D0%B0%D1%82%D0%B5%D0%BB%D1%8C%D0%BD%D0%BE%D0%B3%D0%BE)_%D0%BF%D0%BE%D1%80%D1%82%D0%B0.jpg"/>
</p>
<p align="center">Рисунок 4 –  Монитор Serial (последовательного) порта</p>

<p align="center">
  <img src="https://github.com/NekitJavaDev/VAS_ARDUINO/blob/master/src/img/december/5_%D0%B0%D0%BF%D0%BF%D0%B0%D1%80%D0%B0%D1%82%D0%BD%D0%BE%D0%B5_%D0%BF%D0%BE%D0%B4%D0%BA%D0%BB%D1%8E%D1%87%D0%B5%D0%BD%D0%B8%D0%B5_%D0%B8_%D1%82%D0%B5%D1%81%D1%82%D0%B8%D1%80%D0%BE%D0%B2%D0%B0%D0%BD%D0%B8%D0%B5_%D0%B2%D1%85%D0%BE%D0%B4%D0%BD%D0%BE%D0%B3%D0%BE_%D0%BD%D0%B0%D0%BF%D1%80%D1%8F%D0%B6%D0%B5%D0%BD%D0%B8%D1%8F.jpg"/>
</p>
<p align="center">Рисунок 5 – Аппаратное подключение и тестирование входного напряжения</p>