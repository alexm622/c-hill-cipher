#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include <cipher.h>
#include <matrix.h>
#include <encoding.h>
int main(int argc, char const *argv[])
{
    char * key = "abcdefg";
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
    char* secret_message = "The quick brown fox jumps over the lazy dog";
    printf("the secret_message is %s\n", secret_message);
    printf("the encoding key is %s\n", key);
    char* padded_message = padChars(secret_message, 9);
    int ** key_as_matrix = keyToMatrix(padded_key);
    int message_size = strlen(padded_message);
    int * message_as_int = text_to_matrix(padded_message);
    MatrixList* ml = to_3x3s(message_as_int, message_size);
    int ** matrix;
    int ** keymatrix;
    int ** result;
    for(int i = 0; i < ml->matrix_count; i++){
        matrix = ml->matrix[i];
        keymatrix = key_as_matrix;
        print_matrix(matrix);
        print_matrix(keymatrix);
        result = mul_matrix(keymatrix, matrix);
        free(matrix);
        print_matrix(result);
        result = mod_matrix(result, strlen(CHARSET));
        print_matrix(result);
        
        ml->matrix[i] = result;
        
    }
    free(key_as_matrix);
    for(int i = 0; i < ml->matrix_count; i++){
        int ** matrix = ml->matrix[i];
        for(int j = 0; j < 3; j++){
            printf("%s", decode(matrix[j], 3));
        }
        
    }
    freeMatrixList(ml);
    free(message_as_int);
    free(padded_key);
    
    return 0;
}
