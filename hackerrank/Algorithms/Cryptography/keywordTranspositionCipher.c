/*
 *  KeywordTransposition.c
 *  InterviewStreet
 *
 *  Created by Kyle Donnelly on 2/22/14.
 *
 */

#define CIPHER_LEN 256
#define INPUT_CHAR_RANGE 26

#include <stdio.h>
#include <stdlib.h>

typedef struct _list {
	int characterIndex;
	struct _list *next;
} list;

void quickSortList(list **numbers, int left, int right)
{
	int pivot, l_hold, r_hold;
	
	l_hold = left;
	r_hold = right;
	pivot = numbers[left]->characterIndex;
	list *pivotPtr = numbers[left];
	while (left < right)
	{
		while ((numbers[right]->characterIndex >= pivot) && (left < right))
			right--;
		if (left != right)
		{
			numbers[left] = numbers[right];
			left++;
		}
		while ((numbers[left]->characterIndex <= pivot) && (left < right))
			left++;
		if (left != right)
		{
			numbers[right] = numbers[left];
			right--;
		}
	}
	numbers[left] = pivotPtr;
	int temp = left;
	left = l_hold;
	right = r_hold;
	if (left < temp)
		quickSortList(numbers, left, temp-1);
	if (right > temp)
		quickSortList(numbers, temp+1, right);
}

int keywordTranspositionCipher (void) {
	int cases;
	char *key;
	char *cipher;
	int *usedLetters;
	int numUsedLetters;
	list **columns, *nextPtr;
	int charIndex;
	char *transposition;
	
	key = malloc(sizeof(char) * INPUT_CHAR_RANGE); // may not be sufficient.
	usedLetters = malloc(sizeof(int) * INPUT_CHAR_RANGE);
	columns = malloc(sizeof(list *) * INPUT_CHAR_RANGE);
	transposition = malloc(sizeof(char) * INPUT_CHAR_RANGE);
	cipher = malloc(sizeof(char) * CIPHER_LEN);
	
	for (int i=0; i<INPUT_CHAR_RANGE; i++) {
		columns[i] = NULL;
	}
	
	scanf("%d", &cases);
	
	while (cases--) {
		// reset
		for (int i=0; i<INPUT_CHAR_RANGE; i++) {
			usedLetters[i] = 0;
		}
		numUsedLetters = 0;
		
		scanf("%s\n", key);
		scanf("%256[^\n]s", cipher);
		
		// find unique characters in order
		for (int i=0; key[i] != '\0'; i++) {
			charIndex = key[i] - 'A';
			if (usedLetters[charIndex] == 0) {
				usedLetters[charIndex] = 1;
				columns[numUsedLetters] = malloc(sizeof(list));
				columns[numUsedLetters]->next = NULL;
				columns[numUsedLetters]->characterIndex = charIndex;
				numUsedLetters++;
			}
		}
		
		// go through remaining characters.
		int counter = 0;
		for (int i=0; i<INPUT_CHAR_RANGE; i++) {
			if (usedLetters[i] == 0) {
				list *head = columns[counter];
				while (head->next != NULL) {
					head = head->next;
				}
				head->next = malloc(sizeof(list));
				head->next->next = NULL;
				head->next->characterIndex = i;
				
				counter++;
				if (counter >= numUsedLetters) {
					counter -= numUsedLetters;
				}
			}
		}
		
		quickSortList(columns, 0, numUsedLetters-1);
		
		// map cipher letters to readable letters
		counter = 0;
		for (int i=0; i<numUsedLetters; i++) {
			for (list *iter = columns[i]; iter != NULL; iter = nextPtr) {
				transposition[iter->characterIndex] = 'A' + counter;
				counter++;
				
				// clear memory
				nextPtr = iter->next;
				free(iter);
			}
			columns[i] = NULL;
		}
		
		// translate cipher!
		for (int i=0; cipher[i] != '\0'; i++) {
			charIndex = cipher[i] - 'A';
			// ignore spaces
			if (charIndex >= 0 && charIndex < INPUT_CHAR_RANGE) {
				cipher[i] = transposition[charIndex];
			}
		}
		printf("%s\n", cipher);
	}
	
	free(cipher);
	free(transposition);
	free(columns);
	free(usedLetters);
	free(key);
	
	return 0;
}