#include <stdio.h>
#include "matrix.h"



/*Takes in two integer arrays and two integer arguments each specifying the
number of rows and columns, respectively. Ex. n x m matrix*/
iMatrix createIntMatrix(int** array, int n, int m){

	int i ;
	int j ;
	iMatrix new ; 
		
	
	for(i = 0 ; i < n ; i++ ){
		
	
		for (j = 0; j < m ; j++){
			new.array[i][j] = 1 ; 
		}

	
	
	}
		
	return new ; 
	
}


void printComponents(iMatrix matrix, const int n, const int m){
	int i = 0 ; 
	int j = 0 ; 
	
	for(i = 0 ; i < n ; i++ ){
		
	
		for (j = 0; j < m ; j++){
			printf("%d , ", matrix.array[i][j]);
		}
	
	printf("\n");

	
	
	}
	
}
