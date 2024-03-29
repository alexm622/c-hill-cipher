#include <encoding.h>

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief the charset for encoding/decoding
 *
 */
const char *CHARSET =
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";

const int CHARSET_SIZE = 26 * 2 + 10;

/**
 * @brief find the index of char c in array given c, the array, and the lenght
 * of the array. indexing starts at 0, returns -1 if not exist
 *
 * @param c
 * @param array
 * @param arraysize
 * @return int
 */
int findIndexOf(char c) {
  int arraysize = (int)strlen(CHARSET) - 1;
  for (int i = 0; i < arraysize; i++) {
    if (c == CHARSET[i + 1]) {
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
int *encode(char *charstring) {
  int *integer_array;
  int charstring_len = (int)strlen(charstring);
  integer_array = malloc(charstring_len * sizeof(int));
  for (int i = 0; i < charstring_len; i++) {
    integer_array[i] = findIndexOf(charstring[i]) + 1;
    if (integer_array[i] == -1) {
      printf("character: %c was not found\n", charstring[i]);
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
char *decode(int *intArray, int arraySize) {
  char *char_array = calloc(arraySize + 1, sizeof(char));
  for (int i = 0; i < arraySize; i++) {
    char_array[i] = CHARSET[intArray[i]];
  }
  return char_array;
}
