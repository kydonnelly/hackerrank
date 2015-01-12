/*
 *  missingNumbers.c
 *  InterviewStreet
 *
 *  Created by Kyle Donnelly on 2/17/14.
 *
 */

#define MAX_RANGE 100

#include <stdio.h>
#include <stdlib.h>

int missingNumbers (void) {
	int trimmedArraySize;
	scanf("%d", &trimmedArraySize);
    
	int *trimmedArray = malloc(sizeof(int) * trimmedArraySize);
	for (int i = 0; i < trimmedArraySize; i++) {
		scanf("%d", trimmedArray + i);
	}
	
    int fullArraySize;
	scanf("%d", &fullArraySize);
    
	int *fullArray = malloc(sizeof(int) * fullArraySize);
	for (int i = 0; i < fullArraySize; i++) {
		scanf("%d", fullArray + i);
	}
    
	int minValue = ~(1 << 31);
	for (int i = 0; i < fullArraySize; i++) {
		if (fullArray[i] < minValue) {
			minValue = fullArray[i];
		}
    }
	
	int *counts = malloc(sizeof(int) * (MAX_RANGE+1));
	
	for (int i = 0; i <= MAX_RANGE; i++) {
		counts[i] = 0;
	}
	
	for (int i = 0; i < fullArraySize; i++) {
		counts[fullArray[i] - minValue]++;
	}
	
	for (int i = 0; i < trimmedArraySize; i++) {
		counts[trimmedArray[i] - minValue]--;
	}
	
	for (int i = 0; i <= MAX_RANGE; i++) {
		if (counts[i]) {
			printf("%d ", i + minValue);
		}
	}
	
	free(fullArray);
	free(trimmedArray);
	free(counts);
	
	return 0;
}