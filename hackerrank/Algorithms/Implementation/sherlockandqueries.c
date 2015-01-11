//
//  sherlockandqueries.c
//  hackerrank
//
//  Created by Kyle Donnelly on 1/11/15.
//  Copyright (c) 2015 kyle. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "primitivetypes.h"

#define BIG_PRIME_MODULO 1000000007

int sherlockandqueries (void) {
    int baseArrayLength;
    int modifierArrayLength;
    scanf("%d %d", &baseArrayLength, &modifierArrayLength);
    
    int *baseArray = malloc(sizeof(int) * baseArrayLength);
    int *stepArray = malloc(sizeof(int) * modifierArrayLength);
    int *scalingArray = malloc(sizeof(int) * modifierArrayLength);
    
    for (int i = 0; i < baseArrayLength; i++) {
        scanf("%d", baseArray + i);
    }
    for (int i = 0; i < modifierArrayLength; i++) {
        scanf("%d", stepArray + i);
    }
    for (int i = 0; i < modifierArrayLength; i++) {
        scanf("%d", scalingArray + i);
    }
    
    // In case the stepArray has multiple repeated values
    //   we will end up doing a lot of the same multiplications
    // So pre-multiply everything so that the only variable
    //   is the baseArray value.
    int *preparedScalings = malloc(sizeof(int) * baseArrayLength);
    for (int i = 0; i < baseArrayLength; i++) {
        preparedScalings[i] = 1;
    }
    
    for (int i = 0; i < modifierArrayLength; i++) {
        int scale = scalingArray[i];
        int stepIndex = stepArray[i] - 1;
        preparedScalings[stepIndex] = (preparedScalings[stepIndex] * (ull)scale) % BIG_PRIME_MODULO;
    }
    
    for (int i = 0; i < baseArrayLength; i++) {
        int scale = preparedScalings[i];
        
        for (int j = i; j < baseArrayLength; j += i+1) {
            baseArray[j] = ((ull)baseArray[j] * scale) % BIG_PRIME_MODULO;
        }
    }
    
    for (int i = 0; i < baseArrayLength; i++) {
        printf("%d ", baseArray[i]);
    }
    
    free(baseArray);
    free(stepArray);
    free(scalingArray);
    free(preparedScalings);
    
    return 0;
}
