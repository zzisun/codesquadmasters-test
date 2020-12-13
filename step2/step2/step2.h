#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 100 //사용자 입력 최대갯수 = 100 
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


/* 사용자의 입력을 받는다 */
int getInput(char* command);

void getCommand(QUEUE* q, char* command);

int execute(QUEUE* q, char line, int direction);

/*원형 큐 만든다. //단어의 알파벳마다 노드로 만든다*/
QUEUE* makeQueue();
void makeRow(QUEUE* queue, int row);
void makeCol(QUEUE* queue, int col);

/*QUEUE의 head를 이동시켜 단어를 밀어낸다*/
void pushWord(QUEUE* q, char direction);
void changeRow(QUEUE* q, int line);
void changeCol(QUEUE* q, int line);

/*할당된 메모리 free*/
void freeQueue(QUEUE* q);

/*pushed cube 출력*/
void printCube();
