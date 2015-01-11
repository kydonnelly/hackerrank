/*
 *  Twos.c
 *  InterviewStreet
 *
 *  Created by Kyle Donnelly on 12/16/12.
 *
 */


#include <stdio.h>
#include <stdlib.h>

#include "primitivetypes.h"

void giveCandy (int *priorities, int *candy, int current, int last) {
	if (candy[current] > 0) {
		return;
	}
    
	int candyNeeded = 1;
	if (current < last && priorities[current] > priorities[current+1]) {
        giveCandy(priorities, candy, current+1, last);
		candyNeeded = candy[current+1] + 1;
	}
	
	if (current > 0 && priorities[current] > priorities[current-1]) {
		int neighborCandy = candy[current-1];
		if (neighborCandy >= candyNeeded) {
			// person on left has higher priority than person on right.
			candyNeeded = neighborCandy + 1;
		}
	}
	
	candy[current] = candyNeeded;
}

int candies (void) {
	int numRecipients;
    int *priorities;
    int *candyAmounts;
    uint totalCandy = 0;
	
	scanf("%u", &numRecipients);
	
	priorities = malloc(sizeof(uint) * numRecipients);
	candyAmounts = malloc(sizeof(uint) * numRecipients);
	
	for (int i = 0; i < numRecipients; i++) {
		scanf("%d", priorities + i);
		candyAmounts[i] = 0;
	}
	
	for (int i = 0; i < numRecipients; i++) {
		giveCandy(priorities, candyAmounts, i, numRecipients-1);
        totalCandy += candyAmounts[i];
	}
	
	printf("%u\n", totalCandy);
	
	return 0;
}