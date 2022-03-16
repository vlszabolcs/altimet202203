#include <Arduino.h>
#include <SD.h>

#include <gps_function.h>
#include <bmp280_function.h>
#include <logging.h>
#include <serialInfo.h>

const int period= 1000;
unsigned long time_now = 0;

void bmp280Setup(){
  if (!bmp.begin(0x76)) {
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring!"));
    while (1);
    }
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     // Operating Mode. 
                  Adafruit_BMP280::SAMPLING_X2,     // Temp. oversampling 
                  Adafruit_BMP280::SAMPLING_X16,    // Pressure oversampling 
                  Adafruit_BMP280::FILTER_X16,      //Filtering. 
                  Adafruit_BMP280::STANDBY_MS_500); // Standby time.

}

void firstSetup(){
  //Read data form SD Card
  if (!SD.begin()) {
    Serial.println("Card Mount Failed");
    return;
  }
  File fileRead = SD.open("/lastPresCalc.txt");
  if (fileRead) {
    presCorrig = fileRead.parseFloat();
    Serial.println(presCorrig);
    fileRead.close();
  }
  else {
    Serial.println("Error to open last pressure calc.");
  }
}


void setup() {
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, 16, 17);
  bmp280Setup();
  firstSetup();

}

void loop() {

  //gps_data();
 gps_nmea_read();

  //bmp280_data();

  /*if(millis() > time_now + period){
    time_now = millis();

    //gps_data_write();
    //bmp280_write();

    if(creat_file_name()){
      logging_csv();
    }
    else{
      Serial.println("Not logging");
    }
  }*/

}

