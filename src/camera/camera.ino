

//#include <EasyTransfer.h>
//#include <SoftwareSerial.h>
// #include <OneWire.h>
// #include <DallasTemperature.h>


//#define RS485ID 2 //номер устройства
//#define DIR 10 //RS485
// #define ONE_WIRE_BUS 5 //датчик температуры (цифровой вход)
// #define GERKON_PIN 2 //геркон (цифровой вход)
// #define VOLTAGE_PIN A4 //датчик измерения напряжения (Voltage Sensor)
// #define SMOKE_SENSOR_PIN A0 //датчик дыма
// #define R1_VOLTAGE 30000.0 //R1(Voltage Sensor)
// #define R2_VOLTAGE 7500.0 //R2(Voltage Sensor) 
//#define U_REF 5.0 //опорное напряжение (Voltage Sensor) 
//float Uin = U_REF * ((R1_VOLTAGE + R2_VOLTAGE) / R2_VOLTAGE); //вычисление входного напряжения (max) (Voltage Sensor) 
// float Uin = HIGH * ((R1_VOLTAGE + R2_VOLTAGE) / R2_VOLTAGE); //вычисление входного напряжения (max) (Voltage Sensor) 

//Подключение камеры
// камера - Arduino Uno
//#define 3,3V - 3,3V
//#define GND - GND
//#define SCL - D13 //sioc - system clock
//#define SDA - A4 //siod - data transfer
//#define VS - D12 //vsync
//#define MS - пусто? //href надо подключить
//#define PSLK - D2
//#define MCLK - D3
//#define D7 - D7
//#define D6 - D6
//#define D5 - D4
//#define D4 - D3
//#define D3 - A3
//#define D2 - A2
//#define D1 - A1
//#define D0 - A0
//#define RESET - 3,3V
//#define PWDN - GND
//------------------------


// Посмотреть пины на href и vsync
// #define href 21 //надо подключить
//#define vsync 12
//#define d0 A0
//#define d1 A1
//#define d2 A2
//#define d3 A3
//#define d4 3
//#define d5 4
//#define d6 6
//#define d7 7

// Adafruit_VC0706 cam = Adafruit_VC0706(&cameraconnection);


// OneWire oneWire(ONE_WIRE_BUS);
// DallasTemperature sensor(&oneWire);

//SoftwareSerial RS485Serial(8, 9);
//
//EasyTransfer ETtx, ETrx;
//
//struct SEND_DATA_STRUCTURE {
//    // int ID;
//    // float temp;
//    // int isOpen;
//    // float voltage;
//    // int smoke;
//    //camera
//};
//
//struct RECEIVE_DATA_STRUCTURE {
//  int ID;
//  int cmd;
//};
//
//RECEIVE_DATA_STRUCTURE rxdata;
//SEND_DATA_STRUCTURE txdata;

#include <ov7670_reg.h>

void setup() {


}

void loop() {
  
}




//void setup() {
//  RS485Serial.begin(4800);
//  // Serial.begin(4800);
//  ETrx.begin(details(rxdata), &RS485Serial);
//  ETtx.begin(details(txdata), &RS485Serial);
//  pinMode(DIR, OUTPUT);
//  digitalWrite(DIR, LOW);
//  pinMode(href, INPUT);
//  pinMode(vsync, INPUT);
//
//
//  Serial.begin(9600);
//  pinMode(d0, INPUT);
//  pinMode(d1, INPUT);
//  pinMode(d2, INPUT);
//  pinMode(d3, INPUT);
//  pinMode(d4, INPUT);
//  pinMode(d5, INPUT);
//  pinMode(d6, INPUT);
//  pinMode(d7, INPUT);
//
//
//  attachInterrupt (3, empiezabarrer, RISING);
  // pinMode(GERKON_PIN, INPUT);
  // digitalWrite(GERKON_PIN, HIGH);
  // pinMode(VOLTAGE_PIN, INPUT);
  // pinMode(SMOKE_SENSOR_PIN, INPUT);
  
  // sensor.begin();
  // sensor.setResolution(12);
//}

//void empiezabarrer(){
//
//// read 8 bits (1 byte) and print to serial
//
//int Bit1;
//int Bit2;
//int Bit3;
//int Bit4;
//int Bit5;
//int Bit6;
//int Bit7;
//int Bit8;
//
//Bit1= digitalRead(d0);
//Bit2= digitalRead(d1);
//Bit3= digitalRead(d2);
//Bit4= digitalRead(d3);
//Bit5= digitalRead(d4);
//Bit6= digitalRead(d5);
//Bit7= digitalRead(d6);
//Bit8= digitalRead(d7);
//
//Serial.print(Bit1);
//Serial.print(Bit2);
//Serial.print(Bit3);
//Serial.print(Bit4);
//Serial.print(Bit5);
//Serial.print(Bit6);
//Serial.print(Bit7);
//Serial.print(Bit8);
//Serial.println(" ");
//
////detachInterrupt(3);
//}

// int smoke = 0;

//void loop() {  
  // sensor.requestTemperatures();  
  // float temperature = sensor.getTempCByIndex(0);
  // int isOpen = digitalRead(GERKON_PIN);
  // float voltage = (analogRead(VOLTAGE_PIN) * Uin) / 1024.0 / 10;
  // smoke = analogRead(SMOKE_SENSOR_PIN); // 200-300 нормальная концентрация, >700 - WARNING!
  
//  Serial.print("After read value");
//  Serial.print("Smoke value = ");
//  Serial.println(smoke);
  
//  delay(50);
  
//  if (ETrx.receiveData()) {    
    // txdata.ID = RS485ID;
    // txdata.temp = temperature;
    // txdata.isOpen = isOpen;
    // txdata.voltage = voltage;
    // txdata.smoke = smoke;
    // txdata.camera = camera;
    
//    digitalWrite(DIR, HIGH); // включаем передачу
//    delay(100);
//    Serial.println("----------------");
//    Serial.print("Before send by RS485");
//    Serial.print("Device ID = ");
//    Serial.println(RS485ID);
    // Serial.print("Temperature = ");
    // Serial.println(temperature);
    // Serial.print("Door is open = ");
    // String convertIsOpenDoorValue = isOpen ? "Yes" : "No";
    // Serial.println(convertIsOpenDoorValue);
    // Serial.print("Smoke value = ");
    // Serial.println(txdata.smoke);
//    Serial.println("----------------");
//
//    ETtx.sendData(); //отправляем на управляющее устройство
//    delay(50);
//    digitalWrite(DIR, LOW);

    // the flowing lines captures d0 to d7 directly (all the time)

	/*
	int Bit1;
	int Bit2;
	int Bit3;
	int Bit4;
	int Bit5;
	int Bit6;
	int Bit7;
	int Bit8;

	Bit1= digitalRead(d0);
	Bit2= digitalRead(d1);
	Bit3= digitalRead(d2);
	Bit4= digitalRead(d3);
	Bit5= digitalRead(d4);
	Bit6= digitalRead(d5);
	Bit7= digitalRead(d6);
	Bit8= digitalRead(d7);

	Serial.print(Bit1);
	Serial.print(Bit2);
	Serial.print(Bit3);
	Serial.print(Bit4);
	Serial.print(Bit5);
	Serial.print(Bit6);
	Serial.print(Bit7);
	Serial.print(Bit8);
	Serial.println(" ");
	*/

//  }
//}

/**********************FUNCTION1()*********************/
// void takingPicture(){
//           if (cam.begin()) {
//             Serial.println("Camera Found:");
//           } else {
//             Serial.println("No camera found?");
//             return;
//           }
//           char *reply = cam.getVersion();
//           if (reply == 0) {
//             Serial.print("Failed to get version");
//           } else {
//             Serial.println("-----------------");
//             Serial.print(reply);
   
//             Serial.println("-----------------");
//           }
//           //cam.setImageSize(VC0706_640x480);        // biggest
//           cam.setImageSize(VC0706_320x240);        // medium
//           //cam.setImageSize(VC0706_160x120);          // small

//           uint8_t imgsize = cam.getImageSize();
//           Serial.print("Image size: ");
//           if (imgsize == VC0706_640x480) Serial.println("640x480");
//           if (imgsize == VC0706_320x240) Serial.println("320x240");
//           if (imgsize == VC0706_160x120) Serial.println("160x120");

//           Serial.println("Snap in 3 secs...");
//           delay(3000);
//             cam.takePicture();
//             Serial.println("taking picture");
          
//             file.open("IMAGE.jpg", O_RDWR | O_CREAT);
           
//             uint16_t jpglen = cam.frameLength();  
//             pinMode(8, OUTPUT);
            
//             byte wCount = 0; 
//             while (jpglen > 0) {
//                uint8_t *buffer;
//                uint8_t bytesToRead = min(32, jpglen); 
//                buffer = cam.readPicture(bytesToRead);
//               file.write(buffer, bytesToRead);
//                if(++wCount >= 64) { 
//                   Serial.print('.');
//                   wCount = 0;
//                }
//               jpglen -= bytesToRead;
//             }
//             file.close();
//             Serial.println("end of taking picture");
// }
//  /**********************FUNCTION2()*********************/
// void removePicture(){
//   file.open("IMAGE.jpg", O_READ | O_WRITE);
//   file.remove();
// }
