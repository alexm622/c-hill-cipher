#include <matrix.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * @brief identity matrix constant
 * 
 */
const int IDENTITY_MATRIX[3][3]={
    {1,0,0},
    {0,1,0},
    {0,0,1}
};

/**
 * @brief Take two 3x3 matricies and add them
 * 
 * @param matrix1 
 * @param matrix2 
 * @return int** 
 */
int ** add_matrix(int matrix1[3][3], int matrix2[3][3]){
    int* value = calloc(3, sizeof(int));
    int** rows = malloc(3*sizeof(value));
    printf("adding matricies\n");
    for(int i = 0; i < 3; i++){
        value = calloc(3, sizeof(int));
        for(int j = 0; j < 3; j++){
            value[j] = matrix1[i][j] + matrix2[i][j];
        }
        rows[i] = value;
    }
    return rows;
}

/**
 * @brief take two 3x3 matricies and subtract them
 * 
 * @param matrix1 
 * @param matrix2 
 * @return int** 
 */
int ** sub_matrix(int matrix1[3][3], int matrix2[3][3]){
    int* value = calloc(3, sizeof(int));
    int** rows = malloc(3*sizeof(value));
    printf("subtracting matricies\n");
    for(int i = 0; i < 3; i++){
        value = calloc(3, sizeof(int));
        for(int j = 0; j < 3; j++){
            value[j] = matrix1[i][j] - matrix2[i][j];
        }
        rows[i] = value;
    }
    return rows;
}
/**
 * @brief take two 3x3 matricies and multiply them
 * 
 * @param matrix1 
 * @param matrix2 
 * @return int** 
 */
int ** mul_matrix(int matrix1[3][3], int matrix2[3][3]){
    int* value = calloc(3, sizeof(int));
    int** rows = malloc(3*sizeof(value));
    printf("multiplying matricies\n");
    for(int i = 0; i < 3; i++){
        value = calloc(3, sizeof(int));
        for(int j = 0; j < 3; j++){
            int temp = 0;
            for(int k = 0; k < 3; k++){
                temp += matrix1[i][k]*matrix2[k][j];
            }
            value[j] = temp;
            
        }
        rows[i] = value;
    }
    return rows;
}
/**
 * @brief take a matrix and mod by the mod
 * 
 * @param matrix 
 * @param mod 
 * @return int** 
 */
int ** mod_matrix(int matrix[3][3], int mod){
    int* value = calloc(3, sizeof(int));
    int** rows = malloc(3*sizeof(value));
    printf("modulus of matricies\n");
    for(int i = 0; i < 3; i++){
        value = calloc(3, sizeof(int));
        for(int j = 0; j < 3; j++){
            
            value[j] = matrix[i][j]%mod;
            
        }
        rows[i] = value;
    }
    return rows;
}

/**
 * @brief print the matrix (3x3)
 * 
 * @param matrix 
 */

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
/**
 * @brief Invert a 3x3 matrix
 * 
 * @param matrix 
 * @return int** 
 */
//https://www.wikihow.com/Find-the-Inverse-of-a-3x3-Matrix
// TODO(Alex) finish this
float ** invert_matrix(int matrix[3][3]){
    float* value = calloc(3, sizeof(float));
    float** rows = malloc(3*sizeof(value));
    // initialize the array
    for(int i = 0; i < 3; i++){
        value = calloc(3, sizeof(int));
        for(int j = 0; j < 3; j++){
            value[j] = 0;
        }
        rows[i] = value;
    }
    int determinant = get_determinant(matrix);
    if(determinant == 0){
        return value;
    }
    for(int i =0; i < 3; i++){
        for(int j = 0; j < 3; j++){

        }
    }

    
}
// TODO(Me) rewrite this to be mathematically correct
//https://www.wikihow.com/Find-the-Determinant-of-a-3X3-Matrix
/**
 * @brief Get the determinant of a 3x3 matrix
 * 
 * @param matrix 
 * @return int 
 */
int get_determinant(int matrix[3][3]){
    int determinant = -1;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(IDENTITY_MATRIX[i][j] == 0){
                if(i == 0 & j==0){
                    determinant = matrix[i][j];
                }else{
                    determinant *= matrix[i][j];
                }
            }
        }
    }
    return determinant;
}
