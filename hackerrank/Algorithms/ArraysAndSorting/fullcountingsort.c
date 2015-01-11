//
//  fullcountingsort.c
//  hackerrank
//
//  Created by Kyle Donnelly on 12/6/14.
//  Copyright (c) 2014 kyle. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_STR_LEN 11
#define MAX_RANK 100

int fullcountingsort(void) {
    int inputLines;
    int rank;
    char *str;
    int *ranks;
    char **strings;
    int *rankCounts;
    char **outStrings;
    
    scanf("%d", &inputLines);
    int numRemovedStrings = inputLines / 2;
    
    rankCounts = malloc(sizeof(int) * (MAX_RANK+1));
    ranks = malloc(sizeof(int) * inputLines);
    strings = malloc(sizeof(char *) * inputLines);
    outStrings = malloc(sizeof(char *) * inputLines);
    
    for (int i = 0; i < inputLines; i++) {
        rankCounts[i] = 0;
    }
    
    for (int i = 0; i < numRemovedStrings; i++) {
        str = malloc(sizeof(char) * MAX_STR_LEN);
        scanf("%d %s", &rank, str);
        
        str[0] = '-';
        str[1] = '\0';
        
        ranks[i] = rank;
        strings[i] = str;
        rankCounts[rank+1]++;
    }
    
    for (int i = numRemovedStrings; i < inputLines; i++) {
        str = malloc(sizeof(char) * MAX_STR_LEN);
        scanf("%d %s", &rank, str);
        
        ranks[i] = rank;
        strings[i] = str;
        rankCounts[rank+1]++;
    }
    
    for (int i = 1; i <= MAX_RANK; i++) {
        rankCounts[i] += rankCounts[i-1];
    }
    
    for (int i = 0; i < inputLines; i++) {
        int rank = ranks[i];
        int sortedIndex = rankCounts[rank];
        outStrings[sortedIndex] = strings[i];
        rankCounts[rank]++;
    }
    
    for (int i = 0; i < inputLines; i++) {
        str = outStrings[i];
        printf("%s ", str);
        free(str);
    }
    
    free(rankCounts);
    free(ranks);
    free(strings);
    free(outStrings);
    
    return 0;
}