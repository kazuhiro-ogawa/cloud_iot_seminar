#include <Arduino.h>
#include <M5Stack.h>
#include "Localtime.h"

const char* ntpServer = "ntp.nict.jp";
const long  gmtOffset_sec = 3600 * 9;
const int   daylightOffset_sec = 0;

// 初期化処理
void Localtime::init(){
  // init and get the time
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
}

void Localtime::getTime(struct tm *timeptr)
{
  if(!getLocalTime(timeptr)){
    M5.Lcd.println("Failed to obtain time");
  }
  return;
}

void Localtime::getTimePath(char* timepath)
{
    struct tm ltime;
    getTime(&ltime);
    //char path_t[64];
    sprintf(timepath, "/M5Stack/%04d-%02d-%02d/%02d:%02d", 
                    ltime.tm_year + 1900, ltime.tm_mon + 1, ltime.tm_mday, ltime.tm_hour, ltime.tm_min);
    Serial.print("timepath : ");
    Serial.println(timepath);
}
