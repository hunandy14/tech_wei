20170604
===

## 作業
連接10個節點，使用for迴圈創建節點並連接  
最後使用一個function印出全部節點

下面的代碼不要修改，直接貼上並補上適當代碼完成功能。

```cpp
#include <iostream>
using namespace std;

// 結構
struct Node {
    int data = 0;
    Node* next = nullptr;
};

// 判定結束可以用 nullptr 最後一個節點沒接東西
pri_all(head){
    /*...*/
}
int main(int argc, char const *argv[]){
    Node head = {-1}; // 開頭不算(加上共11個)
    Node n[10]; // 10個節點
    // 連結節點
    for(/*...*/){
        /*...*/  
    }
    pri_all(head);    // 印出所有節點
}
```

---

</br></br></br>

## 內容

dev c++ 載點：[DevCppPortable_gcc710](https://mega.nz/#!AgMVGbrB!_0HtH6t5V-7BFsYyz7_DCcLfZuiELKMhP7lHNeoFBKg)

## git 基本操作
https://charlottehong.blogspot.tw/2017/01/git.html

## 拆分檔案
#### 頭文件hpp
放在頭文件可以一起為其他檔案引用，但是  
盡量少放其他頭文件的引用，給個別的cpp檔案個別引用

記得放保護，才不會重複定義。

```cpp
#pragma once
```

可以用 h 也可以用 hpp 主要是差別在可以看出hpp裡面是 c++ 的語法。

#### 實作檔cpp
定義在這裡，函式是如何實作的

> 每一份cpp都要重新引用自己需要的頭文件

#### 主程式
盡可能只放方法的操作過程，差不多就是流程圖的意思  
也算是實作檔要引用自己有用到的頭文件

</br>

### 拆分方法
可以不用一開始就拆3份檔案，這樣一改可能要同時改3份檔案

1. 一開寫的時候可以先寫在main()等到確定完成，或差不多定型了在移動出去  
2. 拆分之後可以先寫在hpp裡面，確定差不多定型在拆出去cpp

</br>

## 結構
在C上把變數綁在一起，在C++上可以連帶方法函式一起綁定。

## 類別封裝
把一個全域變數與全域函式綁在一起的概念而已。









