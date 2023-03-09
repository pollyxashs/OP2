
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class LABfile{
private:
    string name;
    ofstream out;
public:
    LABfile(string name_file);
    void open();
    void close();
    bool check();
    void inSTRING(string str);
    void inINT(int a);
    void inFLOAT(float b);
};

