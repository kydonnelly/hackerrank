//
//  searching.h
//  hackerrank
//
//  Created by Kyle Donnelly on 1/4/15.
//  Copyright (c) 2015 kyle. All rights reserved.
//

#ifndef hackerrank_searching_h
#define hackerrank_searching_h

#import "primitivetypes.h"

#define BINARY_SEARCH_NOT_FOUND -1

int binarySearchIndex(ull target, ull *array, int length);

int binarySearchIndexBelow(ull target, ull *array, int length);
int binarySearchIndexAbove(ull target, ull *array, int length);

#endif
