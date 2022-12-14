#include <M5Stack.h>

#include "WifiConnect.h"
#include "M5toFirebase.h"

WifiConnect wificonnect = WifiConnect();
M5toFirebase m5fb = M5toFirebase();

void setup() {
  M5.begin();
  wificonnect.init();
  m5fb.init();
  
  M5.Lcd.setTextSize(3);
  M5.Lcd.setCursor(10, 100);
  M5.Lcd.println("Button Click!");
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
    float temperature = 30;
    float humidity = 65;

    String strpass = "/M5Stack";
    m5fb.setData(strpass, temperature, humidity);
  }
}
