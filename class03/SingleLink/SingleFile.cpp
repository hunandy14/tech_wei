/*****************************************************************
Name : 
Date : 2017/06/04
By   : CharlotteHonG
Final: 2017/06/04
*****************************************************************/
#include <iostream>
using namespace std;

// 結構
struct Node {
    int data;
    Node* next = nullptr; // 類內初始化 c11
};


// 印出節點
void pri(Node* n){
    cout << n->data << endl;
}
// 印出所有節點
void pri_all(Node* n){
    while(n != nullptr) {
        cout << n->data << ", ";
        n = n->next;
    } cout << endl;
    return;
}



// struct Node {
//     int data;
//     Node* next = nullptr; // 類內初始化 c11
// };
int main(int argc, char const *argv[]){
    Node head = {-1}; //c11 不用打 =
    Node p[3] = {{1},{2},{3}}; // c14 部分初始化(沒打到靠類內初始化)

    head.next = &p[0];
    p[0].next = &p[1];
    // p[1].next = &p[2];
    (p+1)->next = p+2;

    // 0x01 0x02;

    // pri_all(&head);


    // 常態的單向連結，指針操作

    // // 創建鏈結
    // Node* list = new Node;
    // // 第一點
    // list->data = 1;
    // list->next = new Node;
    // // 第二點
    // list->next->data = 2;
    // list->next->next = nullptr;
    // // 印出
    // pri_all(list);
    return 0;
}