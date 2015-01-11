/*
 *  gameOfThrones1.c
 *  InterviewStreet
 *
 *  Created by Kyle Donnelly on 2/17/14.
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define NUM_LETTERS 26

int gameofthrones (void) {
	char input;
	int index;
	int *charCounts = malloc(sizeof(int) * NUM_LETTERS);
	int sum = 0;
	
	for (int i = 0; i < NUM_LETTERS; i++) {
		charCounts[i] = 0;
	}
	
    input = getchar();
	while (input != '\0' && input != '\n' && input != EOF) {
		index = input - 'a';
		charCounts[index] = 1 - charCounts[index];
        input = getchar();
	}
	
	for (int i = 0; i < NUM_LETTERS; i++) {
		sum += charCounts[i];
	}
	
	if (sum > 1) {
		printf("NO");
	} else {
		printf("YES");
	}
	
	free(charCounts);
	
	return 0;
}