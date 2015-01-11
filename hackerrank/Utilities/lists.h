//
//  lists.h
//  hackerrank
//
//  Created by Kyle Donnelly on 1/3/15.
//  Copyright (c) 2015 kyle. All rights reserved.
//

#ifndef hackerrank_lists_h
#define hackerrank_lists_h

typedef struct _intList {
    int value;
    struct _intList *next;
} intList;

void addToIntList(intList **head, int newValue);
void deleteElementsAfterNode(intList *node, int numToRemove);
void freeIntList(intList *list);

#endif
