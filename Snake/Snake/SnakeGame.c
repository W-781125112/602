#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include "SnakeGame.h"
#include <windows.h>
#include <conio.h>


//����һ���ߺ�ʳ��
SNAKE snake;
FOOD food;

//��������
int dx = 0;
int dy = 0;

//��¼β�ڵ��λ��
int lx = 0;
int ly = 0;

//��ʼ��ʳ��
void init_food(void)
{
	food.x = rand() % WIDE;
	food.y = rand() % HIGH;
}

//��ʼ����
void init_snake(void)
{
	snake.size = 2;
	//����ͷ��λ���м�λ��
	snake.body[0].x = WIDE / 2;
	snake.body[0].y = HIGH / 2;
	//���������ͷ
	snake.body[1].x = WIDE / 2 - 1;
	snake.body[1].y = HIGH / 2;
}


//��ʼ��ǽ
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

//��ʾUI
void showUI(void)
{
	//��ʾʳ��

	//��Ź��λ��
	COORD coord;
	coord.X = food.x;
	coord.Y = food.y;
	//��궨λ
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	putchar('#');

	//��ʾ��
	for (size_t i = 0; i < snake.size; i++)
	{
		//���ù��
		coord.X = snake.body[i].x;
		coord.Y = snake.body[i].y;
		//��λ���
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
	//����β�ڵ�
	coord.X = lx;
	coord.Y = ly;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	putchar(' ');
}

void playGame(void)
{
	char key = 'D';

	//�߲���ײǽ
	while (snake.body[0].x>=0 && snake.body[0].x<WIDE && snake.body[0].y>=0 && snake.body[0].y<HIGH)
	{
		//�߲���ײ�Լ�
		for (size_t i = 1; i < snake.size; i++)
		{
			if (snake.body[0].x == snake.body[i].x && snake.body[0].y == snake.body[i].y)
			{
				return;
			}
		}
		//ײʳ��
		if (snake.body[0].x == food.x && snake.body[0].y == food.y)
		{
			//������
			snake.size++;
			//�������ʳ��
			init_food();
		}

		//�������ƶ�
		//�жϰ����Ƿ���
		if (_kbhit())
		{
			key = _getch();	//��������ȷ��
			//_getch();	//��տ��ַ�
		}
		
		//�ж�wasd�ĸ�������
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
		
		//�ߵ��ƶ�
		//��¼β�ڵ�λ��
		lx = snake.body[snake.size - 1].x;
		ly = snake.body[snake.size - 1].y;

		//�ƶ�
		for (size_t i = snake.size-1; i > 0; i--)
		{
			snake.body[i].x = snake.body[i - 1].x;
			snake.body[i].y = snake.body[i - 1].y;
		}
		//������ͷ
		snake.body[0].x += dx;
		snake.body[0].y += dy;

		//��ʾ
		showUI();
		Sleep(500);
	}
}