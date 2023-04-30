#include <stdexcept>
namespace my_array {
    template <int N, class T>
    class Array {
    private:
        T data[N];
    public:
        Array() {}

        // добавим геттер для доступа к элементу массива по индексу
        T& operator[](int index) {
            if (index < 0 || index >= N) {
                throw std::out_of_range("Index out of range");
            }
            return data[index];
        }

        // функция для поиска максимального элемента
        T max() {
            if (N == 0) {
                throw std::length_error("Empty array");
            }
            T max_val = data[0];
            for (int i = 1; i < N; ++i) {
                if (data[i] > max_val) {
                    max_val = data[i];
                }
            }
            return max_val;
        }
    };
}
