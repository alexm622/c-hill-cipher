#include <stdio.h>
#include <matrix.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int matrix[3][3] = { {1, 2, 3}, {0, 1, 4}, {5, 6, 0} };
    int matrix2[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };

    int ** matrix_result = malloc(sizeof(matrix));
    matrix_result = add_matrix(matrix, matrix2);
    printf("matricies added\n");
    print_matrix(matrix_result);
    matrix_result = sub_matrix(matrix,matrix2);
    print_matrix(matrix_result);
    matrix_result = mul_matrix(matrix,matrix2);
    print_matrix(matrix_result);
    matrix_result = mod_matrix(matrix,2);
    print_matrix(matrix_result);
    int determinant = get_determinant(matrix);
    printf("the determinant is %i \n", determinant);
    float * temp = calloc(3,sizeof(float));
    float ** inverted = malloc(3*sizeof(temp));
    free(temp);
    inverted = invert_matrix(matrix);
    print_matrix_f(inverted);
    return 0;
}
