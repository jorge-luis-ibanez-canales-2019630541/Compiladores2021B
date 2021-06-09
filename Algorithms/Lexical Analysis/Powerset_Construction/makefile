main.exe: main.o State.o NFA.o DFA.o Regex.o GV.o PowersetConstruction.o Powerset.o Closure.o ThompsonAlgo.o TemplateFactory.o
	g++ main.o State.o NFA.o DFA.o Regex.o GV.o PowersetConstruction.o Powerset.o Closure.o ThompsonAlgo.o TemplateFactory.o -o main.exe

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
PowersetConstruction.o: src/PowersetConstruction.cpp
	g++ -c src/PowersetConstruction.cpp
Powerset.o: src/Powerset.cpp
	g++ -c src/Powerset.cpp
Closure.o: src/Closure.cpp
	g++ -c src/Closure.cpp


#Estos dos son para testearlo
ThompsonAlgo.o: ../Thompson_Construction/src/ThompsonAlgo.cpp
	g++ -c ../Thompson_Construction/src/ThompsonAlgo.cpp
TemplateFactory.o: ../Thompson_Construction/src/TemplateFactory.cpp
	g++ -c ../Thompson_Construction/src/TemplateFactory.cpp

clean:
	rm *.o
