/*
 *  StockMax.c
 *  InterviewStreet
 *
 *  Created by Kyle Donnelly on 3/5/13.
 *
 *	Pretty straightforward solution:
 *		Basically, you want to own as many shares as possible on the day
 *			that stock is worth the most
 *			Because any price you could have bought it for previously
 *			is less than it is now.
 *		After that day when it's worth the most, just repeat the process.
 *
 *	We keep an array of prices
 *		and an array of indexes associated with the sorted price array
 *	Step through those indexes in descending order
 *		Buy every day since the last peak in price
 *		simple formula: (this peak index - last peak index) * price of this peak
 *		then subtract the amount of money it would have cost to buy at all the earlier prices.
 *
 *	Space complexity:
 *		We need two arrays of length 'n' --> O(n)
 *
 *	Running time complexity:
 *		Sorting array of length 'n' with quicksort --> O(n*logn)
 *		Look through each
 */

#include <stdio.h>
#include <stdlib.h>

#include "primitivetypes.h"
#include "sorting.h"

int stockmaximize (void) {
	int numTestCases;
	
	scanf("%d", &numTestCases);
    
    while (numTestCases--) {
        int numDays;
        scanf("%d", &numDays);
        
        int *prices = malloc(sizeof(int) * numDays);
        int *sortedPriceIndexes = malloc(sizeof(int) * numDays);
        uint bestPrice = 0;
        int lastIndex = 0;
        
        for (int i = 0; i < numDays; i++) {
            scanf("%d", prices + i);
            sortedPriceIndexes[i] = i;
        }
        
        quicksort_index(prices, sortedPriceIndexes, numDays);
        
        for (int i = 0; i < numDays && lastIndex < numDays; i++) {
            if (sortedPriceIndexes[i] >= lastIndex) {
                bestPrice += prices[sortedPriceIndexes[i]] * (sortedPriceIndexes[i] - lastIndex);
                for (int j = lastIndex; j < sortedPriceIndexes[i]; j++) {
                    bestPrice -= prices[j];
                }
                lastIndex = sortedPriceIndexes[i] + 1;
            }
        }
        
        printf("%u\n", bestPrice);
        free(prices);
        free(sortedPriceIndexes);
    }
	
	return 0;
}