#include <Arduino.h>
#include "WifiConnect.h"
#include <WiFi.h>
#include <WiFiAP.h>
#include <WiFiClient.h>
#include <WiFiGeneric.h>
#include <WiFiMulti.h>
#include <WiFiScan.h>
#include <WiFiServer.h>
#include <WiFiSTA.h>
#include <WiFiType.h>
#include <WiFiUdp.h>

// 初期化処理
void WifiConnect::init(){
  
  // Wi-Fi接続
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
  Serial.println();

  // WiFi Connected
  Serial.println("\nWiFi Connected.");
  Serial.println(WiFi.localIP());
  
}
