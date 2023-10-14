# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Asignatura: Computabilidad y Algoritmia
# 
# @author Rubén Díaz Marrero
# @date 25/09/2023
# 

CXX = g++
CXXFLAGS = -Wall -std=c++17 -g 



all: p05_automata_simulator

p02_strings: src/AFN_main.cc src/automaton.cc src/state.cc src/Alphabet.cc
		$(CXX) $(CXXFLAGS) -o $@ $^
	
#multiple_grades_main.o: src/multiple_grades_main.cc
#		$(CXX) $(CXXFLAGS) -c $^

#multiple_grades.o: src/multiple_grades.cc
#		$(CXX) $(CXXFLAGS) -c $^
	
.PHONY: all clean
clean:
		rm -f src/*.o
		rm -f p05_automata_simulator