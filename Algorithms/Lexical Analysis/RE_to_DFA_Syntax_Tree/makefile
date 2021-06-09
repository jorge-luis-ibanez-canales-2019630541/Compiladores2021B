main.exe: main.o State.o NFA.o DFA.o Regex.o GV.o SyntaxTree.o SyntaxTreeAlgo.o AlgoREtoDFA.o
	g++ main.o State.o NFA.o DFA.o Regex.o GV.o SyntaxTree.o SyntaxTreeAlgo.o AlgoREtoDFA.o -o main.exe

main.o: main.cpp 
	g++ -c main.cpp 

#Automata
State.o: ../Automaton/State.cpp
	g++ -c ../Automaton/State.cpp
NFA.o: ../Automaton/NFA.cpp
	g++ -c ../Automaton/NFA.cpp
DFA.o: ../Automaton/DFA.cpp
	g++ -c ../Automaton/DFA.cpp
Regex.o: ../Automaton/Regex.cpp
	g++ -c ../Automaton/Regex.cpp
GV.o: ../Automaton/GV.cpp
	g++ -c ../Automaton/GV.cpp

#Algoritmo
SyntaxTree.o: src/SyntaxTree.cpp
	g++ -c src/SyntaxTree.cpp
SyntaxTreeAlgo.o: src/SyntaxTreeAlgo.cpp
	g++ -c src/SyntaxTreeAlgo.cpp
AlgoREtoDFA.o: src/AlgoREtoDFA.cpp
	g++ -c src/AlgoREtoDFA.cpp

clean:
	rm *.o




