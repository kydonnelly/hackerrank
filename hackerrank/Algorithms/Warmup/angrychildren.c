/*
 *  angryChildren.c
 *  InterviewStreet
 *
 *  Created by Kyle Donnelly on 2/16/14.
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "sorting.h"

int angrychildren (void) {
	int numPackets, numKids;
	int *packetSizes;
	int minUnfairness = 1 << 30;
	int unfairness;
	
	scanf("%d", &numPackets);
	scanf("%d", &numKids);
	
	packetSizes = malloc(sizeof(int) * numPackets);
	
	for (int i=0; i<numPackets; i++) {
		scanf("%d", &packetSizes[i]);
	}
	
	quicksort_descending(packetSizes, numPackets);
    
	for (int i=0, j=numKids-1; j<numPackets; i++, j++) {
		unfairness = packetSizes[j] - packetSizes[i];
		if (unfairness < minUnfairness) {
			minUnfairness = unfairness;
		}
	}
	
	printf("%d", minUnfairness);
	
	return 0;
}