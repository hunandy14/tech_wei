/*****************************************************************
Name : 
Date : 2017/02/04
By   : CharlotteHonG
Final: 2017/02/04
*****************************************************************/
#include <iostream>
using namespace std;


void pri(int &num);


/*==============================================================*/
int main(int argc, char const *argv[]){
    int num=0;
    pri(num);
    return 0;
}
/*==============================================================*/


void pri(int &num){
    cout << "num=" << num << endl;
}



