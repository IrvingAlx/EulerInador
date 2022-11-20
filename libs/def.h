#include <stdio.h> 
#include <math.h> 
#include <stdlib.h>
#define numberOfDerivates 1

typedef enum{
  WRONG_ARGUMENTS,
  CORRECT_ARGUMENTS,
}ERROR_CODE;

typedef struct data *nodo;