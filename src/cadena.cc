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
#include "Alphabet.h"
#include "cadena.h"

/**
 * Constructor de la clase cadena
 * @param cadena_de_entrada
*/
Cadena::Cadena(std::string& cadena_de_entrada) {
  cadena_ = cadena_de_entrada;
  for (char caracter: cadena_de_entrada) {
    alfabeto_asociado.Insert(caracter);              
  }
}

/**
 * Getter de la cadena
 * @return cadena_
*/
std::string Cadena::GetCadena() {
  return cadena_;
}

/**
 * Getter del alfabeto
 * @return alfabeto_asociado_
*/
Alphabet Cadena::GetAlfabeto() {
  return alfabeto_asociado;
}