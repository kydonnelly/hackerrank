/*
 *  PickingCards.c
 *  For InterviewStreet
 *
 *  Created by Kyle Donnelly on 1/7/12.
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "primitivetypes.h"

int pickingCards (void) {
    int numTestCases;
	scanf("%d", &numTestCases);
	
	while (numTestCases--) {
        int numCards;
		scanf("%d", &numCards);
		
		ull *cardValueCounts = malloc(sizeof(ull) * numCards);
		// prompt says card values are <= numCards
		for (int i = 0; i < numCards; i++) {
			cardValueCounts[i] = 0;
		}
		
        int cardValue;
		for (int i = 0; i < numCards; i++) {
			scanf("%d", &cardValue);
			cardValueCounts[cardValue]++;
		}
		
        ull sum = 0;
        ull product = 1;
		for (int i = 0; i < numCards; i++) {
			sum += cardValueCounts[i];
			product *= sum;
			if (product >= 1000000007) {
				product %= 1000000007;
			}
			sum--;
		}
		
		printf("%qu\n", product);
		
		free(cardValueCounts);
	}
	
	return 0;
}