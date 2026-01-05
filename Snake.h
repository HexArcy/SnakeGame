#ifndef SNAKE_H
#define SNAKE_H

struct Snake{
    int x[100];
    int y[100];
    int length;
    int speed;
    int count;
};
struct Food{
	int x;
	int y;
};
extern int a[];

void initsnake(Snake *snake);
void printsnake(Snake *snake);
void movesnake(Snake *snake);
void eatfood(Snake *snake,Food *food);
void printfood(Snake *snake,Food *food);
int is_dead(Snake *snake);

#endif
