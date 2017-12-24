#include "../head/intercode.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

list_t* inter_code_table;

void init_inter_code_table(){
    inter_code_table = list_new();
}

Operand* copy_operand(Operand* op){
    Operand* res = (Operand*)malloc(sizeof(Operand));
    res->kind = op->kind;
    res->var_type = op->var_type;
    int type = op->kind;
    if(type == OP_CONST_INT){
       res->i_value = op->i_value;
    }else if(type == OP_CONST_FLOAT){
        res->f_value = op->f_value;
    }else if(type == OP_TEMP){
        res->var_no = op->var_no;
    }else{
        int len = strlen(op->name) + 1;
        res->name = (char*)malloc(sizeof(char)*len);
        strcpy(res->name, op->name);
    }
    return res;
}

InterCode* copy_intercode(InterCode* intercode){
    InterCode* res = (InterCode*)malloc(sizeof(InterCode));
    res->kind = intercode->kind;
    int type = intercode->kind;
    if(type == LABEL || type == IR_FUNCTION || type == GOTO){
        int len = strlen(intercode->name)+1;
        res->name = (char*)malloc(sizeof(char)*len);
        strcpy(res->name, intercode->name);
    }else if(type == ASSIGN || type == DEC || type == CALL){
        res->left = copy_operand(intercode->left);
        res->right = copy_operand(intercode->right);
    }else if(type == ADD || type == SUB || type == MUL || type == DIV){
        res->result = copy_operand(intercode->result);
        res->op1 = copy_operand(intercode->op1);
        res->op2 = copy_operand(intercode->op2);
    }else if(type == RETURN || type == ARG || type == PARAM || type == READ || type == WRITE){
        res->op = copy_operand(intercode->op);
    }else{
        res->reltype = intercode->reltype;
        res->src1 = copy_operand(intercode->src1);
        res->src2 = copy_operand(intercode->src2);
        int len = strlen(intercode->dst_label) + 1;
        res->dst_label = (char*)malloc(sizeof(char)*len);
        strcpy(res->dst_label, intercode->dst_label);
    }
    return res;
}


Operand* make_const_int_operand(int assign_type, int i_value){
    Operand* op = (Operand*)malloc(sizeof(Operand));
    op->kind = OP_CONST_INT;
    op->assign_type = assign_type;
    op->i_value = i_value;
    return op;
}

Operand* make_const_float_operand(int assign_type, float f_value){
    Operand* op = (Operand*)malloc(sizeof(Operand));
    op->kind = OP_CONST_FLOAT;
    op->assign_type = assign_type;
    op->f_value = f_value;
    return op;
}

Operand* make_temp_operand(int var_type, int var_no){
    Operand* op = (Operand*)malloc(sizeof(Operand));
    op->kind = OP_TEMP;
    op->var_type = var_type;
    op->var_no = var_no;
    return op;
}

Operand* make_operand(int type, int var_type, char* name){
    Operand* op = (Operand*)malloc(sizeof(Operand));
    op->kind = type;
    op->var_type = var_type;
    int len = strlen(name)+1;
    op->name = (char*)malloc(sizeof(char)*len);
    strcpy(op->name, name);
    return op;
}

InterCode* make_op_intercode(int type, Operand* op){
    InterCode* code = (InterCode*)malloc(sizeof(InterCode));
    code->kind = type;
    code->op = copy_operand(op);
    return code;
}

InterCode* make_unary_intercode(int type, Operand* left, Operand* right){
    InterCode* code = (InterCode*)malloc(sizeof(InterCode));
    code->kind = type;
    code->left = copy_operand(left);
    code->right = copy_operand(right);
    return code;
}

InterCode* make_binary_intercode(int type, Operand* result, Operand* op1, Operand* op2){
    InterCode* code = (InterCode*)malloc(sizeof(InterCode));
    code->kind = type;
    code->result = copy_operand(result);
    code->op1 = copy_operand(op1);
    code->op2 = copy_operand(op2);
    return code;
}

InterCode* make_relop_intercode(RELType reltype, Operand* src1, Operand* src2, char* dst_label){
    InterCode* code = (InterCode*)malloc(sizeof(InterCode));
    code->kind = IF;
    code->reltype = reltype;
    code->src1 = copy_operand(src1);
    code->src2 = copy_operand(src2);
    int len = strlen(dst_label) + 1;
    code->dst_label = (char*)malloc(sizeof(char)*len);
    strcpy(code->dst_label, dst_label);
    return code;
}

InterCode* make_string_intercode(int type, char* name){
    InterCode* code = (InterCode*)malloc(sizeof(InterCode));
    code->kind = type;
    int len = strlen(name) + 1;
    code->name = (char*)malloc(sizeof(char)*len);
    strcpy(code->name, name);
    return code;
}

char* operand_to_string(Operand* op){
    int type = op->kind;
    char* str = (char*)malloc(sizeof(char)*50);
    if(type == OP_CONST_INT){
        if(op->assign_type == IN_ASSIGN){
            sprintf(str,"#%d",op->i_value);
        }
        else if(op->assign_type == OUT_ASSIGN){
            sprintf(str,"%d",op->i_value);
        }
    }else if(type == OP_CONST_FLOAT){
        if(op->assign_type == IN_ASSIGN){
            sprintf(str, "#%lf", op->f_value);
        }else if(op->assign_type == OUT_ASSIGN){
            sprintf(str,"%lf",op->f_value);
        }
    }else if(type == OP_LABEL){
        sprintf(str, "%s", op->name);
    }else if(type == OP_TEMP){
        if(op->var_type == NORMAL){
            sprintf(str, "t%d", op->var_no);
        }else if(op->var_type == REF){
            sprintf(str, "&t%d", op->var_no);
        }else if(op->var_type == DEREF){
            sprintf(str, "*t%d", op->var_no);
        }
    }else if(type == OP_VAR){
        if(op->var_type == NORMAL){
            sprintf(str, "%s", op->name);
        }else if(op->var_type == REF){
            sprintf(str, "&%s", op->name);
        }else if(op->var_type == DEREF){
            sprintf(str, "*%s", op->name);
        }
    }
    return str;
}

char* intercode_to_string(InterCode* code){
    int type = code->kind;
    char* str = (char*)malloc(sizeof(char)*50);
    if(type == LABEL){
        sprintf(str,"LABEL %s :", code->name);
    }else if(type == IR_FUNCTION){
        sprintf(str, "FUNCTION %s :", code->name);
    }else if(type == ASSIGN){
        sprintf(str, "%s := %s", operand_to_string(code->left), operand_to_string(code->right));
    }else if(type == ADD){
        sprintf(str, "%s := %s + %s", operand_to_string(code->result), operand_to_string(code->op1), operand_to_string(code->op2));
    }else if(type == SUB){
        sprintf(str, "%s := %s - %s", operand_to_string(code->result), operand_to_string(code->op1), operand_to_string(code->op2));
    }else if(type == MUL){
        sprintf(str, "%s := %s * %s", operand_to_string(code->result), operand_to_string(code->op1), operand_to_string(code->op2));
    }else if(type == DIV){
        sprintf(str, "%s := %s / %s", operand_to_string(code->result), operand_to_string(code->op1), operand_to_string(code->op2));
    }else if(type == GOTO){
        sprintf(str, "GOTO %s", code->name);
    }else if(type == IF){
        char* rel;
        if(code->reltype == EQ){
            rel = "==";
        }else if(code->reltype == NEQ){
            rel = "!=";
        }else if(code->reltype == GREAT){
            rel = ">";
        }else if(code->reltype == LOW){
            rel = "<";
        }else if(code->reltype == GREATEQ){
            rel = ">=";
        }else if(code->reltype == LOWEQ){
            rel = "<=";
        }
        sprintf(str,"IF %s %s %s GOTO %s", operand_to_string(code->src1), rel, operand_to_string(code->src2), code->dst_label);
    }else if(type == RETURN){
        sprintf(str,"RETURN %s", operand_to_string(code->op));
    }else if(type == DEC){
        sprintf(str, "DEC %s %s", operand_to_string(code->left), operand_to_string(code->right));
    }else if(type == ARG){
        sprintf(str, "ARG %s", operand_to_string(code->op));
    }else if(type == CALL){
        sprintf(str, "%s := CALL %s", operand_to_string(code->left), operand_to_string(code->right));
    }else if(type == PARAM){
        sprintf(str, "PARAM %s", operand_to_string(code->op));
    }else if(type == READ){
        sprintf(str, "READ %s", operand_to_string(code->op));
    }else if(type == WRITE){
        sprintf(str, "WRITE %s", operand_to_string(code->op));
    }
    return str;
}

void write_intercode_to_file(char* filename){
    FILE* file = fopen(filename, "w+");
    list_iterator_t* it = list_iterator_new(inter_code_table, LIST_HEAD);
    list_node_t* node;
    while((node = list_iterator_next(it))){
        InterCode* code = node->val;
        char* str = intercode_to_string(code);
        fprintf(file, "%s\n", str);
    }
    fclose(file);
}

void add_to_intercode_table(InterCode* code){
    list_rpush(inter_code_table, list_node_new(code));
}

void test_inter_code(){
    Operand* op1 = make_operand(OP_VAR, NORMAL, "x");
    Operand* op2 = make_operand(OP_VAR, REF, "y");
    InterCode* code = make_relop_intercode(GREATEQ,op1,op2,"add");
    add_to_intercode_table(code);
    Operand* op3 = make_operand(OP_VAR, NORMAL, "x");
    Operand* op4 = make_operand(OP_VAR, REF, "y");
    Operand* op5 = make_const_int_operand(IN_ASSIGN, 5);
    InterCode* code2 = make_binary_intercode(ADD, op3, op4, op5);
    add_to_intercode_table(code2);
    Operand* op6 = make_operand(OP_VAR, DEREF, "x");
    Operand* op7 = make_temp_operand(NORMAL, 2);
    InterCode* code3 = make_unary_intercode(ASSIGN, op6, op7);
    add_to_intercode_table(code3);
    write_intercode_to_file("test1.ir");
}

int new_temp(){
    static int temp = 0;
    ++temp;
    return temp;
}

char* new_label(){
    static int temp_label = 0;
    ++temp_label;
    char* res = (char*)malloc(10*sizeof(char));
    sprintf(res, "label%d", temp_label);
    return res;
}

int get_factor(Type *type) {
    Type *tmp = type;
    int f = 1;
    while(tmp->array.elem->kind == ARRAY) {
        f = f * tmp->array.elem->array.size;
        tmp = tmp->array.elem;
    }
    return f;
}