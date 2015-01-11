//
//  unboundedknapsack.c
//  hackerrank
//
//  Created by Kyle Donnelly on 1/4/15.
//  Copyright (c) 2015 kyle. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int unboundedknapsack (void) {
    int numTestCases;
    scanf("%d", &numTestCases);
    
    while (numTestCases--) {
        int *sizes;
        int numSizes;
        int capacity;
        int *validCapacities;
        
        scanf("%d %d", &numSizes, &capacity);
        sizes = malloc(sizeof(int) * numSizes);
        for (int i = 0; i < numSizes; i++) {
            scanf("%d", sizes + i);
        }
        
        validCapacities = malloc(sizeof(int) * (capacity+1));
        validCapacities[0] = 1;
        int maxValidCapacity = 0;
        
        for (int i = 1; i <= capacity; i++) {
            for (int j = 0; j < numSizes; j++) {
                int oldCapacity = i - sizes[j];
                if (oldCapacity >= 0 && validCapacities[oldCapacity]) {
                    validCapacities[i] = 1;
                    maxValidCapacity = i;
                    break;
                }
            }
        }
        
        printf("%d\n", maxValidCapacity);
    }
    
    return 0;
}
