
/*
 *  Flowers.c
 *  InterviewStreet
 *
 *  Created by Kyle Donnelly on 8/22/12.
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "sorting.h"

int flowers (void) {
    int numFriends;
    int numFlowers;
	
	scanf("%d %d", &numFlowers, &numFriends);
	int *flowerPrices = malloc(sizeof(int) * numFlowers);
	
	for(int i = 0; i < numFlowers; i++){
		scanf("%d", flowerPrices + i);
	}
	
	quicksort_descending(flowerPrices, numFlowers);
	
    int totalPrice = 0;
	for (int i = 0; i < numFlowers; i++) {
		totalPrice += flowerPrices[i] * (1 + i/numFriends);
	}
	
	printf("%d\n", totalPrice);
    
    free(flowerPrices);
	
    return 0;
}
