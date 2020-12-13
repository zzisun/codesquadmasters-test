#include "step1.h"

int main() {

	char word[200];
	char direction;
	int number;

	flag = 0;
	while (flag != 1) {
		getInput(word, &number, &direction);
		QUEUE* queue = makeQueue(word);
		makeNode(queue, word);
		pushWord(queue, number, direction);

		printWord(queue);
		freeQueue(queue);
	}

	return 0;
}

void getInput(char* word, int* number, char* direction) {
	printf("> ");
	scanf("%s %d %c", word, number, direction);
}

QUEUE* makeQueue(char* word) {
	QUEUE* q = (QUEUE*)malloc(sizeof(QUEUE));
	q->head = NULL;
	q->count = strlen(word);
	return q;
}

void makeNode(QUEUE* queue, char* word) {

	int i;
	NODE* current = NULL;

	for (i = 0; i < queue->count; i++) {
		NODE* new = (NODE*)malloc(sizeof(NODE));
		new->data = word[i];
		new->next = NULL;

		if (queue->head == NULL) {
			queue->head = new;
			current = new;
		}
		else {
			current->next = new;
			current = new;
		}
	}
	current->next = queue->head; //circular queue
}

void pushWord(QUEUE* q, int number, char direction) {
	if (direction == 'l' || direction == 'L')
		pushLeft(q, number);
	else if (direction == 'r' || direction == 'R') {
		pushRight(q, number);
	}
	else {
		printf("Wrong direction!\n");
	}
}

void pushLeft(QUEUE* q, int number) {

	NODE* ptr = q->head;
	for (int i = 0; i < number; i++) {
		ptr = ptr->next;
	}
	q->head = ptr;

}

void pushRight(QUEUE* q, int number) {

	int word_length = q->count;
	number %= word_length;
	pushLeft(q, word_length-number);
}

void printWord(QUEUE* q) {
	NODE* ptr = NULL;
	for (ptr = q->head; ptr->next != q->head; ptr = ptr->next) {
		printf("%c", ptr->data);
	}
	printf("%c\n\n", ptr->data);
}

void freeQueue(QUEUE* q) {
	free(q);
}