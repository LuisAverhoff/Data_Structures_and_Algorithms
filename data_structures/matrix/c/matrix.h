#ifndef Matrix_H_INCLUDED
#define Matrix_H_INCLUDED

typedef struct Matrix
{
    void **data;
    size_t rows;
    size_t columns;
    size_t memSize;
}matrix;

int creatematrix(matrix *, size_t, size_t, size_t);
void *getElement(matrix *, size_t, size_t);
void setElement(matrix *, size_t, size_t, void *);
void freematrix(matrix *);

#endif /* Matrix_H_INCLUDED */
