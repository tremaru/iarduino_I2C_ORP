// ПРИМЕР КАЛИБРОВКИ МОДУЛЯ:                                 // * Строки со звёздочкой являются необязательными.
// Требуется установить библиотеку <iarduino_I2C_Software.h> //   https://iarduino.ru/file/627.html
                                                             //
// ORP-метр, FLASH-I2C:                                      //   https://iarduino.ru/shop/Sensory-Datchiki/orp-metr-flash-i2c.html
// Информация о подключении модулей к шине I2C:              //   https://wiki.iarduino.ru/page/i2c_connection/
// Информация о модуле и описание библиотеки:                //   https://wiki.iarduino.ru/page/orp-flash/
                                                             //
#include <iarduino_I2C_Software.h>                           //   Подключаем библиотеку для работы с программной шиной I2C, до подключения библиотеки iarduino_I2C_ORP.
SoftTwoWire sWire(3,4);                                      //   Создаём объект программной шины I2C указав выводы которым будет назначена роль линий: SDA, SCL.
                                                             //
#include <iarduino_I2C_ORP.h>                                //   Подключаем библиотеку   для работы с ORP-метром I2C-flash.
iarduino_I2C_ORP sensor(0x09);                               //   Объявляем объект sensor для работы с функциями и методами библиотеки iarduino_I2C_ORP, указывая адрес модуля на шине I2C.
                                                             //   Если объявить объект без указания адреса (iarduino_I2C_ORP sensor;), то адрес будет найден автоматически.
void setup(){                                                //
     delay(500);                                             // * Ждём завершение переходных процессов связанных с подачей питания.
     Serial.begin(9600);                                     //   Инициируем работу с шиной UART для передачи данных в монитор последовательного порта на скорости 9600 бит/сек.
     sensor.begin(&sWire);                                   //   Инициируем работу с ORP-метром, указав ссылку на объект для работы с шиной I2C на которой находится модуль (по умолчанию &Wire).
     Serial.print("ОПУСТИТЕ ДАТЧИК В ");                     //
     Serial.print("КАЛИБРОВОЧНУЮ ЖИДКОСТЬ.\r\n");            //
     delay(300000);                                          //   Ждём 5 минут.
     sensor.setCalibration(246);                             //   Выполняем калибровку указав ОВП калибровочной жидкости (в примере 246 мВ).
     while(!sensor.getCalibration()){delay(500);}            //   Ждём завершение калибровки.
     if( sensor.getCalibration()>0 ){                        //
         Serial.println("КАЛИБРОВКА ВЫПОЛНЕНА!");            //
     }else{                                                  //
         Serial.println("ОШИБКА КАЛИБРОВКИ!");               //
     }                                                       //
}                                                            //
                                                             //
void loop(){}                                                //