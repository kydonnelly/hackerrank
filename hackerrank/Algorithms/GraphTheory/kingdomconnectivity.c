/*
 *  KingdomConnectivity.c
 *  InterviewStreet
 *
 *  Created by Kyle Donnelly on 12/16/12.
 *
 *  Recursively finds the number of paths across a directed graph.
 *
 *	Inputs:
 *		Number of cities and roads.
 *		Two integers: city where the road starts and city where it ends (index 1).
 *
 *	Outputs:
 *		Number of paths from city 1 to city N (modulo MOD_LIMIT).
 *
 *	Base case:
 *		Current city is the destination, return 1.
 *
 *	Recursive case:
 *		Current city is not destination
 *		add up the number of paths of each city this one has access to.
 *
 *	This program forces you to stop once you reach the destination.
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

#define MOD_LIMIT 1000000000

typedef struct {
	unsigned int id;
	struct _list *children;
	unsigned int distance;
} graph;

typedef struct _list {
	struct _list *next;
	graph *g;
} list;

static int *visited;
static graph **cities;
static jmp_buf buf;

/* push a graph into a list of graphs */
void push_graph (list **head, graph *g) {
	list *cur;
	if (*head == NULL) {
		cur = *head = malloc(sizeof(list));
	}
	else {
		for (cur = *head; cur->next != NULL; cur = cur->next);
		cur = cur->next = malloc(sizeof(list));
	}
	
	cur->g = g;
	cur->next = NULL;
}

unsigned int find_paths (graph *source, graph *destination) {
	unsigned int retval = 0;
	list *cur;
	
	if (source == destination) {
		/* Awesome, we made it */
		return 1;
	}
	
	if (visited[source->id - 1] == 1) {
		/*
		 * Loop in graph!
		 * Not sure if this city actually leads to destination though.
		 * If not then we don't care.
		 * Alert earlier paths.
		 */
		visited[source->id - 1] = 2;
		return 0;
	}
	
	if (source->distance != -1) {
		/* Already know how many from here */
		return source->distance;
	}
	
	/* Mark that we've gone through this city already */
	visited[source->id - 1] = 1;
	
	for (cur = source->children; cur != NULL; cur = cur->next) {
		/* Check how many paths there are for each child city */
		retval = (retval + find_paths(cur->g, destination)) % (MOD_LIMIT);
	}
	
	/* Store for future paths through this city */
	source->distance = retval;
	
	/* Mark that we're done with this city */
	if (visited[source->id - 1] == 2) {
		/* One of the paths led back here! */
		if (retval > 0) {
			/* There is a loop on the way to the destination! */
			longjmp(buf, 1);
		}
		
		/* But this city didn't lead to the destination anyway */
	}
	visited[source->id - 1] = 0;
	
	return (retval);
}

int kingdomconnectivity (void) {
	unsigned int n, m, to, from;
	unsigned int num_paths;
	
	scanf("%u %u", &n, &m);
	
	cities = malloc(sizeof(graph *) * n);
	visited = malloc(sizeof(unsigned int) * n);
	
	for (unsigned int i=0; i<n; i++) {
		cities[i] = malloc(sizeof(graph));
		cities[i]->id = i+1;
		cities[i]->children = NULL;
		cities[i]->distance = -1;
		visited[i] = 0;
	}
	
	for (unsigned int i=0; i<m; i++) {
		scanf("%u %u", &from, &to);
		
		/* Add node to parent's children */
		push_graph(&(cities[from-1]->children), cities[to-1]);
	}
	
	if (!(setjmp(buf))) {
		num_paths = find_paths(cities[0], cities[n-1]);
		printf("%u\n", num_paths);
	}
	else {
		printf("INFINITE PATHS\n");
	}
	
	return 0;
}