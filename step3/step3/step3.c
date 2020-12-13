#include "step3.h"

int main() {

	int exit_flag = 0;
	int end_flag = 0;
	char mix_flag;
	char command[MAX_INPUT];
	rotate_count = 0;
	int total_time;

	initCube();

	printf("Choose to Mix (Y/N): ");
	scanf("%c", &mix_flag);
	if(mix_flag == 'Y')
		mixCube(); //무작위 섞기

	printCube();

	clock_t start = clock();
	while (exit_flag != 1) {
		exit_flag = getInput(command);
		if (exit_flag)
			break;
		execute(command);
		end_flag = checkCube();
		if (end_flag) {
			printf("축하합니다! 큐브의 모든면이 맞춰졌습니다~\n");
			break;
		}
	}
	clock_t end = clock();
	total_time = (int)(end - start)/CLOCKS_PER_SEC;
	printResult(total_time);

	return 0;
}

void initCube() {
	initSection(cube[U], 'B');
	initSection(cube[B], 'W');
	initSection(cube[L], 'O');
	initSection(cube[F], 'G');
	initSection(cube[R], 'Y');
	initSection(cube[D], 'R');
}
void initSection(char section[3][3], char color) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			section[i][j] = color;
		}
	}
}
void mixCube() {
	int count;

	srand(time(NULL));

	count = rand() % (4 + 1);
	for (int i = 0; i < count; i++)
		rotateU();

	count = rand() % (4 + 1);
	for (int i = 0; i < count; i++)
		rotateB();

	count = rand() % (4 + 1);
	for (int i = 0; i < count; i++)
		rotateL();

	count = rand() % (4 + 1);
	for (int i = 0; i < count; i++)
		rotateR();

	count = rand() % (4 + 1);
	for (int i = 0; i < count; i++)
		rotateD();

}

int getInput(char* command) {
	int res;

	printf("CUBE> ");
	scanf("%s", command);

	if (command[0] == 'Q')
		res = 1; // 'Q'입력시 exit_flag set
	else
		res = 0;

	return res;
}

void execute(char* command) {
	int count = strlen(command);
	char face;
	int direction;
	for (int i = 0; i < count; i++) {
		if (command[i] == 39) { // command[i] == '
			continue;
		}
		else {
			face = command[i];
			if (command[i + 1] == 39) {//39 in ascii code
				direction = 1;
				printf("\n\n%c'", face);
			}
			else {
				direction = 0; //시계방향
				printf("\n\n%c", face);
			}
			rotateCube(face, direction);
			rotate_count++;
			printCube();
		}
	}
}

void rotateCube(char face, int direction) {
	switch (face) {
	case 'U':
		rotateU();
		if (direction == 1) {
			rotateU();
			rotateU();
		}break;
	case 'B':
		rotateB();
		if (direction == 1) {
			rotateB();
			rotateB();
		}break;
	case 'L':
		rotateL();
		if (direction == 1) {
			rotateL();
			rotateL();
		}break;
	case 'F':
		rotateF();
		if (direction == 1) {
			rotateF();
			rotateF();
		}break;
	case 'R':
		rotateR();
		if (direction == 1) {
			rotateR();
			rotateR();
		}break;
	case 'D':
		rotateD();
		if (direction == 1) {
			rotateD();
			rotateD();
		}break;
	default:break;
	}
}
void rotateU(){
	char temp[3];
	int i;
	int dest, src;
	for (i = 0; i < 3; i++) {
		temp[i] = cube[L][0][i];
	}

	dest = L; src = F;
	for (i = 0; i < 3; i++) {
		cube[dest][0][i] = cube[src][0][i];
	}
	dest = F; src = R;
	for (i = 0; i < 3; i++) {
		cube[dest][0][i] = cube[src][0][i];
	}
	dest = R; src = B;
	for (i = 0; i < 3; i++) {
		cube[dest][0][i] = cube[src][0][i];
	}
	dest = B; 
	for (i = 0; i < 3; i++) {
		cube[dest][0][i] = temp[i];
	}
}
void rotateB() {
	char temp[3];
	int i;
	int dest, src;
	for (i = 0; i < 3; i++) {
		temp[i] = cube[R][i][2];
	}

	dest = R; src = D;
	for (i = 0; i < 3; i++) {
		cube[dest][i][2] = cube[src][2][2-i];
	}
	dest = D; src = L;
	for (i = 0; i < 3; i++) {
		cube[dest][2][2 - i] = cube[src][2-i][0];
	}
	dest = L; src = U;
	for (i = 0; i < 3; i++) {
		cube[dest][2-i][0] = cube[src][0][i];
	}
	dest = U;
	for (i = 0; i < 3; i++) {
		cube[dest][0][i] = temp[i];
	}
}
void rotateL() {
	char temp[3];
	int i;
	int dest, src;
	for (i = 0; i < 3; i++) {
		temp[i] = cube[B][i][2];
	}

	dest = B; src = D;
	for (i = 0; i < 3; i++) {
		cube[dest][i][2] = cube[src][2-i][0];
	}
	dest = D; src = F;
	for (i = 0; i < 3; i++) {
		cube[dest][2 - i][0] = cube[src][2 - i][0];
	}
	dest = F; src = U;
	for (i = 0; i < 3; i++) {
		cube[dest][2 - i][0] = cube[src][2-i][0];
	}
	dest = U;
	for (i = 0; i < 3; i++) {
		cube[dest][2-i][0] = temp[i];
	}
}
void rotateF() {
	char temp[3];
	int i;
	int dest, src;
	for (i = 0; i < 3; i++) {
		temp[i] = cube[L][i][2];
	}

	dest = L; src = D;
	for (i = 0; i < 3; i++) {
		cube[dest][i][2] = cube[src][0][i];
	}
	dest = D; src = R;
	for (i = 0; i < 3; i++) {
		cube[dest][0][i] = cube[src][2-i][0];
	}
	dest = R; src = U;
	for (i = 0; i < 3; i++) {
		cube[dest][2-i][0] = cube[src][2][2 - i];
	}
	dest = U;
	for (i = 0; i < 3; i++) {
		cube[dest][2][2 - i] = temp[i];
	}
}
void rotateR() {
	char temp[3];
	int i;
	int dest, src;
	for (i = 0; i < 3; i++) {
		temp[i] = cube[F][i][2];
	}

	dest = F; src = D;
	for (i = 0; i < 3; i++) {
		cube[dest][i][2] = cube[src][i][2];
	}
	dest = D; src = B;
	for (i = 0; i < 3; i++) {
		cube[dest][i][2] = cube[src][2-i][0];
	}
	dest = B; src = U;
	for (i = 0; i < 3; i++) {
		cube[dest][2-i][0] = cube[src][i][2];
	}
	dest = U;
	for (i = 0; i < 3; i++) {
		cube[dest][i][2] = temp[i];
	}
}
void rotateD() {
	char temp[3];
	int i;
	int dest, src;
	for (i = 0; i < 3; i++) {
		temp[i] = cube[L][2][2-i];
	}

	dest = L; src = B;
	for (i = 0; i < 3; i++) {
		cube[dest][2][2-i] = cube[src][2][2-i];
	}
	dest = B; src = R;
	for (i = 0; i < 3; i++) {
		cube[dest][2][2-i] = cube[src][2][2-i];
	}
	dest = R; src = F;
	for (i = 0; i < 3; i++) {
		cube[dest][2][2-i] = cube[src][2][2-i];
	}
	dest = F;
	for (i = 0; i < 3; i++) {
		cube[dest][2][2-i] = temp[i];
	}
}

void printCube() {

	int i, j, indent;
	printf("\n");
	//up
	indent = 13;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < indent; j++)
			printf(" ");
		for (j = 0; j < 3; j++) {
			printf("%c ", cube[U][i][j]);
		}
		printf("\n");
	}

	//middle
	indent = 3;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			printf("%c ", cube[B][i][j]);
		}
		for (j = 0; j < indent; j++)
			printf(" ");

		for (j = 0; j < 3; j++) {
			printf("%c ", cube[L][i][j]);
		}
		for (j = 0; j < indent; j++)
			printf(" ");

		for (j = 0; j < 3; j++) {
			printf("%c ", cube[F][i][j]);
		}
		for (j = 0; j < indent; j++)
			printf(" ");

		for (j = 0; j < 3; j++) {
			printf("%c ", cube[R][i][j]);
		}
		printf("\n");
	}


	indent = 13;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < indent; j++)
			printf(" ");
		for (j = 0; j < 3; j++) {
			printf("%c ", cube[D][i][j]);
		}
		printf("\n");
	}
	printf("\n");
}


int checkCube() {
	int res = 0;
	int flag = 0;
	
	flag += checkSection(cube[U]);
	flag += checkSection(cube[B]);
	flag += checkSection(cube[L]);
	flag += checkSection(cube[F]);
	flag += checkSection(cube[R]);
	flag += checkSection(cube[D]);
	
	if (flag == 0)
		res = 1;

	return res;
}
int checkSection(char section[3][3]) {
	int flag=0;
	char test = section[0][0];
	for (int i = 0; i < 3; i++) {
		for(int j=0; j<3; j++){
			if (section[i][j] != test)
				flag = 1; break;
		}
	}

	return flag;
}

void printResult(int time) {
	int hr, min, sec;
	sec = time % 60;
	time /= 60;
	min = time % 60;
	hr = time / 60;

	printf("경과시간: %2d :%2d :%2d\n", hr, min, sec);
	printf("조작갯수: %d\n", rotate_count);
	printf("이용해주셔서 감사합니다. 뚜뚜뚜\n");
}