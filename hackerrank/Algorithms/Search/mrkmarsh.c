//
//  mrkmarsh.c
//  hackerrank
//
//  Created by Kyle Donnelly on 1/3/15.
//  Copyright (c) 2015 kyle. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define BLOCKED 'x'
#define CLEAR '.'

typedef struct {
    int width;
    int height;
} rectangle;

int mrkmarsh (void) {
    int numRows, numColumns;
    char **grid;
    rectangle ***gridFences;
    
    scanf("%d %d", &numRows, &numColumns);
    grid = malloc(sizeof(char *) * numRows);
    gridFences = malloc(sizeof(rectangle **) * numRows);
    
    for (int i = 0; i < numRows; i++) {
        grid[i] = malloc(sizeof(char) * (numColumns + 1));
        scanf("%s", grid[i]);
    }
    
    for (int i = 0; i < numRows; i++) {
        gridFences[i] = malloc(sizeof(rectangle *) * numColumns);
        for (int j = 0; j < numColumns; j++) {
            rectangle *rect = malloc(sizeof(rectangle));
            rect->width = 0;
            rect->height = 0;
            gridFences[i][j] = rect;
        }
    }
    
    // find max unblocked width and height from each position.
    for (int i = numRows-1; i >= 0; i--) {
        for (int j = numColumns-1; j >= 0; j--) {
            if (grid[i][j] != BLOCKED) {
                if (i+1 < numRows && grid[i+1][j] != BLOCKED) {
                    gridFences[i][j]->height = gridFences[i+1][j]->height + 1;;
                }
                if (j+1 < numColumns && grid[i][j+1] != BLOCKED) {
                    gridFences[i][j]->width = gridFences[i][j+1]->width + 1;
                }
            }
        }
    }
    
    int bestPossibleDistance = 0; // 1-norm for perimeter
    
    // check how close we can get to the max width & height stored above.
    for (int i = numRows-2; i >= 0; i--) {
        for (int j = numColumns-2; j >= 0; j--) {
            rectangle *fence = gridFences[i][j];
            int bestPossibleWidth = fence->width;
            int bestPossibleHeight = fence->height;
            
            // Might be able to do a more intelligent search
            //   but this easily fits in the time limit.
            for (int width = bestPossibleWidth; width > 0; width--) {
                for (int height = bestPossibleHeight; height > 0; height--) {
                    int otherHeight = gridFences[i][j+width]->height;
                    int otherWidth = gridFences[i+height][j]->width;
                    
                    int dHeight = height - otherHeight;
                    int dWidth = width - otherWidth;
                    
                    if (dHeight <= 0 && dWidth <= 0 && width + height > bestPossibleDistance) {
                        bestPossibleDistance = width + height;
                    }
                }
            }
        }
    }
    
    // turn distance into perimeter
    if (bestPossibleDistance > 0) {
        printf("%d\n", 2 * bestPossibleDistance);
    } else {
        printf("impossible\n");
    }
    
    for (int i = 0; i < numRows; i++) {
        free(grid[i]);
        
        for (int j = 0; j < numColumns; j++) {
            free(gridFences[i][j]);
        }
        free(gridFences[i]);
    }
    free(grid);
    free(gridFences);
    
    return 0;
}