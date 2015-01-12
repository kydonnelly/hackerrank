/*
 *  markToys.c
 *  InterviewStreet
 *
 *  Created by Kyle Donnelly on 2/16/14.
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "sorting.h"

int markAndToys (void) {
    int numToys, moneyAvailable;
	scanf("%d %d", &numToys, &moneyAvailable);
    
	int *toyPrices = malloc(sizeof(int) * numToys);
	for (int i = 0; i < numToys; i++) {
		scanf("%d", &toyPrices[i]);
	}
	
	quicksort_ascending(toyPrices, numToys);
	
    int numToysBought = 0;
	for (int i = 0; i < numToys; i++) {
		if (moneyAvailable > toyPrices[i]) {
			moneyAvailable -= toyPrices[i];
			numToysBought++;
		} else {
			break;
		}
	}
	
	printf("%d", numToysBought);
    
    free(toyPrices);
	
	return 0;
}