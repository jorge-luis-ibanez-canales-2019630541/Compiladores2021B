main.exe: main.o State.o NFA.o DFA.o Regex.o GV.o EquivClass.o Partition.o PartitionAlgo.o AlgoREtoDFA.o SyntaxTree.o SyntaxTreeAlgo.o
	g++ main.o State.o NFA.o DFA.o Regex.o GV.o EquivClass.o Partition.o PartitionAlgo.o AlgoREtoDFA.o SyntaxTree.o SyntaxTreeAlgo.o -o main.exe

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


#Algorithm
PartitionAlgo.o: src/PartitionAlgo.cpp
	g++ -c src/PartitionAlgo.cpp
Partition.o: src/Partition.cpp
	g++ -c src/Partition.cpp
EquivClass.o: src/EquivClass.cpp
	g++ -c src/EquivClass.cpp


#To test the algorithm
AlgoREtoDFA.o: ../RE_to_DFA_Syntax_Tree/src/AlgoREtoDFA.cpp
	g++ -c ../RE_to_DFA_Syntax_Tree/src/AlgoREtoDFA.cpp
SyntaxTree.o: ../RE_to_DFA_Syntax_Tree/src/SyntaxTree.cpp
	g++ -c ../RE_to_DFA_Syntax_Tree/src/SyntaxTree.cpp
SyntaxTreeAlgo.o: ../RE_to_DFA_Syntax_Tree/src/SyntaxTreeAlgo.cpp
	g++ -c ../RE_to_DFA_Syntax_Tree/src/SyntaxTreeAlgo.cpp


clean:
	rm *.o