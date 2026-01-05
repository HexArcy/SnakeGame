#include<conio.h>
#include"Game.h"
#include"Snake.h"

int a[2];
int main(){
	game_start:
	unsigned char ch='d',lastch='d';
	cover();
	Snake s,*snake=&s;
	Food f,*food=&f;
	makeframe();
	initsnake(snake);
	printfood(snake,food);
	Sleep(500);
	while(1){
		infor(snake);
		a[0]=snake->x[0];
		a[1]=snake->y[0];
		if(kbhit()){
			lastch=ch;
			ch=getch();
			while(kbhit())getch();
		}
		if((lastch=='w'||lastch=='W')&&(ch=='s'||ch=='S'))ch='w';
		else if((lastch=='s'||lastch=='S')&&(ch=='w'||ch=='W'))ch='s';
		else if((lastch=='a'||lastch=='A')&&(ch=='d'||ch=='D'))ch='a';
		else if((lastch=='d'||lastch=='D')&&(ch=='a'||ch=='A'))ch='d';
		switch(ch){
			case 'W':
			case 'w':{
				movesnake(snake);
				snake->y[snake->length-1]-=1;
				break;
			}
			case 'S':
			case 's':{
				movesnake(snake);
				snake->y[snake->length-1]+=1;
				break;
			}
			case 'A':
			case 'a':{
				movesnake(snake);
				snake->x[snake->length-1]-=2;
				break;
			}
			case 'D':
			case 'd':{
				movesnake(snake);
				snake->x[snake->length-1]+=2;
				break;
			}
			case '`':{
				snake->speed=20;
				snake->count+=30;
				ch=lastch;
				break;
			} 
		}
		eatfood(snake,food);
		printsnake(snake);
		if(is_dead(snake)==1||ch==27){
			Sleep(500);
			gameover(snake);
			while(ch=getch()){
				if(ch=='y'){
					system("cls");
					goto game_start;				
				}else if(ch=='n')
					return 0;
			}
		}
		Sleep(snake->speed);
	}
}
