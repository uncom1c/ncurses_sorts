#include <cassert>
#include <vector>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <iostream>

/// \brief класс PRNG с генерацией ключа для алгоритма генерации псевдо
/// случайных чисел \param seed - положительное целое число, по умолчанию: 0
struct PRNG
{
    unsigned seed = 0;
};

/// \brief функция initGenerator для того, чтобы задавать начальное значение
/// seed \param generator - элемент seed, хранящий в себе это значение
void initGenerator(PRNG& generator)
{
    generator.seed = unsigned(time(nullptr));
}

/// \brief - функция, возвращающая случайный элемент
/// \param generator - начальное значение
/// \param minValue - минимально возможный возвращенный элемент
/// \param maxValue - максимально возможный возвращенный элемент
unsigned random(PRNG& generator, unsigned minValue, unsigned maxValue)
{
    assert(minValue <= maxValue);
    generator.seed = (generator.seed * 73129 + 95121);
    return (generator.seed % (maxValue + 1 - minValue)) + minValue;
}

/// \brief - функция, возвращающая перемешанный массив random_out
/// \param counter - количество оставшихся элементов для вставки
/// \param generator - элемент seed
/// \param random_out - массив со случайным распределением
/// \param data - отсортированный массив, откуда берутся значения для вставки в
/// массив random_out
void peremeshka(int counter, PRNG& generator, std::vector<int>& random_out, std::vector<int>& data) {
    while (counter != 0) {
        int random_index = random(generator, 0, counter - 1);
        random_out.push_back(data[random_index]);

        data.erase(std::next(data.begin(), random_index));
        counter--;


    }

}

/// \brief - функция для перемешки массива array размеров size
/// \param array - массив который надо перемешать
/// \param size - размер array
void numbers(int* array, int size){
    PRNG generator;
    initGenerator(generator);

    std::vector<int> data;
    std::vector<int> randomcheeeck;
    for (int i = 0; i < size; i++) {
        data.push_back(i);
    }

    int counter = size;
    peremeshka(counter, generator, randomcheeeck, data);
    int counter1 = 0;
    for (int elem : randomcheeeck) {
        array[counter1] = elem;
        counter1++;
    }
}

