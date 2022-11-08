#include <cipher.h>

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <encoding.h>
#include <matrix.h>

/**
 * @brief test to see if the key is valid (invertable) if not return false
 *
 * @param key
 * @return true
 * @return false
 */
bool testKey(char *key) {
  int keyLen = (int)strlen(key);
  if (keyLen != 9) {
    return false;
  }
  int **matrix;
  matrix = keyToMatrix(key);
  int det = get_determinant(matrix);
  free_matrix(matrix, 3);
  if (det == 0) {
    return false;
  }
  return true;
}
/**
 * @brief convert the cipher key to a 3x3 matrix assuming the key is 9
 * characters
 *
 * @param key
 * @return int**
 */
int **keyToMatrix(char *key) {
  int *value;
  int **matrix = malloc(3 * sizeof(int *));
  int *encodedKey = encode(key);
  for (int i = 0; i < 3; i++) {
    value = malloc(3 * sizeof(int));
    for (int j = 0; j < 3; j++) {
      value[j] = encodedKey[i * 3 + j];
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
char *padChars(char *chars, int padding_modulus) {
  int size = strlen(chars);
  int padto = (padding_modulus - (size % padding_modulus)) % padding_modulus;
  char *temp = calloc(size + padto + 1, sizeof(char));
  strcat(temp, chars);
  while (padto > 0) {
    strcat(temp, "a");
    padto--;
  }
  return temp;
}
/**
 * @brief convert the text to a 1d array
 *
 * @param text
 * @return int*
 */
int *text_to_matrix(char *text) {
  int size = (int)strlen(text);
  int *out;
  out = encode(text);
  return out;
}
/**
 * @brief take the key and message and return the encoded message
 *
 * @param key
 * @param message
 * @return char*
 */
char *encrypt(char *key, char *message) {
  char *padded_key = padChars(key, 9);
  printf("padded key: %s\n", padded_key);
  bool works = testKey(padded_key);
  if (works) {
    printf("this key works\n");
  } else {
    printf("this key doesn't work\n");
    free(padded_key);
    return 0;
  }
  char *padded_message = padChars(message, 9);
  int **key_as_matrix = keyToMatrix(padded_key);

  int message_size = (int)strlen(padded_message);
  int *message_as_int = text_to_matrix(padded_message);

  MatrixList *ml = to_3x3s(message_as_int, message_size);
  free(padded_key);
  free(padded_message);
  free(message_as_int);

  int **matrix;
  int **keymatrix;
  int *result;
  int *sub;
  long matrix_count = ml->matrix_count;
  // this might need to be split even further...
  for (int i = 0; i < matrix_count; i++) {
    matrix = ml->matrix[i];
    keymatrix = key_as_matrix;
    for (int j = 0; j < 3; j++) {
      sub = matrix[j];

      result = mul_matrix_3x1(sub, keymatrix);

      int *result2 = mod_matrix_3x1(result, (int)strlen(CHARSET));

      matrix[j] = result2;
      free(result);
    }
    ml->matrix[i] = matrix;
  }
  free_matrix(key_as_matrix, 3);
  printf("finished encoding\n");

  char *secret = calloc(matrix_count * 9 + 1, sizeof(char));
  for (int i = 0; i < matrix_count; i++) {
    for (int j = 0; j < 3; j++) {
      char *decoded = decode(ml->matrix[i][j], 3);
      secret = strcat(secret, decoded);
      free(decoded);
    }
  }
  freeMatrixList(ml);
  free(ml);
  // char* secret = "test";
  return secret;
}
// TODO to write the decrypt function the find inverse needs a rewrite
// https://www.jigsawacademy.com/blogs/cyber-security/hill-cipher/#Hill-Cipher-Decryption
/**
 * @brief take the message and the key and return the message
 *
 * @param message
 * @param key
 * @return char*
 */
char *decrypt(char *message, char *key) {
  char *padded_key = padChars(key, 9);
  printf("padded key: %s\n", padded_key);
  bool works = testKey(padded_key);
  if (works) {
    printf("this key works\n");
  } else {
    printf("this key doesn't work\n");
    free(padded_key);
    return 0;
  }
  char *padded_message = padChars(message, 9);
  int **key_as_matrix = keyToMatrix(padded_key);
  int **inverted_key = invert_matrix(key_as_matrix);
  free_matrix(key_as_matrix, 3);

  // get the message size and
  int message_size = (int)strlen(padded_message);
  int *message_as_int = text_to_matrix(padded_message);

  MatrixList *ml = to_3x3s(message_as_int, message_size);

  // initialize the variables needed for multiplying the matrix by the inverse
  // matrix
  int **matrix;
  int **keymatrix;
  int *result;
  int *sub;
  long matrix_count = ml->matrix_count;
  for (int i = 0; i < matrix_count; i++) {
    matrix = ml->matrix[i];
    keymatrix = inverted_key;

    for (int j = 0; j < 3; j++) {
      sub = matrix[j];

      result = mul_matrix_3x1(sub, keymatrix);

      int *result2 = mod_matrix_3x1(result, (int)strlen(CHARSET));

      matrix[j] = result2;
      free(result);
    }
    ml->matrix[i] = matrix;
  }
  // free the space allocated to the inverted matrix
  free_matrix(inverted_key, 3);

  // calloc memory used to store the result
  char *secret = calloc(matrix_count * 9 + 1, sizeof(char));
  // loop through the matrix, decode the int into a char and write to the string
  for (int i = 0; i < matrix_count; i++) {
    for (int j = 0; j < 3; j++) {
      char *decoded = decode(ml->matrix[i][j], 3);
      secret = strcat(secret, decoded);
      free(decoded);
    }
  }
  // free the space allocated by the 3d array and
  freeMatrixList(ml);
  free(ml);
  free(padded_key);
  free(padded_message);
  free(message_as_int);

  // return the secret message
  return secret;
}
