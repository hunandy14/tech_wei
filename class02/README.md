2017/05/21 威
===
###### tags: `teaching`

- [time=Sun, May 21, 2017 4:23 PM]

## 作業
```cpp
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
```

長度問題指的是第一次存入 ABC new 一個長度 4 的
第二次存入要 delete s 重新 new 一個長度為 2 的
> 操作的時候小心不要把指標丟了。

</br></br></br>

## 技巧
- 盡可能減少宣告
- 總是為你的字串保留結束符長度
- 總是注意的字串是否有結束符
- new 有方框 (陣列[]) 就配有方框的 delete
- 一個 fun 內有 new 就必須在 main 接收他

</br></br></br>

## 今天遇到的坑與技巧
### 傳回型態
```cpp
void fun(){
    char* p = new...;
    return p;
}
```
返回型態不符，可以修改 void 也可以修改 char* 看你要回傳什麼
這裡因為要回傳 char* 所以應該修改 void

</br>

### 盡可能減少宣告
長度相加
```cpp
size_t len1 = strlen(str1);
size_t len2 = strlen(str2);
size_t len3 = len1+len2;
```

如果沒用到就減少宣告

```cpp
size_t len = strlen(str1) + strlen(str2);
```

怕寫太長拆兩行寫 `+=`
另外這種方式效能會略優於上面

```cpp
size_t len = strlen(str1);
len += strlen(str2);
```

</br>

### 總是為你的字串保留結束符長度
如果你算出來的字串上長度是 3+3=6 那新的字串長度應為 7
```cpp
char* buff = new char[len+1];
```

</br>

### 總是注意的字串是否有結束符
如果是用 for 迴圈複製的方式會沒有複製到結束符號

```cpp
char* str="ABC\0";
char buf[strlen(str)+1];

for(int i=0; i<strlen(str); ++i){
    buf[i]=str[i];
}

buf[strlen(str)] = '\0';
```

因為長度的算計 strlen() 並不包含結束福
所以在for跑完之後要自己補上結束符

另外這裡寫上 '/0' 會比較好，寫0要花時間思考
> 為什麼是0，0是什麼意思？

</br>

### new 有方框 (陣列[]) 就配有方框的 delete
```cpp
char* p = new char[3];
delete [] p;
```

因為裡面有你必須刪除3次，手動寫就這樣

```cpp
char* p = new char[3];

for(int i=0; i<3; ++i){
    delete (p+i);
}
```

交給系統處理就好不要自己寫~

</br>

### 一個 fun 內有 new 就必須在 main 接收他
```cpp
char* fun(){
    char* p = new char[10];
    return p;
}

char* p = fun();
delete [] p;
```

不把它收起來他就永遠消失了，但是空間還在，要是執行幾萬次會把記憶體吃光。
> 這個行為叫做 [memory leak](https://www.wikiwand.com/zh-tw/%E5%86%85%E5%AD%98%E6%B3%84%E6%BC%8F)

也有人稱為資源遺失(Resource leak)


</br></br></br>

## 更多
- [C語言 字元char與字串 差異與詳解](https://charlottehong.blogspot.tw/2017/04/c-char.html)

- [string.h 函式的實作代碼](http://edisonx.pixnet.net/blog/post/76558463-%5Bc%5D-c-style-string.h-%E9%83%A8%E4%BB%BD%E5%87%BD%E5%BC%8F%E5%AF%A6%E5%81%9A)

</br></br></br>


## 代碼
測試代碼
```cpp
#include <iostream>
#include <cstring>
using namespace std;

char* strre(const char* str){
    int len = strlen(str);

    char* buff = new char[len];
    // char buff[len]; // buff(*)[len] 隱式轉型-> char*

    for(int i=0;i<len;i++){
        buff[len-i-1]=str[i];
        // cout << "i=" << i << endl;
        // cout << "i=" << len-i-1 << endl;
    }
    buff[len]=0;

    return buff;
}

void re(int* arr, int len){}

char* fun(const char* str1, const char* str2){
    size_t len = strlen(str1);
    len += strlen(str2);
    char* buff = new char[len+1];
    strcpy(buff,str1);
    strcat(buff,str2);
    return buff;
}


//================================================================
int main(int argc, char const *argv[]){
    // char str[]="ABC\0";
    // char* buff;
    // buff = strre("ABCDEFG");
    // cout << "buff=" << buff << endl;

    // delete [] buff;
    // return 0;


    char str[]="ABC\0";
    char str2[]="DEF\0";
    char* buff[2];

    buff[0] = fun(str,str2); // buff 地0個存了 一個地址
    cout<< buff[0] <<endl;
    buff[1] = fun(str,str2); // buff 地0個存了 一個地址
    cout<< buff[1] <<endl;


    // if(strcmp(str,str2)==0){
    //     cout<< "same" << endl ;
    // }
    // else{
    //     cout<< "different" << endl;
    // }

    // char* p = nullptr;
    // int len=10;
    // p = new char[len];
    // p='A';
    // delete [] p;

    // return 0;
}
//================================================================

```

