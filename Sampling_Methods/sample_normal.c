#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

//Samples from standard normal distribution using the Box-Muller transform.
//Write the samples to a csv file with two columns. Each row contains two
//independent gaussian random numbers.

int main(int argc, char *argv[]){

    double pi = 3.1415;
    srand(time(NULL)); //RNG
    int N = atoi(argv[1]); //Number of points
    FILE *fp;
    fp = fopen("random_normal.csv", "w");
    if (fp == NULL){
        printf("Error with file pointer!");
        exit(0);
    }
    fprintf(fp, "x,y\n");
    for (int i=0;i<N;i++){
        double u1 = (rand() % 1000) / (double)1000; //Random uniform in (0,1)
        double u2 = (rand() % 1000) / (double)1000; //Random uniform in (0,1)
        double z1 = sqrt(-2.0 * log(u1)) * cos(2.0 * pi * u2); //Box-Muller Transform
        double z2 = sqrt(-2.0 * log(u1)) * sin(2.0 * pi * u2); //Box-Muller Transform
        // printf("%f %f \n", z1, z2);
        if (isinf(z1) == 0 && isinf(z2) == 0){ //May produce infinities due to numerical instability so we discard them
            fprintf(fp, "%f,%f\n", z1, z2);
        }
    }
    fclose(fp);
    return 0;
}
