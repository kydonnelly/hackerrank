//
//  main.c
//  hackerrank
//
//  Created by Kyle Donnelly on 12/2/14.
//  Copyright (c) 2014 kyle. All rights reserved.
//
//  Prompt:
//
//  Roy lives in a city that is circular in shape on a 2D plane. The city center is located at origin (0,0) and it has suburbs lying on the lattice points (points with integer coordinates). The city Police Department Headquarters can only protect those suburbs which are located strictly inside the city. The suburbs located on the border of the city are still unprotected. So the police department decides to build at most k additional police stations at some suburbs. Each of these police stations can protect the suburb it is located in.
//
//  Given the radius of the city, Roy has to determine if it is possible to protect all the suburbs.
//
//  Constraints:
//
//  1 ≤ t ≤ 10^3
//  1 ≤ r ≤ 2e9
//  0 ≤ k ≤ 2e9
//
//  Solution:
//
//  The first thing to notice is that if a city lies on the circumference in one quadrant of the circle,
//    it also will lie on the circumference if rotated 90. So the search space is reduced to 1 out of 4 quadrants.
//  Using some basic trigonometry alongside the problem description we see that
//    an x and y such that x^2 + y^2 = r^2 provides the coordinates of a suburb.
//  Note 1: for each (x, y) pair a suburb lies at (x, y) and (y, x).
//  Note 2: we should only count (0, r) once because (r, 0) is in a different quadrant.
//
//  This is sufficient to reduce the problem to finding the number of distinct numbers n
//    where 0 < n ≤ r and sqrt(r^2 - n^2) is an integer.
//

#include <stdio.h>
#include <math.h>

int circlecity (void) {
    int testCases = 0;
    int radiusSquared = 0;
    int policeStations = 0;
    int distinctFactors = 0;
    int factor = 0;
    
    scanf("%d", &testCases);
    
    while (testCases--) {
        scanf("%d %d", &radiusSquared, &policeStations);
        distinctFactors = 0;
        factor = 0;
        for (int factorSquared = 0; factorSquared < radiusSquared; factorSquared = factor * factor) {
            int otherFactorSquared = radiusSquared - factorSquared;
            int otherFactor = sqrt(otherFactorSquared);
            if (otherFactor * otherFactor == otherFactorSquared) {
                distinctFactors++;
            }
            
            factor++;
        }
        
        if (policeStations < distinctFactors * 4) {
            printf("impossible\n");
        } else {
            printf("possible\n");
        }
    }
    
    return 0;
}