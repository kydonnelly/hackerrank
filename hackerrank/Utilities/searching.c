//
//  searching.c
//  hackerrank
//
//  Created by Kyle Donnelly on 1/4/15.
//  Copyright (c) 2015 kyle. All rights reserved.
//

#include <math.h>

#include "searching.h"

int binarySearchIndex (ull target, ull *array, int length) {
    int left = 0;
    int right = length - 1;
    int result = BINARY_SEARCH_NOT_FOUND;
    
    while (left <= right) {
        int middle = (left + right) / 2;
        ull midValue = array[middle];
        if (midValue < target) {
            left = middle + 1;
        } else if (midValue > target) {
            right = middle - 1;
        } else {
            result = middle;
            break;
        }
    }
    
    return result;
}

int binarySearchIndexBelow (ull target, ull *array, int length) {
    int left = -1;
    int right = length - 1;
    
    while (left < right) {
        int middle = ceil((left + right) / 2.0);
        ull midValue = array[middle];
        if (midValue < target) {
            left = middle;
        } else {
            right = middle - 1;
        }
    }
    
    return left;
}

int binarySearchIndexAbove (ull target, ull *array, int length) {
    int left = 0;
    int right = length;
    
    while (left < right) {
        int middle = (left + right) / 2;
        ull midValue = array[middle];
        if (midValue > target) {
            right = middle;
        } else {
            left = middle + 1;
        }
    }
    
    return left;
}
