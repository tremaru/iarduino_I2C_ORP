// ПРИМЕР ЧТЕНИЯ ДАННЫХ С АНАЛОГОВОГО ВХОДА:        // * Строки со звёздочкой являются необязательными.
                                                    //
// ORP-метр, FLASH-I2C:                             //   https://iarduino.ru/shop/Sensory-Datchiki/orp-metr-flash-i2c.html
// Информация о подключении модулей к шине I2C:     //   https://wiki.iarduino.ru/page/i2c_connection/
// Информация о модуле и описание библиотеки:       //   https://wiki.iarduino.ru/page/orp-flash/
                                                    //
float K = 1;                                        //   Поправочный коэффициент (значение по умолчанию).
                                                    //
void setup(){                                       //
     delay(500);                                    // * Ждём завершение переходных процессов связанных с подачей питания.
     Serial.begin(9600);                            //   Инициируем работу с шиной UART для передачи данных в монитор последовательного порта на скорости 9600 бит/сек.
}                                                   //
                                                    //
void loop(){                                        //
     int Vout = (int)(analogRead(A0)*5.0f/1.0240f); //   Получаем напряжение на входе A0 в мВ.
     int Eh   = (int)(K*(float)(Vout-1650));        //   Вычисляем Eh.
     Serial.print( "Eh = "   );                     //
     Serial.print( Eh         );                    //   Выводим ОВП жидкости.
     Serial.print( " мВ.\r\n" );                    //
     delay(1000);                                   //
}                                                   //
                                                    //
/*   Значения K и Vout можно прочитать по шине I2C  //
 *   используя библиотеку iarduino_I2C_ORP:         //
 *   float K    = sensor.getK();                    //
 *   float Vout = sensor.getVout();                 //
 *   float Eh   = sensor.getEh();                   //
 */