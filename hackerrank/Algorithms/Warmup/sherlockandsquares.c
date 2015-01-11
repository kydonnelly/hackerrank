//
//  sherlockandsquares.c
//  hackerrank
//
//  Created by Kyle Donnelly on 1/6/15.
//  Copyright (c) 2015 kyle. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "primitivetypes.h"
#include "searching.h"

#define MAX_RANGE 1000000000
#define SQRT_MAX_RANGE 31623

int fillSquares (ull *squaresArray, int squaresFound, int target) {
    while (squaresArray[squaresFound] <= target) {
        squaresFound++;
        squaresArray[squaresFound] = squaresFound * squaresFound;
    }
    
    return squaresFound;
}

int sherlocandsquares (void) {
    int numTestCases;
    
    ull *squares = malloc(sizeof(ull) * SQRT_MAX_RANGE);
    squares[0] = 0;
    int squaresFoundIter = 0;
    
    scanf("%d", &numTestCases);
    
    while (numTestCases--) {
        int leftRange, rightRange;
        scanf("%d %d", &leftRange, &rightRange);
        
        squaresFoundIter = fillSquares(squares, squaresFoundIter, rightRange);
        
        int leastAbove = binarySearchIndexBelow(leftRange, squares, squaresFoundIter+1);
        int greatestBelow = binarySearchIndexAbove(rightRange, squares, squaresFoundIter+1);
        
        printf("%d\n", greatestBelow - leastAbove - 1);
    }
    
    free(squares);
    
    return 0;
}
