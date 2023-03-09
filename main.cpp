
#include <iostream>
#include "primer.h"

using namespace std;

int main(){
LABfile file("file.txt");
try {
    file.open();
} catch (std::exception e) {
    cout << "file is not opened" << endl;
}

file.check();

file.inSTRING("hi");
file.inINT(6);
file.inFLOAT(6.6);

file.close();

}
