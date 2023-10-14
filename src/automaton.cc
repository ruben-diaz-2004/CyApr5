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

#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <assert.h>
#include "automaton.h"
#include "state.h"

Automaton::Automaton(std::ifstream& automaton_file) {
  std::string cadena_auxiliar{""};
  std::getline(automaton_file, cadena_auxiliar);
  for (char caracter: cadena_auxiliar) {
    alphabet_.Insert(caracter);                     // Alfabeto
  }
  alphabet_.ReadAlphabet();
  std::getline(automaton_file, cadena_auxiliar);
  number_of_states_ = stoi(cadena_auxiliar);        // Número de estados

  std::getline(automaton_file, cadena_auxiliar);
  initial_state_ = stoi(cadena_auxiliar);           // Estado inicial

  for (int i{0}; i < number_of_states_; ++i) {
    int state_id;
    int is_final;
    int number_of_transitions;
    automaton_file >> state_id >> is_final >> number_of_transitions;
    // State new_state(state_id, is_final, number_of_transitions);
    State new_state;
    new_state.SetFinal(is_final);
    new_state.SetNumOfTransitions(number_of_transitions);
    estados_[state_id] = new_state;

    for (int j{0}; j < number_of_transitions; ++j) {
      char symbol;
      int destination_state;
      automaton_file >> symbol >> destination_state;
      estados_[state_id].AddTransition(symbol, destination_state);
    }
  }
}



bool Automaton::IsAccepted(const std::string& cadena_de_entrada) {
  std::set<int> current_states;
  std::set<int> next_states;
  std::set<int> empty_transitions;

  current_states.insert(initial_state_);

  for (char symbol : cadena_de_entrada) {
    next_states.clear();  
    for (int state : current_states) {
      std::set<int> transitioned_states = estados_[state].Transitioned_States(symbol);
      empty_transitions = estados_[state].CheckEmptyTransitions();
      
      for (int destination : empty_transitions) {
        transitioned_states.insert(destination);
      }
      
      next_states.insert(transitioned_states.begin(), transitioned_states.end());
    }
    current_states = next_states;
  }

  for (int state : current_states) {
    if (estados_[state].Final()) return true;
  }

  return false;
}
