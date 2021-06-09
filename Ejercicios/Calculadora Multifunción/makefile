a.out:	calculadora.tab.o lex.yy.o calc_symtable.h
	gcc lex.yy.o calculadora.tab.o -lfl -lm

calculadora.tab.o:	calculadora.y calc_symtable.h
	bison -d calculadora.y && gcc -c calculadora.tab.c

lex.yy.o: calculadora.l calc_symtable.h
	lex calculadora.l && gcc lex.yy.c -c

clean:
	rm *.c *.o *tab.h