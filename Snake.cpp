#include "Snake.h"
#include "Game.h"

void initsnake(Snake *snake){
    snake->x[0]=FRAMEX+2;
	snake->y[0]=FRAMEY+HIGH/2;
	snake->count=0;
	snake->length=3;
	snake->speed=400;
	for(int i=1;i<snake->length;i++){
		snake->x[i]=snake->x[i-1]+1;
		snake->y[i]=snake->y[i-1];
	}
}
void printsnake(Snake *snake){
	for(int i=0;i<snake->length;i++){
		gotoxy(snake->x[i],snake->y[i]);
		if(i==snake->length-1)
			printf("Í·");
		else if(i==0)
			printf("Î²");
		else
			printf("Éí");
	}
}
void movesnake(Snake *snake){
    gotoxy(snake->x[0],snake->y[0]);
	printf("  ");
	for(int i=1;i<snake->length;i++) {
		snake->x[i-1]=snake->x[i];
		snake->y[i-1]=snake->y[i];
	}
}
void eatfood(Snake *snake,Food *food){
	if(snake->x[snake->length-1]==food->x&&snake->y[snake->length-1]==food->y){
		snake->length++;
		for(int i=snake->length-1;i>0;i--){
			snake->x[i]=snake->x[i-1];
			snake->y[i]=snake->y[i-1];
		}
		snake->x[0]=a[0];
		snake->y[0]=a[1];
		printfood(snake,food);
		snake->count++;
		snake->speed-=15;
		if(snake->speed<20)
			snake->speed=20;
	}
}
void printfood(Snake *snake,Food *food){
	srand((unsigned)time(NULL));
	while(1){
		int i;
		food->x=(rand()%(WIDE/2))*2+2+FRAMEX;
		food->y=rand()%(HIGH-2)+1+FRAMEY;
		for(i=0;i<snake->length;i++){
			if(food->x==snake->x[i]&&food->y==snake->y[i])
				break;
		}
		if(i==snake->length){
			gotoxy(food->x,food->y);
			printf("Ê³");
			break;
		}
	}
}
int is_dead(Snake *snake){
	if(snake->x[snake->length-1]==FRAMEX)
		return 1;
	if(snake->x[snake->length-1]==FRAMEX+WIDE+2)
		return 1;
	if(snake->y[snake->length-1]==FRAMEY)
		return 1;
	if(snake->y[snake->length-1]==FRAMEY+HIGH+1)
		return 1;
	return 0;
}
