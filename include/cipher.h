#ifndef CIPHER_H
#define CIPHER_H
#include <stdbool.h>
bool testKey(char* key);
int ** keyToMatrix(char* key);
char* padChars(char* chars, int padding_modulus);
int * text_to_matrix(char* text);
char * encrypt(char* key, char* message);
char* decrypt(char* message, char* key);
#endif