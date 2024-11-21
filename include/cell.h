#ifndef CELL_H
#define CELL_H

#include <stdio.h>
#include <stdlib.h>

typedef enum {
    INT,
    FLOAT,
    STRING,
    VOID,
    VOID_MALLOC // caso memória seja alocada dinamicamente
} DataType;

typedef struct cell {
    DataType type; 
    void *data;
    struct cell *next;
    struct cell *previous;
} Cell;

Cell* create_cell(void *data, DataType type);
void free_cell(Cell *cell);
void print_cell(Cell *cell);
#endif