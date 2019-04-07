#pragma once

#define WIDE 60  //宽
#define HIGH 20  //高


extern void init_wall(void);
extern void init_food(void);
extern void init_snake(void);
extern void showUI(void);
extern void playGame(void);


 typedef struct  
 {
	 int x;
	 int y;
 }FOOD;	//食物的类型

 typedef struct
 {
	 int x;
	 int y;
 }BODY;

 typedef struct 
 {
	 int size;	//身体长度
	 BODY body[WIDE*HIGH];
 }SNAKE;	//蛇的类型

