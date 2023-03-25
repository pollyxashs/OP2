#include <iostream>
#include "vector.h"

Subset::Subset(const int arr[10]) {
    for (int i = 0; i < 10; i++) {
        set[i] = arr[i];
    }
}

Subset Subset::operator+(const Subset& other) const {
    Subset result;
    for (int i = 0; i < 10; i++) {
        result.set[i] = set[i] + other.set[i];
    }
    return result;
}

bool Subset::operator==(const Subset& other) const {
    for (int i = 0; i < 10; i++) {
        if (set[i] != other.set[i]) {
            return false;
        }
    }
    return true;
}

bool Subset::operator!=(const Subset& other) const {
    return !(*this == other);
}

Subset& Subset::operator+=(int num) {
    if (num >= 0 && num <= 9) {
        set[num] = 1;
    }
    return *this;
}

Subset& Subset::operator-=(int num) {
    if (num >= 0 && num <= 9) {
        set[num] = 0;
    }
    return *this;
}

void Subset::print() const {
    std::cout << "{ ";
    for (int i = 0; i < 10; i++) {
        if (set[i] == 1) {
            std::cout << i << " ";
        }
    }
    std::cout << "}" << std::endl;
}