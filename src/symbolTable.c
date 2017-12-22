#include "../head/symbolTable.h"
#include<stdlib.h>


symbol_table *table_head = NULL;
symbol_table *table_tail = NULL;

int add_to_symbol_table(symbol_table_item *item) {
    if(item == NULL) {
        //printf("Item is Null!\n");
        return 0;
    }

    if(table_head == NULL && table_tail == NULL) {
        table_head = (symbol_table*)malloc(sizeof(symbol_table));
        table_head->item = (symbol_table_item*)malloc(sizeof(symbol_table_item));
        table_head->item->name = (char*)malloc(sizeof(char)*(strlen(item->name)+1));
        strcpy(table_head->item->name, item->name);
        table_head->item->type = copyType(item->type);
        table_head->next = NULL;
        table_tail = table_head;
        //printf("%s has been added.\n", item->name);
        return 1;
    }

    symbol_table *p = table_head;
    while(p != NULL) {
        if(strcmp(item->name, p->item->name) == 0) {
            //printf("%s already exists!\n", item->name);
            return 0;
        }
        p = p->next;
    }

    table_tail->next = (symbol_table*)malloc(sizeof(symbol_table));
    table_tail->next->item = (symbol_table_item*)malloc(sizeof(symbol_table_item));
    table_tail->next->item->name = (char*)malloc(sizeof(char)*(strlen(item->name)+1));
    strcpy(table_tail->next->item->name, item->name);
    table_tail->next->item->type = copyType(item->type);
    table_tail->next->next = NULL;
    table_tail = table_tail->next;
    //printf("%s has been added.\n", item->name);
    return 1;
}

Type* find(char *name) {
    symbol_table *p = table_head;
    if(name == NULL) {
        //printf("Item name is Null!\n");
        return NULL;
    }
    while(p != NULL) {
        if(strcmp(p->item->name, name) == 0) {
            return p->item->type;
        }
        p = p->next;
    }
    //printf("Item name %s not found!\n", name);
    return NULL;
}