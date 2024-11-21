#include <string.h>
#include <stdio.h>
#include <cell.h>

int main(void){
    int value = 42;
    float pi = 3.14;
    char *str = "Hello, World!";
    Cell *int_cell = create_cell(&value, INT);
    Cell *str_cell = create_cell(str, STRING);
    Cell *float_cell = create_cell(&pi, FLOAT);
    Cell *void_cell = create_cell(str, VOID);
    Cell *void_malloc_cell = create_cell(strdup(str), VOID_MALLOC);

    print_cell(int_cell);
    print_cell(str_cell);
    print_cell(float_cell);
    print_cell(void_cell);
    print_cell(void_malloc_cell);

    free_cell(int_cell);
    free_cell(str_cell);
    free_cell(float_cell);
    free_cell(void_cell);
    free_cell(void_malloc_cell);

    return 0;
}