#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*cube�� ������ ������ ���ڵ�� ��Ÿ����*/
#define U 0
#define B 1
#define L 2
#define F 3
#define R 4
#define D 5
#define MAX_INPUT 100 //����� �Է� �ִ밹�� = 100 

char cube[6][3][3] = { 0, };
int rotate_count; //����Ƚ��

/*ť�� �ʱ�ȭ*/
void initCube();
void initSection(char section[3][3], char color);
/*ť�� ������ ����*/
//void mixCube();

int getInput(char* command);

void execute(char* command);

/*ť��ȸ��*/
void rotateCube(char face, int direction);
void rotateU(); //direction 0:�ð����, 1:�ݽð����
void rotateB();
void rotateL();
void rotateF();
void rotateR();
void rotateD();

/*ť�� üũ*/
int checkCube();
int checkSection(char section[3][3]);
/*ť�� ���*/
void printCube();

/*���� ������*/
int checkState();
void printResult(int time);
