// ПРИМЕР ПОЛУЧЕНИЯ НАСТРОЕК МОДУЛЯ:              // * Строки со звёздочкой являются необязательными.
                                                  //
#include <Wire.h>                                 // * Подключаем библиотеку   для работы с аппаратной шиной I2C.
#include <iarduino_I2C_ORP.h>                     //   Подключаем библиотеку   для работы с ORP-метром I2C-flash.
iarduino_I2C_ORP sensor(0x09);                    //   Объявляем объект sensor для работы с функциями и методами библиотеки iarduino_I2C_ORP, указывая адрес модуля на шине I2C.
                                                  //   Если объявить объект без указания адреса (iarduino_I2C_ORP sensor;), то адрес будет найден автоматически.
void setup(){                                     //
     delay(500);                                  // * Ждём завершение переходных процессов связанных с подачей питания.
     Serial.begin(9600);                          //   Инициируем работу с шиной UART для передачи данных в монитор последовательного порта на скорости 9600 бит/сек.
     sensor.begin();                              //   Инициируем работу с ORP-метром I2C-flash.
     Serial.print( "Eh = "             );         //
     Serial.print( sensor.getKnownEh() );         //   Выводим требуемый ОВП жидкости для калибровки модуля кнопкой от 0 до ±1600 мВ.
     Serial.print( "мВ.\r\n"           );         //
     Serial.print( "K = "              );         //
     Serial.print( sensor.getK()     ,4);         //   Выводим поправочный коэффициент от 0,0001 до 6,5535.
     Serial.print( "\r\n"              );         //
}                                                 //
                                                  //
void loop(){}                                     //