/* インクルードガード */
#pragma once

class Localtime     // classの定義
{
  private :               // privateはクラス内からしかアクセスできない
    
  public :                // publicはどこからでもアクセス可能
    void init();
    void getTime(struct tm *timeptr);
    void getTimePath(char* timepath);
};
