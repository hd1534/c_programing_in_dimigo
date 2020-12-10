#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include<conio.h>
#include<time.h>
#define WIDTH 50
#define HEIGHT 24
#define LEFT 75
#define RIGHT 77
#define STAR_NUM 3
typedef struct _Star
{
   int x;
   int y;
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
   }
}
void displaystar(Star *s)
{
   for(int i=0;i<STAR_NUM;i++)
   {
      gotoxy(s[i].x,s[i].y-1);
      printf(" ");
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
int main() {
   srand(time(NULL));
   int score = 0;
   int count = 0;
   char key;
   int xPosition = WIDTH/2;
   Star s[STAR_NUM];
   resizeConsole();
   clearCursor();
   displayStartScreen();
   system("cls");
   printBound();
   displayScore(score);
   initstar(s);
   move(xPosition,0);
   while (1) {
         if(count%30==0)
         {
         displaystar(s);
      }
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
         score++;
         count = 0;
      }
      Sleep(10);
      count++;
   }
   getchar();
}
