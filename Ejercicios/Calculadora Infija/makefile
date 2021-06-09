a.out:	calculadora.tab.o lex.yy.o
	gcc lex.yy.o calculadora.tab.o -lfl -lm

calculadora.tab.o:	calculadora.y
	bison -d calculadora.y && gcc -c calculadora.tab.c

lex.yy.o:	calculadora.l
	lex calculadora.l && gcc lex.yy.c -c

clean:
	rm *.c *.o *.h