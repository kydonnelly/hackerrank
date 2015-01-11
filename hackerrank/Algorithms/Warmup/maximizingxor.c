//
//  maximizingxor.c
//  hackerrank
//
//  Created by Kyle Donnelly on 1/4/15.
//  Copyright (c) 2015 kyle. All rights reserved.
//

#include <stdio.h>

#include "primitivetypes.h"

int maximizingxor (void) {
    uint lowerBound, upperBound;
    scanf("%d %d", &lowerBound, &upperBound);
    
    // clear leading bits that are the same until find a different pair
    uint bitIter;
    for (bitIter = 1 << 31; bitIter > 0; bitIter >>= 1) {
        uint lowerBit = lowerBound & bitIter;
        uint upperBit = upperBound & bitIter;
        if (lowerBit != upperBit) {
            break;
        } else {
            upperBound &= ~bitIter;
            lowerBound &= ~bitIter;
        }
    }
    
    if (bitIter > 0) {
        // make all bits 1s after MSB
        bitIter = (bitIter << 1) - 1;
    }
    
    printf("%u", bitIter);
    
    return 0;
}