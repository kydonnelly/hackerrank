/*
 *  findPoint.c
 *  InterviewStreet
 *
 *  Created by Kyle Donnelly on 2/17/14.
 *
 */

#include <stdio.h>
#include <stdlib.h>

int findPoint (void) {
	int numTestCases;
	scanf("%d", &numTestCases);
	
	while (numTestCases--) {
        int initialX, initialY;
        int reflectionX, reflectionY;
		scanf("%d %d", &initialX, &initialY);
        scanf("%d %d", &reflectionX, &reflectionY);
		
		int dx = reflectionX - initialX;
		int dy = reflectionY - initialY;
		
		printf("%d %d\n", reflectionX + dx, reflectionY + dy);
	}
	
	return 0;
}