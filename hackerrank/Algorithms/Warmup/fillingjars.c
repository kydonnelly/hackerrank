//
//  fillingjars.c
//  hackerrank
//
//  Created by Kyle Donnelly on 1/6/15.
//  Copyright (c) 2015 kyle. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#import "primitivetypes.h"

int fillingjars (void) {
    ull numJars, numOperations;
    ull numItemsInJars;
    
    scanf("%llu %llu", &numJars, &numOperations);
    
    while (numOperations--) {
        int left, right;
        ull numItems;
        
        scanf("%d %d %llu", &left, &right, &numItems);
        numItemsInJars += (right - left + 1) * numItems;
    }
    
    printf("%llu\n", numItemsInJars / numJars);
    
    return 0;
}
