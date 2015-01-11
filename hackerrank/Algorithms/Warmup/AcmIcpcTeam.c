//
//  AcmIcpcTeam.c
//  hackerrank
//
//  Created by Kyle Donnelly on 1/7/15.
//  Copyright (c) 2015 kyle. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int AcmIcpcTeam (void) {
    int numParticipants, numTopics;
    
    scanf("%d %d", &numParticipants, &numTopics);
    
    char **topicKnowledge = malloc(sizeof(char *) * numParticipants);
    int maxSharedTopics = 0;
    int numTeamsAtMax = 0;
    
    for (int i = 0; i < numParticipants; i++) {
        char *topicKnowledgeDescription = malloc(sizeof(char) * (numTopics+1));
        scanf("%s", topicKnowledgeDescription);
        topicKnowledge[i] = topicKnowledgeDescription;
        
        for (int j = 0; j < i; j++) {
            int sharedTopics = 0;
            for (int k = 0; k < numTopics; k++) {
                if (topicKnowledge[j][k] == '1' || topicKnowledgeDescription[k] == '1') {
                    sharedTopics++;
                }
            }
            
            if (sharedTopics > maxSharedTopics) {
                maxSharedTopics = sharedTopics;
                numTeamsAtMax = 1;
            } else if (sharedTopics == maxSharedTopics) {
                numTeamsAtMax++;
            }
        }
    }
    
    printf("%d\n%d\n", maxSharedTopics, numTeamsAtMax);
    
    return 0;
}
