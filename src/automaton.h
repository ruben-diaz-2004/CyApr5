/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia 2023-2024
  *
  * @author Rubén Díaz Marrero 
  * @date 22/09/2023
  * @brief Este programa lee ficheros de texto que contienen especificaciones de
  * cadenas junto con sus respectivos alfabetos. Y es capaz de realizar varias 
  * comprobaciones básicas sobre ellas
  */
#ifndef STRINGS_H_
#define STRINGS_H_

#include <iostream>
#include <fstream>
#include <map>
#include <set>

#include "state.h"
#include "Alphabet.h"


class Automaton {
public:
  Automaton(std::ifstream& automaton_file);

  bool IsAccepted(const std::string& cadena_de_entrada);

private:
  int number_of_states_;
  Alphabet alphabet_;
  int initial_state_;
  std::map<int, State> estados_;

};

#endif