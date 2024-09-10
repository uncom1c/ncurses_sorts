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

