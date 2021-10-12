#include <matrix.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <encoding.h>
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
int ** add_matrix(int** matrix1, int** matrix2){
    int* value;
    int** rows = malloc(3*sizeof(value));
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
int ** sub_matrix(int** matrix1, int** matrix2){
    int* value;
    int** rows = malloc(3*sizeof(value));
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
int ** mul_matrix(int** matrix1, int** matrix2){
    int* value;
    int** rows = malloc(3*sizeof(int*));
    for(int i = 0; i < 3; i++){
        value = malloc(3*sizeof(int));
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
int ** mod_matrix(int** matrix, int mod){
    int* value;
    int** rows = malloc(3*sizeof(value));
    for(int i = 0; i < 3; i++){
        value = calloc(3, sizeof(int));
        for(int j = 0; j < 3; j++){
            int modded = matrix[i][j];
            while(modded<0){
                modded +=mod;
            }
            value[j] = modded%mod;
            
        }
        rows[i] = value;
    }
    return rows;
}

/**
 * @brief print the matrix (3x3) ints
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
 * @brief print the matrix (3x3) floats
 * 
 * @param matrix 
 */

void print_matrix_f(float ** matrix){
    printf("{");
    for(int i = 0; i < 3; i++){
        printf("{");
        for(int j = 0; j < 3; j++){
            printf("%f,", matrix[i][j]);
        }
        printf("}\n");
    }
    printf("}\n");
}
//TODO this needs a rewrite to work better with the hill cipher
//https://www.jigsawacademy.com/blogs/cyber-security/hill-cipher/#Hill-Cipher-Decryption
/**
 * @brief Invert a 3x3 matrix
 * 
 * @param matrix 
 * @return float** 
 */
int ** invert_matrix(int ** matrix){
    int* value;
    int** rows = malloc(3*sizeof(float*));
    // initialize the array with zeros
    for(int i = 0; i < 3; i++){
        value = calloc(3, sizeof(int));
        for(int j = 0; j < 3; j++){
            value[j] = 0;
        }
        rows[i] = value;
    }

    int determinant = get_determinant(matrix);
    //if determinant is 0 then there is no inverse
    if(determinant == 0){
        return rows;
    }
    //rotate the matrix 90 degrees
    for(int i =0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            rows[i][j] = matrix[j][i];
        }
    }

    //calculate the inverse
    int** temp_matrix = malloc(3*sizeof(int*));
    int* t_value;
    for(int i = 0; i < 3; i++){
        t_value=calloc(3,sizeof(int));
        for(int j = 0; j < 3; j++){
            //ad-bc
            t_value[j] = matrix[(1+i)%3][(1+j)%3]*matrix[(2+i)%3][(2+j)%3] - matrix[(2+i)%3][(1+j)%3]*matrix[(1+i)%3][(2+j)%3];
        }
        temp_matrix[i] = t_value;
    }
    
    //get the modulus of the matrix
    int** modded_matrix = mod_matrix(temp_matrix, strlen(CHARSET)-1);

    //get the final mod
    int final_mod = getFinalMod(determinant, strlen(CHARSET) -1);

    free_matrix(rows,3);
    rows = modded_matrix;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j<3; j++){
            int temp = rows[i][j]*final_mod;
            temp %= strlen(CHARSET)-1;
            rows[i][j] = temp;
        }
    }

    free_matrix(temp_matrix,3);
    return rows;
}
/**
 * @brief Get the determinant of a 3x3 matrix using triangles rule
 * 
 * @param matrix 
 * @return int 
 */
int get_determinant(int ** matrix){
    int result = 0;
    for(int i = 0; i < 3; i++){
        result += matrix[0][0+i]*matrix[1][(1+i)%3]*matrix[2][(2+i)%3];
    }
    for(int i = 0; i < 3; i++){
        result -= matrix[0][(2+i)%3]*matrix[1][(1+i)%3]*matrix[2][(0+i)%3];
    }
    return result;
}

/**
 * @brief divide a matrix by the div, returns a float value
 * 
 * @param matrix 
 * @param div 
 * @return float** 
 */
float ** divide_matrix(int** matrix, float div){
    float* value;
    float** rows = malloc(3*sizeof(value));
    for(int i = 0; i < 3; i++){
        value = calloc(3, sizeof(float));
        for(int j = 0; j < 3; j++){
            value[j]= (float)matrix[i][j]/div;
        }
        rows[i] = value;
    }
    return rows;
}
/**
 * @brief free an integer matrix from memory that has size number elements
 * 
 * @param matrix 
 * @param number_elements 
 */
void free_matrix(int ** matrix, int number_elements){
    for(int i =0; i < number_elements; i++){
        free(matrix[i]);
    }
    free(matrix);
}
/**
 * @brief free a float matrix from memory that has size number_elements
 * 
 * @param matrix 
 * @param number_elements 
 */
void free_matrix_f(float ** matrix, int number_elements){
    for(int i =0; i < number_elements; i++){
        free(matrix[i]);
    }
    free(matrix);
}
/**
 * @brief converts a single 1d matrix to a 3d matrix of 3x3 matricies
 * 
 * @param matrix 
 * @param len 
 * @return MatrixList 
 */
MatrixList* to_3x3s(int * matrix, int len){
    
    if(len % 9 != 0 ){
        printf("something went wrong, this matrix was not padded properly\n");
        return NULL; //purposefully crash
    }
    
    MatrixList* m = calloc(2,sizeof(MatrixList *));
    
    long submatricies = len/9;
    printf("creating %li submatricies\n",submatricies);
    m->matrix_count = submatricies;
    int *** matricies = calloc(submatricies, sizeof(int**));
    int ** sub_matrix;
    int * row;
    for(int i = 0; i < submatricies; i++){
        sub_matrix = malloc(3*sizeof(int*));
        for(int j = 0; j < 3; j++){
            row = malloc(3*sizeof(int));
            for(int k = 0; k < 3; k++){
                row[k] = matrix[i*9+j*3+k];
            }
            sub_matrix[j] = row;
        }
        matricies[i] = sub_matrix;
    }
    m->matrix = matricies;
    
    return m;
}
/**
 * @brief free a MatrixList from memory
 * 
 * @param ml 
 */
void freeMatrixList(MatrixList* ml){
    int size = ml->matrix_count;
    printf("size is %i\n", size);
    free3d(ml->matrix,size);
}
/**
 * @brief free a 3 dimensional array from memory
 * 
 * @param matrix 
 * @param size 
 */
void free3d(int*** matrix, int size){
    for(int i =0; i < size; i++){
        free_matrix(matrix[i], 3);
    }
    free(matrix);
}

int getFinalMod(int determinant, int charset_size){
    //get the new positive determinent
    int new_mod = determinant;
    printf("the determinent is %i\n", determinant);
    while(new_mod < 0){
        new_mod += charset_size;
    }
    new_mod = new_mod%charset_size;
    printf("new mod is %i\n",new_mod);

    //find the multiplicative inverse mod
    int final_mod;
    for(int i = 1; i <= charset_size-1; i++){
        int temp = (new_mod*i)%charset_size;
        if(temp==1){
            final_mod = i;
            i = 600;
        }
    }
    printf("the final mod is %i\n", final_mod);
}