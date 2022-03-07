#include <stdio.h>
#include <string.h>
#include <conio.h>
#include "06_7. 스택_MazeArrayStack.h"

StackObject here = { 1,0 }, entry = { 1,0 };
char maze[MAZE_SIZE][MAZE_SIZE] = {
	{'1','1','1','1','1','1'},
	{'e','0','1','0','0','1'},
	{'1','0','0','0','1','1'},
	{'1','0','1','0','1','1'},
	{'1','0','1','0','0','x'},
	{'1','1','1','1','1','1'}
};

void pushLoc(int r, int c) {
	if (r < 0 || c < 0)return;
	if (maze[r][c] != '1' && maze[r][c] != '.') {
		StackObject tmp;
		tmp.r = r;
		tmp.c = c;
		push(tmp);
	}
}

void printMaze(char m[MAZE_SIZE][MAZE_SIZE]) {
	int r, c;
	printf("\n\n");
	for (r = 0; r < MAZE_SIZE; r++) {
		for (c = 0; c < MAZE_SIZE; c++) {
			if (r == here.r && c == here.c)
				printf("m ");
			else {
				if (m[r][c] == 0)
					printf("0 ");
				else
					printf("%c ", m[r][c]);
			}
		}
		printf("\n");
	}
	printf("\n\n");
}

void main() {
	int r, c;
	here = entry;
	printMaze(maze);
	printStack();
	while (maze[here.r][here.c] != 'x') {
		printMaze(maze);
		r = here.r;
		c = here.c;
		maze[r][c] = '.';
		pushLoc(r - 1, c);
		pushLoc(r + 1, c);
		pushLoc(r, c - 1);
		pushLoc(r, c + 1);
		printStack();
		if (isEmpty()) {
			printf("실패\n");
			return;
		}
		else
			here = pop();
		printMaze(maze);
		printStack();
		getchar();
	}
	printf("성공\n");
}