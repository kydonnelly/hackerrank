//
//  median.c
//  hackerrank
//
//  Created by Kyle Donnelly on 1/12/15.
//  Copyright (c) 2015 kyle. All rights reserved.
//
//  not solved yet. times out.
//

#include <stdio.h>
#include <stdlib.h>

#include "trees.h"

#define INSERT_COMMAND 'a'
#define REMOVE_COMMAND 'r'

#define INVALID_COMMAND "Wrong!"

typedef struct {
    int lower, higher;
} medianValues;

medianValues medianValuesInTreeRecursive (intTree *tree, int numBelow, int numAbove) {
    medianValues median;
    
    if (tree->left) {
        numBelow += tree->left->size;
    }
    if (tree->right) {
        numAbove += tree->right->size;
    }
    
    if (numBelow == numAbove) {
        median.lower = median.higher = tree->value;
    } else if (numBelow + 1 == numAbove) {
        median.lower = tree->value;
        median.higher = tree->right ? smallestValueInTree(tree->right) : tree->value;
    } else if (numBelow - 1 == numAbove) {
        median.lower = tree->left ? largestValueInTree(tree->left) : tree->value;
        median.higher = tree->value;
    } else if (numBelow < numAbove) {
        median = medianValuesInTreeRecursive(tree->right, numBelow + 1, numAbove - tree->right->size);
    } else {
        median = medianValuesInTreeRecursive(tree->left, numBelow - tree->left->size, numAbove + 1);
    }
    
    return median;
}

medianValues medianValuesInTree (intTree *head) {
    return medianValuesInTreeRecursive(head, 0, 0);
}

int median (void) {
    int numCommands;
    scanf("%d", &numCommands);
    
    intTree *tree = NULL;
    
    while (numCommands--) {
        char command;
        int commandValue;
        scanf("\n%c %d", &command, &commandValue);
        
        int shouldFindMedian = 1;
        
        if (command == INSERT_COMMAND) {
            addToTree(&tree, commandValue);
        } else if (command == REMOVE_COMMAND) {
            shouldFindMedian = removeFromTreeIfPossible(&tree, commandValue) && tree;
        } else {
            shouldFindMedian = 0;
        }
        
        if (shouldFindMedian) {
            medianValues medianInfo = medianValuesInTree(tree);
            int difference = medianInfo.higher - medianInfo.lower;
            if (difference % 2) {
                printf("%.1f", medianInfo.lower + difference / 2.f);
            } else {
                printf("%d", medianInfo.lower + difference / 2);
            }
        } else {
            printf(INVALID_COMMAND);
        }
        
        printf("\n");
    }
    
    freeTree(tree);
    
    return 0;
}
