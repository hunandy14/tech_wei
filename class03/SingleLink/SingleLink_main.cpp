/*****************************************************************
Name : 
Date : 2017/02/04
By   : CharlotteHonG
Final: 2017/02/04
*****************************************************************/
#include <iostream>
#include "SingleLink.hpp"
#include "SingleLink.cpp"

using namespace std;
/*==============================================================*/
int main(int argc, char const *argv[]){
    // 創建鏈結
    Node* list = new Node;
    // 第一點
    list->data = 1;
    list->next = new Node;
    // 第二點
    list->next->data = 2;
    list->next->next = nullptr;
    // 印出
    pri_all(list);
    return 0;
}
/*==============================================================*/