//
//  countluck.c
//  hackerrank
//
//  Created by Kyle Donnelly on 1/11/15.
//  Copyright (c) 2015 kyle. All rights reserved.
//
//  Limited DFS through empty cells.
//  The limit is on how many times you can recurse to the set of children
//    when the set contains more than one child (child = empty neighbor cell)
//

#include <stdio.h>
#include <stdlib.h>

#define EMPTY_CELL '.'
#define BLOCKED_CELL 'X'

#define START_CELL 'M'
#define TARGET_CELL '*'

#define SUCCESS "Impressed"
#define FAILURE "Oops!"

int canReachTargetInMovesRecursive (char **grid, int startRow, int startColumn,
                                    int movesAllowed, int gridWidth, int gridHeight) {
    if (grid[startRow][startColumn] == TARGET_CELL) {
        return (movesAllowed == 0);
    }
    
    int numOptions = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (abs(i) ^ abs(j)) {
                int childRow = startRow + i;
                int childColumn = startColumn + j;
                if (childRow >= 0 && childColumn >= 0 && childRow < gridHeight && childColumn < gridWidth &&
                    grid[startRow + i][startColumn + j] != BLOCKED_CELL) {
                    numOptions++;
                }
            }
        }
    }
    
    if (numOptions > 1) {
        movesAllowed--;
    }
    if (movesAllowed < 0 || numOptions <= 0) {
        return 0;
    }
    
    // Don't turn around. No cycles to worry about per prompt.
    grid[startRow][startColumn] = BLOCKED_CELL;
    int canReachFromChild = 0;
    
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (abs(i) ^ abs(j)) {
                int childRow = startRow + i;
                int childColumn = startColumn + j;
                
                if (childRow >= 0 && childColumn >= 0 && childRow < gridHeight && childColumn < gridWidth &&
                    grid[childRow][childColumn] != BLOCKED_CELL &&
                    canReachTargetInMovesRecursive(grid, startRow + i, startColumn + j, movesAllowed, gridWidth, gridHeight)) {
                    
                    canReachFromChild = 1;
                    break;
                }
            }
        }
        if (canReachFromChild) {
            break;
        }
    }
    
    return canReachFromChild;
}

int countluck (void) {
    int numTestCases;
    scanf("%d", &numTestCases);
    
    while (numTestCases--) {
        int height, width;
        scanf("%d %d", &height, &width);
        
        char **grid = malloc(sizeof(char *) * height);
        for (int i = 0; i < height; i++) {
            grid[i] = malloc(sizeof(char) * (width+1));
            scanf("%s", grid[i]);
        }
        
        int decisionsAllowed;
        scanf("%d", &decisionsAllowed);
        
        int startRow = -1;
        int startColumn = -1;
        int found = 0;
        
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (grid[i][j] == START_CELL) {
                    startRow = i;
                    startColumn = j;
                    found = 1;
                    break;
                }
            }
            if (found) {
                break;
            }
        }
        
        if (canReachTargetInMovesRecursive(grid, startRow, startColumn, decisionsAllowed, width, height)) {
            printf(SUCCESS);
        } else {
            printf(FAILURE);
        }
        printf("\n");
        
        for (int i = 0; i < height; i++) {
            free(grid[i]);
        }
        free(grid);
    }
    
    return 0;
}
