main.exe:	gramatica.tab.o lex.yy.o  
	gcc lex.yy.o gramatica.tab.o -lfl -o main.exe

gramatica.tab.o: gramatica.y 
	bison -d gramatica.y && gcc -c gramatica.tab.c

lex.yy.o: lexico.l gramatica.tab.h
	lex lexico.l && gcc lex.yy.c -c

clean:
	rm *.c *.o *tab.h