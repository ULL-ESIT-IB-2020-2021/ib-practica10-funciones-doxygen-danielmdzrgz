/**
* Universidad de La Laguna
* Escuela Superior de Ingeniería y Tecnología
* Grado en Ingeniería Informática
* Asignatura: Informática Básica
* Curso: 1º
*
* @brief cripto.cc functions declaration
*/

#include <string>
#include <vector>

const std::string kHelpText;

void Usage(int argc, char *argv[]);

std::vector<std::string> InputFileSentences(std::string kFileName);

int CounterOfE(std::vector<std::string> input_file_sentences);

std::vector<std::string> XorEncryptionDecryption(std::string kPassword, std::vector<std::string> input_file_sentences);

std::vector<std::string> CaesarEncryption(std::vector<std::string> input_file_sentences, std::string password);

std::vector<std::string> CaesarDecryption(std::vector<std::string> input_file_sentences, std::string password);

void OutputFileWritting(std::string kOutputFileName, std::vector<std::string> encrypted_decrypted_vector);

void Menu(std::string kOutputFileName, int kMethod, std::string kPassword, std::string kOperation, std::vector<std::string> input_file_sentences);