/*
 *  anagram.c
 *  InterviewStreet
 *
 *  Created by Kyle Donnelly on 2/15/14.
 *
 */

#define MAX(a, b) (a > b ? a : b)

#define NUM_ENGLISH_LETTERS 26
#define MAX_INPUT_LENGTH 10000

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int anagram (void) {
	int *letterCounts = malloc(sizeof(int) * NUM_ENGLISH_LETTERS);
	char *inputString = malloc(sizeof(char) * (MAX_INPUT_LENGTH+1));
	int inputCount = 0;
	int inputLength = 0;
	int halfway = 0;
	int difference;
	
	scanf("%d", &inputCount);
	
	while (inputCount--) {
		for (int i = 0; i < NUM_ENGLISH_LETTERS; i++) {
			letterCounts[i] = 0;
		}
		difference = 0;
		
		scanf("%s", inputString);
		inputLength = (int)strlen(inputString);
		
		if (inputLength % 2) {
            // odd length strings can't be anagrams.
			printf("-1\n");
			continue;
		}
		
		halfway = inputLength / 2;
		for (int i = 0; i < halfway; i++) {
			letterCounts[inputString[i] - 'a']++;
		}
		for (int i = halfway; i < inputLength; i++) {
			letterCounts[inputString[i] - 'a']--;
		}
		
		for (int i = 0; i < NUM_ENGLISH_LETTERS; i++) {
			// count letters in first string that weren't in second
			difference += MAX(0, letterCounts[i]);
		}
		
		printf("%d\n", difference);
	}
	
	return 0;
}