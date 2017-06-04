/*****************************************************************
Name : 
Date : 2017/06/04
By   : CharlotteHonG
Final: 2017/06/04
*****************************************************************/
#include <iostream>
using namespace std;

struct Num{
    int data;
};

//================================================================
int main(int argc, char const *argv[]){
    Num a{10};
    cout << "a.data = " << a.data << endl;

    Num* p = &a;
    cout << (*p).data << endl;
    cout << p->data << endl;
    
    return 0;
}
//================================================================
