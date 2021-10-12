#ifndef MATRIX_H
#define MATRIX_H
/**
 * @brief a data type that holds multiple 3x3 matricies 
 * 
 */
typedef struct matricies {
    int *** matrix;
    int matrix_count;
} MatrixList;
const int IDENTITY_MATRIX[3][3];
int ** add_matrix(int** matrix1, int** matrix2);
int ** sub_matrix(int** matrix1, int** matrix2);
int ** mul_matrix(int** matrix1, int** matrix2);
int * mul_matrix_3x1(int* matrix1, int** matrix2);
int ** mod_matrix(int** matrix, int mod);
int * mod_matrix_3x1(int* matrix, int mod);
float ** divide_matrix(int** matrix, float div);
int ** invert_matrix(int ** matrix);
int get_determinant(int ** matrix);
void print_matrix(int ** matrix);
void print_matrix_3x1(int * matrix);
void print_matrix_f(float ** matrix);
void free_matrix(int ** matrix, int number_elements);
void free_matrix_f(float ** matrix, int number_elements);
MatrixList* to_3x3s(int * matrix, int len);
void freeMatrixList(MatrixList* ml);
void free3d(int*** matrix, int size);
int getFinalMod(int determinant, int charset_size);
#endif