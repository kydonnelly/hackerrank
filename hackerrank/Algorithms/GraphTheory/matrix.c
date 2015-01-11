/*
 *  Matrix.c
 *  InterviewStreet
 *
 *  Created by Kyle Donnelly on 5/29/13.
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "primitivetypes.h"

typedef enum { FALSE, TRUE } bool;

typedef struct {
	uint city1, city2, cost;
} road;

typedef struct {
	uint city_id, boss_id;
	bool has_machine;
} city;

static void quick_sort (road **a, uint n) {
    if (n < 2)
        return;
    road *p = a[n / 2], **l = a, **r = a + n - 1;
    while (l <= r) {
        if ((*l)->cost > p->cost) {
            l++;
        }
        else if ((*r)->cost < p->cost) {
            r--;
        }
		else {
			road *t = *l;
			*l++ = *r;
			*r-- = t;
		}
    }
    quick_sort(a, (uint)(r - a) + 1);
    quick_sort(l, (uint)(a + n - l));
}

city *find_boss (uint i, city **cities) {
	if (cities[i]->boss_id == i) {
		return cities[i];
	}
	else {
		return find_boss(cities[i]->boss_id, cities);
	}
}

int matrix (void) {
	uint num_cities, num_machines, machine_location, final=0;
	road **roads;
	city **cities;
	
	scanf("%u %u", &num_cities, &num_machines);
	roads = malloc(sizeof(road *) * (num_cities-1));
	cities = malloc(sizeof(city *) * num_cities);
	
	/* Initialize each city as its own entity */
	for (int i=0; i<num_cities; i++) {
		cities[i] = malloc(sizeof(city));
		cities[i]->city_id = i;
		cities[i]->boss_id = i;
		cities[i]->has_machine = 0;
	}
	
	/* Create roads and read in info */
	for (int i=0; i<num_cities-1; i++) {
		roads[i] = malloc(sizeof(road));
		scanf("%u %u %u", &roads[i]->city1, &roads[i]->city2, &roads[i]->cost);
	}
	
	/* Mark cities with machines */
	for (int i=0; i<num_machines; i++) {
		scanf("%u", &machine_location);
		cities[machine_location]->has_machine = TRUE;
	}
	
	quick_sort(roads, num_cities-1);
	
	for (int i=0; i<num_cities-1; i++) {
		if (find_boss(roads[i]->city1, cities)->has_machine && find_boss(roads[i]->city2, cities)->has_machine) {
			/* Can't use this road */
			final += roads[i]->cost;
		}
		else {
			if (find_boss(roads[i]->city1, cities)->has_machine) {
				find_boss(roads[i]->city2, cities)->boss_id = find_boss(roads[i]->city1, cities)->boss_id;
			}
			else {
				find_boss(roads[i]->city1, cities)->boss_id = find_boss(roads[i]->city2, cities)->boss_id;
			}
		}
	}
	
	printf("%u\n", final);
	
	return 0;
}