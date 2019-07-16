/*
 * Main.c
 *
 *  Created on: 23 июн. 2019 г.
 *      Author: vlad
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
static const int BOARD_SIZE = 64;
static const int OPEN = 1;
static const int CLOSE = 2;

typedef struct Cell {
	int state;
	int x;
	int y;
};

const struct Cell board[BOARD_SIZE];

int main() {
//	if (setlocale(LC_CTYPE, "ru-RU") == NULL) {
//		printf("Error locale\n");
//
//	}
	fillBoard(&board);
	int counter = 0;
	makeMove(0, 0, &counter);
	printf("\ncount = %d", counter);
	return 0;
}

int recurseBinarySearch(int *arrayForSearch, int start, int end, int value) {
	printf("end = %d; start = %d\n", end, start);
	int range = end - start;
	if (range == 0 && arrayForSearch[start] != value) {
		return -1;
	}
	printf("range = %d\n", range);
	int position = (end + start) / 2;
	printf("Position %d\n", position);
	if (arrayForSearch[position] == value) {
		return position;
	}
	printf("ArrayValue = %d\n", arrayForSearch[position]);
	int isLarge = value > position;
	return recurseBinarySearch(arrayForSearch, isLarge ? position + 1 : start,
			isLarge ? end : position - 1, value);
}

int checkCell(struct Cell cell, struct Cell *board) {
	for (int i = 0; i < BOARD_SIZE; i++) {
		struct Cell boardCell = board[i];
		if (boardCell.x == cell.x && boardCell.y == cell.y
				&& boardCell.state == CLOSE) {
			return 1;
		}
	}
	return 0;
}

//struct Cell* findCell(int x, int y) {
//	printf("\nfind cell x = %d, y = %d", x, y);
//	for (int i = 0; i < BOARD_SIZE; i++) {
//		struct Cell *boardCell = &board[i];
////		printf("\ngetCell = %i", i);
//		if (boardCell->x == x && boardCell->y == y) {
//			return boardCell;
//		}
//	}
////	printf("\nfind null");
//	struct Cell cell;
//	cell.state = CLOSE;
//	return &cell;
//}
//
//struct Cell* findCell(int x, int y);

int checkCell(struct Cell cell, struct Cell *board);

int routesWithObstacles(struct Cell cellTo, struct Cell *board) {
//	printf("x = %d; y = %d\n", x, y);
	if ((cellTo.x == 0 && cellTo.y == 0) || checkCell(cellTo, board)) {
		return 0;
	}
	if (cellTo.x == 0 || cellTo.y == 0) {
		return 1;
	}
	struct Cell cellY;
	cellY.y = cellTo.y - 1;
	cellY.x = cellTo.x;
	struct Cell cellX;
	cellX.x = cellTo.x - 1;
	cellX.y = cellTo.y;
	return routesWithObstacles(cellX, board) + routesWithObstacles(cellY, board);
}

//int checkBoard() {
//	printf("\nCheckBoard: ");
//	for (int i = 0; i < BOARD_SIZE; i++) {
//		if (board[i].state == OPEN) {
//			printf("Return 0");
//			return 0;
//		}
//	}
//	printf("Return 1");
//	return 1;
//}

//int makeMove(int nextX, int nextY, int *counter) {
//	printf("\nStart makeMove");
//	if (checkBoard()) {
//		printf("Board is full\n");
//		printf("\nreturn %d", 1);
//		return 1;
//	}
//	if(nextX > 7 || nextY > 7) {
//		return 0;
//	}
//	printf("\nCount : %d", *counter);
//	struct Cell *cell = findCell(nextX, nextY);
//	printf("\nFindCell x = %d, y = %d, state = %d", cell->x, cell->y, cell->state);
//	if (cell != NULL && cell->state == OPEN) {
//		cell->state = CLOSE;
//		int result = makeMove(nextX + 1, nextY + 2, counter)
//				|| makeMove(nextX + 1, nextY - 2, counter)
//				|| makeMove(nextX - 1, nextY + 2, counter)
//				|| makeMove(nextX - 1, nextY - 2, counter)
//				|| makeMove(nextX + 2, nextY + 1, counter)
//				|| makeMove(nextX + 2, nextY - 1, counter)
//				|| makeMove(nextX - 2, nextY + 1, counter)
//				|| makeMove(nextX - 2, nextY - 1, counter);
//		printf("RRRRRESULT!!!!");
//		if (!result) {
//			printf("\n\nResult false");
//			cell->state = OPEN;
//		}
//		printf("\nreturn %d", result);
//		return result;
//	} else {
//		printf("\nreturn %d", 0);
//		return 0;
//	}
//}

//int fillBoard(struct Cell *boardPointer) {
//	int position = 0;
//	for (int i = 0; i < 8; i++) {
//		struct Cell cell;
//		cell.y = i;
//		printf("\n");
//		for (int j = 0; j < 8; j++) {
//			cell.x = j;
//			cell.state = OPEN;
//			boardPointer[position] = cell;
////			printf("position = %d; x = %d; y = %d; state = %d| ", position,
////					cell.x, cell.y, cell.state);
//			position++;
//		}
//	}
//}

