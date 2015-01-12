//
//  cutTheTree.c
//  hackerrank
//
//  Created by Kyle Donnelly on 1/11/15.
//  Copyright (c) 2015 kyle. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "lists.h"

#define PARENT_NEIGHBOR_INDEX -1

typedef struct _treeNode {
    int value;
    int subtreeValue;
    
    intList *neighbors;
} treeNode;

void addNeighborNodeHelper (treeNode *node, int neighbor) {
    addToIntList(&node->neighbors, neighbor);
}

void addNeighbor (treeNode **treeNodes, int neighbor1, int neighbor2) {
    addNeighborNodeHelper(treeNodes[neighbor1 - 1], neighbor2 - 1);
    addNeighborNodeHelper(treeNodes[neighbor2 - 1], neighbor1 - 1);
}

void fillSubtreeValues (treeNode **treeNodes, int index, int *seenIndexes) {
    treeNode *currentNode = treeNodes[index];
    seenIndexes[index] = 1;
    
    int childValueSum = 0;
    for (intList *iter = currentNode->neighbors; iter != NULL; iter = iter->next) {
        int neighborIndex = iter->value;
        if (!seenIndexes[neighborIndex]) {
            fillSubtreeValues(treeNodes, neighborIndex, seenIndexes);
            childValueSum += treeNodes[neighborIndex]->subtreeValue;
        } else {
            // we are the child.
            iter->value = PARENT_NEIGHBOR_INDEX;
        }
    }
    
    currentNode->subtreeValue = childValueSum + currentNode->value;
}

int findMinTreeDiffRecursive (treeNode **treeNodes, int currentNodeIndex, int parentValue) {
    treeNode *node = treeNodes[currentNodeIndex];
    int minTreeDiff = INT_MAX;
    
    for (intList *iter = node->neighbors; iter != NULL; iter = iter->next) {
        int neighborIndex = iter->value;
        if (neighborIndex == PARENT_NEIGHBOR_INDEX) {
            continue;
        }
        
        treeNode *cutCandidate = treeNodes[neighborIndex];
        int ourValueAfterCut = node->subtreeValue - cutCandidate->subtreeValue + parentValue;
        
        int treeDiff = abs(ourValueAfterCut - cutCandidate->subtreeValue);
        if (treeDiff < minTreeDiff) {
            minTreeDiff = treeDiff;
        }
        
        int bestCutFromChild = findMinTreeDiffRecursive(treeNodes, neighborIndex, ourValueAfterCut);
        if (bestCutFromChild < minTreeDiff) {
            minTreeDiff = bestCutFromChild;
        }
    }
    
    return minTreeDiff;
}

int findMinTreeDiff (treeNode **treeNodes, int rootIndex) {
    return findMinTreeDiffRecursive(treeNodes, rootIndex, 0);
}

int cutTheTree (void) {
    int numNodes;
    scanf("%d", &numNodes);
    
    treeNode **treeNodes = malloc(sizeof(treeNode *) * numNodes);
    for (int i = 0; i < numNodes; i++) {
        treeNode *node = malloc(sizeof(treeNode));
        node->neighbors = NULL;
        node->subtreeValue = 0;
        
        treeNodes[i] = node;
    }
    
    for (int i = 0; i < numNodes; i++) {
        scanf("%d", &treeNodes[i]->value);
    }
    
    for (int i = 0; i < numNodes-1; i++) {
        int neighbor1, neighbor2;
        scanf("%d %d", &neighbor1, &neighbor2);
        addNeighbor(treeNodes, neighbor1, neighbor2);
    }
    
    int *nodesSeen = malloc(sizeof(int) * numNodes);
    for (int i = 0; i < numNodes; i++) {
        nodesSeen[i] = 0;
    }
    
    fillSubtreeValues(treeNodes, 0, nodesSeen);
    int treeDiff = findMinTreeDiff(treeNodes, 0);
    printf("%d\n", treeDiff);
    
    for (int i = 0; i < numNodes; i++) {
        freeIntList(treeNodes[i]->neighbors);
        free(treeNodes[i]);
    }
    free(treeNodes);
    free(nodesSeen);
    
    return 0;
}
