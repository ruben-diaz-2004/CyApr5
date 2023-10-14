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
#include <set>
#include "Alphabet.h"

Alphabet::Alphabet() {
  alphabet_.clear();
}

void Alphabet::Insert(char symbol) {
  alphabet_.insert(symbol);
}

void Alphabet::ReadAlphabet() {
  for (char symbol : alphabet_) {
    std::cout << symbol << " ";
  }
  std::cout << std::endl;
}