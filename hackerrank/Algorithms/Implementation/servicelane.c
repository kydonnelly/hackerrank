/*
 *  serviceLane.c
 *  InterviewStreet
 *
 *  Created by Kyle Donnelly on 2/16/14.
 *
 */

#include <stdio.h>
#include <stdlib.h>

int serviceLane (void) {
	int roadLength, numCases;
	int numChanges;
	
	scanf("%d %d", &roadLength, &numCases);
	int *widths = malloc(sizeof(int) * roadLength);
	int *changeIndexes = malloc(sizeof(int) * roadLength);
	
	for (int i=0; i<roadLength; i++) {
		scanf("%d", &widths[i]);
	}
	
	changeIndexes[0] = 0;
	numChanges = 1;
	for (int i = 1; i < roadLength; i++) {
		if (widths[i] != widths[i-1]) {
			changeIndexes[numChanges] = i;
			numChanges++;
		}
	}
	
	for (int i = 0; i < numCases; i++) {
        int start, end;
		scanf("%d %d", &start, &end);
        
		int minWidth = 3;
		for (int j = start; j <= end; j++) {
			if (widths[j] < minWidth) {
				minWidth = widths[j];
			}
		}
		
		printf("%d\n", minWidth);
	}
	
	return 0;
}