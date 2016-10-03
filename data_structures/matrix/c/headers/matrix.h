#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

typedef struct Matrix
{
    void *data;
    size_t rows;
    size_t columns;
    size_t memSize;
}matrix;

int createMatrix(matrix *, const size_t, const size_t, const size_t);
void *getElement(matrix *, const size_t, const size_t);
void setElement(matrix *, const size_t, const size_t, const void *);
void freeMatrix(matrix *);

#endif /* MATRIX_H_INCLUDED */
