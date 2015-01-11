//
//  sherlockandarray.c
//  hackerrank
//
//  Created by Kyle Donnelly on 1/11/15.
//  Copyright (c) 2015 kyle. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS "YES"
#define FAILURE "NO"

int doesSumMidpointExist (int *array, int arrayLength) {
    int leftIter = 0;
    int rightIter = arrayLength - 1;
    int leftSum = 0;
    int rightSum = 0;
    
    while (leftIter < rightIter) {
        if (leftSum < rightSum) {
            leftSum += array[leftIter];
            leftIter++;
        } else {
            rightSum += array[rightIter];
            rightIter--;
        }
    }
    
    return (leftSum == rightSum);
}

int sherlockandarray (void) {
    int numTestCases;
    scanf("%d", &numTestCases);
    
    while (numTestCases--) {
        int arrayLength;
        scanf("%d", &arrayLength);
        
        int *array = malloc(sizeof(int) * arrayLength);
        for (int i = 0; i < arrayLength; i++) {
            scanf("%d", array + i);
        }
        
        if (doesSumMidpointExist(array, arrayLength)) {
            printf(SUCCESS);
        } else {
            printf(FAILURE);
        }
        printf("\n");
        
        free(array);
    }
    
    return 0;
}
