#include <stdio.h>
#include <matrix.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int matrix[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int matrix2[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };

    int ** matrix_result = malloc(sizeof(matrix));
    matrix_result = add_matrix(matrix, matrix2);
    printf("matricies added\n");
    printf("{");
    for(int i = 0; i < 3; i++){
        printf("{");
        for(int j = 0; j < 3; j++){
            printf("%i,", matrix_result[i][j]);
        }
        printf("}\n");
    }
    return 0;
}
