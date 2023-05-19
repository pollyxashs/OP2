#include <iostream>
#include <vector>

#include "Procedure1.h"
#include "Procedure2.h"
#include "Procedure3.h"
#include "Procedure4.h"

int main()
{
    // Процедура 1: Отбрасывает от вещественного числа его целую часть
    float number1 = 3.14159;
    discardIntegerPart(&number1);
    std::cout << "Number after discarding integer part: " << number1 << std::endl;

    // Процедура 2: Изменяет вещественную переменную на обратное к ней число
    float number2 = 2.5;
    invertNumber(number2);
    std::cout << "Inverted number: " << number2 << std::endl;

    // Процедура 3: Передвигает квадрат на заданный вектор
    struct Vector2D vector = {2.0, 3.0};
    struct Vector2D square = {1.0, 1.0};
    moveSquare(&square, &vector);
    std::cout << "Square position after moving: (" << square.x << ", " << square.y << ")" << std::endl;

    // Процедура 4: Меняет в матрице местами две указанные строчки
    std::vector<std::vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    swapRows(matrix, 0, 2);
    std::cout << "Matrix after swapping rows:" << std::endl;
    for (const auto& row : matrix) {
        for (const auto& element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

