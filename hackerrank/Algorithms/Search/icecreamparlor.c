/*
 *  iceCreamParlor.c
 *  InterviewStreet
 *
 *  Created by Kyle Donnelly on 2/17/14.
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "sorting.h"

int iceCreamParlor (void) {
    int numTestCases;
	scanf("%d", &numTestCases);
	
	while (numTestCases--) {
        int moneyAvailable, numFlavors;
		scanf("%d", &moneyAvailable);
		scanf("%d", &numFlavors);
		
		int *flavorCosts = malloc(sizeof(int) * numFlavors);
		int *sortedIndexes = malloc(sizeof(int) * numFlavors);
		
		for (int i = 0; i < numFlavors; i++) {
			sortedIndexes[i] = i;
		}
		for (int i = 0; i < numFlavors; i++) {
			scanf("%d", flavorCosts + i);
		}
		
        quicksort_index_ascending(flavorCosts, sortedIndexes, numFlavors);
		
		int leftIter = 0;
		int rightIter = numFlavors-1;
		
		while (flavorCosts[sortedIndexes[leftIter]] + flavorCosts[sortedIndexes[rightIter]] != moneyAvailable) {
			if (flavorCosts[sortedIndexes[leftIter]] + flavorCosts[sortedIndexes[rightIter]] > moneyAvailable) {
				rightIter--;
			} else {
				leftIter++;
			}
		}
		
		// quicksort is not stable, but output expects left index to be smaller.
		if (sortedIndexes[rightIter] < sortedIndexes[leftIter]) {
			int temp = sortedIndexes[rightIter];
			sortedIndexes[rightIter] = sortedIndexes[leftIter];
			sortedIndexes[leftIter] = temp;
		}
		
		printf("%d %d\n", sortedIndexes[leftIter]+1, sortedIndexes[rightIter]+1);
		
		free(flavorCosts);
		free(sortedIndexes);
	}
	
	return 0;
}