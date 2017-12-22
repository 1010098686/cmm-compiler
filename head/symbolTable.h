#ifndef _SYMBOL_TABLE_H
#define _SYMBOL_TABLE_H

#include "type.h"

struct symbol_item{
    char* name;
    Type* type;
};

typedef struct symbol_item symbol_table_item;

struct symbol_table{
    symbol_table_item* item;
    struct symbol_table* next;
};

typedef struct symbol_table symbol_table;

int add_to_symbol_table(symbol_table_item* item);
Type* find(char* name);


#endif