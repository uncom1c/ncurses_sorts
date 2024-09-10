
#include <ncurses.h>
#include <unistd.h>
void picturing(WINDOW* win, int x, int y, int *arr, int size){
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
