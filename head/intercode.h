#ifndef _INTERCODE_H_
#define _INTERCODE_H_

#include "list.h"
#include "type.h"

struct _Operand{
    enum {OP_VAR, OP_TEMP, OP_CONST_INT, OP_CONST_FLOAT, OP_LABEL} kind;
    union{
        enum {REF, DEREF, NORMAL} var_type;
        enum {IN_ASSIGN, OUT_ASSIGN} assign_type;
    };
    union{
        int var_no;
        int i_value;
        float f_value;
        char* name;
    };
};
typedef struct _Operand Operand;

typedef enum _RELType{EQ, NEQ, GREAT, LOW, GREATEQ, LOWEQ} RELType;
struct _InterCode{
    enum{LABEL, IR_FUNCTION, ASSIGN, ADD, SUB, MUL, DIV, GOTO, IF, RETURN, DEC, ARG, CALL, PARAM, READ, WRITE} kind;
    union{
        struct{char* name;};
        struct{Operand *left, *right;};
        struct{Operand *result,*op1,*op2;};
        struct{Operand *op;};
        struct{RELType reltype; Operand *src1, *src2; char* dst_label;};
    };
};
typedef struct _InterCode InterCode;

extern list_t* inter_code_table;
void init_inter_code_table();

Operand* copy_operand(Operand* op);
InterCode* copy_intercode(InterCode* intercode);

Operand* make_const_int_operand(int assign_type, int i_value);
Operand* make_const_float_operand(int assign_type, float f_value);
Operand* make_temp_operand(int var_type,int var_no);
Operand* make_operand(int type, int var_type, char* name);

InterCode* make_op_intercode(int type, Operand* op);
InterCode* make_unary_intercode(int type, Operand* left, Operand* right);
InterCode* make_binary_intercode(int type, Operand* result, Operand* op1, Operand* op2);
InterCode* make_relop_intercode(RELType reltype, Operand* src1, Operand* src2, char* dst_label);
InterCode* make_string_intercode(int type, char* name);

char* operand_to_string(Operand* op);
char* intercode_to_string(InterCode* code);
void write_intercode_to_file(char* filename);

void add_to_intercode_table(InterCode* code);
int new_temp();
char* new_label();

void test_inter_code();

int get_factor(Type *type);
#endif
