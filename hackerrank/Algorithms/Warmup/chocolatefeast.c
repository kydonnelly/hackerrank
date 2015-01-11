/*
 *  chocolateFeast.c
 *  InterviewStreet
 *
 *  Created by Kyle Donnelly on 2/16/14.
 *
 */

#include <stdio.h>
#include <stdlib.h>

int chocolatefeast (void) {
	int numCases;
	
	scanf("%d", &numCases);
	
	while (numCases--) {
        int money, cost, tradeCost;
		scanf("%d %d %d", &money, &cost, &tradeCost);
		
		int firstRoundAmt = money / cost;
		int lastRoundAmt = firstRoundAmt >= tradeCost;
		int midRoundAmt = 0;
		
		if (lastRoundAmt) {
			midRoundAmt = (firstRoundAmt - tradeCost) / (tradeCost - 1);
		}
		
		printf("%d\n", firstRoundAmt + lastRoundAmt + midRoundAmt);
	}
	
	return 0;
}