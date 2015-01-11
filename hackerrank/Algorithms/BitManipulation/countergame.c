//
//  countergame.c
//  hackerrank
//
//  Created by Kyle Donnelly on 1/4/15.
//  Copyright (c) 2015 kyle. All rights reserved.
//

#include <stdio.h>

#include "primitivetypes.h"

#define NUM_PLAYERS 2
#define PLAYERS {"Louise", "Richard"}

int turnsRequired(ull counter) {
    int numBits = 0;
    int firstBit = 0;
    int foundFirstBit = 0;
    
    while (counter != 0) {
        if (counter & 1) {
            numBits++;
            foundFirstBit = 1;
        }
        if (!foundFirstBit) {
            firstBit++;
        }
        counter >>= 1;
    }
    
    return (numBits - 1) + firstBit;
}

int countergame (void) {
    ull counter;
    int numCases;
    scanf("%d", &numCases);
    
    char *players[] = PLAYERS;
    
    while (numCases--) {
        scanf("%llu", &counter);
        int numTurns = turnsRequired(counter);
        printf("%s\n", players[(numTurns + NUM_PLAYERS - 1) % NUM_PLAYERS]);
    }
    
    return 0;
}
