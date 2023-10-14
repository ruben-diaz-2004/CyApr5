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
#include "vector"

#include "state.h"


// State::State(int state_id, int is_final, int number_of_transitions) {
//   state_id_ = state_id;
//   is_final_ = is_final;
//   number_of_transitions_ = number_of_transitions;
// }

void State::SetFinal(int is_final) {
  is_final_ = is_final;
}

void State::SetNumOfTransitions(int number_of_transitions) {
  number_of_transitions_ = number_of_transitions;
}
void State::AddTransition(char symbol, int destination) {
  transitions[symbol].insert(destination);
}

bool State::Final() {
  if (is_final_ == 1) return true;
  return false;
}
std::set<int> State::Transitioned_States(char symbol) {
  return transitions[symbol];
}

std::set<int> State::CheckEmptyTransitions() {
  std::set<int> empty_states;
  empty_states.clear();
  char epsilon{'&'};
  empty_states.insert(transitions[epsilon].begin(), transitions[epsilon].end());
  return empty_states;
}