#include <matrix.h>
#include <stdio.h>

int ** add_matrix(int matrix1[3][3], int matrix2[3][3]){
    int matrix_result[3][3] = {{0,0,0}, {0,0,0}, {0,0,0}};
    printf("adding matricies\n");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            matrix_result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return matrix_result;
}

void print_matrix(int ** matrix){
    
}