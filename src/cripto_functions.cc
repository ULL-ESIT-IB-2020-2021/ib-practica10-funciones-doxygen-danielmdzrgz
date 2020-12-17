/**
* Universidad de La Laguna
* Escuela Superior de Ingeniería y Tecnología
* Grado en Ingeniería Informática
* Asignatura: Informática Básica
* Curso: 1º
*
* @brief cripto.cc functions definition
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>

/**
* It is not a function.
* A string used in the next function when a certain parameter is introduced. 
*/

const std::string kHelpText {
"cripto -- Encryption of files\n\
Usage: ./cripto input_file output_file method password operation\n\
\n\
input_file:   File to encrypt\n\
output_file:  Encrypted file\n\
method:       Method of encryption:\n\
                  1: Xor encryption\n\
                  2: Caesar encryption\n\
password:     Secret word in case of the first method, Value of constant K in case of the second method.\n\
operation:    Operation to be done in the file:\n\
                  +: encrypt the file\n\
                  -: decrypt the file\n"
};

/**
* Assures the program can function correctly with the exact number of parameters
* and shows a help text y the parameter '--help' is introduced, in which an extense
* explanation of the functioning and introduction of parameters is held.
*
* @param argc, number of parameters introduced by command line.
* @param argv, values of those parameters.
* @return It is a void function so it does not return nothing.
*/

void Usage(int argc, char *argv[]) {
  if((argc == 2) && (strcmp(argv[1], "--help") == 0)) {
    std::cout << kHelpText << std::endl;
    exit(EXIT_SUCCESS);
  }
  else if(argc != 6) {
    std::cout << 
    "cripto -- Encryption of files\n\
Usage: ./cripto input_file output_file method password operation\n\
Try './cripto --help' for more information\n";
    exit(EXIT_SUCCESS);
  }
}

/**
* First it assures that the input file can be opened and read, if not the execution
* of the progra finishes.Then it opens the file for reading and introduces each line 
* into a strings vector.
*
* @param kInputFileName, string with the input file name.
* @return Returns a vector with all the sentences of the input file.
*/

std::vector<std::string> InputFileSentences(std::string kInputFileName) {
  std::ifstream input_file(kInputFileName);
  std::vector<std::string> input_file_sentences;
  std::string input_file_words;
  if(!input_file) {
    std::cout << "Oops an error ocurred while trying to open the input file" << std::endl;
    exit(EXIT_SUCCESS);
  }
  else if(input_file.is_open()) {
    while(getline(input_file, input_file_words)) {
      input_file_sentences.emplace_back(input_file_words);
    }
    input_file.close();
  }
  return input_file_sentences;
}

/**
* Counts the numebr of lower case 'e' that figures in the input file.
*
* @param input_file_sentences, vector with the sentences of the input file.
* @returns Returns a counter with the number of 'e' in the file.
*/

int CounterOfE(std::vector<std::string> input_file_sentences) {
  int counter_letter_e {0};
  for(auto sentences : input_file_sentences) {
    for(auto words : sentences) {
      std::stringstream transform_c_to_s;
      transform_c_to_s << words;
      std::string word_to_analyse = transform_c_to_s.str();
      for(auto i = 0; i < word_to_analyse.length(); i++)
      if (word_to_analyse[i] == 'e') counter_letter_e++;
    }
  }
  return counter_letter_e;
}

/**
* He intentado de todo pero no he logrado hacer que la funcionalidad para 
* encriptar o desencriptar en XOR se ejecute si errores. Dejo comentado el código 
* de la función debajo por si me podrían dar alguna indicación de como resolverlo.
*/ 

/**
std::vector<std::string> XorEncryptionDecryption(std::string kPassword, std::vector<std::string> input_file_sentences) {
  std::vector<std::string> xored_text;
  int password_length = kPassword.length();
  char password[password_length + 1];
  strcpy(password, kPassword.c_str());
  int counter = 0;
  for(std::string sentence : input_file_sentences) {
    std::string input_sentence = sentence;
    for(std::string word : input_sentence) {
      int word_length = word.length();
      char xor_word[word_length + 1];
      strcpy(xor_word, word.c_str());
      for(int i = 0; i < word_length; ++i) {
        xor_word[i] = xor_word[i] ^ password[counter];
        if(++counter >= password_length) {counter = 0;}
        else{++counter;}
      }
      xored_text.emplace_back(xor_word);
    }
  }
  return xored_text;
}
*/

/**
* Caesar method encription changes a character in the 'n' position of the alphabet
* for the 'n + key' character of the alphabet. This function takes aech word from the 
* vector with the sentences of the file and replaces each character following the Caesar
* encryption mode. 
*
* @param input_file_sentences, vector with the sentences of the input file.
* @param password, string with the number that is used as a key y caesar encryprion.
* @return Returns a vector with the encrypted text.
*/

std::vector<std::string> CaesarEncryption(std::vector<std::string> input_file_sentences, std::string password) {
  std::vector<std::string> caesar_encrypted_vector;
  auto kPassword = stoi(password);
  for(auto sentence : input_file_sentences) {
    std::string encrypted_sentence;
    for(auto word : sentence) {
      int word_to_caesar = word + kPassword;
      encrypted_sentence += word_to_caesar;
    }
    caesar_encrypted_vector.emplace_back(encrypted_sentence);
  }
  return caesar_encrypted_vector;
}

/**
* This function does the same as the previos one but with decryption in Caesar method. 
*
* @param input_file_sentences, vector with the sentences of the input file.
* @param password, string with the number that is used as a key y caesar encryprion.
* @return Returns a vector with the decrypted text.
*/

std::vector<std::string> CaesarDecryption(std::vector<std::string> input_file_sentences, std::string password) {
  std::vector<std::string> caesar_decrypted_vector;
  int kPassword = stoi(password);
  for(auto sentence : input_file_sentences) {
    std::string decrypted_sentence;
    for(auto word : sentence) {
      int caesar_to_word = word - kPassword;
      decrypted_sentence += caesar_to_word;
    }
    caesar_decrypted_vector.emplace_back(decrypted_sentence);
  }
  return caesar_decrypted_vector;
}

/**
* Writes in the output file all the encrypted or decrypted sentences held in the vector
* which is passed as a parameter.
*
* @param kOutputFileName, string with the output file name.
* @param encrypted_decrypted_vector, vector of strings with the encrypted/decrypted text.
* @return It is a void function so it does not return nothing.
*/

void OutputFileWritting(std::string kOutputFileName, std::vector<std::string> encrypted_decrypted_vector) {
  std::ofstream output_file(kOutputFileName);
  for(auto sentences : encrypted_decrypted_vector) {
    output_file << sentences << "\n";
  }
}

/**
* Just a 'menu' that calls the rest of functions to make the main()
* function cleaner. 
*
+ @param kOutputFileName, string with the name of the output file.
* @param kMethod, number which refers to the type of encryptio/decryption to use.
* @param kPassword, characters or a number wether you select Xor or Caesar.
* @param kOperation, indicates the method selected to encrypt/decrypt.
* @param input_file_sentences, vector with the sentences of the input file.
* @return It is a void function so it does not return nothing.
*/

void Menu(std::string kOutputFileName, int kMethod, std::string kPassword, std::string kOperation, std::vector<std::string> input_file_sentences) {
  if(kMethod == 1) {
    if(kOperation == "+") {
      std::cout << "Xor encryption/decryption is not currently available.\
Check source code for more information.\n";
    }
    else if(kOperation == "-") {
      std::cout << "Xor encryption/decryption is not currently available.\
Check source code for more information.\n";
    }
  }
  else if(kMethod == 2) {
    if(kOperation == "+") {
      std::vector<std::string> encrypted_vector = CaesarEncryption(input_file_sentences, kPassword);
      OutputFileWritting(kOutputFileName, encrypted_vector);
      std::cout << "This is your Caesar encrypted text: \n\n";
      for(auto encrypted_words : encrypted_vector) {
        std::cout << encrypted_words << std::endl;;
      }
      std::cout << "\nYou can find it also in " << kOutputFileName << "\n";
    }
    else if(kOperation == "-") {
      std::vector<std::string> decrypted_vector = CaesarDecryption(input_file_sentences, kPassword);
      OutputFileWritting(kOutputFileName, decrypted_vector);
      std::cout << "This is your Caesar decrypted text: \n\n";
      for(auto decrypted_words : decrypted_vector) {
        std::cout << decrypted_words << std::endl;;
      }
      std::cout << "\nYou can find it also in " << kOutputFileName << "\n";
    }
  }
}