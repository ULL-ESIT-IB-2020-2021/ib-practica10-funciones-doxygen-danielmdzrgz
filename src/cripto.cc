/**
* Universidad de La Laguna
* Escuela Superior de Ingeniería y Tecnología
* Grado en Ingeniería Informática
* Informática Básica
*
* @file cipto.cc
* @author Daniel Méndez alu0101391793@ull.edu.es
* @date 16 Dic 2020
* @brief Desarrolle en C++ un programa cripto.cc cuya finalidad será encriptar y/o 
*        desencriptar ficheros de texto. El programa solo se ejecutará cuando se le 
*        hayan pasado por línea de comandos los parámetros necesarios. En caso de 
*        detectar cualquier inconsistencia en los parámetros, el programa debe abortar 
*        su ejecución. Se indicará asimismo un mensaje de error si el programa no 
*        consigue abrir el fichero de entrada.
* @bug No hay bugs conocidos
* @see https://github.com/ULL-ESIT-IB-2020-2021/IB-P10-Files-Doxygen.git 
* @see https://github.com/ULL-ESIT-IB-2020-2021/ib-practica10-funciones-doxygen-danielmdzrgz.git
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "cripto_functions.h"

int main(int argc, char* argv[]) {
  Usage(argc, argv);

  const std::string kInputFileName = argv[1];
  const std::string kOutputFileName = argv[2];

  std::string method = argv[3];
  const int kMtethod = stoi(method);
  if((kMtethod != 1) && (kMtethod != 2)) {
    std::cerr << "ERROR: Wrong method introduced.\n\
Try './cripto --help' for more information.\n";
    exit(EXIT_SUCCESS);
  }

  const std::string kPassword = argv[4];

  const std::string kOperation = argv[5];
  if((kOperation != "+") && (kOperation != "-")) {
    std::cerr << "ERROR: Wrong operation introduced.\n\
Try './cripto --help' for more information.\n";
    exit(EXIT_SUCCESS);
  }

  std::vector<std::string> input_file_sentences = InputFileSentences(kInputFileName);
  
  Menu(kOutputFileName, kMtethod, kPassword, kOperation, input_file_sentences);
  return 0;
}