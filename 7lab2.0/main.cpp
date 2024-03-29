#include <algorithm>
#include "Circular_Buffer.h"
#include <iostream>

int main() {
    CircularBuffer<int> buff(3);
    try {
        buff.insertBegin(1);
        buff.insertBegin(4);
        buff.insertEnd(3);
        for (int i = 0; i < 3; i++) std::cout << buff[i] << " ";
        std::cout << std::endl;
        std::sort(buff.begin(), buff.end());
        std::reverse(buff.begin(), buff.end());
        for (int i = 0; i < 3; i++) std::cout << buff[i] << " ";
        std::cout << std::endl;
        buff.deleteBegin();
        buff.deleteEnd();
        std::cout << buff[0] << std::endl;
        buff.changeCap(4);
        buff.insertEnd(2);
        buff.insertEnd(3);
        buff.insertEnd(4);
        for (int i = 0; i < 4; i++) std::cout << buff[i] << " ";
        std::cout << std::endl;
        buff.deleteIt(buff.begin() + 1);
        for (int i = 0; i < 3; i++) std::cout << buff[i] << " ";
        std::cout << std::endl;
        buff.insertIt(buff.begin() + 1, -2);
        for (int i = 0; i < 4; i++) std::cout << buff[i] << " ";
    } catch (const std::runtime_error& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}
