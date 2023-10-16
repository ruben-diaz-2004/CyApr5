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

/**
 * Constructor de la clase Alphabet
*/
Alphabet::Alphabet() {
  alphabet_.clear();
}

/**
 * Método que inserta un símbolo en el alfabeto
 * @param symbol
*/
void Alphabet::Insert(char symbol) {
  alphabet_.insert(symbol);
}


/**
 * Método para imprimir el alfabeto
*/
void Alphabet::ReadAlphabet() {
  for (char symbol : alphabet_) {
    std::cout << symbol << " ";
  }
  std::cout << std::endl;
}


/**
 * Método que limpia el alfabeto
*/
void Alphabet::Clear() {
  alphabet_.clear();
}


/**
 * Método que comprueba si un símbolo pertenece al alfabeto
 * @param symbol
 * @return true si el símbolo pertenece al alfabeto
*/
bool Alphabet::Pertenece(char symbol) {
  if (symbol == '&') return true;
  for (char aux_symbol : alphabet_) {
    if (aux_symbol == symbol) return true;
  }
  return false;
}