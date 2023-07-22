#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "preprocessing_methods.h"

int number_of_rows(FILE *fp);
int number_of_columns(FILE *fp, char *delim);
void array_from_column(double *A, int col, FILE *fp, char *delim);

int main(int argc, char *argv[]){

    //Read the file
    FILE *fp;
    fp = fopen("linear_regression.csv", "r");
    if (!fp){
        printf("Cannot open file!");
        exit(0);
    }
    char *delim = ",";

    //Get length of dataframe
    int df_length = number_of_rows(fp);

    rewind(fp);
    //Malloc arrays for the columns
    double *X;
    X = malloc(sizeof(double) * df_length);
    if (!X){
        printf("Memory allocation error!");
        exit(0);
    }
    
    double *Y;
    Y = malloc(sizeof(double) * df_length);
    if (!Y){
        printf("Memory allocation error!");
        exit(0);
    }

    //Fill the arrays
    array_from_column(X, 0, fp, delim);
    array_from_column(Y, 1, fp, delim);

    //Do stuff with the arrays
    printf("Mean value of array Y: %f\n", arithmetic_mean(Y, df_length));
    printf("Variance of array Y: %f\n", variance(Y, df_length));
    printf("Std of array Y: %f\n", standard_deviation(Y, df_length));

    //Test [0, 1] normalization
    normalization(Y, df_length, 0.0, 1.0);
    // for (int i=0;i<df_length;i++){
    //     printf("%f\n", X[i]);
    // }
    printf("Mean value of normalized array Y: %f\n", arithmetic_mean(Y, df_length));
    printf("Variance of normalized array Y: %f\n", variance(Y, df_length));

    //Free the arrays and close the file pointer gg
    free(X);
    free(Y);
    fclose(fp);

    return 0;
}


int number_of_rows(FILE *fp){
    rewind(fp);
    int rows = 0;
    char buffer[128];
    while (fgets(buffer, 128, fp) != NULL){
        rows++;
    }
    return rows - 1; //Do not count header
}


int number_of_columns(FILE *fp, char *delim){
	rewind(fp);
	int cols = 0;
	char buffer[128];
	fgets(buffer, 128, fp);
	char *tokens = strtok(buffer, delim);
	while (tokens != NULL){
		cols++;
		tokens = strtok(NULL, delim);
	}
	return cols;
}

void array_from_column(double *A, int col, FILE *fp, char *delim){
    rewind(fp);
    char buffer[128];
    int cols = number_of_columns(fp, delim);
    int i = 0;
    while (fgets(buffer, 128, fp) != NULL){
        char *tokens = strtok(buffer, delim);
        char *eptr;
        int col_counter = 0;
        while (tokens != NULL){
            if (col_counter % cols == col){
              A[i] = strtod(tokens, &eptr);
              i ++;  
            }
            tokens = strtok(NULL, delim);
            col_counter ++;
        }
    }
}