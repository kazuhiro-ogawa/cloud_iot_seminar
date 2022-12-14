#include <Arduino.h>
#include "Aesht3x.h"
#include <Wire.h>
#include <M5Stack.h>

// 初期化処理
void Aesht3x::init(){
  Wire.begin();
  delay(500); 
  init_Aesht3x();
}

// Ae-sht3xの初期化処理
void Aesht3x::init_Aesht3x() {
  Wire.beginTransmission(SHT31_ADDR);     // I2Cスレーブ「Arduino Uno」のデータ送信開始
  Wire.write(SOFT_RESET_MSB);             // ソフトリセットMSB
  Wire.write(SOFT_RESET_LSB);             // ソフトリセットLSB
  Wire.endTransmission();                 // I2Cスレーブ「Arduino Uno」のデータ送信終了
  delay(500);                             // 500msec待機(0.5秒待機)

  Wire.beginTransmission(SHT31_ADDR);     // I2Cスレーブ「Arduino Uno」のデータ送信開始 
  Wire.write(CLEAR_STATUS_REGISTER_MSB);  // ステータスレジスタ消去MSB
  Wire.write(CLEAR_STATUS_REGISTER_LSB);  // ステータスレジスタ消去LSB
  Wire.endTransmission();                 // I2Cスレーブ「Arduino Uno」のデータ送信終了
  delay(500);                             // 500msec待機(0.5秒待機)
}

void Aesht3x::getTempHumi(float* temperature, float* humidity){
  
    //変数宣言
    unsigned int dac[6];
    unsigned int t , h;
  
    Wire.beginTransmission(SHT31_ADDR);//I2Cスレーブ「Arduino Uno」のデータ送信開始
    Wire.write(SINGLE_SHOT_HIGH_MSB);//単発測定・繰り返し精度レベル高・クロックストレッチ無効 MSB
    Wire.write(SINGLE_SHOT_HIGH_LSB);//単発測定・繰り返し精度レベル高・クロックストレッチ無効 LSB
    Wire.endTransmission();//I2Cスレーブ「Arduino Uno」のデータ送信終了
    delay(300);//300msec待機(0.3秒待機)
  
    Wire.requestFrom(SHT31_ADDR, 6);//dI2Cデバイス「SHT31」に6Byteのデータ要求
    for (int i=0; i<6; i++){
        dac[i] = Wire.read();//dacにI2Cデバイス「SHT31」のデータ読み込み
    }
    Wire.endTransmission();//I2Cスレーブ「Arduino Uno」のデータ送信終了
  
    t = (dac[0] << 8) | dac[1];//1Byte目のデータを8bit左にシフト、OR演算子で2Byte目のデータを結合して、tに代入
    *temperature = ((float)(t) * 175 / 65535.0) - 45.0;//温度の計算、temperatureに代入
    h = (dac[3] << 8) | dac[4];////4Byte目のデータを8bit左にシフト、OR演算子で5Byte目のデータを結合して、hに代入
    *humidity = ((float)(h) / 65535.0) * 100.0;//湿度の計算、humidityに代入
}
