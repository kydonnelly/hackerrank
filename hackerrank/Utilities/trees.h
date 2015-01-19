//
//  trees.h
//  hackerrank
//
//  Created by Kyle Donnelly on 1/12/15.
//  Copyright (c) 2015 kyle. All rights reserved.
//

#ifndef hackerrank_trees_h
#define hackerrank_trees_h

typedef struct _intTree {
    int value;
    int size;
    struct _intTree *left, *right;
} intTree;

void freeTree(intTree *tree);

void addToTree(intTree **head, int value);
int removeFromTreeIfPossible(intTree **head, int value);

int largestValueInTree (intTree *tree);
int smallestValueInTree (intTree *tree);

#endif
