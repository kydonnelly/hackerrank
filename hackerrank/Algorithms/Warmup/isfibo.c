//
//  isfibo.c
//  hackerrank
//
//  Created by Kyle Donnelly on 1/4/15.
//  Copyright (c) 2015 kyle. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "searching.h"

// prompt says we'll be looking for numbers up to 10^10
#define NUM_FIBONACCI 200

#define SUCCESS "IsFibo\n"
#define FAILURE "IsNotFibo\n"

int isFibo (void) {
    ull *fibonacciNumbers;
    int fibonacciIndex = 1;
    
    fibonacciNumbers = malloc(sizeof(ull) * NUM_FIBONACCI);
    fibonacciNumbers[0] = 1;
    fibonacciNumbers[1] = 1;
    
    int numCases;
    scanf("%d", &numCases);
    
    while (numCases--) {
        ull candidate;
        scanf("%llu", &candidate);
        
        while (candidate > fibonacciNumbers[fibonacciIndex]) {
            ull term1 = fibonacciNumbers[fibonacciIndex];
            ull term2 = fibonacciNumbers[fibonacciIndex - 1];
            
            fibonacciIndex++;
            fibonacciNumbers[fibonacciIndex] = term1 + term2;
        }
        
        if (binarySearchIndex(candidate, fibonacciNumbers, fibonacciIndex+1) != BINARY_SEARCH_NOT_FOUND) {
            printf(SUCCESS);
        } else {
            printf(FAILURE);
        }
    }
    
    return 0;
}