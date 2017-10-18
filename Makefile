CC=gcc
LEX=flex
BISON=bison
FLAGS=-lfl -ly

scanner:main.c syntax.tab.c
	$(CC) main.c syntax.tab.c $(FLAGS) -o scanner
syntax.tab.c:syntax.y lexical.l
	$(BISON) -d syntax.y
	$(LEX) lexical.l
clean:
	rm -f lex.yy.c syntax.tab.c syntax.tab.h scanner
