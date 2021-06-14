main.exe: main.o Grammar.o First.o FirstFactory.o Follow.o FollowFactory.o ProductionRule.o Symbol.o CyclesDetector.o State.o NFA.o DFA.o GV.o Closure.o Element.o Kernel.o PowersetAlgo.o TableLR.o ElementLR1.o PowersetAlgoLR1.o TableLR1.o
	g++ -Wall main.o Grammar.o First.o FirstFactory.o Follow.o FollowFactory.o ProductionRule.o Symbol.o CyclesDetector.o  State.o NFA.o DFA.o GV.o Closure.o Element.o Kernel.o PowersetAlgo.o TableLR.o ElementLR1.o PowersetAlgoLR1.o TableLR1.o -o main.exe


main.o: main.cpp 
	g++ -c main.cpp -Wall 

#Automata
State.o: ../../Automaton/State.cpp
	g++ -c ../../Automaton/State.cpp
NFA.o: ../../Automaton/NFA.cpp
	g++ -c ../../Automaton/NFA.cpp
DFA.o: ../../Automaton/DFA.cpp
	g++ -c ../../Automaton/DFA.cpp
GV.o: ../../Automaton/GV.cpp
	g++ -c ../../Automaton/GV.cpp


#Grammar
Grammar.o: ../../Grammar/Grammar.cpp
	g++ -c ../../Grammar/Grammar.cpp -Wall 
First.o: ../../Grammar/First.cpp
	g++ -c ../../Grammar/First.cpp -Wall 
FirstFactory.o: ../../Grammar/FirstFactory.cpp
	g++ -c ../../Grammar/FirstFactory.cpp -Wall 
Follow.o: ../../Grammar/Follow.cpp
	g++ -c ../../Grammar/Follow.cpp -Wall 
FollowFactory.o: ../../Grammar/FollowFactory.cpp
	g++ -c ../../Grammar/FollowFactory.cpp -Wall 
ProductionRule.o: ../../Grammar/ProductionRule.cpp
	g++ -c ../../Grammar/ProductionRule.cpp -Wall 
Symbol.o: ../../Grammar/Symbol.cpp
	g++ -c ../../Grammar/Symbol.cpp -Wall 
CyclesDetector.o: ../../Grammar/CyclesDetector.cpp
	g++ -c ../../Grammar/CyclesDetector.cpp -Wall 


#LR
Closure.o: ../LR/Closure.cpp
	g++ -c ../LR/Closure.cpp -Wall 
Element.o: ../LR/Element.cpp
	g++ -c ../LR/Element.cpp -Wall 
Kernel.o: ../LR/Kernel.cpp
	g++ -c ../LR/Kernel.cpp -Wall 
PowersetAlgo.o: ../LR/PowersetAlgo.cpp
	g++ -c ../LR/PowersetAlgo.cpp -Wall 
TableLR.o: ../LR/TableLR.cpp
	g++ -c ../LR/TableLR.cpp -Wall 


#LR0
ElementLR1.o: src/ElementLR1.cpp
	g++ -c src/ElementLR1.cpp -Wall 
PowersetAlgoLR1.o: src/PowersetAlgoLR1.cpp
	g++ -c src/PowersetAlgoLR1.cpp -Wall 
TableLR1.o: src/TableLR1.cpp
	g++ -c src/TableLR1.cpp -Wall 

clean:
	rm *.o


