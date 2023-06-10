#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

//Samples from standard normal distribution using the Box-Muller transform.
//Write the samples to a csv file with two columns. Each row contains two
//independent gaussian random numbers.

int main(int argc, char *argv[]){

    double pi = 3.1415;
    //RNG
    srand(time(NULL));
    int N = atoi(argv[1]); //Number of points
    FILE *fp;
    fp = fopen("random_normal.csv", "w");
    if (fp == NULL){
        printf("Error with file pointer!");
        exit(0);
    }
    fprintf(fp, "x,y\n");
    for (int i=0;i<N;i++){
        double u1 = (rand() % 1000) / (double)1000;
        double u2 = (rand() % 1000) / (double)1000;
        float z1 = sqrt(-2.0 * log(u1)) * cos(2.0 * pi * u2);
        float z2 = sqrt(-2.0 * log(u1)) * sin(2.0 * pi * u2);
        // printf("%f %f \n", z1, z2);
        fprintf(fp, "%f,%f\n", z1, z2);
    }


    fclose(fp);
    return 0;
}