#include <cipher.h>
#include <encoding.h>
#include <matrix.h>

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  char *key = "backupabc";
  char *padded_key = padChars(key, 9);
  char *secret_message = "retreatnowAAA";
  printf("the secret_message is %s.\n", secret_message);
  printf("the encoding key is %s.\n", key);
  char *secret = encrypt(key, secret_message);
  printf("the secret is:%s.\n", secret);
  char *decoded = decrypt(secret, key);
  printf("decoded message is %s.\n", decoded);
  free(decoded);
  free(secret);
  free(padded_key);

  return 0;
}
