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

#ifndef _ALPHABET_H
#define _ALPHABET_H

class Alphabet {
  public:
  Alphabet();
  void Insert(char symbol);
  void ReadAlphabet();

  private:
  std::set<char> alphabet_;
};



#endif