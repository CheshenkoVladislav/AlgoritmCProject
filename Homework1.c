/*
 * Main.c
 *
 *  Created on: 23 июн. 2019 г.
 *      Author: Vladislav Cheshenko
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

void decimalToBinary(int decimalNumber) {
	if (decimalNumber > 1) {
		decimalToBinary(decimalNumber / 2);
	}
	printf("%i", decimalNumber % 2);
}

int exponentiationRecursion(int num, int exponent) {
	if (exponent == 0) {
		return 1;
	} else if (exponent == 1) {
		return num;
	} else {
		return num * exponentiation(num, --exponent);
	}
}

int exponentiationRecursionPower(int num, int exponent) {
	if (exponent == 1) {
		return num;
	} else if (exponent == 0) {
		return 1;
	} else if (exponent % 2 == 0) {
		return exponentiationRecursionPower(num * num, exponent / 2);
	} else {
		return num * exponentiationRecursionPower(num, --exponent);
	}
}

int exponentiation(int num, int exponent) {
	int result = 1;
	while (exponent > 0) {
		result *= num;
		exponent--;
	}
	return result;
}

static const int MULTIPLY_AT_TWO = 2;
static const int PLUS_ONE = 1;
static const int EMPTY_OPERATION = 0;

void examinationExercise(char *operations, int result, int *start, int *counter) {
	if (*start == result || *start > result) {
		return;
	}
	if (result / 2 > *start) {
		operations[1] = EMPTY_OPERATION;
	}
	for (int i = 0; i < strlen(operations); i++) {
		switch (operations[i]) {
		case MULTIPLY_AT_TWO:
			*start *= 2;
			++*counter;
			break;
		case PLUS_ONE:
			++*start;
			++*counter;
			break;
		}
		examinationExercise(operations, result, start, counter);
	}
}

int main() {
	if (setlocale(LC_CTYPE, "ru-RU") == NULL) {
		printf("Error locale\n");

	}
	int i = 0;

	int startValue = 3;
	int *start = &startValue;
	int *counter = &i;
	char operations [] = {PLUS_ONE, MULTIPLY_AT_TWO};
	examinationExercise(operations, 20, start, counter);
	printf("Result = %i", *counter);
	return 0;
}
