#ifndef MATRIX_H
#define MATRIX_H
const int IDENTITY_MATRIX[3][3];
int ** add_matrix(int matrix1[3][3], int matrix2[3][3]);
int ** sub_matrix(int matrix1[3][3], int matrix2[3][3]);
int ** mul_matrix(int matrix1[3][3], int matrix2[3][3]);
int ** mod_matrix(int matrix2[3][3], int mod);
float ** divide_matrix(int matrix[3][3], float div);
float ** invert_matrix(int matrix[3][3]);
int get_determinant(int matrix[3][3]);
void print_matrix(int matrix[3][3]);
void print_matrix_f(float ** matrix);
#endif