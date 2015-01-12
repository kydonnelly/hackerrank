/*
 *  minimumDraws.c
 *  InterviewStreet
 *
 *  Created by Kyle Donnelly on 2/22/14.
 *
 *  This problem is trivial.
 *
 */

#include <stdio.h>
#include <stdlib.h>

int minimumDraws (void) {
    int numTestCases;
    scanf("%d", &numTestCases);
    
    int sockPairs;
    while (numTestCases--) {
        scanf("%d", &sockPairs);
        printf("%d\n", sockPairs + 1);
    }
    
    return 0;
}
