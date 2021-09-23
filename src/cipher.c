#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <cipher.h>
#include <matrix.h>
#include <encoding.h>

/**
 * @brief test to see if the key is valid (invertable) if not return false
 * 
 * @param key 
 * @return true 
 * @return false 
 */
bool testKey(char* key){
    int keyLen = (int)strlen(key);
    if(keyLen != 9){
        return false;
    }
    int ** matrix;
    matrix = keyToMatrix(key);
    int det = get_determinant(matrix);
    free_matrix(matrix, 3);
    if(det == 0){
        return false;
    }
    return true;
}
/**
 * @brief convert the cipher key to a 3x3 matrix assuming the key is 9 characters
 * 
 * @param key 
 * @return int** 
 */
int ** keyToMatrix(char* key){
    int * value;
    int ** matrix = malloc(3*sizeof(int *));
    int * encodedKey = encode(key);
    for(int i = 0; i < 3; i++){
        value = malloc(3*sizeof(int));
        for(int j = 0; j < 3; j++){
            value[j] = encodedKey[i*3+j];
        }
        matrix[i] = value;
    }
    
    free(encodedKey);
    return matrix;
}
/**
 * @brief pad a charstring so that its length [mod padding_modulus equals 0
 * 
 * @param chars 
 * @param padding_modulus 
 * @return char* 
 */
char* padChars(char* chars, int padding_modulus){
    int size = strlen(chars);
    int padto = padding_modulus - (size % padding_modulus);
    char * temp = calloc(size+padto+1, sizeof(char));
    strcat(temp, chars);
    while(padto > 0){
        strcat(temp,"a");
        padto--;
    }
    return temp;
}

int * text_to_matrix(char* text){
    int size = (int)strlen(text);
    int * out;
    out = encode(text);
    return out;
}

char * encrypt(char* key, char* message){
    char * padded_key = padChars(key, 9);
    printf("padded key: %s\n",padded_key);
    bool works = testKey(padded_key);
    if(works){
        printf("this key works\n");
    }else{
        printf("this key doesn't work\n");
        free(padded_key);
        return 0;
    }
    char* padded_message = padChars(message, 9);
    int ** key_as_matrix = keyToMatrix(padded_key);
   
    
    int message_size = (int)strlen(padded_message);
    int * message_as_int = text_to_matrix(padded_message);
    
    MatrixList* ml = to_3x3s(message_as_int, message_size); //this is failing
    free(padded_key);
    free(padded_message);
    free(message_as_int);
    
    
    int ** matrix;
    int ** keymatrix;
    int ** result;
    int matrix_count = ml->matrix_count;
    for(int i = 0; i < matrix_count; i++){
        matrix = ml->matrix[i];
        keymatrix = key_as_matrix;
        //print_matrix(matrix);
        //print_matrix(keymatrix);
        result = mul_matrix(keymatrix, matrix);
        
        //print_matrix(result);
        int ** result2 = mod_matrix(result, (int)strlen(CHARSET));
        
        ml->matrix[i] = result2;
        free_matrix(matrix,3);
        free_matrix(result, 3);
    }
    free_matrix(key_as_matrix, 3);
    
    char * secret = calloc(matrix_count*10,sizeof(char));
    for(int i = 0; i < matrix_count; i++){
        for(int j = 0; j < 3; j++){
            char* decoded = decode(ml->matrix[i][j], 3);
            secret = strcat(secret,decoded);
            free(decoded);
        }
    }
    freeMatrixList(ml);
    free(ml);
    //char* secret = "test";
    return secret;
}