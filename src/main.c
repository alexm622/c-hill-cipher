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
    char* secret_message = "The quick brown fox jumps over the lazy dog";
    printf("the secret_message is %s\n", secret_message);
    printf("the encoding key is %s\n", key);
    char * secret = encrypt(key, secret_message);
    printf("the secret is:%s\n",secret);
    free(secret);
    free(padded_key);
/*
    char* charstr = "absdefghi";
    int** as_matrix = keyToMatrix(charstr);
    int** result = mul_matrix(as_matrix,as_matrix);
    free_matrix(result, 3);
    print_matrix(as_matrix);
    free_matrix(as_matrix,3);*/
    
    return 0;
}
