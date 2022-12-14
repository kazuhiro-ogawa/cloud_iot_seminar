#include <M5Stack.h>

#include "Aesht3x.h"
#include "Localtime.h"
#include "WifiConnect.h"
#include "M5toFirebase.h"

Aesht3x sht3x = Aesht3x();
Localtime lcltime = Localtime();
WifiConnect wificonnect = WifiConnect();
M5toFirebase m5fb = M5toFirebase();

void setup() {
  M5.begin();
  wificonnect.init();
  m5fb.init();
  
  M5.Lcd.setTextSize(2);
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.println("Click the right button to send data");
  
  sht3x.init();
  lcltime.init();
}

void loop() {
  M5.update();

  if (M5.BtnA.wasPressed())
  {

  }
  if (M5.BtnB.wasPressed())
  {

  }
  if (M5.BtnC.wasPressed())
  {
    M5.Lcd.clear();
    M5.Lcd.setTextSize(2);
    M5.Lcd.setCursor(0, 0);
    M5.Lcd.println("Click the right button to send data");
    
    float temperature = 0;
    float humidity = 0;

    sht3x.getTempHumi(&temperature, &humidity);

    String strpass = "";
    char pathtime[64];
    lcltime.getTimePath(pathtime);
    strpass = pathtime;

    m5fb.setData(strpass, temperature, humidity);

    M5.Lcd.setCursor(0, 100);
    M5.Lcd.println("Path : " + strpass);
    M5.Lcd.print("Temperature : ");
    M5.Lcd.setTextColor(ORANGE);
    M5.Lcd.println(String(temperature) + " deg");
    M5.Lcd.setTextColor(WHITE);
    M5.Lcd.print("Humidity : ");
    M5.Lcd.setTextColor(CYAN);
    M5.Lcd.println(String(humidity) + " percent");
    M5.Lcd.setTextColor(WHITE);
  }
}
