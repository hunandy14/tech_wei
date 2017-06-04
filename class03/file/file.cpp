/*****************************************************************
Name : 
Date : 2017/06/04
By   : CharlotteHonG
Final: 2017/06/04
*****************************************************************/
#include <iostream>
#include <fstream>
using namespace std;


//================================================================
int main(int argc, char const *argv[]){
    fstream fs;
    fs.open("data.in", ios::in);
    string buf;
    fs >> buf;
    cout << "buf=" << buf << endl;
    fs >> buf;
    cout << "buf=" << buf << endl; 
    fs >> buf;
    cout << "buf=" << buf << endl;
    fs.close();

    fstream fo;
    fo.open("data.out", ios::in | ios::out | ios::app);
    string s="Hello";
    fo << s;
    fo << " - " << s;
    fo.close();
    
    return 0;
}
//================================================================
