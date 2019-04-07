#pragma once

#define WIDE 60  //��
#define HIGH 20  //��


extern void init_wall(void);
extern void init_food(void);
extern void init_snake(void);
extern void showUI(void);
extern void playGame(void);


 typedef struct  
 {
	 int x;
	 int y;
 }FOOD;	//ʳ�������

 typedef struct
 {
	 int x;
	 int y;
 }BODY;

 typedef struct 
 {
	 int size;	//���峤��
	 BODY body[WIDE*HIGH];
 }SNAKE;	//�ߵ�����

