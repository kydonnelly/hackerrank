/*
 *  handshake.c
 *  InterviewStreet
 *
 *  Created by Kyle Donnelly on 2/22/14.
 *
 */

#include <stdio.h>
#include <stdlib.h>

int handshake (void) {
    int numTestCases;
    scanf("%d", &numTestCases);
    
    int directors;
    while (numTestCases--) {
        scanf("%d", &directors);
        printf("%d\n", (directors * (directors - 1)) / 2);
    }
    
    return 0;
}
