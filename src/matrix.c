#include <matrix.h>
#include <stdio.h>
#include <stdlib.h>

int ** add_matrix(int matrix1[3][3], int matrix2[3][3]){
    //int matrix_result[3][3] = {{0,0,0}, {0,0,0}, {0,0,0}};
    int* values = calloc(9, sizeof(int));
    int** rows = malloc(3*sizeof(int*));
    printf("adding matricies\n");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            values[j] = matrix1[i][j] + matrix2[i][j];
        }
        rows[i] = values;
    }
    return rows;
}

void print_matrix(int ** matrix){
    
}