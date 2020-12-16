#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DICT_SIZE 52875
#define MAX_WORD_SIZE 46
#define MIN(a,b) (a < b)? a : b
void create_dict();
int lookup (const char *a);
int fixspelling (const char*a);
void printindex(int index);
unsigned int distance (const char *a, const char *b);
