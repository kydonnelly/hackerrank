// Warning: old code

/*
 *  kDifference.c
 *  CodePSU Example Problem
 *
 *  Created by Kyle Donnelly on 3/07/12.
 *
 *	This program finds how many pairs of numbers
 *		have a difference of 'k' in a given set
 *		of distinct integers.
 *	It uses 'k' lists that are accessed by performing
 *		n mod k for each n in the set. Once in the list
 *		it compares n / k to the others to see
 *		if any pair can be made.
 *
 *	Visualization:
 *		Say we have set {1, 3, 4, 5, 8, 9, 10, 11, 13, 16}
 *		and want the numbers that are 3 apart...
 *
 *	1 3 4 5 8 9 10 11 13 16 ---
 *							  |
 *				.-sort by n%3--
 *				v
 *  3 9  ///  1 4 10 13 16  ///  5 8 11  ----
 *											|
 *				.------ divide by 3 ---------
 *				v
 *  1 3  ///  0 1 3  4  5   ///  1 2 3
 *  no pair  ///  pairs (0,1), (3,4), (4,5)
 *                      /// pairs (1,2), (2,3)
 *  RESULT: 5 total pairs
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct _list {
	int val;
	struct _list *next;
} list;

int pairs (void) {
	/* set size, difference, number of pairs found, current set element */
    int n, k, pairs, cur;
	int mod, div;						/* Manipulations of element */
	list **head;						/* array of lists */
	list *iter;							/* current list iterator */
	
	int *in;
	
	/* Get set size & difference from stdin */
	scanf("%d %d", &n, &k);
	head = malloc(sizeof(list *)*k);	/* make k lists */
	pairs = 0;							/* counter starts at 0 */
	
	in = malloc(sizeof(int) * n);
	
	for (int i=0; i<n; i++) {
		/* Get element from stdin */
		scanf("%d", &(in[i]));
	}
	
	for (int i=0; i<n; i++) {
		cur = in[i];
		mod = cur % k;
		div = cur / k;
		
		/* Search list for a place to put it */
		iter = head[mod];
		
		/* First element of that multiple */
		if (iter == NULL) {
			iter = malloc(sizeof(list));
			iter->val = div;
			iter->next = NULL;
			head[mod] = iter;
		}
		else {						/* not first */
			list *temp = malloc(sizeof(list));
			temp->val = div;
			
			if (iter->val > div) {
				/* Insert at front of list */
				temp->next = iter;
				head[mod] = temp;
			}
			else {
				/* Insert in middle/end of list */
				while (iter->next && (iter->next->val < div)) {
					iter = iter->next;
				}
				/* iter is node before insertion point */
				temp->next = iter->next;
				iter->next = temp;
			}
			/* Insertion done, check for pair */
			if ((div - iter->val) == 1) {
				pairs++;
			}
			if (temp->next && (temp->next->val - div) == 1) {
				pairs++;
			}
		}
	}
	
	printf("%d\n", pairs);
    return 0;
}