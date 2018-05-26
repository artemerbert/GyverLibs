/*
   Пример управления RGB лентой в пространстве HSV одним потенциомтером
   Выход ШИМ инвертирован (255-0) для драйвера
   Потенциометр подключен к А0
   Драйвер подключен к ШИМ пинам!
   Для УНО и НАНО это 3, 5, 6, 9, 10, 11
    _____
   /     \
  |       |
  |       |
  |_______|
   | | | |
   | | | |
   | | | |
     | | |
       |
   B G   R
*/

#include "GyverRGB.h"
GRGB diode(6, 5, 3);  // куда подключены цвета (R, G, B)

void setup() {
  diode.init();
  diode.reverse(1);   // 1 - инвертировать выход (для LED драйверов)
}

void loop() {
  byte H = map(analogRead(0), 0, 1023, 0, 255);
  diode.setHSV(H, 255, 255);
}