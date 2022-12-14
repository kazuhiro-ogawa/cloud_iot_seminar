/* インクルードガード */
#pragma once

#define WIFI_SSID "ここに使用するWIFIのSSIDを記述"
#define WIFI_PASSWORD "こっちはパスワードです"

class WifiConnect     // classの定義
{
  private :               // privateはクラス内からしかアクセスできない
    
  public :                // publicはどこからでもアクセス可能
    void init();
};
