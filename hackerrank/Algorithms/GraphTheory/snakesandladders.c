/*
 *  snakesandladders.c
 *  InterviewStreet
 *
 *  Created by Kyle Donnelly on 2/16/14.
 *  Pretty much a basic BFS to the 100th square.
 *  If final square is unreachable, it gives count to last point before unreachability.
 *
 */

#define MAX(a, b) (a > b ? a : b)
#define SPACES_ON_BOARD 100
#define MAX_DIE_ROLE 6

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _list {
	int val;
	struct _list *next;
} list;

int snakesandladders (void) {
	int cases;
	int numSnakes, numLadders;
	int *squares;
	int *visitedSquares;
	int moves;
	int from, to;
	
	list *openList;
	list *nextList, *nextPtr;
	
	// marks where we climb/fall to when landing on indexed square
	squares = malloc(sizeof(int) * (SPACES_ON_BOARD+1));
	visitedSquares = malloc(sizeof(int) * (SPACES_ON_BOARD+1));
	
	scanf("%d", &cases);
	
	while (cases--) {
		moves = 0;
		for (int i = 0; i <= SPACES_ON_BOARD; i++) {
			// reset data
			squares[i] = i;
			visitedSquares[i] = 0;
		}
		
		scanf("%d,%d", &numLadders, &numSnakes);
		
		for (int i=0; i<numLadders + numSnakes; i++) {
			scanf("%d,%d", &from, &to);
			squares[from] = to;
		}
		
		nextList = malloc(sizeof(list));
		nextList->val = 0;
		nextList->next = NULL;
		visitedSquares[0] = 1;
		
		// while we haven't found the ending square
		while (visitedSquares[SPACES_ON_BOARD] == 0 && nextList) {
			moves++;
			openList = nextList;
			nextList = NULL;
			for (list *iter = openList; iter != NULL; iter = nextPtr) {
				int startIndex = iter->val;
				for (int i=startIndex+1; i <= startIndex + MAX_DIE_ROLE; i++) {
					if (visitedSquares[squares[i]] == 0) {
						// move to this square
						visitedSquares[squares[i]] = 1;
						nextPtr = nextList;
						nextList = malloc(sizeof(list));
						nextList->val = squares[i];
						nextList->next = nextPtr;
					}
				}
				
				nextPtr = iter->next;
				free(iter);
			}
		}
		
		for (list *iter = nextList; iter != NULL; iter = nextPtr) {
			nextPtr = iter->next;
			free(iter);
		}
		
		printf("%d\n", moves);
	}
	
	free(squares);
	
	return 0;
}