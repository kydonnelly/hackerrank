/*
 *  sherlockandthebeast.c
 *  InterviewStreet
 *
 *  Created by Kyle Donnelly on 2/17/14.
 *
 */

#include <stdio.h>

int sherlockandthebeast (void) {
	int numCases;
	
	int numThrees[3];
	numThrees[0] = 0;
	numThrees[1] = 10;
	numThrees[2] = 5;
	
	scanf("%d", &numCases);
	
	while (numCases--) {
        int numDigits;
		scanf("%d", &numDigits);
        
		if (numDigits < 3 || numDigits == 4 || numDigits == 7) {
			printf("-1\n");
			continue;
		}
		
		int leftoverFives = numDigits % 3;
		for (int i = 0; i < numDigits - numThrees[leftoverFives]; i++) {
			printf("5");
		}
		for (int i = 0; i < numThrees[leftoverFives]; i++) {
			printf("3");
		}
		printf("\n");
	}
	
	return 0;
}