//
//  cipher.c
//  hackerrank
//
//  Created by Kyle Donnelly on 1/19/15.
//  Copyright (c) 2015 kyle. All rights reserved.
//
//  We need to find the original message from only the final message
//    and the number of offset-xors.
//  The first bit is always the same in the original and encoded messages.
//  Since we know the first bit we can find the second bit by xor-ing
//    the encoded second bit with the unencoded first bit
//    (or in the trivial case k = 1, it's just the same as the encoded second bit).
//  And so on.
//
//  Formally,
//  given an encoded message 'e' based on unencoded messaged 'm' of length 'n'
//     using cipher-shift 'k'
//  for a bit at index i where 0 ≤ i < n
//    m[i] = e[i] xor (m[i - j] for all j in [1, max(i, k-1)])
//
//  Since the inner xor loop is going over mostly the same values each time
//    I'll use a trailing iterator to avoid having to recalculate.
//

#include <stdio.h>
#include <stdlib.h>

#include "primitivetypes.h"

#define INT_TO_CHAR(i) (i + '0')
#define CHAR_TO_INT(c) (c - '0')

int cipher (void) {
    int originalMessageLength;
    int cipherShift;
    scanf("%d %d", &originalMessageLength, &cipherShift);
    
    char *originalMessage = malloc(sizeof(char) * (originalMessageLength + 1));
    char *encodedMessage = malloc(sizeof(char) * (originalMessageLength + cipherShift + 2));
    scanf("%s", encodedMessage);
    
    uint trailingMessageXor = 0;
    int trailingIter = 0;
    for (int i = 0; i < originalMessageLength; i++) {
        originalMessage[i] = INT_TO_CHAR(CHAR_TO_INT(encodedMessage[i]) ^ trailingMessageXor);
        trailingMessageXor = CHAR_TO_INT(originalMessage[i]) ^ trailingMessageXor;
        
        if (i - trailingIter >= cipherShift - 1) {
            trailingMessageXor = CHAR_TO_INT(originalMessage[trailingIter]) ^ trailingMessageXor;
            trailingIter++;
        }
    }
    
    originalMessage[originalMessageLength] = '\0';
    printf("%s\n", originalMessage);
    
    free(originalMessage);
    free(encodedMessage);
    
    return 0;
}
