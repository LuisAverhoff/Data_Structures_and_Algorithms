#include "matrix.h"


int main(int argc, char* argv[]){

const int rows = atoi(argv[1]);
const int columns = atoi(argv[2]);
int** list = malloc( (rows*sizeof(int*)) ) ;
// int arrayOfArray[rows][columns] ;


iMatrix test = createIntMatrix(list , rows, columns);



printComponents(test, rows, columns); 


return 0;

}
