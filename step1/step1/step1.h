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

/* ������� �Է��� �޴´� */
void getInput(char* word, int* number, int* direction); 

/*���� ť �����. //�ܾ��� ���ĺ����� ���� �����*/
QUEUE* makeQueue(char* word); 
void makeNode(QUEUE* queue, char* word); 

void pushWord(QUEUE* q, int number, char direction);
void pushLeft(QUEUE* q, int number);
void pushRight(QUEUE* q, int number);

void printWord(QUEUE* q); 

void freeQueue(QUEUE* q);
