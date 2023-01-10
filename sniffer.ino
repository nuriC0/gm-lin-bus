#include <SPI.h>
#include <SD.h>

//
//  In example below, i am using Arduinos HARDWARE serial to get data from LIN BUS and writing data to SD card
//
// Code could be modified to use SoftwareSerial and then you could view data thru Arduino IDE or Putty
//
//  Following PDF will be your friend in understanding data you see from LIN BUS
//  https://www.cs-group.de/wp-content/uploads/2016/11/LIN_Specification_Package_2.2A.pdf
//
//  See exampleLog.txt for example what gets created by following code.

int cnt = 0;  //simple counter, used in loop
void setup()
{

  Serial.begin(10417); //i have Arduino connected directly to LIN BUS module
  while (!Serial) {
    ; // wait for serial port to connect
  }
  
  //we will write all sniffer data to SD card, easier for later analysis
  SD.begin(4);
  myFile = SD.open("log_data.txt", FILE_WRITE);

  myFile.println("Started...");
  myFile.flush();

}

void loop()
{

  while(Serial.available()){
    
    int v = Serial.read();

    if (v == 0){
      myFile.println("");//mostly for easier reading later on
    }
    myFile.print(String(v, HEX));//print it as HEX in file
    myFile.print(", ");

    cnt = cnt+1;
    if (cnt > 200){
      cnt=0;
      myFile.flush();// there must be a better way, but this writes it to SD card from time to time
    }
  }

}
