/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 1: Contenedores asociativos
 * Autor: Raúl Navarro Cobos
 * Correo: alu0101484365@ull.edu.es
 * Fecha: 10/09/2026
 * Archivo alphabet.cc: programa donde se definen los métodos la clase Alphabet
 * Historial de revisiones:
 *   20/09/2026 - Creación del código
 */ 

#include "alphabet.h"

/**
 * @brief Constructor por defecto de Alphabet
 */
Alphabet::Alphabet() {}

/**
 * @brief Devuelve la cantidad de símbolos que forman el alfabeto
 * @return size_t Número de símbolos únicos
 */
size_t Alphabet::Size() const {
  return symbols_.size();
}

/**
 * @brief Añade un nuevo símbolo al alfabeto
 * @param symbol Simbolo a insertar
 */
void Alphabet::AddSymbol(char symbol) {
  symbols_.insert(symbol);
}

/**
 * @brief Comprueba si un símbolo pertenece al alfabeto
 * @param symbol Carácter a verificar
 * @return true si pertenece, false en caso contrario
 */
bool Alphabet::Validation(char symbol) const {
  return symbols_.count(symbol) > 0;
}

/**
 * @brief Sobrecarga del operador de salida para imprimir el alfabeto
 * @param os Flujo de salida
 * @param alphabet Objeto alfabeto a imprimir
 * @return std::ostream& os -> Referencia al flujo de salida
 */
std::ostream& operator<<(std::ostream& os, const Alphabet& alphabet) {
  os << "{ ";
  for (char symbol : alphabet.symbols_) {
    os << symbol << " ";
  }
  os << "}";
  return os;
}