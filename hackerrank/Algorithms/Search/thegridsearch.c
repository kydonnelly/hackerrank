//
//  thegridsearch.c
//  hackerrank
//
//  Created by Kyle Donnelly on 1/3/15.
//  Copyright (c) 2015 kyle. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS "YES";
#define FAILURE "NO";

//#define DEBUG_INPUT

int doesGridMatchPattern (char **grid, char **pattern, int columnOffset, int rows, int columns) {
    for (int row = 0; row < rows; row++) {
        char *gridString = grid[row] + columnOffset;
        for (int column = 0; column < columns; column++) {
            if (gridString[column] != pattern[row][column]) {
                return 0;
            }
        }
    }
    
    return 1;
}

int doesGridContainPattern (char **grid, char **pattern, int numGridRows, int numGridColumns, int numPatternRows, int numPatternColumns) {
    int maxRow = numGridRows - numPatternRows;
    int maxColumn = numGridColumns - numPatternColumns;
    for (int row = 0; row <= maxRow; row++) {
        for (int column = 0; column <= maxColumn; column++) {
            if (doesGridMatchPattern(grid + row, pattern, column, numPatternRows, numPatternColumns)) {
                return 1;
            }
        }
    }
    
    return 0;
}

int thegridsearch (void) {
    int numTestCases;
    int numGridRows, numGridColumns;
    int numPatternRows, numPatternColumns;
    char **grid;
    char **pattern;
   
#ifdef DEBUG_INPUT
    numTestCases = 5;
#else
    scanf("%d", &numTestCases);
#endif
    
    while (numTestCases--) {
#ifdef DEBUG_INPUT
        numGridRows = 1000;
        numGridColumns = 1000;
#else
        scanf("%d %d", &numGridRows, &numGridColumns);
#endif
        grid = malloc(sizeof(char *) * numGridRows);
        
        for (int i = 0; i < numGridRows; i++) {
            grid[i] = malloc(sizeof(char) * (numGridColumns+1));
#ifdef DEBUG_INPUT
            for (int j = 0; j < numGridColumns; j++) {
                grid[i][j] = 'a' + (rand() % ('z' - 'a'));
            }
#else
            scanf("%s", grid[i]);
#endif
        }
        
#ifdef DEBUG_INPUT
        numPatternRows = 1000;
        numPatternColumns = 1000;
#else
        scanf("%d %d", &numPatternRows, &numPatternColumns);
#endif
        pattern = malloc(sizeof(char *) * numPatternRows);
        
        for (int i = 0; i < numPatternRows; i++) {
            pattern[i] = malloc(sizeof(char) * (numPatternColumns+1));
#ifdef DEBUG_INPUT
            for (int j = 0; j < numGridColumns; j++) {
                grid[i][j] = 'a' + (rand() % ('z' - 'a'));
            }
#else
            scanf("%s", pattern[i]);
#endif
        }
        
        char *result = FAILURE;
        if (doesGridContainPattern(grid, pattern, numGridRows, numGridColumns, numPatternRows, numPatternColumns)) {
            result = SUCCESS;
        }
        printf("%s\n", result);
        
        
        for (int i = 0; i < numGridRows; i++) {
            free(grid[i]);
        }
        for (int i = 0; i < numPatternRows; i++) {
            free(pattern[i]);
        }
        free(grid);
        free(pattern);
    }
    
    return 0;
}