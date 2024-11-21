#ifndef CELL_H
#define CELL_H

typedef enum {
    INT,
    FLOAT,
    STRING,
    VOID
} DataType;

typedef struct cell {
    DataType type; 
    void *data;
    struct cell *next;
    struct cell *previous;
} Cell;

Cell* create_cell(void *data, DataType type);
void print_cell(Cell *cell);

#endif