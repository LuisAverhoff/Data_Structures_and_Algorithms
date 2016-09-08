#include <stdio.h> // for input and output (printf)
#include <string.h> //for assignment of strings and names
#include <stdlib.h> //for atoi(char*) function 
#include <limits.h> //for int min/max



/*Typedef declaration for integer matrix*/

struct imatrix {
char* name ; 
int rows ; 
int columns ;
int list[100][100] ;

};

typedef struct imatrix iMatrix ;


iMatrix createIntMatrix(int **, const int, const int, char*);

void printComponents(iMatrix);
