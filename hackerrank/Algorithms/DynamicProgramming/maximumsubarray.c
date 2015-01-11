//
//  maximumsubarray.c
//  hackerrank
//
//  Created by Kyle Donnelly on 1/3/15.
//  Copyright (c) 2015 kyle. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VAL(a, b) (a > b ? a : b)

int kadaneSum (int *array, int length) {
    int sumOfLeftElements = 0;
    int maxSum = 0;
    for (int i = 0; i < length; i++) {
        sumOfLeftElements = MAX_VAL(array[i] + sumOfLeftElements, 0);
        if (sumOfLeftElements > maxSum) {
            maxSum = sumOfLeftElements;
        }
    }
    
    return maxSum;
}

int maximumsubarray (void) {
    int numCases;
    scanf("%d", &numCases);
    
    while (numCases--) {
        int length;
        int *array;
        
        scanf("%d", &length);
        
        array = malloc(sizeof(int) * length);
        for (int i = 0; i < length; i++) {
            scanf("%d", array + i);
        }
        
        int maxValue = INT_MIN;
        int positiveSum = 0;
        for (int i = 0; i < length; i++) {
            if (array[i] > maxValue) {
                maxValue = array[i];
            }
            if (array[i] > 0) {
                positiveSum += array[i];
            }
        }
        if (maxValue < 0) {
            // because the prompt doesn't want subarrays of length zero...
            positiveSum = maxValue;
        } else {
            maxValue = kadaneSum(array, length);
        }
        
        printf("%d %d\n", maxValue, positiveSum);
    }
    
    return 0;
}