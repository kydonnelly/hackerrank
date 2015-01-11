//
//  coinonthetable.c
//  hackerrank
//
//  Created by Kyle Donnelly on 1/3/15.
//  Copyright (c) 2015 kyle. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ABS(a) ((a > 0) ? a : -1 * (a))
#define IMPOSSIBLE -1
#define UNENCOUNTERED -2

typedef struct {
    int stepsToTarget;
    int changesRequired;
} gridInfo;

static int numRows;
static int numColumns;
static int targetRow;
static int targetColumn;
static char **grid;
static gridInfo **cachedGridInfo;

int minChangesToTargetRecursive(int, int, int);

static inline int safeMinChangesToTargetRecursive (int startRow, int startColumn, int stepsRemaining) {
    if (startRow >= 0 && startColumn >= 0 && startRow < numRows && startRow < numColumns) {
        return minChangesToTargetRecursive(startRow, startColumn, stepsRemaining);
    } else {
        return IMPOSSIBLE;
    }
}

static inline int cacheAndReturnMinChanges (int minChanges, int startRow, int startColumn, int stepsRemaining) {
    gridInfo info;
    info.stepsToTarget = stepsRemaining;
    info.changesRequired = minChanges;
    cachedGridInfo[startRow][startColumn] = info;
    
    return minChanges;
}

int minChangesToTargetRecursive (int startRow, int startColumn, int stepsRemaining) {
    gridInfo info = cachedGridInfo[startRow][startColumn];
    if (info.stepsToTarget != UNENCOUNTERED && info.stepsToTarget >= stepsRemaining) {
        return info.changesRequired;
    }
    
    int distance = ABS(startRow - targetRow) + ABS(startColumn - targetColumn);
    if (distance <= 0) {
        return cacheAndReturnMinChanges(0, startRow, startColumn, stepsRemaining);
    } else if (distance > stepsRemaining) {
        return cacheAndReturnMinChanges(IMPOSSIBLE, startRow, startColumn, stepsRemaining);
    }
    
    // check direction of no change
    char direction = grid[startRow][startColumn];
    int dRow = 0;
    int dColumn = 0;
    switch (direction) {
        case 'R':
            dColumn = 1;
            break;
        case 'L':
            dColumn = -1;
            break;
        case 'U':
            dRow = -1;
            break;
        case 'D':
            dRow = 1;
            break;
        default:
            return cacheAndReturnMinChanges(IMPOSSIBLE, startRow, startColumn, stepsRemaining);
    }
    
    int changesInPreferredDirection = safeMinChangesToTargetRecursive(startRow + dRow, startColumn + dColumn, stepsRemaining - 1);
    int minChanges = (changesInPreferredDirection == IMPOSSIBLE) ? INT_MAX : changesInPreferredDirection;

    if (minChanges <= 1) {
        // checking other directions won't be any better.
        return cacheAndReturnMinChanges(changesInPreferredDirection, startRow, startColumn, stepsRemaining);
    }
    
    int changeInOtherDirection;
    // check up, down, left, right
    for (int row = -1; row <= 1; row++) {
        for (int column = -1; column <= 1; column++) {
            if (ABS(row) ^ ABS(column)) {
                changeInOtherDirection = safeMinChangesToTargetRecursive(startRow + row, startColumn + column, stepsRemaining - 1);
                if (changeInOtherDirection != IMPOSSIBLE && (changeInOtherDirection + 1) < minChanges) {
                    minChanges = changeInOtherDirection + 1;
                    if (minChanges <= 1) {
                        // checking other directions won't be any better.
                        return cacheAndReturnMinChanges(minChanges, startRow, startColumn, stepsRemaining);
                    }
                }
            }
        }
    }
    
    return cacheAndReturnMinChanges(minChanges, startRow, startColumn, stepsRemaining);
}

int coinonthetable (void) {
    int numSteps;
    
    scanf("%d %d %d", &numRows, &numColumns, &numSteps);
    grid = malloc(sizeof(char *) * numRows);
    cachedGridInfo = malloc(sizeof(gridInfo *) * numRows);
    
    for (int i = 0; i < numRows; i++) {
        grid[i] = malloc(sizeof(char) * numColumns);
        cachedGridInfo[i] = malloc(sizeof(gridInfo) * (numColumns+1));
        scanf("%s", grid[i]);
    }
    
    for (int row = 0; row < numRows; row++) {
        for (int column = 0; column < numColumns; column++) {
            if (grid[row][column] == '*') {
                targetRow = row;
                targetColumn = column;
                break;
            }
            
            gridInfo info = {UNENCOUNTERED, UNENCOUNTERED};
            cachedGridInfo[row][column] = info;
        }
    }
    
    printf("%d", minChangesToTargetRecursive(0, 0, numSteps));
    
    for (int i = 0; i < numRows; i++) {
        free(grid[i]);
        free(cachedGridInfo[i]);
    }
    free(grid);
    free(cachedGridInfo);
    
    return 0;
}