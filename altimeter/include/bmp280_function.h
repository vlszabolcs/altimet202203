#include <Adafruit_BMP280.h>
Adafruit_BMP280 bmp;

float pres;
float temp ;
float presAlti ;
float presCorrig;
String  bmp_message;

void bmp280_data () {
  
  pres = bmp.readPressure() / 100.0F;
  temp = bmp.readTemperature()-2;
  presAlti = bmp.readAltitude(presCorrig);
  bmp_message= String(pres)  + "," + String(temp) + "," + String(presAlti);
  
}