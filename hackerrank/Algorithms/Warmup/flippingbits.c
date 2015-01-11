//
//  flippingbits.c
//  hackerrank
//
//  Created by Kyle Donnelly on 1/5/15.
//  Copyright (c) 2015 kyle. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "primitivetypes.h"

int flippingbits (void) {
    int numTestCases;
    scanf("%d", &numTestCases);
    
    while (numTestCases--) {
        uint input;
        scanf("%u", &input);
        printf("%u\n", input ^ -1);
    }
    
    return 0;
}
