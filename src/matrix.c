#include <matrix.h>
#include <stdio.h>
#include <stdlib.h>

int ** add_matrix(int matrix1[3][3], int matrix2[3][3]){
    int* value = calloc(3, sizeof(int));
    int** rows = malloc(3*sizeof(value));
    printf("adding matricies\n");
    for(int i = 0; i < 3; i++){
        value = calloc(3, sizeof(int) + 1);
        for(int j = 0; j < 3; j++){
            value[j] = matrix1[i][j] + matrix2[i][j];
        }
        rows[i] = value;
    }
    return rows;
}

int ** sub_matrix(int matrix1[3][3], int matrix2[3][3]){
    int* value = calloc(3, sizeof(int));
    int** rows = malloc(3*sizeof(value));
    printf("subtracting matricies\n");
    for(int i = 0; i < 3; i++){
        value = calloc(3, sizeof(int) + 1);
        for(int j = 0; j < 3; j++){
            value[j] = matrix1[i][j] - matrix2[i][j];
        }
        rows[i] = value;
    }
    return rows;
}
int ** mul_matrix(int matrix1[3][3], int matrix2[3][3]){
    int* value = calloc(3, sizeof(int));
    int** rows = malloc(3*sizeof(value));
    printf("subtracting matricies\n");
    for(int i = 0; i < 3; i++){
        value = calloc(3, sizeof(int) + 1);
        for(int j = 0; j < 3; j++){
            value[j] = matrix1[i][j] - matrix2[i][j];
        }
        rows[i] = value;
    }
    return rows;
}

//take a 3x3 matrix as input
void print_matrix(int ** matrix){
    printf("{");
    for(int i = 0; i < 3; i++){
        printf("{");
        for(int j = 0; j < 3; j++){
            printf("%i,", matrix[i][j]);
        }
        printf("}\n");
    }
    printf("}\n");
}