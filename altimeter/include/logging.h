String head = "Time,Latitude,Longitude,GPSAltitude,Speed,Pressure,Temperature,Altitude";
String message;
String path;
File file;
bool once_run = false;
bool file_name_exist= false;

bool creat_directory(String directory_name){
    bool success=false;
    if (!SD.exists("/"+directory_name))
    {
        if (SD.mkdir("/"+directory_name)){
            Serial.println(directory_name+" is directory CREATED");
            success = true;
        }
        else{
            Serial.println("Directory creation is FAILD");
        }

    }
    else {
        Serial.println(directory_name+" is exists!");
        success=true;
    }
    return success;
}

bool creat_file_name(){

    if( gps.location.isValid() && !once_run){
      
       if(gps.date.isValid() && gps.time.isValid()){ 
        
            if (creat_directory(String(gpsDate))){

                path ="/"+String(gpsDate)+ "/" + String(gpsDate)+"_"+String(gpsTime) + ".csv";
                
                Serial.println(path);

                file = SD.open(path, FILE_WRITE);
                
                if (file) {
                    file.println(head);
                } else {Serial.println("Failed to open file for writing");}
                
                once_run = true;
            
            }
        }
    
    } else if (gps.location.isValid() && once_run){
        Serial.print("file name is: ");
        Serial.println(path);
    
    } else{
        Serial.println("No file name");
    
        Serial.println(gps_message);
        Serial.println(bmp_message);
    }

    return once_run;
}


void logging_csv(){
    message=gps_message+bmp_message;

    if (file) {
        file.println(message);
        file.flush();
        Serial.println(message);
        Serial.println("Logging run!");
    }
    
}

