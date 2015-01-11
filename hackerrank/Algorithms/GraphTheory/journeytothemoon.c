/*
 *  journeytothemoon.c
 *  InterviewStreet
 *
 *  Created by Kyle Donnelly on 2/16/14.
 *
 */

#define MIN(a,b) (a < b ? a : b)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long int llint;

typedef struct _list {
	llint val;
	struct _list *next;
} list;

int journeytothemoon (void) {
	llint numAstronauts, numPairs;
	llint astronaut1, astronaut2;
	llint *astronautCountryIds;
	llint *bossCounts;
	llint bossId1, bossId2;
	llint countryId;
	llint combos = 0;
	
	list *bossList = malloc(sizeof(list));
	bossList->val = 0;
	bossList->next = NULL;
	
	scanf("%lld %lld", &numAstronauts, &numPairs);
	astronautCountryIds = malloc(sizeof(llint) * numAstronauts);
	bossCounts = malloc(sizeof(llint) * numAstronauts);
	
	for (llint i=0; i<numAstronauts; i++) {
		astronautCountryIds[i] = i;
		bossCounts[i] = 0;
	}
	
	for (llint i=0; i<numPairs; i++) {
		scanf("%lld %lld", &astronaut1, &astronaut2);
		
		// get boss of astronaut1
		bossId1 = astronaut1;
		while (astronautCountryIds[bossId1] != bossId1) {
			bossId1 = astronautCountryIds[bossId1];
		}
		
		bossId2 = astronaut2;
		while (astronautCountryIds[bossId2] != bossId2) {
			bossId2 = astronautCountryIds[bossId2];
		}
		
		countryId = MIN(bossId1, bossId2);
		
		astronautCountryIds[bossId1] = countryId;
		astronautCountryIds[bossId2] = countryId;
		astronautCountryIds[astronaut1] = countryId;
		astronautCountryIds[astronaut2] = countryId;
	}
	
	for (llint i=0; i<numAstronauts; i++) {
		bossId1 = i;
		// get country id for this astronaut (boss)
		while (astronautCountryIds[bossId1] != bossId1) {
			bossId1 = astronautCountryIds[bossId1];
		}
		bossCounts[bossId1]++;
		
		if (bossCounts[bossId1] == 1 && bossId1 > 0) {
			// first time realizing this is a boss
			list *oldHead = bossList;
			bossList = malloc(sizeof(list));
			bossList->val = bossId1;
			bossList->next = oldHead;
		}
	}
	
	for (list *iter = bossList; iter != NULL; iter = iter->next) {
		numAstronauts -= bossCounts[iter->val];
		combos += numAstronauts * bossCounts[iter->val];
	}
	
	free(astronautCountryIds);
	free(bossCounts);
	
	printf("%lld\n", combos);
	
	return 0;
}