/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia 2023-2024
  *
  * @author Rubén Díaz Marrero 
  * @date 13/10/2023
  * @brief
  */

#include <iostream>
#include <fstream>
#include "parameters.cc"
#include "automaton.h"



int main(int argc, char *argv[]) {
  CheckCorrectParameters(argc, argv, 3);

  std::ifstream input_NFA{argv[1]};
  std::ifstream cadenas{argv[2]};
  
  Automaton mi_automata(input_NFA);

  std::string cadena_a_probar;
    do {
    cadenas >> cadena_a_probar;
    if (mi_automata.IsAccepted(cadena_a_probar)) {
      std::cout << cadena_a_probar << " --- Acepted\n";
    } else {
      std::cout << cadena_a_probar << " --- Rejected\n";
    }
  } while (cadenas);
  
  return 0;
}