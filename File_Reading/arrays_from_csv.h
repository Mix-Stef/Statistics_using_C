#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int number_of_rows(FILE *fp);
int number_of_columns(FILE *fp, char *delim);
void array_from_column(double *A, int col, FILE *fp, char *delim);


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