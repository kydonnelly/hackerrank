//
//  cavitymap.c
//  hackerrank
//
//  Created by Kyle Donnelly on 1/7/15.
//  Copyright (c) 2015 kyle. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int cavitymap (void) {
    int gridSize;
    char **grid;
    
    scanf("%d", &gridSize);
    grid = malloc(sizeof(char *) * gridSize);
    for (int i = 0; i < gridSize; i++) {
        grid[i] = malloc(sizeof(char) * (gridSize+1));
        scanf("%s", grid[i]);
    }
    
    for (int i = 1; i < gridSize-1; i++) {
        for (int j = 1; j < gridSize-1; j++) {
            char depth = grid[i][j];
            if (depth > grid[i-1][j] &&
                depth > grid[i+1][j] &&
                depth > grid[i][j-1] &&
                depth > grid[i][j+1]) {
                grid[i][j] = 'X';
            }
        }
    }
    
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
    
    for (int i = 0; i < gridSize; i++) {
        free(grid[i]);
    }
    free(grid);
    
    return 0;
}
