/*
 *  encryption.c
 *  InterviewStreet
 *
 *  Created by Kyle Donnelly on 2/16/14.
 *
 */

#define MAX_LEN (81 + 1)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main (void) {
	char *message = malloc(sizeof(char) * MAX_LEN);
	scanf("%s", message);
    
	int messageLength = (int)strlen(message);
	double root = sqrt(messageLength);
	int width = root;
	int height = ceil(root);
	
	if (width * height < messageLength) {
		width++;
	}
	
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
            int messageIndex = height * j + i;
			if (messageIndex < messageLength) {
				printf("%c", message[messageIndex]);
			}
		}
		printf(" ");
	}
	
	free(message);
	
	return 0;
}