#include <iostream>
#include "vector.h"
using namespace std;

int main() {

    int arr1[10] = { 3, 5, 2, 0, 1, 0, 0, 4, 1, 0 };
    int arr2[10] = { 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 };

    Subset a(arr1);
    Subset b(arr2);

    Subset s3 = a + b;
    s3.print();

    if (a == b) {
        std::cout << "a is equal to b" << std::endl;
    }
    else {
        std::cout << "a is not equal to b" << std::endl;
    }

    if (a != b) {
        std::cout << "a is not equal to b" << std::endl;
    }
    else {
        std::cout << "a is equal to b" << std::endl;
    }

    a += 5;
    a.print();
    b -= 2;
    b.print();

    return 0;
}