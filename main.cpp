#include <ncurses.h>

using namespace std;

int main(){

    initscr();

    int height, width, start_y, start_x;
    height = 30;
    width = 100;
 
    start_x = start_y = 0;

    WINDOW * win = newwin(height, width, start_y, start_x);
    refresh();

    box(win, 0, 0);
    mvwprintw(win, 0, 0, "Box");
    wrefresh(win);

    getch();

    endwin();

    return 0;
}