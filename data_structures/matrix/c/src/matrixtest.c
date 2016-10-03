#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"

int main(int argc, char* argv[])
{
    matrix mat;
    char element;
    int i, j, errCheck; /*Change element to the appropriate data type you will be workng with.*/
    const int ROWS = 3;
    const int COL = 3;

    /*You can change sizeof() for any data type you want(integers, char arrays etc)*/
    errCheck = createMatrix(&mat, ROWS, COL, sizeof(char));

    /*If we were not able to successfully allocate memory*/
    if(errCheck == -1)
    {
        printf("Couldn't not allocate any more memory.");
        exit(EXIT_FAILURE);
    }

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COL; j++)
        {
            /*
               Note, when ever you decide to use scanf, make sure that first character you enter is a space else
               a newline will be consumed in the process.
             */
            errCheck = scanf(" %c", &element);

            /*Make sure that scanf did not fail. Scanf returns an integer based on the number of successful entries. */
            if(errCheck == 1)
            {
              setElement(&mat, i, j, &element);
            }
        }
    }

    printf("\n");

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COL; j++)
        {
            /*Returns void * so I must cast it to the appropriate type.*/
            element = *(char*)getElement(&mat, i, j);

            printf("%c ", element);
        }
        printf("\n");
    }

    freeMatrix(&mat);

    return 0;
}
