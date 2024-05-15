// ПРИМЕР СМЕНЫ АДРЕСА МОДУЛЯ:                    // * Строки со звёздочкой являются необязательными.
                                                  //
// ORP-метр, FLASH-I2C:                           //   https://iarduino.ru/shop/Sensory-Datchiki/orp-metr-flash-i2c.html
// Информация о подключении модулей к шине I2C:   //   https://wiki.iarduino.ru/page/i2c_connection/
// Информация о модуле и описание библиотеки:     //   https://wiki.iarduino.ru/page/orp-flash/
                                                  //
// Данный скетч демонстрирует не только           //
// возможность смены адреса на указанный в        //
// переменной newAddress, но и обнаружение,       //
// и вывод текущего адреса модуля на шине I2C.    //
                                                  //
// Библиотека <iarduino_I2C_ORP.h> предназначена  //
// для работы с ORP-метрами I2C-flash             //
// и меняет только их адреса.                     //
// Но, в разделе Файл/Примеры/.../findSortDevices //
// находятся примеры смены и сортировки адресов   //
// любых модулей iarduino серии Flash I2C.        //
                                                  //
uint8_t newAddress = 0x09;                        //   Назначаемый модулю адрес (0x07 < адрес < 0x7F).
                                                  //
#include <Wire.h>                                 //   Подключаем библиотеку   для работы с аппаратной шиной I2C, до подключения библиотеки iarduino_I2C_ORP.
#include <iarduino_I2C_ORP.h>                     //   Подключаем библиотеку   для работы с ORP-метром I2C-flash.
iarduino_I2C_ORP sensor;                          //   Объявляем объект sensor для работы с функциями и методами библиотеки iarduino_I2C_ORP.
                                                  //   Если при объявлении объекта указать адрес, например, iarduino_I2C_ORP sensor(0xBB), то пример будет работать с тем модулем, адрес которого был указан.
void setup(){                                     //
    delay(500);                                   // * Ждём завершение переходных процессов связанных с подачей питания.
    Serial.begin(9600);                           //
    while(!Serial){;}                             // * Ждём завершения инициализации шины UART.
    if( sensor.begin(&Wire) ){                    //   Инициируем работу с модулем, указав ссылку на объект для работы с шиной I2C на которой находится модуль (Wire, Wire1, Wire2 ...).
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
