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
#ifndef SRTRINGS_H_
#define SRTRINGS_H_

#include <iostream>
#include <fstream>
#include <map>
#include <set>


class State {
public:
//  State(int state_id, int is_final, int number_of_transitions);
  void SetFinal(int is_final);
  void SetNumOfTransitions(int number_of_transitions);
  int Transitions_Count() const { return number_of_transitions_; }
  bool Final();
  void AddTransition(char symbol, int destination);
  std::set<int> Transitioned_States(char symbol);
  std::set<int> CheckEmptyTransitions();
private:
  int state_id_{0};
  int is_final_;
  int number_of_transitions_{0};
  std::map<char, std::set<int>> transitions;
};


#endif