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
	return 0;
}
