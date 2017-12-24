#ifndef _TRANSLATE_H_
#define _TRANSLATE_H_

#include "tree.h"
#include "intercode.h"
#include "symbolTable.h"

void translate_exp(TREE_NODE* node, Operand* place);
void translate_stmt(TREE_NODE* node);
void translate_compst(TREE_NODE* node);
void translate_cond(TREE_NODE* exp, char* label_true, char* label_false);
void translate_args(TREE_NODE* node, list_t* arg_list);

//added
void translate_stmtlist(TREE_NODE *node);

void translate_deflist(TREE_NODE *node);

void translate_def(TREE_NODE *node);

void translate_specifier(TREE_NODE *node);

void translate_declist(TREE_NODE *node);

void translate_dec(TREE_NODE *node, Operand *place);

void translate_vardec(TREE_NODE *node, Operand *place);

void translate_fundec(TREE_NODE *node);

void translate_varlist(TREE_NODE *node);

void translate_paramdec(TREE_NODE *node);

void translate_extdef(TREE_NODE *node);

void translate_extdeflist(TREE_NODE *node);

void translate_program(TREE_NODE *node);

#endif