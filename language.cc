/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 2: Cadenas y Lenguajes
 * Autor: Raúl Navarro Cobos
 * Correo: alu0101484365@ull.edu.es
 * Fecha: 21/09/2026
 * Archivo language.cc: programa donde se definee la clase Language.
 * Historial de revisiones:
 *   21/09/2026 - Creación del código
 */

#include "language.h"

/**
 * @brief Constructor por defecto de la clase Language
 */
Language::Language() {}

/**
 * @brief Devuelve el número de cadenas que componen el lenguaje
 * @return size_t Cardinal del conjunto de cadenas
 */
size_t Language::Size() const {
  return chains_.size();
}

/**
 * @brief Inserta una nueva cadena en el lenguaje
 * @param chain Cadena a añadir
 */
void Language::AddChain(const Chain& chain) {
  chains_.insert(chain);
}

/**
 * @brief Sobrecarga del operador de salida para imprimir el lenguaje
 * @param os Flujo de salida
 * @param language Objeto lenguaje a imprimir
 * @return std::ostream& Referencia al flujo
 */
std::ostream& operator<<(std::ostream& os, const Language& language) {
  os << "{";
  bool first = true;
  for (const Chain& chain : language.chains_) {
    if (!first) {
      os << ", ";
    }
    os << chain;
    first = false;
  }
  os << "}";
  return os;
}