#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <mmsystem.h>
#include <conio.h>

// 윈도우 lib
#pragma comment(lib, "winmm.lib")

//콘솔 설정.
#define WIDTH 500
#define HEIGHT 150
#define CURSOR_INVISIBLE TRUE

#define USER_SPEED 10
//콘솔 설정.

//전역변수 선언//

//전역변수 선언
void gotoxy(int x, int y)
{
    COORD pos = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}


void sys_color(int i)
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
        if (y<5)
            printf("\n");
        else
            for(x=0;x<WIDTH;x+=2)
                if(x <= 2 || (y>= 5 && y <=7) || x>= WIDTH -4 || y>= HEIGHT -2)
                    printf("■");//■는 char a[3]="??"
                else
                    printf("  ");
    }
    puts("");
}


void font_color(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_ERROR_HANDLE),color);
}


void display_score(int s)
{
    gotoxy(4,0);
    font_color(7);
    printf("Score : %2d",s);
}


char random_print_char(int *x,int *y)
{
    *x = rand()%46+2; // 2~47
    *y = rand()%22+3; //3~24
    char text = rand()%26+'a';
    gotoxy(*x,*y);
    printf("%c",text);
    return text;
}


void delete_one(int x,int y)
{
    gotoxy(x,y);
    printf(" ");
}


void ran_font_color()
{
    int color = rand()%15+1;
    SetConsoleTextAttribute(GetStdHandle(STD_ERROR_HANDLE),color);
}



void display_time(int playtime)
{
    gotoxy(WIDTH/2+5,0);
    font_color(7);
    printf("Play Time : %2d",time(NULL)-playtime);
}


void print_img(int x, int y, FILE *fp)
{
    int ch;
    fseek(fp,SEEK_SET,0);
    gotoxy(x,y);
    while((ch=fgetc(fp))!=EOF)
    {
        if(ch=='\n')
            gotoxy(x,++y);
        else
            printf("%c",ch);
    }
}


void delete_img(int x, int y, FILE *fp)
{
    char ch;
    fseek(fp,SEEK_SET,0);
    gotoxy(x,y);
    while((ch=fgetc(fp))!=EOF)
    {
        if(ch=='\n')
            gotoxy(x,++y);
        printf(" ");
    }
}


void move_img(int *x,int *y, FILE *fp)
{
    delete_img(*x,*y,fp);
        switch(getch())
        {
            case 75: //←
                *x-=USER_SPEED;
                print_img(*x,*y,fp);
                break;
            case 77: //→
                *x+=USER_SPEED;
                print_img(*x,*y,fp);
                break;
            case 72: //↑
                *y-=USER_SPEED;
                print_img(*x,*y,fp);
                break;
            case 80: //↓
                *y+=USER_SPEED;
                print_img(*x,*y,fp);
                break;
        }
}


void starting()
{
    FILE *fp = fopen("opening.txt","r");
    print_img(0,13,fp);
}

void print_abc(int x,int y,char ch)
{
    char str[100];
    FILE *fp;
    sprintf(str,".//abc//%c.txt",ch);
    fp=fopen(".//abc//D.txt","r");
    print_img(x,y,fp);
    fclose(fp);
}


int main()
{
    //선언
    int score = 0;
    int x=10,y=10;
    int t;
    int input;
    char text,ch;
    int playtime = time(NULL);
    FILE *fp=fopen(".//abc//A.txt","r");
    srand(time(NULL));
    //선언


    //콘솔 세팅
    set_con();
    //set_edge();
    //콘솔 세팅


    //music start
    PlaySound(".\\sounds\\Marshmello - TELL ME.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    //music start

    //작업

    starting();

    print_img(10,10,fp);
    getch();

    while(1)
    {

        if(!kbhit())//keyboard hit
            continue;
        switch(getch())
        {
            case 224://방향키 아스키 224 75 이런식으로 2byte
                move_img(&x,&y,fp);
                Sleep(1);
                break;
            case 'a':
                goto game_stop;
        }
    }
    //작업

    //종료
    system("cls");
    printf ("you win!\nplay time : %ds",time(NULL)-playtime);
    getchar();
    system("cls");
    fclose(fp);
    PlaySound(NULL, 0, 0);
    return 0;
    game_stop:
    system("cls");
    printf("게임을 종료 하시겠습니까?");
    getch();
    fclose(fp);
    PlaySound(NULL, 0, 0);
    return 0;
    //종료
}
