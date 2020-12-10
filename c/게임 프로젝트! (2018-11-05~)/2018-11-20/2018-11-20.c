#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include<conio.h>
#include<time.h>
#define WIDTH 50
#define HEIGHT 24
#define LEFT 75
#define RIGHT 77
#define DOWN 80
#define STAR_NUM 6
#define STAR_SPEED_SET 5

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
         if (x == 0 || y == 0 || x == WIDTH - 2 || y == HEIGHT - 1) printf("★");
         else printf("  ");
      }
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
   else if(dir == DOWN)
   {

   }
   gotoxy(x,HEIGHT-2);
   printf("▲");
}

int main()
{
   srand(time(NULL));
   char ch='y';
   int score = 0;
   char key;
   int xPosition = WIDTH/2;
   int yPosition = HEIGHT/2;
   resizeConsole();
   clearCursor();
   displayStartScreen();
   while(ch == 'y')
   {
       score = 0;
       system("cls");
       printBound();
       while (1) {
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
          Sleep(10);
       }
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
