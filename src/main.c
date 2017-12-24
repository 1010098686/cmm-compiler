#include "../head/tree.h"
#include "../head/type_check.h"
#include "../head/symbolTable.h"
#include "../head/intercode.h"
#include "../head/translate.h"
#include <stdio.h>
extern FILE* yyin;
extern int yydebug;
extern int yylex(void);
extern int yyparse(void);
extern void yyrestart(FILE* f);

void init(){
    init_symbol_table();
    init_inter_code_table();
}

int main(int argc, char** argv){
    if(argc<3) return 1;
    init();
    //test_inter_code();
    FILE* f = fopen(argv[1],"r");
    if(!f){
        perror(argv[1]);
        return 1;
    }
    yyrestart(f);
    //yydebug = 1;
    yyparse();
    if(!error){
        process_program(root,NULL);
        translate_program(root);
        write_intercode_to_file(argv[2]);
        //print_tree(root,0);
    }
    return 0;
}
