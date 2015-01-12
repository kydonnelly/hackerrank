/*
 * Kyle Donnelly
 * MeetingPoint.c
 * InterviewStreet
 * 16 April 2012
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef long long int ll;

#define ABS(a) (a > 0 ? a : -(a))
#define MAX_VALUE(a, b) (a > b ? a : b)

int meetingPoint (void) {
    int numHouses;
	scanf("%d", &numHouses);
	
	ll *x = malloc(sizeof(ll) * numHouses);
	ll *y = malloc(sizeof(ll) * numHouses);
	
	for (int i = 0; i < numHouses; i++) {
		scanf("%lld %lld", x + i, y + i);
	}
    
    long double avgX = 0;
    long double avgY = 0;
	for (int i = 0; i < numHouses; i++) {
		avgX += (long double)x[i] / numHouses;
		avgY += (long double)y[i] / numHouses;
	}
    
	long double minDistance = avgX * avgX + avgY * avgY;
    int minIndex = -1;
	
	for (int i = 0; i < numHouses; i++) {
        double xDiff = avgX - x[i];
        double yDiff = avgY - y[i];
		long double distance = sqrt(xDiff * xDiff + yDiff * yDiff);
        
		if (distance < minDistance) {
			minDistance = distance;
			minIndex = i;
		}
	}
	
    ll distanceSum = 0;
    ll minX = x[minIndex];
    ll minY = y[minIndex];
    
	for (int i = 0; i < numHouses; i++) {
        ll dx = ABS(minX - x[i]);
        ll dy = ABS(minY - y[i]);
		distanceSum += MAX_VALUE(dx, dy);
	}
    
	printf("%lld\n", distanceSum);
    
    free(x);
    free(y);
	
	return 0;
}