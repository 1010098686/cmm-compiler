#include"../head/type_check.h"
#include"../head/symbolTable.h"
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

void process_int(TREE_NODE* node,Type* type){

}
void process_float(TREE_NODE* node,Type* type){

}
void process_id(TREE_NODE* node,Type* type){

}
void process_semi(TREE_NODE* node,Type* type){

}
void process_comma(TREE_NODE* node,Type* type){

}
void process_assignop(TREE_NODE* node,Type* type){

}
void process_relop(TREE_NODE* node,Type* type){

}
void process_plus(TREE_NODE* node,Type* type){

}
void process_minus(TREE_NODE* node,Type* type){

}
void process_star(TREE_NODE* node,Type* type){

}
void process_div(TREE_NODE* node,Type* type){

}
void process_and(TREE_NODE* node,Type* type){

}
void process_or(TREE_NODE* node,Type* type){

}
void process_dot(TREE_NODE* node,Type* type){

}
void process_not(TREE_NODE* node,Type* type){

}
void process_type(TREE_NODE* node,Type* type){
    node->type = (Type*)malloc(sizeof(Type));
    if(strcmp(node->s_value,"int")==0){
        node->type->kind = BASIC_INT;
    }else{
        node->type->kind = BASIC_FLOAT;
    }
    //node->type->basic = node->type->kind;
}
void process_lp(TREE_NODE* node,Type* type){

}
void process_rp(TREE_NODE* node,Type* type){

}
void process_lb(TREE_NODE* node,Type* type){

}
void process_rb(TREE_NODE* node,Type* type){

}
void process_lc(TREE_NODE* node,Type* type){

}
void process_rc(TREE_NODE* node,Type* type){

}
void process_struct(TREE_NODE* node,Type* type){

}
void process_return(TREE_NODE* node,Type* type){

}
void process_if(TREE_NODE* node,Type* type){

}
void process_else(TREE_NODE* node,Type* type){

}
void process_while(TREE_NODE* node,Type* type){

}
void process_program(TREE_NODE* node,Type* type){
    process_extdeflist(node->first_child,NULL);
}
void process_extdeflist(TREE_NODE* node,Type* type){
    TREE_NODE* head = node->first_child;
    process_extdef(head,NULL);
    if(head->brother != NULL){
        process_extdeflist(head->brother,NULL);
    }
}
void process_extdef(TREE_NODE* node,Type* type){
    TREE_NODE* specifier = node->first_child;
    process_specifier(specifier,NULL);
    node->type = (Type*)malloc(sizeof(Type));
    if(specifier->brother->node_type == EXTDECLIST_T){
        process_extdeclist(specifier->brother,specifier->type);
    }else if(specifier->brother->node_type == FUNDEC_T){
        TREE_NODE* fundec = specifier->brother;
        process_fundec(fundec,NULL);
        node->type = copyType(fundec->type);
        node->type->function.elem[0] = copyType(specifier->type);
        Type* temp = find(fundec->s_value);
        if(temp != NULL){
            print_error(4,node->lineno,"redefined function");
        }else{
            symbol_table_item* item = (symbol_table_item*)malloc(sizeof(symbol_table_item));
            copyString(&item->name,fundec->s_value);
            item->type = copyType(node->type);
            add_to_symbol_table(item);
        }
        process_compst(specifier->brother->brother, node->type);
    }
}
void process_extdeclist(TREE_NODE* node,Type* type){
    TREE_NODE* head = node->first_child;
    process_vardec(head,type);
    if(head->brother != NULL){
        process_extdeclist(head->brother->brother,type);
    }
}

void process_specifier(TREE_NODE* node,Type* type){
   TREE_NODE* head = node->first_child;
   if(head->node_type == TYPE_T){
       process_type(head,NULL);
   }else{
       process_structspecifier(head,NULL);
   }
   node->type = copyType(head->type);
}

void process_structspecifier(TREE_NODE* node,Type* type){
    TREE_NODE* head = node->first_child;
    node->type = (Type*)malloc(sizeof(Type));
    if(head->brother->node_type == TAG_T){
        process_tag(head->brother,NULL);
        Type* type = find(head->brother->s_value);
        if(type == NULL){
            print_error(17,node->lineno,"undefined structure");
            node->type->kind = UNDEFINED;
        }else{
            node->type = copyType(type);
        }
    }else if(head->brother->node_type == OPTTAG_T){
        process_opttag(head->brother,NULL);
        Type* type = find(head->brother->s_value);
        if(type != NULL){
            print_error(16,node->lineno,"redefined structure");
        }else{
            TREE_NODE* deflist = head->brother->brother->brother;
            process_deflist(deflist,NULL,1);
            node->type = copyType(deflist->type);
            symbol_table_item* item = (symbol_table_item*)malloc(sizeof(symbol_table_item));
            copyString(&item->name, head->brother->s_value);
            item->type = copyType(node->type);
            add_to_symbol_table(item);
        }
    }else{
        TREE_NODE* deflist = head->brother->brother;
        process_deflist(deflist,NULL,1);
        node->type = copyType(deflist->type);
    }
}

void process_opttag(TREE_NODE* node,Type* type){
    TREE_NODE * head = node->first_child;
    if(head != NULL){
        copyString(&node->s_value, head->s_value);
    }
}
void process_tag(TREE_NODE* node,Type* type){
    TREE_NODE * head = node->first_child;
    copyString(&node->s_value,head->s_value);
}
void process_vardec(TREE_NODE* node,Type* type){
    TREE_NODE* head = node->first_child;
    //node->type = (Type*)malloc(sizeof(Type));
    if(head->node_type == ID_T){
        copyString(&node->s_value,head->s_value);
        node->type = copyType(type);
    }else{
        TREE_NODE* int_value = head->brother->brother;
        process_vardec(head,type);
        int size = int_value->i_value;
        copyString(&node->s_value,head->s_value);
        // node->type->kind = ARRAY;
        // node->type->array.size = size;
        // node->type->array.elem = copyType(head->type);
        node->type = copyType(head->type);
        Type* temp = node->type;
        if(temp->kind != ARRAY){
            node->type->kind = ARRAY;
            node->type->array.size = size;
            node->type->array.elem = copyType(head->type);
        }else{
            while(temp->kind == ARRAY && temp->array.elem->kind == ARRAY){
                temp = temp->array.elem;
            }
            Type* t = copyType(temp->array.elem);
            temp->array.elem->kind = ARRAY;
            temp->array.elem->array.size = size;
            temp->array.elem->array.elem = copyType(t);
        }
    }
    if(node->brother == NULL || node->brother->node_type != LB_T){
        Type* temp = find(node->s_value);
        if(temp != NULL){
            print_error(3,node->lineno,"redefined variable");
        }else{
            symbol_table_item* item = (symbol_table_item*)malloc(sizeof(symbol_table_item));
            copyString(&item->name,node->s_value);
            item->type = copyType(node->type);
            add_to_symbol_table(item);
        }        
    }
}
void process_fundec(TREE_NODE* node,Type* type){
    TREE_NODE* head = node->first_child;
    copyString(&node->s_value,head->s_value);
    node->type = (Type*)malloc(sizeof(Type));
    node->type->kind = FUNCTION;
    if(head->brother->brother->node_type == RP_T){
        node->type->function.size = 1;
        node->type->function.elem = (Type**)malloc(sizeof(Type*));
    }else{
        TREE_NODE* varlist = head->brother->brother;
        process_varlist(varlist,NULL);
        int size = varlist->type->function.size;
        node->type->function.size = size;
        node->type->function.elem = (Type**)malloc(size*sizeof(Type*));
        for(int i=1;i<size;++i){
            node->type->function.elem[i] = copyType(varlist->type->function.elem[i]);
        }
    }
}
void process_varlist(TREE_NODE* node,Type* type){
    TREE_NODE* head = node->first_child;
    node->type = (Type*)malloc(sizeof(Type));
    node->type->kind = FUNCTION;
    process_paramdec(head,NULL);
    if(head->brother == NULL){
        node->type->function.size = 2;
        node->type->function.elem = (Type**)malloc(2*sizeof(Type*));
        node->type->function.elem[1] = copyType(head->type);
    }else{
        TREE_NODE* varlist = head->brother->brother;
        process_varlist(varlist,NULL);
        int size = varlist->type->function.size + 1;
        node->type->function.size = size;
        node->type->function.elem = (Type**)malloc(size*sizeof(Type*));
        node->type->function.elem[1] = copyType(head->type);
        // modified by fzy: i < size - 1
        for(int i=1;i<size-1;++i){
            node->type->function.elem[1+i] = copyType(varlist->type->function.elem[i]);
        }
    }
}
void process_paramdec(TREE_NODE* node,Type* type){
    TREE_NODE* head = node->first_child;
    process_specifier(head,NULL);
    process_vardec(head->brother,head->type);
    node->type = copyType(head->brother->type);
}
void process_compst(TREE_NODE* node,Type* type){
    TREE_NODE* head = node->first_child;
    if(head->brother->node_type == RC_T){
        //do nothing
    }else if(head->brother->node_type == DEFLIST_T){
        process_deflist(head->brother,NULL,0);
        if(head->brother->brother->node_type == STMTLIST_T){
            process_stmtlist(head->brother->brother,type);
        }
    }else{
        process_stmtlist(head->brother,type);
    }
}
void process_stmtlist(TREE_NODE* node,Type* type){
    TREE_NODE* head = node->first_child;
    process_stmt(head,type);
    if(head->brother){
        process_stmtlist(head->brother,type);
    }
}
void process_stmt(TREE_NODE* node,Type* type){
    // implemented by fzy
    // printf("Stmt process begins.\n");
    TREE_NODE *head = node->first_child;
    switch(head->node_type) {
        case EXP_T:
        process_exp(head, NULL);
        break;

        case COMPST_T:
        process_compst(head, type);
        break;

        case RETURN_T:
        process_exp(head->brother, NULL);
        // type mismatch for return: error type 8
        // updated
        if(type_equal(head->brother->type, type->function.elem[0]) == 0) {
            print_error(8, head->lineno, "Type mismatch for return.");
        }
        break;

        case WHILE_T:
        process_exp(head->brother->brother, NULL);
        if(head->brother->brother->type->kind != BASIC_INT) {
            print_error(7, head->lineno, "Type mismatch for 'while'.");
        }
        process_stmt(head->brother->brother->brother->brother, type);
        break;

        case IF_T:
        if(head->brother->brother->brother->brother->brother != NULL) {
            process_exp(head->brother->brother, NULL);
            if(head->brother->brother->type->kind != BASIC_INT) {
                print_error(7, head->lineno, "Type mismatch for 'if'.");
            }
            process_stmt(head->brother->brother->brother->brother, type);
            process_stmt(head->brother->brother->brother->brother->brother->brother, type);
        }
        else {
            process_exp(head->brother->brother, NULL);
            if(head->brother->brother->type->kind != BASIC_INT) {
                print_error(7, head->lineno, "Type mismatch for 'if'.");
            }
            process_stmt(head->brother->brother->brother->brother, type);
        }
        break;

        default:
        break;
    }
    // printf("Stmt has been processed.\n");
}
void process_deflist(TREE_NODE* node,Type* type,int in_struct){
    TREE_NODE* head = node->first_child;
    process_def(head,NULL,in_struct);
    node->type = copyType(head->type);
    if(head->brother != NULL){
        TREE_NODE* deflist = head->brother;
        process_deflist(deflist,NULL,in_struct);
        FieldList* h = node->type->structure, *tail = h;
        FieldList* p = deflist->type->structure;
        while(p){
            FieldList* tmp = (FieldList*)malloc(sizeof(FieldList));
            copyString(&tmp->name,p->name);
            tmp->type = copyType(p->type);
            tmp->next = NULL;
            tail->next = tmp;
            tail = tmp;
            p = p->next;
        }
    }
    if(in_struct){
        FieldList* p = node->type->structure;
        while(p){
            FieldList* q = p->next;
            while(q){
                if(strcmp(p->name,q->name) == 0){
                    print_error(15,node->lineno,"redefine a variable in a structure");
                    return;
                }
                q = q->next;
            }
            p = p->next;
        }
    }

}
void process_def(TREE_NODE* node,Type* type,int in_struct){
    TREE_NODE* specifier = node->first_child;
    process_specifier(specifier,NULL);
    process_declist(specifier->brother,specifier->type,in_struct);
    node->type = copyType(specifier->brother->type);
}
void process_declist(TREE_NODE* node,Type* type,int in_struct){
    TREE_NODE* head = node->first_child;
    process_dec(head,type,in_struct);
    node->type = (Type*)malloc(sizeof(Type));
    node->type->kind = STRUCTURE;
    node->type->structure = (FieldList*)malloc(sizeof(FieldList));
    copyString(&node->type->structure->name,head->type->structure->name);
    node->type->structure->type = copyType(head->type->structure->type);
    node->type->structure->next = NULL;
    if(head->brother != NULL){
        FieldList* h = node->type->structure, *tail = h;
        TREE_NODE* declist = head->brother->brother;
        process_declist(declist,type,in_struct);
        FieldList* p = declist->type->structure;
        while(p){
            FieldList* tmp = (FieldList*)malloc(sizeof(FieldList));
            copyString(&tmp->name,p->name);
            tmp->type = copyType(p->type);
            tmp->next = NULL;
            tail->next = tmp;
            tail = tmp;
            p = p->next;
        }
    }


}
void process_dec(TREE_NODE* node,Type* type,int in_struct){
    TREE_NODE* head = node->first_child;
    if(in_struct && head->brother != NULL){
        print_error(15,node->lineno,"initialize variable in structure definition");
    }
    process_vardec(head,type);
    node->type = (Type*)malloc(sizeof(Type));
    node->type->kind = STRUCTURE;
    node->type->structure = (FieldList*)malloc(sizeof(FieldList));
    copyString(&node->type->structure->name,head->s_value);
    node->type->structure->type = copyType(head->type);
    node->type->structure->next = NULL;
    if(head->brother != NULL){
        process_exp(head->brother->brother,NULL);
    }
}
void process_exp(TREE_NODE* node,Type* type){
    // implemented by fzy
    // printf("Exp process begins.\n");
    TREE_NODE *head = node->first_child;
    Type *t1, *t2;
    node->type = (Type*)malloc(sizeof(Type));
    switch(head->node_type) {
        case LP_T:
        case MINUS_T:
        process_exp(head->brother, NULL);
        node->type = copyType(head->brother->type);
        node->type->is_constant = 1;
        case NOT_T:
        process_exp(head->brother, NULL);
        if(head->brother->type->kind != BASIC_INT) {
            print_error(7, head->lineno, "Type mismatch for operands.");
            node->type->kind = UNDEFINED;
        }
        else {
            node->type = copyType(head->brother->type);
            node->type->is_constant = 1;
        }
        break;

        case ID_T:
        // variable or function has not been defined: error type 1, 2
        t1 = find(head->s_value);
        if(t1 == NULL) {
            // variable
            if(head->brother == NULL) {
                print_error(1, head->lineno, "Undefined variable.");
            }
            // function
            else {
                print_error(2, head->lineno, "Undefined function.");
            }
            node->type->kind = UNDEFINED;
        }
        else {
            if(head->brother != NULL) {
                // illegal use of "()": error type 11
                if(t1->kind != FUNCTION) {
                    print_error(11, head->lineno, "Illegal use of '( )'.");
                    node->type->kind = UNDEFINED;
                }
                else {
                    // error about function arguments: error type 9
                    if(head->brother->brother->node_type == ARGS_T) {
                        process_args(head->brother->brother, NULL);
                        if(para_equal(t1, head->brother->brother->type) == 0) {
                            print_error(9, head->lineno, "Function is not applicable for arguments.");
                            node->type->kind = UNDEFINED;
                        } 
                        else {
                            node->type = copyType(t1->function.elem[0]);
                            node->type->is_constant = 1;
                        }
                    }
                    else {
                        if(t1->function.size >= 2){
                            print_error(9, head->lineno, "Function is not applicable for arguments.");
                            node->type->kind = UNDEFINED;
                        }
                        else {
                            node->type = copyType(t1->function.elem[0]);
                            node->type->is_constant = 1;
                        }
                    }           
                }
            }
            else {
                node->type = copyType(t1);
            }
        }

        break;

        case INT_T:
        node->type->kind = BASIC_INT;
        //node->type->basic = BASIC_INT;
        node->type->is_constant = 1;
        break;

        case FLOAT_T:
        node->type->kind = BASIC_FLOAT;
        //node->type->basic = BASIC_FLOAT;
        node->type->is_constant = 1;
        break;

        case EXP_T:
        process_exp(head, NULL);
        if(head->brother->node_type == DOT_T) {
            // illegal use of ".": error type 13
            if(head->type->kind != STRUCTURE) {
                print_error(13, head->lineno, "Illegal use of '.'");
                node->type->kind = UNDEFINED;
            }
            else {
                // Non-existent field: error type 14
                int flag = 0;
                FieldList *p = head->type->structure;
                while(p != NULL) {
                    if(strcmp(p->name, head->brother->brother->s_value) == 0) {
                        flag = 1;
                        break;
                    }
                    p = p->next;
                }
                if(flag == 0) {
                    print_error(14, head->lineno, "Non-existent field.");
                    node->type->kind = UNDEFINED;
                }
                else {
                    t1 = find(head->brother->brother->s_value);
                    node->type = copyType(t1);
                }
            }
        }
        else if(head->brother->brother->node_type == EXP_T) {
            process_exp(head->brother->brother, NULL);
            if(head->brother->node_type == LB_T) {
                // illegal use of "[]": error type 10
                if(head->type->kind != ARRAY) {
                    print_error(10, head->lineno, "Illegal use of '[ ]'.");
                    node->type->kind = UNDEFINED;
                }
                else {
                    // array argument is not an integer: error type 12
                    if(head->brother->brother->type->kind != BASIC_INT) {
                        // updated
                        print_error(12, head->lineno, "Array argument is not an integer.");
                        node->type->kind = UNDEFINED;
                    }
                    else {
                        node->type = copyType(head->type->array.elem);
                    }
                }
            }
            else {
                if(head->brother->node_type == ASSIGNOP_T) {
                    // left-hand side problem: error type 6
                    if(head->type->is_constant == 1) {
                        print_error(6, head->lineno, "The left-hand side of an assignment must be a variable.");
                        node->type->kind = UNDEFINED;
                    }
                    // type mismatch for assignment: error type 5
                    else if(type_equal(head->type, head->brother->brother->type) == 0) {

                        // updated
                        print_error(5, head->lineno, "Type mismatch for assignment.");
                        node->type->kind = UNDEFINED;
                    }
                    else {
                        node->type = copyType(head->type);
                        node->type->is_constant = 1;
                    }
                }
                else {
                    // type mismatch for operands: error type 7
                    // relop unhandled
                    if(type_equal(head->type, head->brother->brother->type) == 0) {
                        print_error(7, head->lineno, "Type mismatch for operands.");
                        node->type->kind = UNDEFINED;
                    }
                    else {
                        if(head->brother->node_type == AND_T || head->brother->node_type == OR_T) {
                            if(head->type->kind != BASIC_INT) {
                                print_error(7, head->lineno, "Type mismtach for operands.");
                                node->type->kind = UNDEFINED;
                            }
                            else {
                                node->type = copyType(head->type);
                                node->type->is_constant = 1;
                            }
                        }
                        else if(head->brother->node_type == RELOP_T){
                            if(head->type->kind != BASIC_INT && head->type->kind != BASIC_FLOAT) {
                                print_error(7, head->lineno, "Type mismatch for operands.");
                                node->type->kind = UNDEFINED;
                            }
                            else {
                                node->type->kind = BASIC_INT;
                                //node->type->basic = BASIC_INT;
                                node->type->is_constant = 1;
                            }
                        }
                        else {
                            if(head->type->kind != BASIC_INT && head->type->kind != BASIC_FLOAT) {
                                print_error(7, head->lineno, "Type mismatch for operands.");
                                node->type->kind = UNDEFINED;
                            }
                            else {
                                node->type = copyType(head->type);
                                node->type->is_constant = 1;
                            }
                        }
                    }
                }
            }
        }
        break;

        default:
        break;
    }
    // printf("Exp has been processed.\n");
}
void process_args(TREE_NODE* node,Type* type){
    // implemented by fzy
    // printf("Args process begins.\n");
    node->type = (Type*)malloc(sizeof(Type));
    node->type->kind = FUNCTION;
    TREE_NODE *head = node->first_child;
    process_exp(head, NULL);
    if(head->brother != NULL) {
        process_args(head->brother->brother, NULL);
        int size = head->brother->brother->type->function.size + 1;
        node->type->function.size = size;
        node->type->function.elem = (Type**)malloc(size*sizeof(Type*));
        node->type->function.elem[1] = copyType(head->type);
        for(int i = 1;i < size - 1;i++) {
            node->type->function.elem[i+1] = head->brother->brother->type->function.elem[i];
        }
    }
    else {
        node->type->function.size = 2;
        node->type->function.elem = (Type**)malloc(2*sizeof(Type*));
        node->type->function.elem[1] = copyType(head->type);
    }
    // printf("Args has been processed.\n");
}

void print_error(int error_type,int lineno,char* description){
    printf("Error type %d at Line %d: %s\n",error_type,lineno,description);
}

void copyString(char** dst,char* src){
    if(*dst != NULL){
        free(*dst);
    }
    int len = strlen(src)+1;
    *dst = (char*)malloc(len*sizeof(char));
    strcpy(*dst,src);
    //dst[len]=0;
}