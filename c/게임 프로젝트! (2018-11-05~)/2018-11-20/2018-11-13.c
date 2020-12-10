#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include<conio.h>
#include<time.h>
#define WIDTH 50
#define HEIGHT 24
#define LEFT 75
#define RIGHT 77
#define STAR_NUM 6
#define STAR_SPEED_SET 5

int speed_up=0;

typedef struct _Star
{
   int x;
   int y;
   int speed;
}Star;
void gotoxy(int x, int y) {
   COORD pos = { x, y };
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void resizeConsole() {
   char chTemp[50];
   sprintf(chTemp, "Mode con cols=%d lines=%d", WIDTH, HEIGHT);
   system(chTemp);
}
void clearCursor() {
   CONSOLE_CURSOR_INFO c = { 0 };
   c.dwSize = 1;
   c.bVisible = FALSE;
   SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &c);
}
void displayStartScreen() {
   while (!kbhit()) {
      gotoxy(11, HEIGHT / 2);
      printf("시작하려면 아무키나 누르세요");
      Sleep(400);
      gotoxy(11, HEIGHT / 2);
      printf("                            ");
      Sleep(600);
   }
   while (_kbhit()) {
      _getch();
   }
}
void printBound() {
   for (int y = 0; y < HEIGHT; y++) {
      for (int x = 0; x < WIDTH; x += 2) {
         if (y < 2) printf("\n");
         else if (x == 0 || y == 2 || x == WIDTH - 2 || y == HEIGHT - 1) printf("■");
         else printf("  ");
      }
   }
}
void initstar(Star *s)
{
   for(int i=0;i<STAR_NUM;i++)
   {
      s[i].x=rand()%46+2;
      s[i].y=3;
      s[i].speed = rand() % STAR_SPEED_SET + 1;
   }
}
void displaystar(Star *s, int count, int *HP, int user_x)
{
   for(int i=0;i<STAR_NUM;i++)
   {
        if(count % s[i].speed )
            continue;
        if(s[i].y >3)
        {
            gotoxy(s[i].x,s[i].y-1);
            printf(" ");
        }
        if(s[i].y > HEIGHT -2)
        {
            gotoxy(s[i].x, s[i].y - 1);
            printf(" ");
            if(user_x == s[i].x||user_x == s[i].x-1)
                (*HP)--;
            s[i].x = rand()%46+2;
            s[i].y=3;
            if(speed_up > 13)
                speed_up=13;
            s[i].speed = rand() % STAR_SPEED_SET + 15 - ++speed_up;
        }

      gotoxy(s[i].x, s[i].y);
      printf("*");
      s[i].y++;
   }
}
void displayScore(int s) {
   gotoxy(WIDTH / 2, 1);
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
   printf("Score : %2d", s);
}
void displayHP(int HP) {
   gotoxy(WIDTH / 2 - 9, 1);
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
   printf("HP : %2d", HP);
}
void move(int x, int dir)
{
   if(dir==LEFT)
   {
      gotoxy(x+1,HEIGHT-2);
      printf(" ");
   }
   else if(dir == RIGHT)
   {
      gotoxy(x-1,HEIGHT-2);
      printf(" ");
   }
   gotoxy(x,HEIGHT-2);
   printf("▲");
}

int main()
{
   srand(time(NULL));
   char ch='y';
   int score = 0;
   int count = 0;
   int HP = 3;
   char key;
   int xPosition = WIDTH/2;
   Star s[STAR_NUM];
   resizeConsole();
   clearCursor();
   displayStartScreen();
   while(ch == 'y')
   {
       HP = 3;
       count = 0;
       score = 0;
       system("cls");
       printBound();
       displayScore(score);
       initstar(s);
       move(xPosition,0);
       while (1) {
             displaystar(s,count,&HP,xPosition);
             if(kbhit())
             {
             key = getch();
             if(key==LEFT)
             {
                if(xPosition>2)
                   move(--xPosition,LEFT);
             }
             else if(key==RIGHT)
             {
                if(xPosition< WIDTH-4)
                   move(++xPosition,RIGHT);
             }
          }
             if (count % 100 == 0) {
             displayScore(score);
             displayHP(HP);
             score++;
             count = 0;
          }
          Sleep(10);
          count++;
          if (HP <= 0)
            break;
       }
       displayHP(HP);
       displayScore(score);
        gotoxy(WIDTH / 2 -6, HEIGHT / 2);
       printf("you are loser");
       gotoxy(WIDTH / 2 -6, HEIGHT / 2 + 1);
       printf("score : %d",score);
       gotoxy(WIDTH / 2 -6, HEIGHT / 2 + 2);
       printf("do you want a retry?(y/n) : ");
       ch = getch();
    }
   return 0;
}
