#include <iostream>
#include <list>
#include <vector>

// #include "C:\Users\USER\Documents\cloudfact\cpp_project_tests\sorts\sorts.h"
#include "../sorts/sorts.h"
#include <gtest/gtest.h>
int size = 45;
TEST(SortingTests, TestselectionSort)
{
    int listUnSorted[size];
    int listSorted[size];
    for (int i = 0; i < size; i++){
        listUnSorted[i] = 44 - i;
        listSorted[i] = i;
    }
    selectionSort(listUnSorted, 45, 0);
    for (int i = 0; i < size; i++){
        ASSERT_EQ(listUnSorted[i], listSorted[i]);
    }
}

TEST(SortingTests, TestinsertSort)
{
    int listUnSorted[size];
    int listSorted[size];
    for (int i = 0; i < size; i++){
        listUnSorted[i] = 44 - i;
        listSorted[i] = i;
    }
    insertSort(listUnSorted, size, 0);
    for (int i = 0; i < size; i++){
        ASSERT_EQ(listUnSorted[i], listSorted[i]);
    }
}
TEST(SortingTests, TestbubbleSort)
{
    int listUnSorted[size];
    int listSorted[size];
    for (int i = 0; i < size; i++){
        listUnSorted[i] = 44 - i;
        listSorted[i] = i;
    }
    bubbleSort(listUnSorted, size, 0);
    for (int i = 0; i < size; i++){
        ASSERT_EQ(listUnSorted[i], listSorted[i]);
    }
}

TEST(SortingTests, TestcocktailSort)
{
    int listUnSorted[size];
    int listSorted[size];
    for (int i = 0; i < size; i++){
        listUnSorted[i] = 44 - i;
        listSorted[i] = i;
    }
    cocktailSort(listUnSorted, size, 0);
    for (int i = 0; i < size; i++){
        ASSERT_EQ(listUnSorted[i], listSorted[i]);
    }
}
TEST(SortingTests, TestquickSort)
{
    int listUnSorted[size];
    int listSorted[size];
    for (int i = 0; i < size; i++){
        listUnSorted[i] = 44 - i;
        listSorted[i] = i;
    }
    int left =0;
    int right = 44;
    quickSort(listUnSorted, left, right, size, 0);
    for (int i = 0; i < size; i++){
        ASSERT_EQ(listUnSorted[i], listSorted[i]);
    }
}
TEST(SortingTests, TestshellSort)
{
    std::vector<std::pair<int, int>> iter;
    int listUnSorted[size];
    int listSorted[size];
    for (int i = 0; i < size; i++){
        listUnSorted[i] = 44 - i;
        listSorted[i] = i;
    }
    ShellSort(listUnSorted, size, 0);
    for (int i = 0; i < size; i++){
        ASSERT_EQ(listUnSorted[i], listSorted[i]);
    }
}
TEST(SortingTests, TestgnomeSort)
{
    std::vector<std::pair<int, int>> iter;
    int listUnSorted[size];
    int listSorted[size];
    for (int i = 0; i < size; i++){
        listUnSorted[i] = 44 - i;
        listSorted[i] = i;
    }
    gnome_sort(listUnSorted, size, 0);
    for (int i = 0; i < size; i++){
        ASSERT_EQ(listUnSorted[i], listSorted[i]);
    }
}
TEST(SortingTests, TeststoogeSort)
{
    std::vector<std::pair<int, int>> iter;
    int listUnSorted[size];
    int listSorted[size];
    for (int i = 0; i < size; i++){
        listUnSorted[i] = 44 - i;
        listSorted[i] = i;
    }
    int left =0;
    int right = 44;
    stooge_sort(listUnSorted, left, right, size, 0);
    for (int i = 0; i < size; i++){
        ASSERT_EQ(listUnSorted[i], listSorted[i]);
    }
}
TEST(SortingTests, TestslowSort)
{
    std::vector<std::pair<int, int>> iter;
    int listUnSorted[size];
    int listSorted[size];
    for (int i = 0; i < size; i++){
        listUnSorted[i] = 44 - i;
        listSorted[i] = i;
    }
    int left =0;
    int right = 44;
    slow_sort(listUnSorted, left, right, size, 0);
    for (int i = 0; i < size; i++){
        ASSERT_EQ(listUnSorted[i], listSorted[i]);
    }
}
TEST(SortingTests, Test_odd_even_Sort)
{
    std::vector<std::pair<int, int>> iter;
    int listUnSorted[size];
    int listSorted[size];
    for (int i = 0; i < size; i++){
        listUnSorted[i] = 44 - i;
        listSorted[i] = i;
    }
    odd_even_sort(listUnSorted, size, 0);
    for (int i = 0; i < size; i++){
        ASSERT_EQ(listUnSorted[i], listSorted[i]);
    }
}
int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
