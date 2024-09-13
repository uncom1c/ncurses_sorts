#include <iostream>
#include <ncurses.h>
#include <vector>
#include <cassert>
#include <stdlib.h>
#include <unistd.h>
#include <cstring>


#include "random/random.h"
#include "sorts/sorts.h"
int main(int argc, char *argv[])
{
    if (argc < 2){
        std::cout<<"need more argumets lol";
        return 0;
    }
    initscr();
    curs_set(0);
    timeout(-1);
    noecho();
    cbreak();
    int arr[45];
    numbers(arr);
    int row, col;
    int x, y;
    int size = sizeof(arr)/sizeof(arr[0]);
    getmaxyx(stdscr,row,col);
    WINDOW* win = newwin(row,col,0,0);
    x = row;
    y=0;
    if (!strcmp(argv[1], "gnome")){
        gnome_sort(win, arr, size, x , y);
    } 
    if (!strcmp(argv[1], "selection")){
        selectionSort(win, arr, size, x , y);
    } 
    if (!strcmp(argv[1], "insert")){
        insertSort(win, arr, size, x , y);
    } 
    if (!strcmp(argv[1], "bubble")){
        bubbleSort(win, arr, size, x , y);
    } 
    if (!strcmp(argv[1], "cocktail")){
        cocktailSort(win, arr, size, x , y);
    } 
    if (!strcmp(argv[1], "quick")){
        int left = 0;
        int right = size-1;
        quickSort(win, arr, left, right, size, x , y);
    } 
    if (!strcmp(argv[1], "shell")){
        ShellSort(win, arr, size, x , y);
    } 
    if (!strcmp(argv[1], "stooge")){
        int left = 0;
        int right = size-1;
        stooge_sort(win, arr, left, right, size, x , y);
    } 
    if (!strcmp(argv[1], "slow")){
        int left = 0;
        int right = size-1;
        slow_sort(win, arr, left, right, size, x , y);
    } 
    if (!strcmp(argv[1], "odd_even")){
        odd_even_sort(win, arr, size, x , y);
    } 
    if (!strcmp(argv[1], "bogo")){
        bool is_sorted = false;
        while (!is_sorted){
            bogo_sort(win, arr, size, x , y, is_sorted);
            numbers(arr);
        }
    } 
    getch(); // ждём нажатия символа
    endwin();

	return 0;
}
