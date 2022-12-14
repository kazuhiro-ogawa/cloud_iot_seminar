#include <Arduino.h>
#include <ArduinoJson.h>
#include <IOXhop_FirebaseESP32.h>
#include <IOXhop_FirebaseStream.h>
#include "M5toFirebase.h"

// 初期化処理
void M5toFirebase::init(){
  // Firebase初期化
  Firebase.begin(FIREBASE_DATABASE_URL);
}

void M5toFirebase::setData(String path, float t, float h)
{
    Firebase.setFloat(path + "/temperature", t);
    Firebase.setFloat(path + "/humidity", h);
}
