//
//  manasastones.c
//  hackerrank
//
//  Created by Kyle Donnelly on 1/7/15.
//  Copyright (c) 2015 kyle. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int manasastones (void) {
    int numTestCases;
    scanf("%d", &numTestCases);
    
    while (numTestCases--) {
        int numStones;
        int stepSize1, stepSize2;
        
        scanf("%d", &numStones);
        scanf("%d %d", &stepSize1, &stepSize2);
        
        if (stepSize1 > stepSize2) {
            int temp = stepSize1;
            stepSize1 = stepSize2;
            stepSize2 = temp;
        }
        
        int stepDifference = stepSize2 - stepSize1;
        int currentFinalValue = stepSize1 * (numStones-1);
        int largestFinalValue = currentFinalValue + stepDifference * numStones;
        
        do {
            printf("%d ", currentFinalValue);
            currentFinalValue += stepDifference;
        } while (currentFinalValue < largestFinalValue);
        printf("\n");
    }
    
    return 0;
}
