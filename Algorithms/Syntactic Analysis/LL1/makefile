main.exe: main.o Grammar.o First.o FirstFactory.o Follow.o FollowFactory.o ProductionRule.o Symbol.o CyclesDetector.o TableLL1.o AnalyzerLL1.o
	g++ -Wall main.o Grammar.o First.o FirstFactory.o Follow.o FollowFactory.o ProductionRule.o Symbol.o CyclesDetector.o TableLL1.o AnalyzerLL1.o -o main.exe


main.o: main.cpp 
	g++ -c main.cpp -Wall 

#Grammar
Grammar.o: Grammar/Grammar.cpp
	g++ -c Grammar/Grammar.cpp -Wall 
First.o: Grammar/First.cpp
	g++ -c Grammar/First.cpp -Wall 
FirstFactory.o: Grammar/FirstFactory.cpp
	g++ -c Grammar/FirstFactory.cpp -Wall 
Follow.o: Grammar/Follow.cpp
	g++ -c Grammar/Follow.cpp -Wall 
FollowFactory.o: Grammar/FollowFactory.cpp
	g++ -c Grammar/FollowFactory.cpp -Wall 
ProductionRule.o: Grammar/ProductionRule.cpp
	g++ -c Grammar/ProductionRule.cpp -Wall 
Symbol.o: Grammar/Symbol.cpp
	g++ -c Grammar/Symbol.cpp -Wall 
CyclesDetector.o: Grammar/CyclesDetector.cpp
	g++ -c Grammar/CyclesDetector.cpp -Wall 



#Algoritmo
TableLL1.o: LL1/TableLL1.cpp
	g++ -c LL1/TableLL1.cpp -Wall 
AnalyzerLL1.o: LL1/AnalyzerLL1.cpp
	g++ -c LL1/AnalyzerLL1.cpp -Wall 


clean:
	rm *.o


