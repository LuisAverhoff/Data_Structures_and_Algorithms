#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "Matrix.h"

int createMatrix(matrix *mat, size_t rows, size_t columns, size_t memSize)
{
    assert(mat); /* Should not be null at this point. */
    assert(!mat->data); /* Should not have any more allocated to it at this point. */
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

void setElement(matrix *mat, size_t x, size_t y, void *data)
{
    /*
       Remember this formula. (i * numOfColumns) + j to traverse a 2D array in a 1D fashion(This formula only applies to Row Major Order Arrays).
       We are also multiplying by the appropriate memory size because different types of data have different memory sizes.
    */
    size_t offset = (x * mat->columns * mat->memSize) + (y * mat->memSize);
    memcpy(mat->data + offset, data, mat->memSize);
}

void *getElement(matrix *mat, size_t x, size_t y)
{
    size_t offset = (x * mat->columns * mat->memSize) + (y * mat->memSize);
    return mat->data + offset;
}

void freeMatrix(matrix *mat)
{
    if(mat != NULL)
    {
        free(mat->data);
        *mat = {NULL, 0, 0, mat->memSize};
    }
}
