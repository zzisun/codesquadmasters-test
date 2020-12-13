#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node {
	char data;
	struct _node* next;
}NODE;

typedef struct _queue {
	NODE* head;
	int count;
}QUEUE;

int flag; //error handler

/* 사용자의 입력을 받는다 */
void getInput(char* word, int* number, int* direction); 

/*원형 큐 만든다. //단어의 알파벳마다 노드로 만든다*/
QUEUE* makeQueue(char* word); 
void makeNode(QUEUE* queue, char* word); 

void pushWord(QUEUE* q, int number, char direction);
void pushLeft(QUEUE* q, int number);
void pushRight(QUEUE* q, int number);

void printWord(QUEUE* q); 

void freeQueue(QUEUE* q);
