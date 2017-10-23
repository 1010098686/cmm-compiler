CC=gcc
LEX=flex
BISON=bison
FLAGS=-ll -ly

parser:tree.c syntax.tab.c main.c
	$(CC) tree.c syntax.tab.c main.c $(FLAGS) -o parser
syntax.tab.c:syntax.y lexical.l
	$(BISON) -d syntax.y
	$(LEX) lexical.l
clean:
	rm -f lex.yy.c syntax.tab.c syntax.tab.h parser
