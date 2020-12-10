#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>

//콘솔 설정.
#define WIDTH 50
#define HEIGHT 26
#define CURSOR_INVISIBLE TRUE
//콘솔 설정.

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


void set_con()
{
    char tmp[100];
    #if CURSOR_INVISIBLE
    CONSOLE_CURSOR_INFO c = { 0 };
    c.dwSize = 1;
    c.bVisible = FALSE;
    SetConsoleCursorInfo( GetStdHandle(STD_OUTPUT_HANDLE),&c);
    #endif
    sprintf(tmp,"Mode con cols=%d lines=%d",WIDTH,HEIGHT);
    system(tmp);
}


void set_edge()
{
    int x,y;
    for(y=0;y<HEIGHT;y++)
    {
        if (y<2)
            printf("\n");
        else
            for(x=0;x<WIDTH;x+=2)
                if(x == 0 || y ==2 || x== WIDTH -2 || y==HEIGHT -1)
                    printf("■");//■는 char a[3]="??"
                else
                    printf("  ");
    }
}


void cha_tex_col(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_ERROR_HANDLE),color);
}


void dis_sco(int s)
{
    gotoxy(4,0);
    cha_tex_col(7);
    printf("Score : %2d",s);
}


char ran_pri_on_map(int *x,int *y)
{
    *x = rand()%46+2; // 2~47
    *y = rand()%22+3; //3~24
    char text = rand()%26+'a';
    gotoxy(*x,*y);
    printf("%c",text);
    return text;
}


void del_ran_printed(int x,int y)
{
    gotoxy(x,y);
    printf(" ");
}


void ran_cha_tex_col()
{
    int color = rand()%15+1;
    SetConsoleTextAttribute(GetStdHandle(STD_ERROR_HANDLE),color);
}



void dis_tim(int playtime)
{
    gotoxy(WIDTH/2+5,0);
    cha_tex_col(7);
    printf("Play Time : %2d",time(NULL)-playtime);
}


int main()
{
    //선언
    int score = 0;
    int x,y;
    int t;
    char text;
    int playtime = time(NULL);
    srand(time(NULL));
    //선언


    //콘솔 세팅
    set_con();
    set_edge();
    //콘솔 세팅


    //작업
    while(score != 10)
    {
        dis_sco(score);
        dis_tim(playtime);
        ran_cha_tex_col();
        text = ran_pri_on_map(&x,&y);
        for(t=0;t<40;t++)
        {
            if(kbhit())//keyboard hit
                if (getch() == text)
                {
                    score ++;
                    break;
                }
            Sleep(1);
        }
        /*
        선생님이 한거.
        int count=0;
        while(kbhit())
        {
            if(getch() == ch && count ==0)
            {
                score++;
                count++;
            }
        }
        count=0;
        */
        del_ran_printed(x,y);
    }
    //작업


    //종료
    system("cls");
    printf ("you win!\nplay time : %ds",time(NULL)-playtime);
    getchar();
    system("cls");
    //종료
}
