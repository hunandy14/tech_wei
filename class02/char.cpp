/*****************************************************************
Name : 
Date : 2017/05/21
By   : CharlotteHonG
Final: 2017/05/21

1. strcat, strcpy, strlen
    - 寫一個能傳入2個CHAR返還相串的
    - 寫一個能傳入兩個CHAR讓1變成2 (1比較長)
    - 寫一個副程式由1.0決定上述兩項功能

1. new
2. void*
3. class封裝

git 介紹
*****************************************************************/
#include <iostream>
#include <cstring>
using namespace std;

char* s;
void copy(const char* str);
//================================================================
int main(int argc, char const *argv[]){
    // 注意長度問題，每次都要要delete後重新new
    copy("ABC");// 把 ABC 複製到 s
    copy("A");// 把 A 複製到 s
    copy("ABCDEF");// 把 A 複製到 s
    return 0;
}
//================================================================
