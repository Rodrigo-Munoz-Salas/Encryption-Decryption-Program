#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define VALID 0
#define INVALID 1
#define MAX_SIZE 1000
#define COMMAND_SIZE 7
#define NOT_ENOUGH_ARGS 1
#define NINT 2
#define EXCEED_KEY_LENGTH 3
#define MISMATCH_KEY 4
#define WRONG_PATTERN 5
#define error(code, message) do{fprintf(stderr, "%s\n", message); return code;}while(0)

void encrypt();
void decrypt();
int extractMessage(char string[], char message[], int l, int length, int pos);
void setKeyOrder(int key[], int m, char* argv[]);
