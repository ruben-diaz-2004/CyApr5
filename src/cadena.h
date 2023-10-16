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
#ifndef CADENA_H_
#define CADENA_H_

#include <iostream>
#include "Alphabet.h"

class Cadena {
  public:
  Cadena(std::string& cadena_de_entrada);
  std::string GetCadena();
  Alphabet GetAlfabeto();
  
  private:
  std::string cadena_{0};
  Alphabet alfabeto_asociado;

};


#endif