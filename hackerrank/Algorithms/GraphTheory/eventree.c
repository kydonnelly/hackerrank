/*
 *  EvenTree.c
 *  InterviewStreet
 *
 *  Created by Kyle Donnelly on 12/15/12.
 *  Copyright 2012 Penn State University. All rights reserved.
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct _tree {
	int num;
	struct _list *children;
	struct _tree **parent;
	int subtree_size;
} tree;

typedef struct _list {
	tree *t;
	struct _list *next;
} list;

void list_push (list **head, tree *t) {
	list *cur;
	if (*head == NULL) {
		cur = *head = malloc(sizeof(list));
	}
	else {
		for (cur = *head; cur->next != NULL; cur = cur->next);
		cur = cur->next = malloc(sizeof(list));
	}
	
	cur->t = t;
	cur->next = NULL;
}

int set_subtree_size (tree *t) {
	int size = 0;
	
	if (t->subtree_size == 0) {
		for (list *it = t->children; it != NULL; it=it->next) {
			size += set_subtree_size(it->t);
		}
        
		t->subtree_size = size + 1;
	}
	
	return t->subtree_size;
}

int delete_path (tree *t) {
	list *cur, *next;
	
	if (t == NULL) {
		return 0;
	}
	
	if (t->subtree_size == 0) {
		set_subtree_size(t);
	}
	
	if (t->subtree_size % 2 == 0) {
		if (t->parent == NULL) {
			return 0;
		}
		
		/* Delete parent pointer */
		for (cur = (*(t->parent))->children; cur != NULL && cur->t->num != t->num; cur = cur->next);
		if (cur != NULL) {
			if (cur->next == NULL) {
				free(cur);
			}
			else {
				cur->t = cur->next->t;
				next = cur->next->next;
				free(cur->next);
				cur->next = next;
			}
		}
		t->parent = NULL;
		return 1;
	}
    
	return 0;
}

int eventree (void) {
	int n, m;
	int top, bottom, sum=0;
	tree **nodes;
	
	scanf("%d %d", &n, &m);
	nodes = malloc(sizeof(tree *) * n);
	
	for (int i=0; i<n; i++) {
		nodes[i] = malloc(sizeof(tree));
		nodes[i]->num = i + 1;
		nodes[i]->parent = NULL;
		nodes[i]->subtree_size = 0;
	}
	
	for (int i=0; i<m; i++) {
		scanf("%d %d", &bottom, &top);
		
		list_push(&(nodes[top-1]->children), nodes[bottom-1]);
		nodes[bottom-1]->parent = malloc(sizeof(tree *));
		*(nodes[bottom-1]->parent) = nodes[top-1];
	}
	
	for (int i=0; i<n; i++) {
		sum += delete_path(nodes[i]);
	}
	
	printf("%d\n", sum);
	
	free(nodes);
	
	return 0;
}