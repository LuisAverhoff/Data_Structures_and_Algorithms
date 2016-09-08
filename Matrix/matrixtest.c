#include "matrix.h"


int main(int argc, char* argv[]){

const int rows = atoi(argv[1]);
const int columns = atoi(argv[2]);
int** list  ;
// int arrayOfArray[rows][columns] ;
char* name = "Daniel" ; 


iMatrix test = createIntMatrix(list , rows, columns, name);



printComponents(test); 


return 0;

}
