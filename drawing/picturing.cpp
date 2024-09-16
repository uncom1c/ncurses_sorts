
#include <ncurses.h>
#include <unistd.h>
void picturing( int *arr, int size){
    int x, y;
    int row, col;
    getmaxyx(stdscr,row,col);
    x= row;
    y = 0;
    WINDOW* win = newwin(row,col,0,0);
    erase();
    for(int i = 0; i< size;i++)
    {
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
