CC=gcc
FLAGS=-lfl

scanner:main.c lex.yy.c
	$(CC) main.c lex.yy.c $(FLAGS) -o scanner
lex.yy.c:lexical.l
	flex lexical.l
clean:
	rm lex.yy.c scanner
