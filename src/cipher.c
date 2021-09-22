#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

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
    int keyLen = charStringSize(key);
    if(keyLen != 9){
        return false;
    }
    int ** matrix = malloc(3*sizeof(int*));
    matrix = keyToMatrix(key);
    int det = get_determinant(matrix);
    free(matrix);
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
        value = calloc(3, sizeof(int));
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
    int size = charStringSize(chars);
    int padto = size % padding_modulus;
    char* out = chars;
    while(padto > 0){
        strcat(out," ");
    }
    return out;
}