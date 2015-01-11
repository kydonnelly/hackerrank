//
//  lonelyinteger.c
//  hackerrank
//
//  Created by Kyle Donnelly on 2/16/14.
//  Copyright (c) 2014 kyle. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUE 100

int findMinValueWithFrequency(int *array, int arraySize, int frequency) {
	int *numbers = malloc(sizeof(int) * (MAX_VALUE + 1));
    int foundValue = -1;
    
    for (int i = 0; i <= MAX_VALUE; i++) {
		numbers[i] = 0;
	}
	
	for (int i = 0; i < arraySize; i++) {
		numbers[array[i]]++;
	}
    
    for (int i = 0; i <= MAX_VALUE; i++) {
		if (numbers[i] == frequency) {
            foundValue = i;
            break;
		}
	}
    
    free(numbers);
    return foundValue;
}

int lonelyinteger (void) {
    int arraySize;
    scanf("%d", &arraySize);
    
    int *array = malloc(sizeof(int) * arraySize);
    for (int i = 0; i < arraySize; i++) {
        scanf("%d", array + i);
    }
    
    printf("%d", findMinValueWithFrequency(array, arraySize, 1));
    
    free(array);
    
    return 0;
}