#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{

    //int A[10000][10000];
    // create a 2D vector A[100][100]
    vector < vector<int> > A;

    int size = 100;
    A.resize(size);
    for(int i=0; i < size; ++i){
        A[i].resize(size);
    }

    if(argc != 3)
    {
        cout << "Usage: ./[exe] [input file] [output file]" << endl;
        system("pause");
//        exit(1);
    }

    // open the input file
    fstream fin;
    fin.open(argv[1], fstream::in);
    if(!fin.is_open() =! 0)
    {
        cout << "Error: the input file is not opened!!" << endl;
        exit(1);
    }

    // parse the input file
    cout << "======================" << endl;
    cout << "        Parser        " << endl;
    cout << "======================" << endl;

    char buffer[100];

    fin >> buffer;
    int numChord = atoi(buffer);

    cout << "#Chords:" << numChord << endl;

    for(int i = 0; i < numChord / 2; ++i)
    {
        fin >> buffer;
        int point1 = atoi(buffer);
        fin >> buffer;
        int point2 = atoi(buffer);
        cout << "Chord(" << point1 << "," << point2 << ")" << endl;
    }


    // open the output file
    fstream fout;
    fout.open(argv[2],fstream::out);
    if(!fout.is_open())
    {
        cout << "Error: the output file is not opened!!" << endl;
        exit(1);
    }

    // output something to the output file
    fout << "Hello world!" << endl;
    system("pause");
    return 0;
}

