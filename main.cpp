#include <iostream>
#include "random/random.h"
#include <ncurses.h>
#include <vector>
#include <cassert>
#include <stdlib.h>
#include <unistd.h>
void picturing(WINDOW* win, int x, int y, int *arr, int size){
    erase();
    for(int i = 0; i< size;i++){
        move(x, y);
        for (int j=0; j<arr[i]; j++){
            move(x-j-1,y);
            printw("x");
            move(x-j-1,y+1);
            printw("x");
            move(x-j-1,y+2);
            printw("x");
        }
        y=y+3;
    }

    usleep(100000);
}
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
int main()
{
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
    gnome_sort(win, arr, size, x , y);
    getch(); // ждём нажатия символа
    endwin();

	return 0;
}
