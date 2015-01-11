//
//  lists.c
//  hackerrank
//
//  Created by Kyle Donnelly on 1/3/15.
//  Copyright (c) 2015 kyle. All rights reserved.
//

#include <stdlib.h>

#include "lists.h"

void addToIntList (intList **head, int newValue) {
    intList *newHead = malloc(sizeof(intList));
    newHead->next = *head;
    newHead->value = newValue;
    *head = newHead;
}

void freeIntList (intList *list) {
    while (list != NULL) {
        intList *next = list->next;
        free(list);
        list = next;
    }
}

void deleteElementsAfterNode(intList *node, int numToRemove) {
    intList *next = node->next;
    for (int i = 0; i < numToRemove && next != NULL; i++) {
        intList *trail = next;
        next = next->next;
        free(trail);
    }
    
    node->next = next;
}
