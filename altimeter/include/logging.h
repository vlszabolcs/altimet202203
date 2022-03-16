String message;
String path;
File file;
bool once_run = true;


bool creat_file_name(){

    if( gps.location.isValid() && once_run){
        String filename = String(gps.date.value())+"_"+String(gps.time.value());
        path = "/" + filename + ".csv";
        String head = "Time,Latitude,Longitude,GPSAltitude,Speed,Pressure,Temperature,Altitude";
        Serial.println(path);
        Serial.println();
        file = SD.open(path, FILE_WRITE);
        if (file) {
            file.println(head);
            file.println(message);
        } else {Serial.println("Failed to open file for writing");}
        once_run= false;
        return true;
    }
    else {
        Serial.println("No file name");
    }
}

void logging_csv(){
    message=gps_message+bmp_message;

    if (file) {
        file.println(message);
        file.flush();
    }
    
}