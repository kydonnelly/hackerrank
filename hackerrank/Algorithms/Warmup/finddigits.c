/*
 *  findDigits.c
 *  InterviewStreet
 *
 *  Created by Kyle Donnelly on 2/17/14.
 *
 */

#define BASE 10

#include <stdio.h>
#include <stdlib.h>

int finddigits (void) {
	int numCases;
	int *divisors = malloc(sizeof(int) * BASE);
	divisors[0] = 1;
	
	scanf("%d", &numCases);
	
	while (numCases--) {
        int number;
		int divisorDigits = 0;
		scanf("%d", &number);
		
		for (int i = 1; i < BASE; i++) {
			divisors[i] = (number % (i+1)) == 0;
		}
		
		while (number > 0) {
			if (divisors[(number % BASE) - 1]) {
				divisorDigits++;
			}
			number /= BASE;
		}
		
		printf("%d\n", divisorDigits);
	}
	
	return 0;
}