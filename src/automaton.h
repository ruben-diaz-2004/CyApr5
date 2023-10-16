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
#ifndef AUTOMATON_H_
#define AUTOMATON_H_

#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include "cadena.h"
#include "state.h"
#include "Alphabet.h"


class Automaton {
public:
  Automaton(std::ifstream& automaton_file);
  int GetNumberOfStates() const { return number_of_states_; }
  int GetInitialState() const { return initial_state_; }
  Alphabet GetAlphabet() const { return alphabet_; }
  bool IsAccepted(Cadena& cadena_de_entrada);

private:
  int number_of_states_;
  int initial_state_;
  Alphabet alphabet_;
  std::map<int, State> estados_;

};

#endif