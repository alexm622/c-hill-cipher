#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include <cipher.h>

const char* charset = "abcdefghijklmnopqrstuvwxyz1234567890";
const int charset_size = 36;
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
    int arraysize = charset_size;
    for(int i = 0; i < arraysize; i++){
        if(c == charset[i]){
            return i;
        }
    }
    return -1;
}

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
char* decode(int* intArray, int arraySize){
    char* char_array;
    char_array = malloc(arraySize*sizeof(int));
    for(int i = 0; i < arraySize; i++){
        char_array[i] = charset[intArray[i]-1];
    }
    return char_array;
}

int charStringSize(char* charstring){
    bool counting;
    int size=0;
    while(counting){
        if(charstring[size] == 0x00){
            break;
        }
        size++;
    }
    return size; 
}
