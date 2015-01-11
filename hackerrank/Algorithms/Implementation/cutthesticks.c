//
//  cutthesticks.c
//  hackerrank
//
//  Created by Kyle Donnelly on 1/11/15.
//  Copyright (c) 2015 kyle. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "sorting.h"

int cutthesticks (void) {
    int numSticks;
    scanf("%d", &numSticks);
    
    int *stickLengths = malloc(sizeof(int) * numSticks);
    for (int i = 0; i < numSticks; i++) {
        scanf("%d", stickLengths + i);
    }
    
    quicksort_ascending(stickLengths, numSticks);
    
    int lastStickLength = -1;
    for (int i = 0; i < numSticks; i++) {
        if (stickLengths[i] != lastStickLength) {
            printf("%d\n", numSticks - i);
        }
        lastStickLength = stickLengths[i];
    }
    
    free(stickLengths);
    
    return 0;
}
