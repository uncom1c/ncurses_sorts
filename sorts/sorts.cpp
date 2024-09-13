#include <iostream>
#include <ncurses.h>
#include "../drawing/picturing.h"

void gnome_sort(WINDOW* win,int *arr, int size ,int x,int y)
{
    int i = 1;
    int j=2;   
	while(i< size)  
    {
        if (arr[i-1] < arr[i]){
            i=j;
            j++;
            picturing(win, x,y,arr,size);
            refresh();
        }
        else{
            std::swap(arr[i-1], arr[i]);
            i=i-1;
            picturing(win, x,y,arr,size);
            refresh();
            if (i==0){
                i=j; 
                j++;
            }
        }
    }
}
void selectionSort(WINDOW* win, int* arr, int size, int x, int y)
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

        picturing(win, x,y,arr,size);
        refresh();
    }
}
void insertSort(WINDOW* win, int* arr, int size, int x, int y) {
    for (int i = 1; i < size; i++) {
        for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) {
            std::swap(arr[j-1], arr[j]);
            picturing(win, x,y,arr,size);
            refresh();
        }
    }
}


/// \brief Сортировка пузырьком
/// \brief Прохождение по каждому элементу и сравнение каждой последующей пары. Если они не удовлетворяют сортировке то менять местами
/// \param arr - рандомное распределение
/// \param size - размер arr
/// \param vec - вектор, хранящий все итерации, чтобы впоследствии их визуализировать
void bubbleSort(WINDOW* win, int* arr, int size, int x, int y)
{

    for (int i = 0; i < size - 1; ++i) // i - номер прохода
    {
        for (int j = 0; j < size - 1; ++j) // внутренний цикл прохода
        {
            if (arr[j + 1] < arr[j])
            {
                std::swap(arr[j], arr[j + 1]);
                picturing(win, x,y,arr,size);
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
void cocktailSort(WINDOW* win, int* arr, int size, int x, int y) {
    bool flag = true;
    int start = 0, end = size - 1;
    while (flag) {
        flag = false;
        for (int i = start; i < end; i++) { //scan from left to right as bubble sort
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                picturing(win, x,y,arr,size);
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
                picturing(win, x,y,arr,size);
                refresh();
                flag = true;
            }
        }
        start++;
    }
}
int partition(WINDOW* win, int* arr, int left, int right, int size, int x, int y)
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
                picturing(win, x,y,arr,size);
                refresh();
        }
    }
    std::swap(arr[right], arr[i+1]);
    picturing(win, x,y,arr,size);
    refresh();
    return i + 1;
}
/// \brief Быстрая сортировка
/// \param arr - рандомное распределение
/// \param left - левая граница
/// \param right - правая граница
/// \param vec - вектор, хранящий все итерации, чтобы впоследствии их визуализировать
void quickSort(WINDOW* win, int* arr, int left, int right, int size, int x, int y)
{
    int p;
    if (left < right) {
        p = partition( win,arr, left, right, size, x, y);
        quickSort(win, arr, left, p - 1, size, x, y);
        quickSort(win, arr, p + 1, right, size, x, y);
    }
}

//СОРТИРОВКА ШЕЛЛА
void ShellSort(WINDOW* win, int* arr, int size, int x, int y)
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
                    picturing(win, x,y,arr,size);
                    refresh();
                }
            }
        }
    }
}


void stooge_sort(WINDOW* win, int* arr, int left, int right, int size, int x, int y){
    if(arr[left]> arr[right]){
        std::swap(arr[left], arr[right]);
        picturing(win, x,y,arr,size);
        refresh();
    }
    if(left+1 >= right){
        return ;
    }
    int temp;
    temp = (right-left+1)/3;
    stooge_sort(win, arr, left, right - temp, size, x, y);
    stooge_sort(win, arr, left + temp, right, size, x, y);
    stooge_sort(win, arr, left, right - temp, size, x, y);

}


void slow_sort(WINDOW* win, int* arr, int left, int right, int size, int x, int y){
    if (left>=right){
        return;
    }
    int middle = (left+right)/2;
    slow_sort(win, arr, left, middle, size, x, y);
    slow_sort(win,arr, middle+1, right, size, x, y);
    if (arr[right]< arr[middle]){
        std::swap(arr[right], arr[middle]);
        picturing(win, x,y,arr,size);
        refresh();
    }
    slow_sort(win, arr, left, right-1, size, x, y);
}


void odd_even_sort(WINDOW* win, int *arr, int size, int x, int y){
    bool is_sorted =false;
    while (!is_sorted){
        is_sorted=true;
        for (int i =1; i<=size-2; i=i+2){
            if (arr[i]> arr[i+1]){
                std::swap(arr[i], arr[i+1]);
                picturing(win, x,y,arr,size);
                refresh();
                is_sorted=false;
            }
        }
        for (int i =0; i<=size-2; i=i+2){
            if (arr[i]> arr[i+1]){
                std::swap(arr[i], arr[i+1]);
                picturing(win, x,y,arr,size);
                refresh();
                is_sorted=false;
            }
        }
    }
    return;
}
void bogo_sort(WINDOW* win, int *arr, int size, int x, int y, bool is_sorted)
{
    picturing(win, x,y,arr,size);
    refresh();
    is_sorted = true;
    for (int i=1; i<size; i++){
        if (arr[i]<arr[i-1]){
            is_sorted = false;
        }
    }
}
