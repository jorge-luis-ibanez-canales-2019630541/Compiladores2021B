main.exe: main.o State.o NFA.o ThompsonAlgo.o Regex.o GV.o TemplateFactory.o
	g++ main.o State.o NFA.o ThompsonAlgo.o Regex.o GV.o TemplateFactory.o -o main.exe


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
ThompsonAlgo.o: src/ThompsonAlgo.cpp
	g++ -c src/ThompsonAlgo.cpp
TemplateFactory.o: src/TemplateFactory.cpp
	g++ -c src/TemplateFactory.cpp


clean:
	rm *.o



