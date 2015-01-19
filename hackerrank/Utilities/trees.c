//
//  trees.c
//  hackerrank
//
//  Created by Kyle Donnelly on 1/12/15.
//  Copyright (c) 2015 kyle. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "trees.h"

#pragma mark - Memory Management

void freeTree (intTree *tree) {
    if (tree) {
        freeTree(tree->left);
        freeTree(tree->right);
        free(tree);
    }
}

#pragma mark - Flatten Trees

typedef struct {
    int *values;
    int numValues;
} flattenedTree;

static inline int sizeOfTree (intTree *tree) {
    if (tree) {
        return tree->size;
    } else {
        return 0;
    }
}

void flattenTreeRecursive (intTree *head, int *values, int numValues, int debug) {
    if (!head) {
        return;
    }
    
    int numLeftNodes = sizeOfTree(head->left);
    int numRightNodes = sizeOfTree(head->right);
    
    values[numLeftNodes] = head->value;
    
    flattenTreeRecursive(head->left, values, numLeftNodes, debug);
    flattenTreeRecursive(head->right, values + numLeftNodes + 1, numRightNodes, debug + numLeftNodes + 1);
}

flattenedTree treeToArray (intTree *head) {
    flattenedTree flatTree;
    if (!head) {
        flatTree.numValues = 0;
        return flatTree;
    }
    
    int numTreeNodes = 1 + sizeOfTree(head->left) + sizeOfTree(head->right);
    
    int *array = malloc(sizeof(int) * numTreeNodes);
    flattenTreeRecursive(head, array, numTreeNodes, 0);
    
    flatTree.values = array;
    flatTree.numValues = numTreeNodes;
    return flatTree;
}

#pragma mark - Build trees

intTree *arrayToTree (int *values, int numValues) {
    if (numValues <= 0) {
        return NULL;
    }
    
    // assume sorted array.
    int middleIndex = numValues / 2;
    intTree *tree = malloc(sizeof(intTree));
    tree->value = values[middleIndex];
    tree->size = numValues;
    
    tree->left = arrayToTree(values, middleIndex);
    tree->right = arrayToTree(values + middleIndex + 1, numValues - middleIndex - 1);
    
    return tree;
}

#pragma mark - Rebalance

void rebalanceTree (intTree **head) {
    flattenedTree flatTree = treeToArray(*head);
    freeTree(*head);
    
    intTree *newTree = arrayToTree(flatTree.values, flatTree.numValues);
    free(flatTree.values);
    *head = newTree;
}

#pragma mark - Search

int largestValueInTreeWithPop (intTree **tree, int shouldPop) {
    intTree *node = *tree;
    int largestValue = 0;
    
    if (node->right) {
        largestValue = largestValueInTreeWithPop(&node->right, shouldPop);
        
        if (shouldPop) {
            node->size--;
        }
    } else {
        largestValue = node->value;
        
        if (shouldPop) {
            *tree = node->left;
            free(node);
        }
    }
    
    return largestValue;
}

int smallestValueInTreeWithPop (intTree **tree, int shouldPop) {
    intTree *node = *tree;
    int smallestValue = 0;
    
    if (node->left) {
        smallestValue = smallestValueInTreeWithPop(&node->left, shouldPop);
        
        if (shouldPop) {
            node->size--;
        }
    } else {
        smallestValue = node->value;
        
        if (shouldPop) {
            *tree = node->right;
            free(node);
        }
    }
    
    return smallestValue;
}

int largestValueInTree (intTree *tree) {
    return largestValueInTreeWithPop(&tree, 0);
}

int smallestValueInTree (intTree *tree) {
    return smallestValueInTreeWithPop(&tree, 0);
}

#pragma mark - Insertion

int addToTreeRecursive (intTree **head, int value) {
    intTree *node = *head;
    
    if (node == NULL) {
        intTree *leaf = malloc(sizeof(intTree));
        leaf->left = leaf->right = NULL;
        leaf->value = value;
        leaf->size = 1;
        
        *head = leaf;
        return 0;
    }
    
    node->size++;
    
    int shouldAddToLeft = 0;
    if (value < node->value) {
        shouldAddToLeft = 1;
    } else if (value == node->value && sizeOfTree(node->left) < sizeOfTree(node->right)) {
        shouldAddToLeft = 1;
    }
    
    int needsRebalanced = 0;
    if (shouldAddToLeft) {
        needsRebalanced = addToTreeRecursive(&node->left, value);
    } else {
        needsRebalanced = addToTreeRecursive(&node->right, value);
    }
    
    if (needsRebalanced) {
        return needsRebalanced;
    }
    
    int numLeftNodes = sizeOfTree(node->left);
    int numRightNodes = sizeOfTree(node->right);
    
    if (shouldAddToLeft) {
        return numLeftNodes >= (numRightNodes+1) * 2;
    } else {
        return numRightNodes >= (numLeftNodes+1) * 2;
    }
}

void addToTree (intTree **head, int value) {
    int needsRebalanced = addToTreeRecursive(head, value);
    if (needsRebalanced) {
        rebalanceTree(head);
    }
}

#pragma mark - Deletion

int popLargestValueInTree (intTree **tree) {
    return largestValueInTreeWithPop(tree, 1);
}

int popSmallestValueInTree (intTree **tree) {
    return smallestValueInTreeWithPop(tree, 1);
}

typedef struct {
    int didRemove, shouldRebalance;
} removalReturnValue;

removalReturnValue removeFromTreeIfPossibleRecursive (intTree **head, int value) {
    intTree *node = *head;
    
    removalReturnValue finalResult;
    finalResult.didRemove = 0;
    finalResult.shouldRebalance = 0;
    
    int didRemoveLeft = 0;
    int didRemoveRight = 0;
    
    if (!node) {
        // noop
    } else if (node->value > value) {
        finalResult = removeFromTreeIfPossibleRecursive(&node->left, value);
        didRemoveLeft = finalResult.didRemove;
    } else if (node->value < value) {
        finalResult = removeFromTreeIfPossibleRecursive(&node->right, value);
        didRemoveRight = finalResult.didRemove;
    } else {
        if (node->left) {
            node->value = popLargestValueInTree(&node->left);
            didRemoveLeft = 1;
        } else if (node->right) {
            node->value = popLargestValueInTree(&node->right);
            didRemoveRight = 1;
        } else {
            free(node);
            *head = NULL;
        }
        
        finalResult.didRemove = 1;
        finalResult.shouldRebalance = 0;
    }
    
    if (didRemoveLeft || didRemoveRight) {
        node->size--;
        
        if (!finalResult.shouldRebalance) {
            int numLeftNodes = sizeOfTree(node->left);
            int numRightNodes = sizeOfTree(node->right);
            
            if (didRemoveLeft) {
                finalResult.shouldRebalance = (numRightNodes >= (numLeftNodes+1) * 2);
            } else {
                finalResult.shouldRebalance = (numLeftNodes >= (numRightNodes+1) * 2);
            }
        }
    }
    
    return finalResult;
}

int removeFromTreeIfPossible (intTree **head, int value) {
    removalReturnValue result = removeFromTreeIfPossibleRecursive(head, value);
    
    if (result.shouldRebalance) {
        rebalanceTree(head);
    }
    
    return result.didRemove;
}
