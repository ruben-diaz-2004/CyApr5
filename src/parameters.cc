/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia 2023-2024
  *
  * @author Rubén Díaz Marrero 
  * @date 22/09/2023
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
      std::cout << "Modo de uso: ./p05_automaton filein.fa filein.txt" << std::endl << std::endl;
      std::cout << "El fichero de entrada debe ser un fichero con la extensión .fa que contenga la ";
      std::cout << "especificacion del automata" << std::endl;
      std::cout << "Por su parte, el segundo fichero debe ser un fichero de texto (.txt) en ";
      std::cout << "el que se deben incluir las cadenas que debe probar el automata" << std::endl;
      std::cout << std::endl << std::endl;
      exit(EXIT_SUCCESS);
    }
  }
  if (argc != kCorrectNumber) {
  std::cout << "Modo de uso: ./p05_automaton filein.fa filein.txt" << std::endl;
  std::cout << "Pruebe ./p05_automaton --help para más información" << std::endl;
    exit(EXIT_SUCCESS);
  }
  return true;
}
