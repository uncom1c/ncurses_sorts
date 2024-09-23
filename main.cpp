#include <cassert>
#include <cstring>
#include <iostream>
#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include "random/random.h"
#include "sorts/sorts.h"
int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << "need more argumets lol" << std::endl;
    std::cout << "A viable list of options you can use:" << std::endl;
    std::cout << "./Kartinka <gnome, selection, insert, bubble, cocktail, "
                 "quick, shell, stooge, slow, odd-even, bogo>"
              << std::endl;
    return 0;
  }
  initscr();
  curs_set(0);
  timeout(-1);
  noecho();
  cbreak();
  int row, col, size;
  getmaxyx(stdscr, row, col);
  WINDOW *win = newwin(row, col, 0, 0);
  if (row > 25) {
    size = 46;
  } else {
    size = 22;
  }
  bool seen_cmd = false;
  int arr[size];
  numbers(arr, size);
  if (!strcmp(argv[1], "gnome")) {
    seen_cmd = true;
    gnome_sort(arr, size, 1);
  }
  if (!strcmp(argv[1], "selection")) {
    selectionSort(arr, size, 1);
    seen_cmd = true;
  }
  if (!strcmp(argv[1], "insert")) {
    insertSort(arr, size, 1);
    seen_cmd = true;
  }
  if (!strcmp(argv[1], "bubble")) {
    bubbleSort(arr, size, 1);
    seen_cmd = true;
  }
  if (!strcmp(argv[1], "cocktail")) {
    cocktailSort(arr, size, 1);
    seen_cmd = true;
  }
  if (!strcmp(argv[1], "quick")) {
    int left = 0;
    int right = size - 1;
    quickSort(arr, left, right, size, 1);
    seen_cmd = true;
  }
  if (!strcmp(argv[1], "shell")) {
    ShellSort(arr, size, 1);
    seen_cmd = true;
  }
  if (!strcmp(argv[1], "stooge")) {
    int left = 0;
    int right = size - 1;
    stooge_sort(arr, left, right, size, 1);
    seen_cmd = true;
  }
  if (!strcmp(argv[1], "slow")) {
    int left = 0;
    int right = size - 1;
    slow_sort(arr, left, right, size, 1);
    seen_cmd = true;
  }
  if (!strcmp(argv[1], "odd-even")) {
    odd_even_sort(arr, size, 1);
    seen_cmd = true;
  }
  if (!strcmp(argv[1], "bogo")) {
    seen_cmd = true;
    bool is_sorted = false;
    while (!is_sorted) {
      bogo_sort(arr, size, is_sorted, 1);
      numbers(arr, size);
    }
  }
  if (seen_cmd == false) {

    seen_cmd = true;
    bool is_sorted = false;
    while (!is_sorted) {
      bogo_sort(arr, size, is_sorted, 1);
      numbers(arr, size);
    }
  }
  getch(); // ждём нажатия символа
  endwin();

  return 0;
}
