//
//  sorting.c
//  hackerrank
//
//  Created by Kyle Donnelly on 1/3/15.
//  Copyright (c) 2015 kyle. All rights reserved.
//

void quicksort_index_recursive (int *array, int *idx, int begin, int end, int isAscending) {
	if (end > begin + 1) {
		int pivot = array[idx[(end+begin)/2]];
        int left = begin;
        int right = end - 1;
        
		while (left <= right) {
			if (isAscending ? array[idx[left]] < pivot
                            : array[idx[left]] > pivot) {
				left++;
            } else if (isAscending ? array[idx[right]] > pivot
                                   : array[idx[right]] < pivot) {
				right--;
			} else {
				int t = idx[left];
				idx[left++] = idx[right];
				idx[right--] = t;
			}
		}
        
		quicksort_index_recursive(array, idx, begin, right+1, isAscending);
		quicksort_index_recursive(array, idx, left, end, isAscending);
	}
}

//  idx must be array containing values 0, 1, ... |array|.
//
//  Permutes idx so that its values correspond to a sorted order of the array
//   but the array is not actually changed.
void quicksort_index_descending (int *array, int *idx, int length) {
    quicksort_index_recursive(array, idx, 0, length, 0);
}

void quicksort_index_ascending(int *array, int *idx, int length) {
    quicksort_index_recursive(array, idx, 0, length, 1);
}

void quicksort_recursive (int *array, int begin, int end, int isAscending) {
    if (end > begin + 1) {
        int midPoint = (end + begin) / 2;
		int pivot = array[midPoint];
        int left = begin;
        int right = end - 1;
        
		while (left <= right) {
			if (isAscending ? array[left] < pivot
                            : array[left] > pivot) {
				left++;
            } else if (isAscending ? array[right] > pivot
                                   : array[right] < pivot) {
				right--;
			} else {
				int t = array[left];
				array[left++] = array[right];
				array[right--] = t;
			}
		}
        
		quicksort_recursive(array, begin, right+1, isAscending);
		quicksort_recursive(array, left, end, isAscending);
	}
}

void quicksort_ascending (int *array, int length) {
    quicksort_recursive(array, 0, length, 1);
}

void quicksort_descending (int *array, int length) {
    quicksort_recursive(array, 0, length, 0);
}