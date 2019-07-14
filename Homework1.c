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

int main() {
	if (setlocale(LC_CTYPE, "ru-RU") == NULL) {
		printf("Error locale\n");

	}
	int array[10] = { 1, 5, 2, 5, 7, 1, 3, 6, 7, 15 };
	int array2[10] = { 1, 5, 2, 5, 7, 1, 3, 6, 7, 2 };
	int array3[10] = { 1, 5, 2, 5, 7, 1, 3, 6, 7, 2 };
	int count = modifyBubleSort(&array, 10);
	int count2 = bubleSort(&array2, 10);\
	int count3 = shakerSort(&array3, 10);
	printf("CountModify = %d\n", count);
	printf("Count = %d\n", count2);
	printf("CountShaker = %d\n", count3);
	for (int i = 0; i < 10; i++) {
		printf("%d ", array[i]);
	}
	printf("\nFindPosition = %d", recurseLineSearch(&array, 15, 0));
	return 0;
}

void swap(int *int1, int *int2) {
	*int1 ^= *int2;
	*int2 ^= *int1;
	*int1 ^= *int2;
}

void swap(int *int1, int *int2);

int bubleSort(int *arrayForSort, int length) {
	int operations = 0;
	for (int i = 0; i < length; i++) {
		operations++;
		for (int j = 0; j < length - 1 - i; j++) {
			operations++;
			if (arrayForSort[j] > arrayForSort[j + 1]) {
				swap(&arrayForSort[j], &arrayForSort[j + 1]);
			}
		}
	}
	return operations;
}

int modifyBubleSort(int *arrayForSort, int length) {
	int operations = 0;
	for (int i = 0; i < length / 2; i++) {
		operations++;
		for (int j = 1; j < length - 1 - i; j++) {
			operations++;
			if (arrayForSort[j] < arrayForSort[0]) {
				swap(&arrayForSort[j], &arrayForSort[0]);
			}
			if (arrayForSort[j] > arrayForSort[length - 1]) {
				swap(&arrayForSort[j], &arrayForSort[length - 1]);
			}
			if (arrayForSort[j] > arrayForSort[j + 1]) {
				swap(&arrayForSort[j], &arrayForSort[j + 1]);
			}
		}
	}
	return operations;
}

int shakerSort(int *arrayForSort, int length) {
	int operations = 0;
	for (int i = 0; i < length / 2; i++) {
		operations++;
		if (i % 2 == 0) {
			for (int j = i; j < length - 1 - i; j++) {
				operations++;
				if (arrayForSort[j] > arrayForSort[j + 1]) {
					swap(&arrayForSort[j], &arrayForSort[j + 1]);
				}
			}
		} else {
			for (int j = length - 1 - i; j > i; j--) {
				operations++;
				if (arrayForSort[j] < arrayForSort[j - 1]) {
					swap(&arrayForSort[j], &arrayForSort[j - 1]);
				}
			}
		}
	}
	return operations;
}

int recurseLineSearch(int *arrayForSearch, int value, int position, int length) {
	if(arrayForSearch[position] == value) {
		return position;
	}
	if(position == length - 1) {
		return -1;
	}
	return recurseLineSearch(arrayForSearch, value, position + 1, length);
}
