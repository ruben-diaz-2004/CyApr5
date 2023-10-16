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
#include "cadena.h"


int main(int argc, char *argv[]) {
  CheckCorrectParameters(argc, argv, 3);

  std::ifstream input_NFA{argv[1]};
  std::ifstream cadenas{argv[2]};
  
  Automaton mi_automata(input_NFA);

  std::string cadena_auxiliar;
  cadenas >> cadena_auxiliar;
    while (cadenas) {
    Cadena cadena_bien(cadena_auxiliar);
      if (mi_automata.IsAccepted(cadena_bien)) {
        std::cout << cadena_bien.GetCadena() << " --- Acepted\n";
      } else {
        std::cout << cadena_bien.GetCadena() << " --- Rejected\n";
      }
      cadenas >> cadena_auxiliar;
    }

  return 0;
}