#ifndef _TYPE_CHECK_H
#define _TYPE_CHECK_H

#include"tree.h"
#include<assert.h>

void process_int(TREE_NODE* node,Type* type);
void process_float(TREE_NODE* node,Type* type);
void process_id(TREE_NODE* node,Type* type);
void process_semi(TREE_NODE* node,Type* type);
void process_comma(TREE_NODE* node,Type* type);
void process_assignop(TREE_NODE* node,Type* type);
void process_relop(TREE_NODE* node,Type* type);
void process_plus(TREE_NODE* node,Type* type);
void process_minus(TREE_NODE* node,Type* type);
void process_star(TREE_NODE* node,Type* type);
void process_div(TREE_NODE* node,Type* type);
void process_and(TREE_NODE* node,Type* type);
void process_or(TREE_NODE* node,Type* type);
void process_dot(TREE_NODE* node,Type* type);
void process_not(TREE_NODE* node,Type* type);
void process_type(TREE_NODE* node,Type* type);
void process_lp(TREE_NODE* node,Type* type);
void process_rp(TREE_NODE* node,Type* type);
void process_lb(TREE_NODE* node,Type* type);
void process_rb(TREE_NODE* node,Type* type);
void process_lc(TREE_NODE* node,Type* type);
void process_rc(TREE_NODE* node,Type* type);
void process_struct(TREE_NODE* node,Type* type);
void process_return(TREE_NODE* node,Type* type);
void process_if(TREE_NODE* node,Type* type);
void process_else(TREE_NODE* node,Type* type);
void process_while(TREE_NODE* node,Type* type);
void process_program(TREE_NODE* node,Type* type);
void process_extdeflist(TREE_NODE* node,Type* type);
void process_extdef(TREE_NODE* node,Type* type);
void process_extdeclist(TREE_NODE* node,Type* type);
void process_opttag(TREE_NODE* node,Type* type);
void process_tag(TREE_NODE* node,Type* type);
void process_vardec(TREE_NODE* node,Type* type);
void process_fundec(TREE_NODE* node,Type* type);
void process_varlist(TREE_NODE* node,Type* type);
void process_paramdec(TREE_NODE* node,Type* type);
void process_compst(TREE_NODE* node,Type* type);
void process_stmtlist(TREE_NODE* node,Type* type);
void process_stmt(TREE_NODE* node,Type* type);
void process_deflist(TREE_NODE* node,Type* type,int in_struct);
void process_def(TREE_NODE* node,Type* type,int in_struct);
void process_declist(TREE_NODE* node,Type* type,int in_struct);
void process_dec(TREE_NODE* node,Type* type,int in_struct);
void process_exp(TREE_NODE* node,Type* type);
void process_args(TREE_NODE* node,Type* type);
void process_specifier(TREE_NODE* node,Type* type);
void process_structspecifier(TREE_NODE* node,Type* type);

void print_error(int error_type,int lineno,char* desciption);
void copyString(char** dst,char* src);

#endif
