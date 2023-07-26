#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

//Samples from standard normal distribution using the Box-Muller transform.
//Write the samples to a csv file with two columns. Each row contains two
//independent gaussian random numbers. Using the Box-Muller transform we can
//generate a synthetic dataset for linear regression tests of the form 
//(x, y) = (x, a * x + b + Gaussian_Noise(mu, var))

int main(int argc, char *argv[]){


    double pi = 3.1415;
    srand(time(NULL)); //RNG
    unsigned int N = atoi(argv[1]); //Number of points
    double mu = atof(argv[2]); //The mean of the gaussian
    double sigma = atof(argv[3]); //The standard deviation

    //Generate pair of independent gaussian random variables
    
    // FILE *fp;
    // fp = fopen("random_normal_new.csv", "w");
    // if (fp == NULL){
    //     printf("Error with file pointer!");
    //     exit(0);
    // }
    // fprintf(fp, "x,y\n");
    // for (int i=0;i<N;i++){
    //     double u1 = (rand() % 1000) / (double)1000;
    //     double u2 = (rand() % 1000) / (double)1000;
    //     double z1 = sigma * sqrt(-2.0 * log(u1)) * cos(2.0 * pi * u2) + mu;
    //     double z2 = sigma * sqrt(-2.0 * log(u1)) * sin(2.0 * pi * u2) + mu;
    //     printf("%f %f \n", z1, z2);
    //     if (isinf(z1) == 0 && isinf(z2) == 0){
    //         fprintf(fp, "%f,%f\n", z1, z2);
    //     }
    // }
    // fclose(fp);


    //Generate dataset for linear regression y = a * x + b + gaussian_error(mu=0, sigma=2)
    double step = 0.01;
    FILE *fp;
    fp = fopen("linear_regression.csv", "w");
    if (fp == NULL){
        printf("Error with file pointer!");
        exit(0);
    }
    fprintf(fp, "x,y\n");
    for (int i=0;i<N;i++){
        double x_value = 0 + i * step;
        double u1 = (rand() % 1000) / (double)1000;
        double u2 = (rand() % 1000) / (double)1000;
        double z1 = sigma * sqrt(-2.0 * log(u1)) * cos(2.0 * pi * u2) + mu;
        double y_value = 2 * x_value + 3 + z1;
        // printf("%f %f \n", z1, z2);
        if (isinf(z1) == 0){
            fprintf(fp, "%f,%f\n", x_value, y_value);
        }
    }
    fclose(fp);


    return 0;
}
