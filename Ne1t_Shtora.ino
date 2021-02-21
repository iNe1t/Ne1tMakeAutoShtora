// Code by iNe1t

#include <Servo.h>
#include "IRremote.h"

Servo servo_main; // объявляем переменную servo_main типа Servo
IRrecv irrecv(8); // указываем вывод, к которому подключен приемник
// FB58A7 - Вверх
//FB12ED - Вниз

decode_results results;

void setup() {
  servo_main.attach(5);
  Serial.begin(9600); // выставляем скорость COM порта
  irrecv.enableIRIn(); // запускаем прием
}

void loop() {
  if ( irrecv.decode( &results)) { // если данные пришли (&results )
    Serial.println( results.value, HEX ); // печатаем данные
     switch (results.value) {
      case 0x19621025:// это для кнопки вверх
      servo_main.write(180);
      break;
      case 0x92DB79C9: // это для кнопки вниз
      servo_main.write(0);
      break;
     }
    irrecv.resume();
    
  }
}
