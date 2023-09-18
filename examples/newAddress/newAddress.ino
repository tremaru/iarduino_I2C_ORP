// ПРИМЕР СМЕНЫ АДРЕСА МОДУЛЯ:                    // * Строки со звёздочкой являются необязательными.
                                                  //
uint8_t newAddress = 0x09;                        //   Назначаемый модулю адрес (0x07 < адрес < 0x7F).
                                                  //
#include <Wire.h>                                 // * Подключаем библиотеку   для работы с аппаратной шиной I2C.
#include <iarduino_I2C_ORP.h>                     //   Подключаем библиотеку   для работы с ORP-метром I2C-flash.
iarduino_I2C_ORP sensor;                          //   Объявляем объект sensor для работы с функциями и методами библиотеки iarduino_I2C_ORP.
                                                  //   Если при объявлении объекта указать адрес, например, iarduino_I2C_ORP sensor(0xBB), то пример будет работать с тем модулем, адрес которого был указан.
void setup(){                                     //
    delay(500);                                   // * Ждём завершение переходных процессов связанных с подачей питания.
    Serial.begin(9600);                           //
    while(!Serial){;}                             // * Ждём завершения инициализации шины UART.
    if( sensor.begin() ){                         //   Инициируем работу с модулем.
        Serial.print("Найден модуль 0x");         //
        Serial.println(sensor.getAddress(), HEX); //   Выводим текущий адрес модуля.
        if( sensor.changeAddress(newAddress) ){   //   Меняем адрес модуля на newAddress.
            Serial.print("Адрес изменён на 0x");  //
            Serial.println(sensor.getAddress(),HEX);// Выводим текущий адрес модуля.
        }else{                                    //
            Serial.println("Адрес не изменён!");  //
        }                                         //
    }else{                                        //
        Serial.println("Модуль не найден!");      //
    }                                             //
}                                                 //
                                                  //
void loop(){                                      //
}                                                 //
                                                  //
//  ПРИМЕЧАНИЕ:                                   //
//  Данный скетч демонстрирует не только          //
//  возможность смены адреса на указанный в       //
//  переменной newAddress, но и обнаружение,      //
//  и вывод текущего адреса модуля на шине I2C.   //