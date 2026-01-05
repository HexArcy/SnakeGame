#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <windows.h>
#include <time.h>

#define FRAMEX 5
#define FRAMEY 2
#define WIDE 80
#define HIGH 20

struct Snake;

void gotoxy(int x,int y);
void hidecursor();
void cover();
void makeframe();
void infor(Snake *snake);
void gameover(Snake *snake);

#endif
