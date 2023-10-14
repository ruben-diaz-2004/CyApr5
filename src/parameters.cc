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


/**
 * Comprueba que al programa se le pasen los parámetros adecuados
 * @param argc, número de argumentos
 * @param argv, cada argumento que se le pasa al programa
 * @param KcorrectNumber, número correcto de parámetros
 * @return true, si todo funciona bien.
*/
bool CheckCorrectParameters(const int argc, char* argv[], const int kCorrectNumber) {
  if (argc > 1) {
    std::string parameter{argv[1]};
    if (parameter == "--help") {
      std::cout << "Modo de uso: ./p02_strings filein.txt fileout.txt opcode" << std::endl << std::endl;
      std::cout << "El fichero de entrada debe ser un fichero de texto (.txt) que contenga la ";
      std::cout << "especificacion de las cadenas" << std::endl;
      std::cout << "Por su parte, el fichero fileout tambien debe ser un fichero de texto (.txt) en ";
      std::cout << "el que se imprimira la salida del programa" << std::endl;
      std::cout << "Por ultimo el opcode se trata de un numero entre el 1 y el 5 que especifica la operacion que se quiere realizar." << std::endl;
      std::cout << "1 para imprimir los lenguajes." << std::endl;
      std::cout << "2 para imprimir la longitud de las cadenas." << std::endl;
      std::cout << "3 para imprimir la inversa de las cadenas." << std::endl;
      std::cout << "4 para imprimir los posibles prefijos de las cadenas" << std::endl;
      std::cout << "5 para imprimir los posibles sufijos de las cadenas" << std::endl;
      std::cout << std::endl << std::endl;
      exit(EXIT_SUCCESS);
    }
  }
  if (argc != kCorrectNumber) {
  std::cout << "Modo de uso: ./p02_strings filein.txt fileout.txt opcode" << std::endl;
  std::cout << "Pruebe ./p02_strings --help para más información" << std::endl;
    exit(EXIT_SUCCESS);
  }
  return true;
}
