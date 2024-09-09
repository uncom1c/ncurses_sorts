#include <cassert>
#include <vector>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <iostream>
struct PRNG

{
    unsigned seed = 0;
};

void initGenerator(PRNG& generator)
{
    generator.seed = unsigned(time(nullptr));
}

unsigned random(PRNG& generator, unsigned minValue, unsigned maxValue)
{
    assert(minValue <= maxValue);
    generator.seed = (generator.seed * 73129 + 95121);
    return (generator.seed % (maxValue + 1 - minValue)) + minValue;
}

void peremeshka(int counter, PRNG& generator, std::vector<int>& randomcheeeck, std::vector<int>& data) {
    while (counter != 0) {
        int random_index = random(generator, 0, counter - 1);
        randomcheeeck.push_back(data[random_index]);

        data.erase(std::next(data.begin(), random_index));
        counter--;


    }

}

void numbers(int* array){
    PRNG generator;
    initGenerator(generator);

    int n = 45;
    std::vector<int> data;
    std::vector<int> randomcheeeck;
    for (int i = 0; i < n; i++) {
        data.push_back(i);
    }

    int counter = n;
    peremeshka(counter, generator, randomcheeeck, data);
    int counter1 = 0;
    for (int elem : randomcheeeck) {
        array[counter1] = elem;
        counter1++;
    }
}

