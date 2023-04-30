#include <iostream>
#include "Head_1.hh"
using namespace std;

int main() {
    Square s1(0.0, 0.0, 5.0);
    Square s2(0.0, 0.0, 5.0);

    cout << "s1: " << s1.area() << endl;
    cout << "s2: " << s2.area() << endl;

    if (s1 == s2) {
        cout << "*****" << endl;
    }
    else if (s1 < s2) {
        cout << "s1 < s2" << endl;
    }
    else if (s1 > s2) {
        cout << "s1 > s2" << endl;
    }
    else {
        cout << "s1 != s2" << endl;
    }

    s1.scale(2);
    cout << "s1: " << s1.area() << endl;

    s1.move(1, 2);
    s1.kordi();
}
