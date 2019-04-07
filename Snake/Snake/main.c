#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#include "SnakeGame.h"

int main(int argc, char *argv[])
{
	//设置随机种子
	srand(time(NULL));

	//取消光标
	CONSOLE_CURSOR_INFO cci;
	cci.bVisible = FALSE;	//取消光标
	cci.dwSize = sizeof(cci);
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);

	init_wall();
	init_food();
	init_snake();

	playGame();
	//system("pause");
	getchar();
	return 0;
}