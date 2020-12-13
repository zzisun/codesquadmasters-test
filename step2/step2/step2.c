#include "step2.h"

int main() {

	printCube();

	int exit_flag=0;
	char command[MAX_INPUT];

	while (exit_flag != 1) {
		exit_flag = getInput(command);
		if (exit_flag) {
			printf("Bye~\n");
			break;
		}
		QUEUE* queue = makeQueue();
		getCommand(queue, command);
		//if (exit_flag)break;
	}

	return 0;
}

int getInput(char* command) {
	int res;

	printf("CUBE> ");
	scanf("%s",command);

	if (command[0] == 'Q')
		res = 1; // 'Q'ют╥б╫ц exit_flag set
	else
		res = 0;

	return res;
}

void getCommand(QUEUE* q, char* command) {
	int res = 0;
	int count = strlen(command);
	char line;
	int direction; //0: left,up  1:right, down
	for (int i = 0; i < count; i++) {
		q->head = NULL;
		if (command[i] == 39) {
			continue;
		}
		else {
			line = command[i];
			if (command[i + 1] == 39) {//39 in ascii code
				direction = 1;
				printf("\n%c'", line);
			}
			else {
				direction = 0;
				printf("\n%c", line);
			}
			execute(q, line, direction);
			printCube();
		}
	}
}

QUEUE* makeQueue() {
	QUEUE* q = (QUEUE*)malloc(sizeof(QUEUE));
	q->head = NULL;
	q->count = MAT_SIZE;

	return q;
}

void makeRow(QUEUE* queue, int row) {

	int i;
	NODE* current = NULL;

	for (i = 0; i < queue->count; i++) {
		NODE* new = (NODE*)malloc(sizeof(NODE));
		new->data = cube[row][i];
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

void makeCol(QUEUE* queue, int col) {
	int i;
	NODE* current = NULL;

	for (i = 0; i < queue->count; i++) {
		NODE* new = (NODE*)malloc(sizeof(NODE));
		new->data = cube[i][col];
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

int execute(QUEUE* q, char line, int direction) { 
	int res = 0; // if wrong direction, res=1

	switch (line) {  // "'" = 39
	case 'R':
		makeCol(q, MAT_SIZE-1);
		pushWord(q, direction);
		changeCol(q, MAT_SIZE - 1);
		break;
	case 'L':
		makeCol(q, 0);
		pushWord(q, direction);
		changeCol(q, 0);
		break;
	case 'U':
		makeRow(q, 0);
		pushWord(q, direction);
		changeRow(q, 0);
		break;
	case 'B':
		makeRow(q, MAT_SIZE-1);
		pushWord(q, direction);
		changeRow(q, MAT_SIZE - 1);
		break;
	default:
		printf("Wrong direction!\n\n");
		res = 1;
		break;
	}

	return res;
}

void pushWord(QUEUE* q, int direction) {

	NODE* ptr = q->head;
	if (direction == 0) {
		q->head = q->head->next;
	}
	else {
		for (int i = 0; i < MAT_SIZE - 1; i++) {
			ptr = ptr->next;
		}
		q->head = ptr;
	}
}

void changeRow(QUEUE* q, int line) {
	NODE* ptr = q->head;
	for (int i = 0; i < MAT_SIZE; i++, ptr=ptr->next) {
		cube[line][i] = ptr->data;
	}
}

void changeCol(QUEUE* q, int line) {
	NODE* ptr = q->head;
	for (int i = 0; i < MAT_SIZE; i++, ptr = ptr->next) {
		cube[i][line] = ptr->data;
	}
}

void freeQueue(QUEUE* q) {
	q->head = NULL;
	/*NODE* ptr = q->head;
	NODE* del = ptr;

	while (del != NULL) {
		ptr = ptr->next;
		free(del);
		del = ptr;
	}

	if (q->head)
		printf("FAIL\n");*/
}

void printCube() {
	printf("\n");
	for (int i = 0; i < MAT_SIZE; i++) {
		for (int j = 0; j < MAT_SIZE; j++) {
			printf("%c ", cube[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

/*void pushLeft(QUEUE* q) {

	NODE* ptr = q->head;
	for (int i = 0; i < number; i++) {
		ptr = ptr->next;
	}
	q->head = ptr;

}

void pushRight(QUEUE* q) {

	int word_length = q->count;
	number %= word_length;
	pushLeft(q, word_length - number);
}

void printWord(QUEUE* q) {
	NODE* ptr = NULL;
	for (ptr = q->head; ptr->next != q->head; ptr = ptr->next) {
		printf("%c", ptr->data);
	}
	printf("%c\n\n", ptr->data);
}
*/