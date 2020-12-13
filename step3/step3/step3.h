#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*cube의 각면을 다음의 숫자들로 나타낸다*/
#define U 0
#define B 1
#define L 2
#define F 3
#define R 4
#define D 5
#define MAX_INPUT 100 //사용자 입력 최대갯수 = 100 

char cube[6][3][3] = { 0, };
int rotate_count; //조작횟수

/*큐브 초기화*/
void initCube();
void initSection(char section[3][3], char color);
/*큐브 무작위 섞기*/
//void mixCube();

int getInput(char* command);

void execute(char* command);

/*큐브회전*/
void rotateCube(char face, int direction);
void rotateU(); //direction 0:시계방향, 1:반시계방향
void rotateB();
void rotateL();
void rotateF();
void rotateR();
void rotateD();

/*큐브 체크*/
int checkCube();
int checkSection(char section[3][3]);
/*큐브 출력*/
void printCube();

/*실행 결과출력*/
int checkState();
void printResult(int time);
