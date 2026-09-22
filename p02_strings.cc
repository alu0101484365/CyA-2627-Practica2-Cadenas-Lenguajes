/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 2: Cadenas y Lenguajes
 * Autor: Raúl Navarro Cobos
 * Correo: alu0101484365@ull.edu.es
 * Fecha: 22/09/2026
 * Archivo p02_strings.cc: programa cliente principal
 * Historial de revisiones:
 *   22/09/2026 - Creación del código
 */

#include "alphabet.h"
#include "chain.h"
#include "language.h"

 #include <fstream>
#include <iostream>
#include <sstream>
#include <string>


/**
 * @brief Muestra el mensaje de ayuda en pantalla (--help)
 */
void ShowHelp() {
  std::cout << "Modo de empleo: ./p02_strings filein.txt fileout.txt opcode\n\n";
  std::cout << "Descripción:\n";
  std::cout << "  Lee cadenas y sus alfabetos asociados desde filein.txt, aplica\n";
  std::cout << "  la operación especificada por opcode y escribe el resultado en fileout.txt.\n\n";
  std::cout << "Formatos de fichero:\n";
  std::cout << "  Fichero de entrada (filein.txt): cada línea contiene <cadena> <alfabeto>\n";
  std::cout << "  Ejemplo: abbab ab\n\n";
  std::cout << "Códigos de operación (opcode):\n";
  std::cout << "  1 : Alfabeto -> Muestra el alfabeto asociado a la cadena\n";
  std::cout << "  2 : Longitud -> Muestra la longitud de la cadena\n";
  std::cout << "  3 : Inversa  -> Muestra la cadena invertida\n";
  std::cout << "  4 : Prefijos -> Muestra el conjunto de prefijos (lenguaje)\n";
  std::cout << "  5 : Sufijos  -> Muestra el conjunto de sufijos (lenguaje)\n";
  std::cout << "  6 : Validar  -> Comprueba si la cadena es válida sobre su alfabeto (OK/ERROR)\n";
}

/**
 * @brief Procesa el archivo de entrada y aplica el opcode correspondiente
 * @param input_name Nombre del archivo de entrada
 * @param output_name Nombre del archivo de salida
 * @param opcode Código de operación a ejecutar (1 a 6)
 * @return true si el procesamiento fue exitoso, false si ocurrió un error
 */
bool ProcessFile(const std::string& input_name, const std::string& output_name, int opcode) {
  std::ifstream input_file(input_name);
  if (!input_file.is_open()) {
    std::cerr << "Error: No se pudo abrir el fichero de entrada: " << input_name << "\n";
    return false;
  }
  std::ofstream output_file(output_name);
  if (!output_file.is_open()) {
    std::cerr << "Error: No se pudo crear/abrir el fichero de salida: " << output_name << "\n";
    return false;
  }
  std::string line;
  while (std::getline(input_file, line)) {
    if (line.empty()) {
      continue;
    }
    std::stringstream ss(line);
    std::string sequence_str, alphabet_str;
    ss >> sequence_str >> alphabet_str;
    Alphabet alphabet;
    for (char symbol : alphabet_str) {
      alphabet.AddSymbol(symbol);
    }
    Chain chain(sequence_str, alphabet);
    switch (opcode) {
      case 1:
        output_file << chain.GetSequence() << ": " << chain.GetAlphabet() << "\n";
        break;
      case 2:
        output_file << chain.Length() << "\n";
        break;
      case 3:
        output_file << chain.GetSequence() << " -> " << chain.Reverse() << "\n";
        break;
      case 4:
        output_file << chain.Prefixes() << "\n";
        break;
      case 5:
        output_file << chain.Suffixes() << "\n";
        break;
      case 6:
        if (chain.IsValid()) {
          output_file << "OK\n";
        } else {
          output_file << "ERROR\n";
        }
        break;
      default:
        std::cerr << "Error: Código de operación 'opcode' no válido (debe ser de 1 a 6).\n";
        return false;
    }
  }

  return true;
}

/**
 * @brief Función principal del programa
 * @param argc Número de argumentos
 * @param argv Vector de argumentos
 * @return int Estado de salida del programa
 */
int main(int argc, char* argv[]) {
  if (argc == 2 && std::string(argv[1]) == "--help") {
    ShowHelp();
    return 0;
  }
  if (argc != 4) {
    std::cout << "Modo de empleo: ./p02_strings filein.txt fileout.txt opcode\n";
    std::cout << "Pruebe './p02_strings --help' para más información.\n";
    return 1;
  }
  std::string input_filename = argv[1];
  std::string output_filename = argv[2];
  int opcode = std::stoi(argv[3]);
  // Procesamiento del fichero
  if (!ProcessFile(input_filename, output_filename, opcode)) {
    return 1;
  }
  return 0;
}