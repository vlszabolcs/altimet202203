String incomingByte;
String valami;

void gps_nmea_write(){
    Serial.write(c);
}

void gps_data_write(){
    Serial.println(gps_message);
}


void bmp280_write(){
    Serial.println(bmp_message);
}

/*
void serial_read(){
    if (Serial.available()){
        incomingByte = Serial.readString();
        
       valami= incomingByte.strin(":");

        Serial.println(incomingByte);
    }

}

void device_contrlol(){


}*/