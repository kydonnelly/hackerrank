//
//  mrkmarsh.c
//  hackerrank
//
//  Created by Kyle Donnelly on 1/3/15.
//  Copyright (c) 2015 kyle. All rights reserved.
//

// NOT SOLVED YET

#include <stdio.h>
#include <stdlib.h>

//#define MAX_VAL(a, b) (a > b ? a : b)

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
        
        for (int j = 0; j < numColumns; j++) {
            rectangle *rect = malloc(sizeof(rectangle));
            rect->width = 0;
            rect->height = 0;
        }
    }
    
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
    
    for (int i = numRows-2; i >= 0; i--) {
        for (int j = numColumns-2; j >= 0; j--) {
            rectangle *fence = gridFences[i][j];
            int bestPossibleWidth = fence->width;
            int bestPossibleHeight = fence->height;
            int distanceFound = 0;
            
            for (int width = j + bestPossibleWidth; width > j; width--) {
                for (int height = i + bestPossibleHeight; height > i; height--) {
                    
                    int otherHeight = gridFences[i][width]->height;
                    int otherWidth = gridFences[height][j]->width;
                    
                    int dHeight = bestPossibleHeight - otherHeight;
                    int dWidth = bestPossibleWidth - otherWidth;
                    
                    if (dHeight <= 0 && dWidth <= 0 && (width - j) + (height - i) > distanceFound) {
                        distanceFound = (width - j) + (height - i);
                    }
                }
            }
            
            // using this loop instead of above seems to give different success cases
            // so bug somewhere because this should be just less exhaustive version of above.
            // ie it shouldn't succeed where above one fails, but it appears to.
//            while (bestPossibleHeight > 0 && bestPossibleWidth > 0) {
//                int otherHeight = gridFences[i][j+bestPossibleWidth]->height;
//                int otherWidth = gridFences[i+bestPossibleHeight][j]->width;
//                
//                int dHeight = MAX_VAL(bestPossibleHeight - otherHeight, 0);
//                int dWidth = MAX_VAL(bestPossibleWidth - otherWidth, 0);
//                
//                if (dHeight > dWidth) {
//                    bestPossibleWidth--;
//                } else if (dHeight < dWidth) {
//                    bestPossibleHeight--;
//                } else {
//                    distanceFound = bestPossibleHeight + bestPossibleWidth;
//                    break;
//                }
//            }
            
            if (distanceFound > bestPossibleDistance) {
                bestPossibleDistance = distanceFound;
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