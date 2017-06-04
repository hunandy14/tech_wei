/*****************************************************************
Name :
Date : 2017/04/29
By   : CharlotteHonG
Final: 2017/04/29
*****************************************************************/
#include <iostream>
#include <iomanip>
#include <vector>
#include <initializer_list>
#include <fstream>
#include <string>
using namespace std;

class Chords{
public:
    Chords(initializer_list<vector<unsigned>> init): v(init){}
    Chords(string filename){
        // cout << "filename=" << filename << endl;
        fstream f;
        f.open(filename, fstream::in);
        if(!f.is_open())
            cout << "No File" << endl;

        char buf[64]{};
        char buf2[64]{};

        f >> buf;
        size_t len = atoi(buf)/2 + 1;
        v.resize(len);
        v[0].push_back(atoi(buf));
        // ��ʼ��
        for (unsigned i = 1; i < len; ++i){
            // v[i].resize(2);
            f >> buf;
            f >> buf2;
                // v[i].push_back(atoi(buf));
                // v[i].push_back(atoi(buf2));
            if(atoi(buf) > atoi(buf2)) {
                v[i].push_back(atoi(buf2));
                v[i].push_back(atoi(buf));
                // cout << "buf=" << v[i][0] << ", ";
                // cout << v[i][1] << endl;
            } else {
                v[i].push_back(atoi(buf));
                v[i].push_back(atoi(buf2));
            }
        }


    }
    // ȡ���B�Y���c
    int get_lnk(size_t p){
        for(unsigned i = 1; i < v.size(); ++i) {
            if(v[i][0]==p) {
                return v[i][1];
            }
        }
        // �]���c
        return -1;
    }
    // ������·��(һ�Ӷ�ȡǰ��)
    size_t mis(size_t a, size_t b){
        size_t all_chd = v.size()-1;
        size_t max_chd=0;
        bool used[2*all_chd]{};
        // �ҹ�������ྀ
        for(int j=all_chd; j!=0; --j){
            size_t chd=0;
            bool flag=1;
            vector<unsigned> log(0);// �o�·��
            for(unsigned i = a; i < b; ++i) {
                if(used[i]) // �ѽ����^
                    continue;
                int temp=get_lnk(i);
                if(temp != -1) { // ��Ч�B�Y
                    log.push_back(i);
                    used[i]=flag; //��ӛ��·��
                    flag=0;
                    i = temp;
                    ++chd; // �yӋ�ׂ�߅
                    cout << i << ", ";
                }
            }cout << endl;
            // �����߅
            if(chd > max_chd) {
                max_chd = chd;
                path = log;
            }
        }
        return max_chd;
    }
    void pri_path(){
        for(unsigned i = 0; i < path.size(); ++i) {
            cout << "[" << setw(3) << i+1 << "] " << path[i] << " -> ";
            cout << get_lnk(path[i]) << endl;
        }
    }
private:
    vector<vector<unsigned>> v;
    vector<unsigned> path;
};
//================================================================
int main(int argc, char const *argv[]){
    Chords a("500.in");
    cout << "max = " << a.mis(0, 499) << endl;
    a.pri_path();

    return 0;
}
//================================================================
