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
#include "cadena.h"

Automaton::Automaton(std::ifstream& automaton_file) {
  std::string cadena_auxiliar;
  cadena_auxiliar.clear();
  alphabet_.Clear();
  std::getline(automaton_file, cadena_auxiliar);
  for (char caracter: cadena_auxiliar) {
    if (caracter == '&') {
      std::cerr << "Carácter inválido";
      exit(EXIT_SUCCESS);
    }
    alphabet_.Insert(caracter);                     // Alfabeto
  }
  alphabet_.ReadAlphabet();
  std::getline(automaton_file, cadena_auxiliar);
  number_of_states_ = stoi(cadena_auxiliar);        // Número de estados

  std::getline(automaton_file, cadena_auxiliar);
  initial_state_ = stoi(cadena_auxiliar);           // Estado inicial

  std::set<int> estados_a_los_que_transitas;
  std::set<int> estados_del_automata;
  int contador{0};
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
    estados_del_automata.insert(state_id);
    for (int j{0}; j < number_of_transitions; ++j) {
      char symbol;
      int destination_state;
      automaton_file >> symbol >> destination_state;
      estados_[state_id].AddTransition(symbol, destination_state);
      estados_a_los_que_transitas.insert(destination_state);
    }
    contador++;
  }
  if (contador != number_of_states_) {
    std::cerr << "Error en la especificación de los estados";
    exit(EXIT_SUCCESS);
  }
  for (int estado : estados_a_los_que_transitas) {
    if(estados_del_automata.find(estado) == estados_del_automata.end()) {
      std::cerr << "Los estados a los que se transita deben ser estados que forman parte del propio automata";
      exit(EXIT_SUCCESS);
    }
  }
}



bool Automaton::IsAccepted(Cadena& cadena_de_entrada) {
  std::set<int> current_states;
  std::set<int> next_states;
  std::set<int> empty_transitions;
  std::string cadena_bien = cadena_de_entrada.GetCadena();
  current_states.insert(initial_state_);
  empty_transitions = estados_[initial_state_].CheckEmptyTransitions();
  current_states.insert(empty_transitions.begin(), empty_transitions.end());
  for (char symbol : cadena_bien) {
    if (alphabet_.Pertenece(symbol) == true) {
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
    } else {
      std::cerr << "Los sımbolos de las transiciones deben ser sımbolos del alfabeto sobre el que se define el automata.";
      exit(EXIT_SUCCESS);
    }
  }

  for (int state : current_states) {
    if (estados_[state].Final()) return true;
  }

  return false;
}
