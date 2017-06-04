/*****************************************************************
Name :
Date : 2017/04/24
By   : 
Final: 2017/04/24
*****************************************************************/
#include <iostream>
#include <vector>
#include <initializer_list>
using namespace std;

class Dijk{
public:
    // ��l��
    Dijk(initializer_list<vector<int>> mat):
        graph(mat), vert(mat.size()),
        dist(vert), parent(vert), sptSet(vert)
    {}
    // �L�X���|(���k�d���|)
    void printPath(int i){
        if (parent[i] == -1)
            return;
        printPath(parent[i]);
        printf("%d ", i);
        // �x�s���|
        path.push_back(i);
    }
    // �L�X���|
    void printSolution(int src, int end){
        printf("Vertex\t  Distance\tPath\n");
        printf("%d->%d \t\t%d\t%d ", src, end, dist[end], src);
        printPath(end);// ���j�@���L�X
        cout << endl;
    }
    // ��^�̤p�Z�����I
    int minDistance(){
        int min = INT_MAX, min_index;
        for (int i = 0; i < vert; i++){
            // ���L�w���̵u�� , �ç�̵u��
            if (sptSet[i] == false && dist[i] <= min){
                min = dist[i];
                min_index = i;
            }
        }
        return min_index;
    }
    // dijk�t��k
    auto& dijkstra(int src, int end){
        // ��l�Ƹ��
        for(int i = 0; i < vert ; ++i) {
            dist[i] = INT_MAX;
            parent[i] = -1;
            sptSet[i] = false;
            path.resize(0);
        }
        // ��J�_�I
        path.push_back(src);
        dist[src] = 0;
        // �̧ǧ��I
        for (int j = 0; j < vert-1; j++){
            // �U�@�ӳ̵u�Z���O�����I
            int u = minDistance();
            sptSet[u] = true;// ��L���аO
            for (int v = 0; v < vert; v++){
                if (sptSet[v]==0 &&   // �٨S�T�{�̵u
                    graph[u][v]!=0 && // �U���I�O���ĶZ��
                    dist[u]+graph[u][v] < dist[v]) // ��e���|����u
                {
                    parent[v] = u; // ��s���|
                    dist[v] = dist[u] + graph[u][v]; // ��s�Z��
                }
            }
        }
        // �L�X���|
        printSolution(src, end);
        return path;
    }
    // ����O�_�b���|��
    int compare(vector<int>& rhs){
        unsigned flag=0;
        for(unsigned j=0; j<path.size()-rhs.size()+1; ++j){
            for (unsigned i=0; i < rhs.size(); ++i){
                if( rhs[i] == path[i+j] ){
                    flag++;
                }
            }
            if(flag==rhs.size()){
                return 1;
            }
            flag=0;
        }
        return 0;
    }
    // �˴��O�_�����ĸ��|�A�ó]�w����(-1��ܳ�����)
    int check_path(){
        for (unsigned i = 0; i < path.size()-1; ++i){
            size_t x = path[i];
            size_t y = path[i+1];

            if(cls_path[x][y] == 1) {
                graph[x][y] = 0; // �w�������W����
                return path[idx];
            }
            ++idx;
        }
        return -1;
    }
public:
    vector<vector<int>> graph; // �F���x�}
    int vert;
    vector<int> dist;   // ���I���̵u�Z��
    vector<int> parent; // ���I���̵u���|�A�Ӧۭ����I
    vector<bool> sptSet;// ���I���̵u���|�A�w�Q���
    vector<int> path;   // �w�g��쪺�̵u���|

    vector<vector<int>> cls_path; // �Q���������u
    int idx=0; // ���ޥؿ�
};
//================================================================
int main(int argc, char const *argv[]){
    // Dijk a{
    //     {0, 10, 0, 0, 0, 0, 0, 10},
    //     {10, 0, 10, 0, 0, 0, 0, 10},
    //     {0, 10, 0, 10, 0, 0, 100, 0},
    //     {0, 0, 10, 0, 10, 10, 0, 0},
    //     {0, 0, 0, 10, 0, 10, 0, 0},
    //     {0, 0, 0, 10, 10, 0, 10, 0},
    //     {0, 0, 100, 0, 0, 10, 0, 10},
    //     {10, 10, 0, 0, 0, 0, 10, 0},
    // };
    // // �̵u���|(��J)
    // auto path1 = a.dijkstra(1, 6);
    // auto path2 = a.dijkstra(2, 4);
    // // �L�X
    // for(unsigned i = 0; i < path1.size(); ++i) {
    //     cout << path1[i] << ", ";
    // } cout << endl;
    // for(unsigned i = 0; i < path1.size(); ++i) {
    //     cout << path2[i] << ", ";
    // } cout << endl;

    // // �O�_�b�w��X���̵u���|��
    // vector<int> v{2, 3};
    // cout << "a.compare(v)=" << a.compare(v) << endl;


    // ���u��
    Dijk a{
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0},
    };
    // �Q������|

    vector<vector<int>> cls_path=
    {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
    };

    a.cls_path = cls_path;
    int pos=2; // �ثe��m
    // �����F�ت�
    while(pos != -1) {
        a.dijkstra(pos, 0);
        pos = a.check_path();
        cout << "pos=" << pos << endl;
    }
    return 0;
}
//================================================================
