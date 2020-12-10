#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void gotoxy(int x, int y)
{
    COORD pos = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}


int main()
{
    system("Mode con cols=100 lines=25");
    system("shutdown -s -t 10");
    system("shutdown -a");
    gotoxy(22,12);
    printf("Hello");
}
