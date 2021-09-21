#ifndef CIPHER_H
#define CIPHER_H
const char* charset;
const int charset_size;
int findIndexOf(char c);
int* encode(char* charstring);
char* decode(int* intArray, int arraySize);
int charStringSize(char* charstring);
int intArraySize(int* intarray);
#endif