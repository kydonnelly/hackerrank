/*
 *  birthdayGift.c
 *  InterviewStreet
 *
 *  Created by Kyle Donnelly on 2/17/14.
 *
 */

#include <stdio.h>
#include <stdlib.h>

int birthdayGift (void) {
	int numSteps;
	scanf("%d", &numSteps);
    
    int sum = 0;
	while (numSteps--) {
        int input;
		scanf("%d", &input);
		sum += input;
	}
	
    // expected sum value after fair coin flip
	printf("%.1f", sum / 2.0);
	
	return 0;
}