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
    Node* next = nullptr;
};

int main(int argc, char const *argv[]){
    Node head = {-1};
    Node p[3] = {{1},{2},{3}};
    // 連結
    head.next = &p[0];
    p[0].next = &p[1];
    p[1].next = &p[2];
    return 0;
}