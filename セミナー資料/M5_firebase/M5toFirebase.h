/* インクルードガード */
#pragma once

#define FIREBASE_DATABASE_URL "https://を除いたfirebaseのURLを貼り付け"

class M5toFirebase     // classの定義
{
  private :               // privateはクラス内からしかアクセスできない
    
  public :                // publicはどこからでもアクセス可能
    void init();
    void setData(String path, float t, float h);
};
