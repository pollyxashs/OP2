#include <iostream>
#include <stdexcept>
#include "header.h"

int main() {
    try {
        my_array::Array<5, int> arr;
        arr[0] = 1;
        arr[1] = 10;
        arr[2] = -5;
        arr[3] = 7;
        arr[4] = 2;
        std::cout << "Max element: " << arr.max() << std::endl;
        // попробуем обратиться к элементу по неверному индексу
        std::cout << "Element with index 10: " << arr[10] << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Out of range error: " << e.what() << std::endl;
    }
    catch (const std::length_error& e) {
        std::cerr << "Length error: " << e.what() << std::endl;
    }
}
