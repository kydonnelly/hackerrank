//
//  SansaAndXor.c
//  https://www.hackerrank.com/challenges/sansa-and-xor
//
//  Created by Kyle Donnelly on 1/18/15.
//  Copyright (c) 2015 kyle. All rights reserved.
//
//  We want to do as few xors as possible.
//  Notice that xor-ing a value with itself results in zero.
//  It follows that xor-ing a value with itself n * 2 times results in zero.
//  So if we find how many times a value appears in the set of subarrays
//    we can ignore those that occur an even number of times
//    and keep those that occur an odd number.
//
//  Note that the number of times it occurs in the subarrays is based on 2 things:
//  1. total length of original array (because there's more subarrays)
//  2. index, because an element at index i can't appear at the (i+1)'th index of a subarray
//       (or if an element is the last element, there can't be any after it in a subarray).
//
//  The number of times an element at index i occurs where:
//  i = 1-based index from start of array
//  n = number of elements of array
//
//  ~~hand waving~~
//  SUM (from j=1 to n) { min(i, j, n-j) }
//
//  which is equivalent to
//
//  (i * (i+1) / 2)  +  i * (n - i*2)  +  (i * (i+1) / 2)
//
//  (initial sum until i == j, middle part where i < min(j, n-j), trailing sum from i == n-j)
//
//  simplifies to
//
//  i * (n - i + 1)
//
//  or (i+1) * (n-i) for 0-based indexes.
//
//  Here we can note that both the (i+1) and (n-i) terms are both odd iff i is even and n is odd.
//  Otherwise the product is even so we can disregard that element.
//  This problems reduces to xor-ing elements at even indexes in odd-length arrays.
//

#include <stdio.h>
#include <stdlib.h>

#include "primitivetypes.h"

int sansaAndXor (void) {
    int numTestCases;
    scanf("%d", &numTestCases);
    
    while (numTestCases--) {
        int inputLength;
        scanf("%d", &inputLength);
        
        uint xorSum = 0;
        int isInputLengthOdd = inputLength % 2;
        int isEvenIndex = 1;
        
        while (inputLength--) {
            uint element;
            scanf("%u", &element);
            
            if (isInputLengthOdd && isEvenIndex) {
                xorSum ^= element;
            }
            
            isEvenIndex = !isEvenIndex;
        }
        
        printf("%u\n", xorSum);
    }
    
    return 0;
}
