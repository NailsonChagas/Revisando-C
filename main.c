#include <string.h>
#include <cell.h>
#include <list.h>

int main(void){
    int value = 42;
    float pi = 3.14;
    char *str = "Hello, World!";
    Cell *int_cell = create_cell(&value, INT);
    Cell *str_cell = create_cell(str, STRING);
    Cell *float_cell = create_cell(&pi, FLOAT);
    Cell *void_cell = create_cell(str, VOID);
    Cell *void_malloc_cell = create_cell(strdup(str), VOID_MALLOC);

    List *list = create_list();
    list_insert(list, int_cell);
    list_insert(list, str_cell);
    list_insert(list, float_cell);
    list_insert(list, void_cell);
    list_insert(list, void_malloc_cell);

    print_list(list);
    // clear_list(list);
    // print_list(list);
    
    list_remove(list, 0);
    list_remove(list, 3);
    list_remove(list, 1);
    print_list(list);
    
    print_cell(list_get_idx(list, 1));

    free_list(list);
    return 0;
}