/*
 *  twoArrays.c
 *  InterviewStreet
 *
 *  Created by Kyle Donnelly on 2/16/14.
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "sorting.h"

#define SUCCESS "YES"
#define FAILURE "NO"

int twoArrays (void) {
	int numTestCases;
	scanf("%d", &numTestCases);
	
	while (numTestCases--) {
        int arrayLength, minDifference;
		scanf("%d %d", &arrayLength, &minDifference);
		
		int *array1 = malloc(sizeof(int) * arrayLength);
		int *array2 = malloc(sizeof(int) * arrayLength);
		
		for (int i = 0; i < arrayLength; i++) {
			scanf("%d", array1 + i);
		}
		for (int i = 0; i < arrayLength; i++) {
			scanf("%d", array2 + i);
		}
		
        quicksort_ascending(array1, arrayLength);
        quicksort_ascending(array2, arrayLength);
		
		int hasInsufficientDifference = 0;
		for (int i = 0; i < arrayLength; i++) {
			if (array1[i] + array2[arrayLength-i-1] < minDifference) {
                hasInsufficientDifference = 1;
				break;
			}
		}
		
		if (hasInsufficientDifference) {
			printf(FAILURE);
		} else {
			printf(SUCCESS);
		}
        printf("\n");
        
        free(array1);
        free(array2);
	}
	
	return 0;
}