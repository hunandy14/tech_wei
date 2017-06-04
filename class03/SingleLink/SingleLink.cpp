/*****************************************************************
Name : 
Date : 2017/02/04
By   : CharlotteHonG
Final: 2017/02/04
*****************************************************************/
#include <iostream>
using namespace std;
// 印出節點
void pri(Node* n){
    cout << n->data << endl;
}
// 印出所有節點
void pri_all(Node* n){
    while(1) {
        if(n == nullptr) {
            break;
        } else {
            cout << n->data << ", ";
            n = n->next;
        }
    } cout << endl;
    return;
}