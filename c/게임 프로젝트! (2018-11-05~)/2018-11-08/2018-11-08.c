#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

void gotoxy(int x, int y)
{
    COORD pos = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}


void sys_col(int i)
{
    char tmp[100];
    sprintf(tmp,"color %2x",i);
    system(tmp);
}


void hello_()
{
    gotoxy(22,12);
    printf("Hello");
    Sleep(400);
    gotoxy(22,12);
    printf("     ");
    Sleep(400);
    gotoxy(22,12);
    printf("Hello");
}


void set_sys()
{
    system("Mode con cols=50 lines=26");
}


int main()
{
    int i=256;
    set_sys();
    while(i--)
    {
        hello_();
        sys_col(i);
    }
}
