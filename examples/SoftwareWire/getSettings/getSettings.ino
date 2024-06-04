// ПРИМЕР ПОЛУЧЕНИЯ НАСТРОЕК МОДУЛЯ:                         // * Строки со звёздочкой являются необязательными.
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
     Serial.print( "Eh = "             );                    //
     Serial.print( sensor.getKnownEh() );                    //   Выводим требуемый ОВП жидкости для калибровки модуля кнопкой от 0 до ±1600 мВ.
     Serial.print( "мВ.\r\n"           );                    //
     Serial.print( "K = "              );                    //
     Serial.print( sensor.getK()     ,4);                    //   Выводим поправочный коэффициент от 0,0001 до 6,5535.
     Serial.print( "\r\n"              );                    //
}                                                            //
                                                             //
void loop(){}                                                //