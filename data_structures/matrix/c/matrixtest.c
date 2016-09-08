#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"

int main(int argc, char* argv[])
{
    matrix mat;
    int i, j, element; /*Change element to the appropriate data type you will be workng with.*/
    const int ROWS = atoi(argv[1]);
    const int COL = atoi(argv[2]);

    creatematrix(&mat, ROWS, COL, sizeof(int)); /*You can change sizeof() for any data type you want(integers, char arrays.)*/

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COL; j++)
        {
            scanf(" %d", &element);
            setElement(&mat, i, j, &element);
        }
    }

    printf("\n");

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COL; j++)
        {
            printf("%d ", *(int*)getElement(&mat, i, j)); /*Returns void * so I must cast it to the appropriate type.*/
        }
        printf("\n");
    }

    freematrix(&mat);

    return 0;
}
