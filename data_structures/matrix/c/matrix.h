#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEFAULTROWS	4
#define DEFAULTCOLUMNS	4

/*Typedef declaration for integer matrix*/

struct imatrix {
char* matrixName ; 
const int rows ; 
const int columns ;
int array[DEFAULTROWS][DEFAULTCOLUMNS] ;  	


};

typedef struct imatrix iMatrix ;


iMatrix createIntMatrix(int **, const int, const int);

void printComponents(iMatrix,const int,const int);
