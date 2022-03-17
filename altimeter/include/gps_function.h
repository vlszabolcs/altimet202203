#include <TinyGPS++.h>
TinyGPSPlus gps;


double gpsLon;
double gpsLat;
double gpsAlti;
double gpsSpd;
int    gpsDate;
int    gpsTime;
char c ;
String gps_message;

void gps_nmea_read(){
    if (Serial2.available()){
    c = Serial2.read();   
    //Serial.write(c);
    gps.encode(c);
  }
}

bool gps_data(){
    gps_nmea_read();
    
    gpsDate = gps.date.value();
    gpsTime = gps.time.value();
    gpsAlti = gps.altitude.meters();
    gpsLon =  gps.location.lat();
    gpsLat =  gps.location.lng();
    gpsSpd =  gps.speed.kmph();
  

    gps_message=    String(gpsDate) + "_" +
                    String(gpsTime) + "," + 
                    String(gpsLon,6)  + "," +
                    String(gpsLat,6)  + "," +
                    String(gpsAlti,2) + "," +
                    String(gpsSpd)  + ",";

    return gps.location.isValid();
}