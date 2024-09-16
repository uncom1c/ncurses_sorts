#include <iostream>
#include <ncurses.h>
#include "../drawing/picturing.h"

void gnome_sort(int *arr, int size )
{
    int i = 1;
    int j=2;   
	while(i< size)  
    {
        if (arr[i-1] < arr[i]){
            i=j;
            j++;
            picturing(arr,size);
            refresh();
        }
        else{
            std::swap(arr[i-1], arr[i]);
            i=i-1;
            picturing(arr,size);
            refresh();
            if (i==0){
                i=j; 
                j++;
            }
        }
    }
}
void selectionSort( int* arr, int size)
{   
    int min;
    for (int i = 0; i < size - 1; i++)
    {
        min = i; 
        for (int j = i + 1; j < size; j++) 
        {   
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        if (min == i) continue;  
        std::swap(arr[i], arr[min]);

            picturing(arr,size);
        refresh();
    }
}
void insertSort( int* arr, int size) {
    for (int i = 1; i < size; i++) {
        for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) {
            std::swap(arr[j-1], arr[j]);
            picturing(arr,size);
            refresh();
        }
    }
}


/// \brief Сортировка пузырьком
/// \brief Прохождение по каждому элементу и сравнение каждой последующей пары. Если они не удовлетворяют сортировке то менять местами
/// \param arr - рандомное распределение
/// \param size - размер arr
/// \param vec - вектор, хранящий все итерации, чтобы впоследствии их визуализировать
void bubbleSort( int* arr, int size)
{

    for (int i = 0; i < size - 1; ++i) // i - номер прохода
    {
        for (int j = 0; j < size - 1; ++j) // внутренний цикл прохода
        {
            if (arr[j + 1] < arr[j])
            {
                std::swap(arr[j], arr[j + 1]);
            picturing(arr,size);
                refresh();
            }
        }
    }
}
/// \brief Сортировка шейкером
/// \brief Алгоритм очень похож на пузырек, но при завершении обхода списка этот алгоритм не начинает все время с одного и того же конца, как пузырёк, а ходит туда-сюда
/// \param arr - рандомное распределение
/// \param n - размер arr
/// \param vec - вектор, хранящий все итерации, чтобы впоследствии их визуализировать
void cocktailSort( int* arr, int size) {
    bool flag = true;
    int start = 0, end = size - 1;
    while (flag) {
        flag = false;
        for (int i = start; i < end; i++) { //scan from left to right as bubble sort
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
            picturing(arr,size);
                refresh();
                flag = true;
            }
        }
        if (!flag) { //if nothing has changed simply break the loop
            break;
        }
        flag = false;
        end--; //decrease the end pointer
        for (int i = end - 1; i >= start; i--) { //scan from right to left
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i],arr[i + 1]);
            picturing(arr,size);
                refresh();
                flag = true;
            }
        }
        start++;
    }
}
int partition( int* arr, int left, int right, int size)
{
    int median = arr[right];
    int i = left - 1;
    int j;
    for (j = left; j < right; j++)
    {
        if (arr[j]<= median)
        {
            i++;
            std::swap(arr[i], arr[j]);
            picturing(arr,size);
                refresh();
        }
    }
    std::swap(arr[right], arr[i+1]);
            picturing(arr,size);
    refresh();
    return i + 1;
}
/// \brief Быстрая сортировка
/// \param arr - рандомное распределение
/// \param left - левая граница
/// \param right - правая граница
/// \param vec - вектор, хранящий все итерации, чтобы впоследствии их визуализировать
void quickSort( int* arr, int left, int right, int size)
{
    int p;
    if (left < right) {
        p = partition(arr, left, right, size);
        quickSort( arr, left, p - 1, size);
        quickSort( arr, p + 1, right, size);
    }
}

//СОРТИРОВКА ШЕЛЛА
void ShellSort( int* arr, int size)
{
    for (int step = size / 2; step > 0; step = step / 2)  // Расстояние между элементами
    {
        for (int i = step; i < size; i++)                 // Проходим по массиву
        {
            for (int j = i - step; j >= 0; j = j - step)    // Проходим по элементам массива
            {
                if (arr[j] > arr[j + step])                 // Сравниваем элементы
                {
                    std::swap(arr[j], arr[j + step]);
            picturing(arr,size);
                    refresh();
                }
            }
        }
    }
}


void stooge_sort( int* arr, int left, int right, int size){
    if(arr[left]> arr[right]){
        std::swap(arr[left], arr[right]);
            picturing(arr,size);
        refresh();
    }
    if(left+1 >= right){
        return ;
    }
    int temp;
    temp = (right-left+1)/3;
    stooge_sort( arr, left, right - temp, size);
    stooge_sort( arr, left + temp, right, size);
    stooge_sort( arr, left, right - temp, size);

}


void slow_sort( int* arr, int left, int right, int size){
    if (left>=right){
        return;
    }
    int middle = (left+right)/2;
    slow_sort( arr, left, middle, size);
    slow_sort(arr, middle+1, right, size);
    if (arr[right]< arr[middle]){
        std::swap(arr[right], arr[middle]);
            picturing(arr,size);
        refresh();
    }
    slow_sort( arr, left, right-1, size);
}


void odd_even_sort( int *arr, int size){
    bool is_sorted =false;
    while (!is_sorted){
        is_sorted=true;
        for (int i =1; i<=size-2; i=i+2){
            if (arr[i]> arr[i+1]){
                std::swap(arr[i], arr[i+1]);
            picturing(arr,size);
                refresh();
                is_sorted=false;
            }
        }
        for (int i =0; i<=size-2; i=i+2){
            if (arr[i]> arr[i+1]){
                std::swap(arr[i], arr[i+1]);
            picturing(arr,size);
                refresh();
                is_sorted=false;
            }
        }
    }
    return;
}
void bogo_sort( int *arr, int size, bool is_sorted)
{
            picturing(arr,size);
    refresh();
    is_sorted = true;
    for (int i=1; i<size; i++){
        if (arr[i]<arr[i-1]){
            is_sorted = false;
        }
    }
}
