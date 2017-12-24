#include "../head/translate.h"
#include <assert.h>



void translate_exp(TREE_NODE* node, Operand* place){
    TREE_NODE* head = node->first_child;
    if(head->node_type == EXP_T){
        if(head->brother->node_type == ASSIGNOP_T) {
            //assert(0);
            // added
            // something unhandled
            // int t = new_temp();
            // Operand *op1;
            // Operand *op2 = make_temp_operand(NORMAL, t);
            // // variable
            // if(head->first_child->node_type == ID_T) {
            //     op1 = make_operand(OP_VAR, NORMAL, head->first_child->s_value);
            // }
            // // array
            // else {
            //     int t1 = new_temp();
            //     op1 = make_temp_operand(NORMAL, t1);
            //     translate_exp(head, op1);
            //     op1->var_type = DEREF;
            // }
            int t1 = new_temp();
            int t2 = new_temp();
            Operand *op1 = make_temp_operand(NORMAL, t1);
            Operand *op2 = make_temp_operand(NORMAL, t2);
            translate_exp(head, op1);
            translate_exp(head->brother->brother, op2); 
            InterCode *code1 = make_unary_intercode(ASSIGN, op1, op2);
            add_to_intercode_table(code1);
            // if(place != NULL) {
            //     InterCode *code2 = make_unary_intercode(ASSIGN, place, op1);
            //     add_to_intercode_table(code2);
            // }

        }else if(head->brother->node_type == PLUS_T){
            int t1 = new_temp();
            int t2 = new_temp();
            Operand* op1 = make_temp_operand(NORMAL, t1);
            Operand* op2 = make_temp_operand(NORMAL, t2);
            translate_exp(head, op1);
            translate_exp(head->brother->brother, op2);
            InterCode* code = make_binary_intercode(ADD, place, op1, op2);
            add_to_intercode_table(code);
        }else if(head->brother->node_type == MINUS_T){
            int t1 = new_temp();
            int t2 = new_temp();
            Operand* op1 = make_temp_operand(NORMAL, t1);
            Operand* op2 = make_temp_operand(NORMAL, t2);
            translate_exp(head, op1);
            translate_exp(head->brother->brother, op2);
            InterCode* code = make_binary_intercode(SUB, place, op1, op2);
            add_to_intercode_table(code);
        }
        else if(head->brother->node_type == STAR_T){
            int t1 = new_temp();
            int t2 = new_temp();
            Operand* op1 = make_temp_operand(NORMAL, t1);
            Operand* op2 = make_temp_operand(NORMAL, t2);
            translate_exp(head, op1);
            translate_exp(head->brother->brother, op2);
            InterCode* code = make_binary_intercode(MUL, place, op1, op2);
            add_to_intercode_table(code);
        }else if(head->brother->node_type == DIV_T){
            int t1 = new_temp();
            int t2 = new_temp();
            Operand* op1 = make_temp_operand(NORMAL, t1);
            Operand* op2 = make_temp_operand(NORMAL, t2);
            translate_exp(head, op1);
            translate_exp(head->brother->brother, op2);
            InterCode* code = make_binary_intercode(DIV, place, op1, op2);
            add_to_intercode_table(code);
        }else if(head->brother->node_type == AND_T || head->brother->node_type == OR_T || head->brother->node_type == RELOP_T){
            char* label1 = new_label();
            char* label2 = new_label();
            Operand* op1 = make_const_int_operand(IN_ASSIGN, 0);
            InterCode* code1 = make_unary_intercode(ASSIGN, place, op1);
            add_to_intercode_table(code1);
            translate_cond(node, label1, label2);
            InterCode* code2 = make_string_intercode(LABEL, label1);
            add_to_intercode_table(code2);
            Operand* op2 = make_const_int_operand(IN_ASSIGN, 1);
            InterCode* code3 = make_unary_intercode(ASSIGN, place, op2);
            add_to_intercode_table(code3);
            InterCode* code4 = make_string_intercode(LABEL, label2);
            add_to_intercode_table(code4);
        }else if(head->brother->node_type == LB_T || head->brother->node_type == DOT_T){
            // assert(0);
            // added
            int t1 = new_temp();
            int t2 = new_temp();
            int t3 = new_temp();
            Operand *op1 = make_temp_operand(NORMAL, t1);
            Operand *op2 = make_temp_operand(NORMAL, t2);
            int tmp = get_factor(head->type);
            //printf("%d\n", tmp);
            Operand *op3 = make_const_int_operand(IN_ASSIGN, tmp * 4);
            Operand *op4 = make_temp_operand(NORMAL, t3);
            translate_exp(head, op1);
            if(head->first_child->node_type == ID_T && head->first_child->brother == NULL) {
                int temp = find_temp_from_name(head->first_child->s_value);
               if(temp != -1) {
                   op1 = make_temp_operand(NORMAL, temp);
               }
            }
            
            translate_exp(head->brother->brother, op2);
            InterCode *code1 = make_binary_intercode(MUL, op4, op2, op3);
            add_to_intercode_table(code1);
            InterCode *code2 = make_binary_intercode(ADD, place, op1, op4);
            add_to_intercode_table(code2);
            if(node->type->kind != ARRAY) {
                place->var_type = DEREF;
            }
        }
    }else if(head->node_type == INT_T){
        int value = head->i_value;
        Operand* op = make_const_int_operand(IN_ASSIGN, value);
        InterCode* code = make_unary_intercode(ASSIGN, place, op);
        add_to_intercode_table(code);
    }else if(head->node_type == FLOAT_T){
        float value = head->f_value;
        Operand* op = make_const_float_operand(IN_ASSIGN, value);
        InterCode* code = make_unary_intercode(ASSIGN, place, op);
        add_to_intercode_table(code);

    }else if(head->node_type == MINUS_T){
        int t1 = new_temp();
        Operand* op = make_temp_operand(NORMAL, t1);
        translate_exp(head->brother, op);
        Operand* op2 = make_const_int_operand(IN_ASSIGN, 0);
        InterCode* code = make_binary_intercode(SUB, place, op2, op);
        add_to_intercode_table(code);
    }else if(head->node_type == NOT_T){
        char* label1 = new_label();
        char* label2 = new_label();
        Operand* op1 = make_const_int_operand(IN_ASSIGN, 0);
        InterCode* code1 = make_unary_intercode(ASSIGN, place, op1);
        add_to_intercode_table(code1);
        translate_cond(node, label1, label2);
        InterCode* code2 = make_string_intercode(LABEL, label1);
        add_to_intercode_table(code2);
        Operand* op2 = make_const_int_operand(IN_ASSIGN, 1);
        InterCode* code3 = make_unary_intercode(ASSIGN, place, op2);
        add_to_intercode_table(code3);
        InterCode* code4 = make_string_intercode(LABEL, label2);
        add_to_intercode_table(code4);
    }else if(head->node_type == LP_T){
        translate_exp(head->brother, place);
    }else if(head->node_type == ID_T){
        if(head->brother == NULL) {
            char* name = head->s_value;
            // unupdated
            // if(place != NULL){
            //     free(place);
            // }
            // place = make_operand(OP_VAR, NORMAL, name);
            // updated
            place->kind = OP_VAR;
            place->var_type = NORMAL;
            int len = strlen(name) + 1;
            place->name = (char*)malloc(sizeof(char)*len);
            strcpy(place->name, name);
        }
        else {
            char* name = head->s_value;
            if(head->brother->brother->node_type == RP_T){
                if(strcmp(name,"read")==0){
                    InterCode* code = make_op_intercode(READ, place);
                    add_to_intercode_table(code);
                }else{
                    Operand* op = make_operand(OP_LABEL,NORMAL, name);
                    InterCode* code = make_unary_intercode(CALL, place, op);
                    add_to_intercode_table(code);
                }
            }else{
                TREE_NODE* args = head->brother->brother;
                list_t* args_list = list_new();
                translate_args(args, args_list);
                if(strcmp(name,"write")==0){
                    InterCode* code = make_op_intercode(WRITE, args_list->head->val);
                    add_to_intercode_table(code);
                }   else{
                    list_iterator_t* it = list_iterator_new(args_list,LIST_HEAD);
                    list_node_t* temp_node;
                    while((temp_node=list_iterator_next(it))){
                        InterCode* code = make_op_intercode(ARG, temp_node->val);
                        add_to_intercode_table(code);
                    }
                    list_destroy(args_list);
                    InterCode* code;
                    if(place == NULL){
                        int t = new_temp();
                        Operand* op = make_temp_operand(NORMAL, t);
                        code = make_unary_intercode(CALL, op, make_operand(OP_LABEL, NORMAL, name));
                    }else{
                        code = make_unary_intercode(CALL,place,make_operand(OP_LABEL,NORMAL,name));
                    }
                    add_to_intercode_table(code);
                }
            }
        }
    }

}

void translate_args(TREE_NODE* node, list_t* args_list){
    TREE_NODE* head = node->first_child;
    if(head->type->kind == ARRAY){
        Operand* op = make_operand(OP_VAR, REF, head->first_child->s_value);
        list_node_t* temp_node = list_node_new(op);
        list_lpush(args_list, temp_node);
    }else{
        int t = new_temp();
        Operand* op = make_temp_operand(NORMAL, t);
        translate_exp(head, op);
        list_node_t* temp_node = list_node_new(op);
        list_lpush(args_list, temp_node);
    }
    if(head->brother != NULL) {
        translate_args(head->brother->brother, args_list);
    }
}

void translate_stmt(TREE_NODE* node){
    TREE_NODE* head = node->first_child;
    int type = head->node_type;
    if(type == EXP_T){
        translate_exp(head, NULL);
    }else if(type == COMPST_T){
        translate_compst(head);
    }else if(type == RETURN_T){
        int t = new_temp();
        Operand* op = make_temp_operand(NORMAL, t);
        translate_exp(head->brother, op);
        InterCode* code = make_op_intercode(RETURN, op);
        add_to_intercode_table(code);
    }else if(type == WHILE_T){
        char* label1 = new_label();
        char* label2 = new_label();
        char* label3 = new_label();
        InterCode* code1 = make_string_intercode(LABEL, label1);
        add_to_intercode_table(code1);
        translate_cond(head->brother->brother, label2, label3);
        InterCode* code2 = make_string_intercode(LABEL, label2);
        add_to_intercode_table(code2);
        translate_stmt(head->brother->brother->brother->brother);
        InterCode* code3 = make_string_intercode(GOTO, label1);
        add_to_intercode_table(code3);
        InterCode* code4 = make_string_intercode(LABEL, label3);
        add_to_intercode_table(code4);
    }else{
        if(head->brother->brother->brother->brother->brother == NULL){
            char* label1 = new_label();
            char* label2 = new_label();
            translate_cond(head->brother->brother,label1, label2);
            InterCode* code1 = make_string_intercode(LABEL, label1);
            add_to_intercode_table(code1);
            translate_stmt(head->brother->brother->brother->brother);
            InterCode* code2 = make_string_intercode(LABEL, label2);
            add_to_intercode_table(code2);
        }else{
            TREE_NODE* exp = head->brother->brother;
            TREE_NODE* stmt1 = head->brother->brother->brother->brother;
            TREE_NODE* stmt2 = head->brother->brother->brother->brother->brother->brother;
            char* label1 = new_label();
            char* label2 = new_label();
            char* label3 = new_label();
            translate_cond(exp, label1, label2);
            InterCode* code1 = make_string_intercode(LABEL, label1);
            add_to_intercode_table(code1);
            translate_stmt(stmt1);
            InterCode* code2 = make_string_intercode(GOTO, label3);
            add_to_intercode_table(code2);
            InterCode* code3 = make_string_intercode(LABEL, label2);
            add_to_intercode_table(code3);
            translate_stmt(stmt2);
            InterCode* code4 = make_string_intercode(LABEL, label3);
            add_to_intercode_table(code4);
        }
    }
}

void translate_compst(TREE_NODE *node) {
    // added
    TREE_NODE *head = node->first_child;
    if(head->brother->node_type == DEFLIST_T) {
        translate_deflist(head->brother);
        if(head->brother->brother->node_type == STMTLIST_T) {
            translate_stmtlist(head->brother->brother);
        }
    }
    else if(head->brother->node_type == STMTLIST_T) {
        translate_stmtlist(head->brother);
    }
}

void translate_stmtlist(TREE_NODE *node) {
    // added
    TREE_NODE *head = node->first_child;
    translate_stmt(head);
    if(head->brother != NULL) {
        translate_stmtlist(head->brother);
    }
}

void translate_deflist(TREE_NODE *node) {
    // added
    TREE_NODE *head = node->first_child;
    translate_def(head);
    if(head->brother != NULL) {
        translate_deflist(head->brother);
    }
}

void translate_def(TREE_NODE *node) {
    // added
    TREE_NODE *head = node->first_child;
    translate_specifier(head);
    translate_declist(head->brother);
}

void translate_specifier(TREE_NODE *node) {
    // added
}

void translate_declist(TREE_NODE *node) {
    // added
    TREE_NODE *head = node->first_child;
    int t = new_temp();
    Operand *op = make_temp_operand(NORMAL, t);
    translate_dec(head, op);
    if(head->brother != NULL) {
        translate_declist(head->brother->brother);
    }
}

void translate_dec(TREE_NODE *node, Operand *place) {
    // added
    TREE_NODE *head = node->first_child;
    if(head->brother != NULL) {
        int t1 = new_temp();
        int t2 = new_temp();
        Operand *op1 = make_temp_operand(NORMAL, t1);
        Operand *op2 = make_temp_operand(NORMAL, t2);
        translate_vardec(head, op1);
        translate_exp(head->brother->brother, op2); 
        InterCode *code1 = make_unary_intercode(ASSIGN, op1, op2);
        add_to_intercode_table(code1);
        // if(place != NULL) {
        //     InterCode *code2 = make_unary_intercode(ASSIGN, place, op1);
        //     add_to_intercode_table(code2);
        // }
    }
    else {
        int t1 = new_temp();
        Operand *op1 = make_temp_operand(NORMAL, t1);
        translate_vardec(head, op1);
    }
}

void translate_vardec(TREE_NODE *node, Operand *place) {
    // added
    TREE_NODE *head = node->first_child;
    // variable
    if(head->node_type == ID_T) {
        // unupdated
        // if(place != NULL) {
        //     free(place);
        // }
        // place = make_operand(OP_VAR, NORMAL, head->s_value);
        // updated
        char *name = head->s_value;
        place->kind = OP_VAR;
        place->var_type = NORMAL;
        int len = strlen(name) + 1;
        place->name = (char*)malloc(sizeof(char)*len);
        strcpy(place->name, name);
    }
    // array
    else {
        char *name;
        TREE_NODE *tmp = head;
        while(tmp->node_type != ID_T) {
            tmp = tmp->first_child;
        }
        Type *type = find(tmp->s_value);
        int size = get_size(type);
        Operand *op1 = make_operand(OP_VAR, NORMAL, tmp->s_value);        
        Operand *op2 = make_const_int_operand(OUT_ASSIGN, size);
        InterCode *code1 = make_unary_intercode(DEC, op1, op2);
        add_to_intercode_table(code1);
        int t = new_temp();
        Operand* left = make_temp_operand(NORMAL, t);
        Operand* right = make_operand(OP_VAR, REF, tmp->s_value);
        InterCode* code2 = make_unary_intercode(ASSIGN, left, right);
        add_to_intercode_table(code2);
        MAP_ITEM* map_item = (MAP_ITEM*)malloc(sizeof(MAP_ITEM));
        map_item->temp = t;
        map_item->name = (char*)malloc((strlen(tmp->s_value)+1)*sizeof(char));
        strcpy(map_item->name, tmp->s_value);
        list_node_t* node = list_node_new(map_item);
        list_lpush(array_map, node);
    }
}

void translate_fundec(TREE_NODE *node) {
    // added
    TREE_NODE *head = node->first_child;
    InterCode *code1 = make_string_intercode(IR_FUNCTION, head->s_value);
    add_to_intercode_table(code1);
    if(head->brother->brother->node_type == VARLIST_T) {
        translate_varlist(head->brother->brother);
    }
}

void translate_varlist(TREE_NODE *node) {
    // added
    TREE_NODE *head = node->first_child;
    translate_paramdec(head);
    if(head->brother != NULL) {
        translate_varlist(head->brother->brother);
    }
}

void translate_paramdec(TREE_NODE *node) {
    // added
    TREE_NODE *head = node->first_child;
    Operand *op = make_operand(OP_VAR, NORMAL, head->brother->first_child->s_value);
    InterCode *code = make_op_intercode(PARAM, op);
    add_to_intercode_table(code);
}

void translate_extdef(TREE_NODE *node) {
    // added
    TREE_NODE *head = node->first_child;
    if(head->brother->node_type == FUNDEC_T) {
        translate_fundec(head->brother);
        translate_compst(head->brother->brother);
    }
}

void translate_extdeflist(TREE_NODE *node) {
    // added
    TREE_NODE *head = node->first_child;
    translate_extdef(head);
    if(head->brother != NULL) {
        translate_extdeflist(head->brother);
    }
}

void translate_program(TREE_NODE *node) {
    // added
    TREE_NODE *head = node->first_child;
    translate_extdeflist(head);
}

void translate_cond(TREE_NODE* exp, char* label_true, char* label_false){
    TREE_NODE* head = exp->first_child;
    if(head->node_type == NOT_T){
        translate_cond(head->brother, label_false, label_true);
    }else if(head->brother->node_type == RELOP_T){
        char* relop = head->brother->s_value;
        RELType reltype;
        if(strcmp(relop, "==")==0){
            reltype = EQ;
        }else if(strcmp(relop, "!=")==0){
            reltype = NEQ;
        }else if(strcmp(relop,">")==0){
            reltype = GREAT;
        }else if(strcmp(relop, "<")==0){
            reltype = LOW;
        }else if(strcmp(relop,">=")==0){
            reltype = GREATEQ;
        }else if(strcmp(relop,"<=")==0){
            reltype = LOWEQ;
        }
        int t1 = new_temp();
        int t2 = new_temp();
        Operand* op1 = make_temp_operand(NORMAL, t1);
        Operand* op2 = make_temp_operand(NORMAL, t2);
        translate_exp(head, op1);
        translate_exp(head->brother->brother, op2);
        InterCode* code1 = make_relop_intercode(reltype,op1, op2, label_true);
        add_to_intercode_table(code1);
        InterCode* code2 = make_string_intercode(GOTO, label_false);
        add_to_intercode_table(code2);
    }else if(head->brother->node_type == AND_T){
        char* label = new_label();
        translate_cond(head,label, label_false);
        InterCode* code = make_string_intercode(LABEL, label);
        add_to_intercode_table(code);
        translate_cond(head->brother->brother, label_true, label_false);
    }else if(head->brother->node_type == OR_T){
        char* label = new_label();
        translate_cond(head, label_true, label);
        InterCode* code = make_string_intercode(LABEL, label);
        add_to_intercode_table(code);
        translate_cond(head->brother->brother,label_true, label_false);
    }else{
        int t = new_temp();
        Operand* op1 = make_temp_operand(NORMAL, t);
        translate_exp(exp,op1);
        Operand* op2=  make_const_int_operand(IN_ASSIGN, 0);
        InterCode* code1 = make_relop_intercode(NEQ, op1, op2, label_true);
        add_to_intercode_table(code1);
        InterCode* code2 = make_string_intercode(GOTO, label_false);
        add_to_intercode_table(code2);
    }
}

