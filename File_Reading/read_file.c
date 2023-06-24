#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

double column_sum(int col, FILE *fp, char *delim);
double column_mean(int col, FILE *fp, char *delim);
double column_variance(int col, FILE *fp, char *delim);
int number_of_columns(FILE *fp, char *delim);
double column_max(int col, FILE *fp, char *delim);
double column_min(int col, FILE *fp, char *delim);

int main(){

	FILE *fp;
	fp = fopen("random_normal.csv", "r");
	if (fp == NULL){
		printf("Cannot open file.\n");
		exit(0);
	}
	char *delim = ",";
	int c = number_of_columns(fp, delim);
	double s = column_sum(0, fp, delim);
	double m = column_mean(0, fp, delim);
	double v = column_variance(0, fp, delim);
	double std = sqrt(v);
	double M = column_max(0, fp, delim);
	double min = column_min(0, fp, delim);
	printf("Number of columns: %d\n", c);
	printf("Sum of first column: %f\n", s);
	printf("Mean of first column: %f\n", m);
	printf("Variance of first column: %f\n", v);
	printf("Std of first column: %f \n", std);
	printf("Column max: %f \n", M);
	printf("Column minimum: %f \n", min);

	fclose(fp);
	return 0;
}

//	Get the sum of a row
//	while(fgets(buffer, 128, fp)){
//		if (count == line){ //Catch the desired line
//		char *tokens = strtok(buffer, delim); //Strtok splits the string 
//		while (tokens != NULL){
//			printf("%s\n", tokens);
//			//char *eptr;
//			//printf("%f\n", strtod(tokens, &eptr)); //Make the strings doubles 
//			tokens = strtok(NULL, delim);
//			}
//		}
//		count++;
//	}

//Function to get the number of columns (variables) of a .csv file
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


//Function to get the sum of a column
double column_sum(int col, FILE *fp, char *delim){
	rewind(fp); //Just for safety
	double sum = 0.0;
	int number_of_cols = number_of_columns(fp, delim);
	char buffer[128];
	while (fgets(buffer, 128, fp)){
		char *tokens = strtok(buffer, delim);
		char *eptr;
		int col_counter = 0;
		while (tokens != NULL){
			if (col_counter % number_of_cols == col){
				double x_value = strtod(tokens, &eptr);
				sum += x_value;
				break;
				}
			tokens = strtok(NULL, delim);
			col_counter++;
			}
		}
	return sum;
}


//Functions to get the mean value and the variance of a column of a .csv file
double column_mean(int col, FILE *fp, char *delim){
	rewind(fp); //Just for safety
	int count = 0;
	double mean = 0.0;
	int number_of_cols = number_of_columns(fp, delim);
	char buffer[128];
	while (fgets(buffer, 128, fp)){
		char *tokens = strtok(buffer, delim);
		char *eptr;
		int col_counter = 0;
		while (tokens != NULL){
			if (col_counter % number_of_cols == col){
				double x_value = strtod(tokens, &eptr);
				mean += x_value;
				count++;
				break;
				}
			tokens = strtok(NULL, delim);
			col_counter++;
			}
		}
	mean = mean / count;
	return mean;
}


double column_variance(int col, FILE *fp, char *delim){
	rewind(fp); //Go back to the start of the file in case something was done on it
	double mean = column_mean(col, fp, delim);
	int count = 0;
	int number_of_cols = number_of_columns(fp, delim);
	double var = 0.0;
	char buffer[128];
	rewind(fp); //Go back to the start of the file to re-read the data!
	while (fgets(buffer, 128, fp)){
		char *tokens = strtok(buffer, delim);
		char *eptr;
		int col_counter = 0;
		while (tokens != NULL){
			if (col_counter % number_of_cols == col){
				double x_value = strtod(tokens, &eptr);
				var = var + pow(x_value - mean, 2);
				count++;
				break;
			}
			tokens = strtok(NULL, delim);
			col_counter += 1;
		}
	}
	var = var / count;
	return var;
}


//Functions to get the minimum and maximum of a column
double column_max(int col, FILE *fp, char *delim){
	rewind(fp); //Just for safety
	int count = 0;
	double maximum = -INFINITY;
	int number_of_cols = number_of_columns(fp, delim);
	char buffer[128];
	while (fgets(buffer, 128, fp)){
		char *tokens = strtok(buffer, delim);
		char *eptr;
		int col_counter = 0;
		while (tokens != NULL){
			if (col_counter % number_of_cols == col){
				double x_value = strtod(tokens, &eptr);
				if (x_value > maximum){
					maximum = x_value;
				}
				}
			tokens = strtok(NULL, delim);
			col_counter++;
			}
		}
	return maximum;
}

double column_min(int col, FILE *fp, char *delim){
	rewind(fp); //Just for safety
	int count = 0;
	double minimum = INFINITY;
	int number_of_cols = number_of_columns(fp, delim);
	char buffer[128];
	while (fgets(buffer, 128, fp)){
		char *tokens = strtok(buffer, delim);
		char *eptr;
		int col_counter = 0;
		while (tokens != NULL){
			if (col_counter % number_of_cols == col){
				double x_value = strtod(tokens, &eptr);
				if (x_value < minimum){
					minimum = x_value;
				}
				}
			tokens = strtok(NULL, delim);
			col_counter++;
			}
		}
	return minimum;
}






