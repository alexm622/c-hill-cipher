#ifndef ENCODING_H
#define ENCODING_H
extern const char *CHARSET;
extern const int CHARSET_SIZE;
int findIndexOf(char c);
int *encode(char *charstring);
char *decode(int *intArray, int arraySize);
int charStringSize(char *charstring);
int intArraySize(int *intarray);
#endif
