//
//  halloweenparty.c
//  hackerrank
//
//  Created by Kyle Donnelly on 1/7/15.
//  Copyright (c) 2015 kyle. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#import "primitivetypes.h"

int halloweenparty (void) {
    int numTestCases;
    scanf("%d", &numTestCases);
    
    while (numTestCases--) {
        ull numCuts;
        scanf("%llu", &numCuts);
        
        printf("%llu\n", numCuts / 2 * ((numCuts+1) / 2));
    }
    
    return 0;
}
