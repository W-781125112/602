#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include "SnakeGame.h"
#include <windows.h>
#include <conio.h>


//定义一个蛇和食物
SNAKE snake;
FOOD food;

//方向增量
int dx = 0;
int dy = 0;

//记录尾节点的位置
int lx = 0;
int ly = 0;

//初始化食物
void init_food(void)
{
	food.x = rand() % WIDE;
	food.y = rand() % HIGH;
}

//初始化蛇
void init_snake(void)
{
	snake.size = 2;
	//将蛇头定位到中间位置
	snake.body[0].x = WIDE / 2;
	snake.body[0].y = HIGH / 2;
	//蛇身紧跟蛇头
	snake.body[1].x = WIDE / 2 - 1;
	snake.body[1].y = HIGH / 2;
}


//初始化墙
void init_wall(void)
{
	for (size_t y = 0; y <= HIGH; y++)
	{
		for (size_t x = 0; x <= WIDE; x++)
		{
			if (x == WIDE || y == HIGH)
			{
				printf("=");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	
}

//显示UI
void showUI(void)
{
	//显示食物

	//存放光标位置
	COORD coord;
	coord.X = food.x;
	coord.Y = food.y;
	//光标定位
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	putchar('#');

	//显示蛇
	for (size_t i = 0; i < snake.size; i++)
	{
		//设置光标
		coord.X = snake.body[i].x;
		coord.Y = snake.body[i].y;
		//定位光标
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		if (i == 0)
		{
			putchar('@');
		}
		else
		{
			putchar('*');
		}
	}
	//处理尾节点
	coord.X = lx;
	coord.Y = ly;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	putchar(' ');
}

void playGame(void)
{
	char key = 'D';

	//蛇不能撞墙
	while (snake.body[0].x>=0 && snake.body[0].x<WIDE && snake.body[0].y>=0 && snake.body[0].y<HIGH)
	{
		//蛇不能撞自己
		for (size_t i = 1; i < snake.size; i++)
		{
			if (snake.body[0].x == snake.body[i].x && snake.body[0].y == snake.body[i].y)
			{
				return;
			}
		}
		//撞食物
		if (snake.body[0].x == food.x && snake.body[0].y == food.y)
		{
			//长个子
			snake.size++;
			//随机出现食物
			init_food();
		}

		//控制蛇移动
		//判断按键是否按下
		if (_kbhit())
		{
			key = _getch();	//按下立马确认
			//_getch();	//清空空字符
		}
		
		//判断wasd哪个键按下
		switch (key)
		{
		case 'w':
		case 'W':
			dx = 0;
			dy = -1;
			break;
		case 'a':
		case 'A':
			dx = -1;
			dy = 0;
			break;
		case 's':
		case 'S':
			dx = 0;
			dy = 1;
			break;
		case 'd':
		case 'D':
			dx = 1;
			dy = 0;
			break;
		}
		
		//蛇的移动
		//记录尾节点位置
		lx = snake.body[snake.size - 1].x;
		ly = snake.body[snake.size - 1].y;

		//移动
		for (size_t i = snake.size-1; i > 0; i--)
		{
			snake.body[i].x = snake.body[i - 1].x;
			snake.body[i].y = snake.body[i - 1].y;
		}
		//更新蛇头
		snake.body[0].x += dx;
		snake.body[0].y += dy;

		//显示
		showUI();
		Sleep(500);
	}
}