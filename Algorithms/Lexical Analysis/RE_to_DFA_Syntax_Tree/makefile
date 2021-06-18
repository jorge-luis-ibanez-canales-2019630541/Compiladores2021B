main.exe: main.o State.o NFA.o DFA.o Regex.o GV.o SyntaxTree.o AlgoREtoDFA.o Node.o SyntaxTreeAlgo.o NodeAlgo.o
	g++ main.o State.o NFA.o DFA.o Regex.o GV.o SyntaxTree.o AlgoREtoDFA.o Node.o SyntaxTreeAlgo.o NodeAlgo.o -o main.exe

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
Node.o: src/Node.cpp
	g++ -c src/Node.cpp
SyntaxTreeAlgo.o: src/SyntaxTreeAlgo.cpp
	g++ -c src/SyntaxTreeAlgo.cpp
NodeAlgo.o: src/NodeAlgo.cpp
	g++ -c src/NodeAlgo.cpp
AlgoREtoDFA.o: src/AlgoREtoDFA.cpp
	g++ -c src/AlgoREtoDFA.cpp

clean:
	rm *.o




