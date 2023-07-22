#include <stdlib.h>
#include <stdio.h>
#include "statistical_quantities.h"


void normalization(double A[], int len, double m, double M);

// Normalization inside [m, M]
void normalization(double A[], int len, double m, double M){
    double min = array_min(A, len);
    double max = array_max(A, len);
    for (int i=0;i<len;i++){
        A[i] = (A[i] - min) * ((M - m) / (max - min)) + m;
    }
}