#include <stdio.h>
#include "matrix.h"



/*Takes in two integer arrays and two integer arguments each specifying the
number of rows and columns, respectively. Ex. n x m matrix*/
iMatrix createIntMatrix(int** array, const int n, const int m, char* name){

	int i ;
	int j ;
		
		
	iMatrix new ;
	new.rows = n ; 
	new.columns = m ;
	new.name = name ; 
		

	for(i = 0 ; i < n ; i++ ){
		
	
		for (j = 0; j < m ; j++){
			new.list[i][j] = 1 ; 
		}

	
	
	}
		
	return new ; 
	
}


void printComponents(iMatrix matrix){
	int i = 0 ; 
	int j = 0 ; 

	
	
	for(i = 0 ; i < matrix.rows ; i++ ){
		
		/*Formatting*/
		for (j = 0; j < matrix.columns ; j++){
			
			if(j !=(matrix.columns-1)){			
				printf("%d , ", matrix.list[i][j]);
			}
			else{
				printf("%d", matrix.list[i][j]);
			}
		}
	
	printf("\n");

	
	
	}
	
}
