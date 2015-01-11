//
//  sherlockandGCG.c
//  hackerrank
//
//  Created by Kyle Donnelly on 1/7/15.
//  Copyright (c) 2015 kyle. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS "YES"
#define FAILURE "NO"

int sherlockandGCD (void) {
    int numTestCases;
    scanf("%d", &numTestCases);
    
    while (numTestCases--) {
        int arraySize;
        scanf("%d", &arraySize);
        
        int *array = malloc(sizeof(int) * arraySize);
        int *divisibleLocations = malloc(sizeof(int) * arraySize);
        int **sharedDivisorTable = malloc(sizeof(int *) * arraySize);
        
        for (int i = 0; i < arraySize; i++) {
            scanf("%d", array + i);
        }
        
        int maxValue = 1;
        for (int i = 0; i < arraySize; i++) {
            if (array[i] > maxValue) {
                maxValue = array[i];
            }
            
            sharedDivisorTable[i] = malloc(sizeof(int) * arraySize);
            for (int j = 0; j < arraySize; j++) {
                sharedDivisorTable[i][j] = 0;
            }
        }
        
        int divisor = 2;
        while (divisor <= maxValue) {
            maxValue = 1;
            for (int i = 0; i < arraySize; i++) {
                divisibleLocations[i] = 0;
                while (array[i] % divisor == 0) {
                    array[i] /= divisor;
                    divisibleLocations[i] = 1;
                }
                
                if (array[i] > maxValue) {
                    maxValue = array[i];
                }
                
                if (divisibleLocations[i]) {
                    for (int j = 0; j < i; j++) {
                        if (divisibleLocations[j]) {
                            sharedDivisorTable[i][j] = 1;
                        }
                    }
                }
            }
            
            divisor++;
        }
        
        int noSharedDivisorExists = 0;
        for (int i = 0; i < arraySize; i++) {
            for (int j = 0; j < i; j++) {
                if (sharedDivisorTable[i][j] == 0) {
                    noSharedDivisorExists = 1;
                    break;
                }
            }
            if (noSharedDivisorExists) {
                break;
            }
        }
        
        if (noSharedDivisorExists) {
            printf(SUCCESS);
        } else {
            printf(FAILURE);
        }
        printf("\n");
        
        free(array);
        free(divisibleLocations);
        for (int i = 0; i < arraySize; i++) {
            free(sharedDivisorTable[i]);
        }
        free(sharedDivisorTable);
    }
    
    return 0;
}
