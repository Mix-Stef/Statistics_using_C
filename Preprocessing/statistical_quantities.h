#include <stdlib.h>
#include <stdio.h>
#include <math.h>


//Given an array of numbers compute various statistical quantities
double arithmetic_mean(double A[], int len);
double geometric_mean(double A[], int len);
double hypergeometric_mean(double A[], int len);
double variance(double A[], int len);
double standard_deviation(double A[], int len);
double array_max(double A[], int len);
double array_min(double A[], int len);

double arithmetic_mean(double A[], int len){

	double mean = 0;
	for (int i=0;i<len;i++){
		mean = mean + A[i];
	}
	mean = mean / len;
	return mean;
}

double geometric_mean(double A[], int len){
	
	double mean = 1;
	for (int i=0;i<len;i++){
		mean = mean * A[i];
	}
	mean = pow(mean, 1. / len);
	return mean;
}


double hypergeometric_mean(double A[], int len){

	double mean = 0;
	for (int i=0;i<len;i++){
		mean = mean + 1. / A[i];
	}
	mean = len / mean;
	return mean;
}

double variance(double A[], int len){
	double var = 0.0;
	double mean = arithmetic_mean(A, len);
	for (int i=0;i<len;i++){
		var = var + pow(A[i] - mean, 2);
	}
	var = var / len;

	return var;
}

double standard_deviation(double A[], int len){
	double var = variance(A, len);
	double std_dev = sqrt(var);
	return std_dev;
}

double array_max(double A[], int len){
	double max = -INFINITY;
	for (int i=0;i<len;i++){
		if (A[i] > max){
			max = A[i];
		}
	}
	return max;
}

double array_min(double A[], int len){
	double min = INFINITY;
	for (int i=0;i<len;i++){
		if (A[i] < min){
			min = A[i];
		}
	}
	return min;
}


	









