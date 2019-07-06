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

static const char YEAR1[] = " лет";
static const char YEAR2[] = " год";
static const char YEAR3[] = " года";

int calculateSequareEquality(int a, int b, int c, float *x, float *y) {
	float discriminant = (b * b) - 4 * a * c;
	printf("Discriminant = %f\n", discriminant);
	if (discriminant > 0) {
		*x = ((-b) + sqrt(discriminant)) / (2 * a);
		*y = ((-b) - sqrt(discriminant)) / (2 * a);
		return 1;
	} else if (discriminant == 0) {
		*x = (-b) / (2 * a);
		return 0;
	} else {
		return -1;
	}
}

char* calculateBodymassIndex(int weight, int height) {
	return weight / (height << 1);
}

int ageFormat(int age, char *formattedAgePointer) {
	int firstGrade = age % 10;
	int secondGrade = (age / 10) % 10;
	int length;
	int nDigits = floor(log10(abs(age))) + 1;
	for (int i = 0; i < nDigits; i++) {
		formattedAgePointer[nDigits - 1 - i] = (age % 10) + '0';
		age /= 10;
	}
	if (secondGrade == 1) {
		length = sizeof(YEAR1) / sizeof(char);
	} else if (firstGrade < 5 & firstGrade != 0) {
		length = sizeof(YEAR2) / sizeof(char);
	} else if (firstGrade >= 5 || firstGrade == 0) {
		length = sizeof(YEAR3) / sizeof(char);
	}

	for (int i = 0; i < length; i++) {
		formattedAgePointer[nDigits + i] = YEAR1[i];
		printf("Element number %d = %c\n", nDigits + i,
				formattedAgePointer[nDigits + i]);
	}
	return nDigits + length;
}

static const int BLACK = 1;
static const int WHITE = 0;

typedef struct cell {
	int color;
} Cell;

int compareColor(int x1, int y1, int x2, int y2) {
	Cell cell1;
	if ((x1 % 2 == 0 && y1 % 2 == 0) || (x1 % 2 == 0 && y1 % 2 == 0)) {
		cell1.color = BLACK;
	} else {
		cell1.color = WHITE;
	}
	Cell cell2;
	if ((x2 % 2 == 0 && y2 % 2 == 0) || (x2 % 2 == 0 && y2 % 2 == 0)) {
		cell2.color = BLACK;
	} else {
		cell2.color = WHITE;
	}
	return cell1.color == cell2.color;
}

void automorphNums() {
	int x = 1;
	while(x < 10000) {
		int square = x * x;
		int digits = floor(log10(abs(x))) + 1;
		int delimeter = pow(10, digits);
		int endOfDigit = square % delimeter;
		if(endOfDigit == x) {
			printf("%d\n", x);
		}
		x++;
	}
}

int main() {
	if (setlocale(LC_CTYPE, "ru-RU") == NULL) {
		printf("Error locale\n");

	}
	automorphNums();
	return 0;
}
