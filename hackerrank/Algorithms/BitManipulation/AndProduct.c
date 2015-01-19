//
//  AndProduct.c
//  hackerrank
//
//  Created by Kyle Donnelly on 1/19/15.
//  Copyright (c) 2015 kyle. All rights reserved.
//
//  This problem is just finding all consecutive MSB shared between two numbers.

#include <stdio.h>
#include <stdlib.h>

#include "primitivetypes.h"

int andProduct (void) {
    int numTestCases;
    scanf("%d", &numTestCases);
    
    while (numTestCases--) {
        uint low, high;
        scanf("%u %u", &low, &high);
        
        uint sharedBits = 0;
        for (uint bitIter = 1 << 31; bitIter > 0; bitIter >>= 1) {
            uint lowBitValue = low & bitIter;
            uint highBitValue = high & bitIter;
            
            if (lowBitValue != highBitValue) {
                break;
            } else {
                sharedBits |= highBitValue;
            }
        }
        
        printf("%u\n", sharedBits);
    }
    
    return 0;
}
