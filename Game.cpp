#include "Game.h"
#include "Snake.h"

void gotoxy(int x,int y){
	COORD pos;
	pos.X=x;
	pos.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void hidecursor(){
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursorInfo);
    cursorInfo.bVisible=FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursorInfo);
}
void cover(){
	for(int i=0;i<=WIDE+3;i++){
		gotoxy(FRAMEX+i,FRAMEY);
		printf("=");
	}
	for(int i=0;i<=WIDE+3;i++){
		gotoxy(FRAMEX+i,FRAMEY+HIGH+1);
		printf("=");
	}
	for(int i=1;i<=HIGH;i++){
		gotoxy(FRAMEX,FRAMEY+i);
		printf("||");
	}
	for(int i=1;i<=HIGH;i++){
		gotoxy(FRAMEX+WIDE+2,FRAMEY+i);
		printf("||");
	}
	gotoxy(FRAMEX+2,FRAMEY+3);
	printf("   ____    _   _      _      _  __  _____     ____      _      __  __   _____ ");
	gotoxy(FRAMEX+2,FRAMEY+4);
	printf("  / ___|  | \\ | |    / \\    | |/ / | ____|   / ___|    / \\    |  \\/  | | ____|");
	gotoxy(FRAMEX+2,FRAMEY+5);
	printf("  \\___ \\  |  \\| |   / _ \\   | ' /  |  _|    | |  _    / _ \\   | |\\/| | |  _|  ");
	gotoxy(FRAMEX+2,FRAMEY+6);
	printf("   ___) | | |\\  |  / ___ \\  | . \\  | |___   | |_| |  / ___ \\  | |  | | | |___ ");
	gotoxy(FRAMEX+2,FRAMEY+7);
	printf("  |____/  |_| \\_| /_/   \\_\\ |_|\\_\\ |_____|   \\____| /_/   \\_\\ |_|  |_| |_____|");
	gotoxy(FRAMEX+WIDE/2-5,FRAMEY+HIGH-1);
	printf("Press Enter");
	hidecursor();
	char a;
	a=getchar();
	system("cls");
}
void makeframe(){
	gotoxy(FRAMEX+WIDE+6,FRAMEY+1);
	printf("SnakeGame");
	gotoxy(FRAMEX+WIDE+6,FRAMEY+3);
	printf("WASD移动/继续");
	gotoxy(FRAMEX+WIDE+6,FRAMEY+5);
	printf("任意键暂停");
	gotoxy(FRAMEX+WIDE+6,FRAMEY+7);
	printf("`加入宗门");
	gotoxy(FRAMEX+WIDE+6,FRAMEY+9);
	printf("ESC紫砂");
	for(int i=0;i<=WIDE+3;i++){
		gotoxy(FRAMEX+i,FRAMEY);
		printf("=");
	}
	for(int i=0;i<=WIDE+3;i++){
		gotoxy(FRAMEX+i,FRAMEY+HIGH+1);
		printf("=");
	}
	for(int i=1;i<=HIGH;i++){
		gotoxy(FRAMEX,FRAMEY+i);
		printf("||");
	}
	for(int i=1;i<=HIGH;i++){
		gotoxy(FRAMEX+WIDE+2,FRAMEY+i);
		printf("||");
	}
}
void infor(Snake *snake){
	gotoxy(FRAMEX+WIDE+6,FRAMEY+18);
	printf("当前速度:%.2f字节/秒",1000.0/snake->speed);
	gotoxy(FRAMEX+WIDE+6,FRAMEY+20);
	printf("已食用数量:%d",snake->count);
}
void gameover(Snake *snake){
	system("cls");
	for(int i=0;i<=WIDE+3;i++){
		gotoxy(FRAMEX+i,FRAMEY);
		printf("=");
	}
	for(int i=0;i<=WIDE+3;i++){
		gotoxy(FRAMEX+i,FRAMEY+HIGH+1);
		printf("=");
	}
	for(int i=1;i<=HIGH;i++){
		gotoxy(FRAMEX,FRAMEY+i);
		printf("||");
	}
	for(int i=1;i<=HIGH;i++){
		gotoxy(FRAMEX+WIDE+2,FRAMEY+i);
		printf("||");
	}
	gotoxy(FRAMEX+11,FRAMEY+3);
	printf(" __   __   ___    _   _     ____    _____      _      ____  ");
	gotoxy(FRAMEX+11,FRAMEY+4);
	printf(" \\ \\ / /  / _ \\  | | | |   |  _ \\  | ____|    / \\    |  _ \\ ");
	gotoxy(FRAMEX+11,FRAMEY+5);
	printf("  \\ V /  | | | | | | | |   | | | | |  _|     / _ \\   | | | |");
	gotoxy(FRAMEX+11,FRAMEY+6);
	printf("   | |   | |_| | | |_| |   | |_| | | |___   / ___ \\  | |_| |");
	gotoxy(FRAMEX+11,FRAMEY+7);
	printf("   |_|    \\___/   \\___/    |____/  |_____| /_/   \\_\\ |____/ ");                                          
	gotoxy(FRAMEX+WIDE/2-5,FRAMEY+HIGH-3);
	printf("最终得分:%d",snake->count);
	gotoxy(FRAMEX+WIDE/2-7,FRAMEY+HIGH-1);
	printf("重新开始?(y/n)");
}
