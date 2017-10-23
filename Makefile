CC=gcc
LEX=flex
BISON=bison
ifeq ($(shell uname), Linux)
	FLAGS := -lfl -ly
else ifeq ($(shell uname), Darwin)
	FLAGS := -ll -ly
endif

parser:tree.c syntax.tab.c main.c
	$(CC) tree.c syntax.tab.c main.c $(FLAGS) -o parser
syntax.tab.c:syntax.y lexical.l
	$(BISON) -d syntax.y
	$(LEX) lexical.l
clean:
	rm -f lex.yy.c syntax.tab.c syntax.tab.h parser
