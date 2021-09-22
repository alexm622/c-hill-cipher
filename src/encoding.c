#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include <encoding.h>
/**
 * @brief the charset for encoding/decoding
 * 
 */
const char* CHARSET = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 ";
/**
 * @brief the size of the charset
 * 
 */
const int CHARSET_SIZE = 36;
/**
 * @brief find the index of char c in array given c, the array, and the lenght of the array.
 * indexing starts at 0, returns -1 if not exist
 * 
 * @param c 
 * @param array 
 * @param arraysize 
 * @return int 
 */
int findIndexOf(char c){
    int arraysize = CHARSET_SIZE;
    for(int i = 0; i < arraysize; i++){
        if(c == CHARSET[i]){
            return i;
        }
    }
    return -1;
}
/**
 * @brief encode a charstring to a string of integers
 * 
 * @param charstring 
 * @return int* 
 */
int* encode(char* charstring){
    int* integer_array;
    int charstring_len = charStringSize(charstring);
    integer_array = malloc(charstring_len*sizeof(int));
    for(int i = 0; i < charstring_len; i++){
        integer_array[i] = findIndexOf(charstring[i])+1;
        if(integer_array[i] == -1){
            printf("character: %c was not found\n",charstring[i]);
        }
    }
    
    return integer_array;
}
/**
 * @brief decode an array of integers into a chararray
 * 
 * @param intArray 
 * @param arraySize 
 * @return char* 
 */
char* decode(int* intArray, int arraySize){
    char* char_array;
    char_array = malloc(arraySize*sizeof(int));
    for(int i = 0; i < arraySize; i++){
        char_array[i] = CHARSET[intArray[i]-1];
    }
    return char_array;
}

/**
 * @brief get the size of a charstring
 * 
 * @param charstring 
 * @return int 
 */
int charStringSize(char* charstring){
    bool counting = true;
    int size=0;
    while(counting){
        if(charstring[size] == 0x00){
            break;
        }
        size++;
    }
    return size; 
}
