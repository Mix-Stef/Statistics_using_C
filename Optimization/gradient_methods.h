#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define DIMENSIONS 2 //Number of variables
#define TOLERANCE 0.0001
#define STEP 0.03

double *gradient(double (*f)(double, double), double x, double y); //Grad of f
double norm(double *A, int len);
void gradient_descent(double (*f)(double, double), double *x_init);

void gradient_descent(double (*objective)(double, double), double *x_init){

    double *grad;
    if (!grad){
        printf("Memory error!");
        exit(0);
    }
    grad =  gradient(objective, x_init[0], x_init[1]);
    double grad_norm = norm(grad, DIMENSIONS);
    while (grad_norm > TOLERANCE){
        x_init[0] -= STEP * grad[0];
        x_init[1] -= STEP * grad[1];
        grad_norm = norm(gradient(objective, x_init[0], x_init[1]), DIMENSIONS);
        printf("x0: %f x1: %f\n", x_init[0], x_init[1]);
    }
}

double *gradient(double (*f)(double, double), double x, double y){
    double h = 0.0001;
    static double grads[DIMENSIONS]; //Need static for some reason
    double fx = (f(x + h, y) - f(x, y)) / h;
    double fy = (f(x, y + h) - f(x, y)) / h;
    grads[0] = fx;
    grads[1] = fy;
    return grads;
}

double norm(double *A, int len){
    double result = 0;
    for (int i=0;i<len;i++){
        result += pow(A[i], 2);
    }
    return sqrt(result);
}
