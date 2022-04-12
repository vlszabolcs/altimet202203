#include <TinyGPS++.h>
TinyGPSPlus gps;


double gpsLon, gpsLat;
float gpsAlti,gpsSpd;
int   gpsYear,gpsMonth,gpsDay,gpsHour,gpsMinute, gpsSecond;
String gpsDtime;
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
    
    gpsYear = gps.date.year();
    gpsMonth=gps.date.month();
    gpsDay=gps.date.day();
    gpsHour=gps.time.hour();
    gpsMinute=gps.time.minute();
    gpsSecond=gps.time.second();
    gpsDtime= String(gps.date.year())+
              String(gps.date.month())+
              String(gps.date.day())+
              String(gps.time.hour())+
              String(gps.time.minute())+
              String(gps.time.second());
    gpsAlti = gps.altitude.meters();
    gpsLon =  gps.location.lat();
    gpsLat =  gps.location.lng();
    gpsSpd =  gps.speed.kmph();
  

    gps_message=    
                    gpsDtime + "," + 
                    String(gpsLon,10)  + "," +
                    String(gpsLat,10)  + "," +
                    String(gpsAlti,2) + "," +
                    String(gpsSpd)  + ",";

    return gps.location.isValid();
}