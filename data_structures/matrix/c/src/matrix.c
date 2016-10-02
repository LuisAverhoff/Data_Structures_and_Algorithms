#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Matrix.h"

int createMatrix(matrix *mat, const size_t rows, const size_t columns, const size_t memSize)
{
    void **data = calloc(rows * columns, memSize);

    if(data != NULL) /*In case calloc fails*/
    {
        mat->rows = rows;
        mat->columns = columns;
        mat->memSize = memSize;
        mat->data = data;
        return 1;
    }

    return -1;
}

void setElement(matrix *mat, const size_t x, const size_t y, const void *data)
{
    /*
       Remember this formula. (i * numOfColumns) + j to traverse a 2D array in a 1D fashion(This formula only applies to Row Major Order Arrays).
    */
    size_t offset = (x * mat->columns) + y;
    memcpy(mat->data + offset, data, mat->memSize);
}

void *getElement(matrix *mat, const size_t x, const size_t y)
{
    size_t offset = (x * mat->columns) + y;
    return mat->data + (offset * mat->memSize);
}

void freeMatrix(matrix *mat)
{
    if(mat->data != NULL)
    {
       /*Set back every back to their default values to preserve invariants.*/
        free(mat->data);
        mat->data = NULL;
        mat->rows = 0;
        mat->columns = 0;
        mat->memSize = 0;
    }
}

