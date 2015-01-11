/*
 *  utopianTree.c
 *  InterviewStreet
 *
 *  Created by Kyle Donnelly on 2/17/14.
 *
 */

#include <stdio.h>
#include <stdlib.h>

int utopiantree (void) {
	int numCases;
	scanf("%d", &numCases);
	
	while (numCases--) {
        int cycles;
		scanf("%d", &cycles);
		int isEven = (cycles % 2 == 0);
		
		if (cycles == 0) {
			printf("1\n");
			continue;
		}
		
		if (isEven) {
			cycles--;
		}
		
		int treeHeight = 1 << ((cycles / 2) + 2);
		
		if (isEven) {
			treeHeight -= 1;
		} else {
			treeHeight -= 2;
		}
		
		printf("%d\n", treeHeight);
	}
	
	return 0;
}