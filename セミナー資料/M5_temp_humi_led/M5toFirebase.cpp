#include <Arduino.h>
#include <ArduinoJson.h>
#include <IOXhop_FirebaseESP32.h>
#include <IOXhop_FirebaseStream.h>
#include "M5toFirebase.h"

#define LED_PIN 16

// 初期化処理
void M5toFirebase::init(){
  // Firebase初期化
  Firebase.begin(FIREBASE_DATABASE_URL);
  digitalWrite(LED_PIN, Firebase.getBool("/M5Stack/led"));
  
}

void M5toFirebase::setData(String path, float t, float h)
{
  Firebase.setFloat(path + "/temperature", t);
  Firebase.setFloat(path + "/humidity", h);
}

void M5toFirebase::startFirebaseStream()
{
  Firebase.stream("", [](FirebaseStream stream) {
    if (stream.getEvent() == "put" && stream.getPath() == "/led") {
        digitalWrite(LED_PIN, stream.getDataBool());
    }else if(stream.getEvent() == "patch" && stream.getPath() == "/M5Stack"){
        digitalWrite(LED_PIN, stream.getDataBool());
    }
  });
}
