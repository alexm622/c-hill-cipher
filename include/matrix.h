#ifndef MATRIX_H
#define MATRIX_H
int ** add_matrix(int matrix1[3][3], int matrix2[3][3]);
int ** sub_matrix(int matrix1[3][3], int matrix2[3][3]);
int ** mul_matrix(int matrix1[3][3], int matrix2[3][3]);
int ** mod_matrix(int matrix2[3][3], int mod);
void print_matrix(int ** matrix);
#endif