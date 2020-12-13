#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 100 //����� �Է� �ִ밹�� = 100 
#define MAT_SIZE 3


char cube[MAT_SIZE][MAT_SIZE] = { {'R', 'R', 'W'},
										{'G', 'C', 'W'},
										{'G', 'B', 'B'} };
typedef struct _node {
	char data;
	struct _node* next;
}NODE;

typedef struct _queue {
	NODE* head;
	int count;
}QUEUE;


/* ������� �Է��� �޴´� */
int getInput(char* command);

void getCommand(QUEUE* q, char* command);

int execute(QUEUE* q, char line, int direction);

/*���� ť �����. //�ܾ��� ���ĺ����� ���� �����*/
QUEUE* makeQueue();
void makeRow(QUEUE* queue, int row);
void makeCol(QUEUE* queue, int col);

/*QUEUE�� head�� �̵����� �ܾ �о��*/
void pushWord(QUEUE* q, char direction);
void changeRow(QUEUE* q, int line);
void changeCol(QUEUE* q, int line);

/*�Ҵ�� �޸� free*/
void freeQueue(QUEUE* q);

/*pushed cube ���*/
void printCube();
