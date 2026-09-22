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
 * Archivo Chain.cc: programa donde se define la clase Chain
 * Historial de revisiones:
 *   21/09/2026 - Creación del código
 */

#include "chain.h"
#include "language.h"


/**
 * @brief Constructor por defecto de la clase Chain
 */
Chain::Chain() : sequence_("&"), alphabet_() {}

/**
 * @brief Constructor parametrizado de la clase Chain
 * @param sequence Secuencia de caracteres
 * @param alphabet Alfabeto asociado
 */
Chain::Chain(const std::string& sequence, const Alphabet& alphabet)
    : sequence_(sequence), alphabet_(alphabet) {}

/**
 * @brief Devuelve la secuencia de caracteres de la cadena
 * @return std::string Secuencia textual
 */
std::string Chain::GetSequence() const {
  return sequence_;
}

/**
 * @brief Devuelve el alfabeto asociado a la cadena
 * @return Alphabet Objeto alfabeto
 */
Alphabet Chain::GetAlphabet() const {
  return alphabet_;
}

/**
 * @brief Devuelve la longitud de la cadena
 * @return size_t Longitud (0 si es la cadena vacía '&')
 */
size_t Chain::Length() const {
  if (sequence_ == "&") {
    return 0;
  }
  return sequence_.length();
}

/**
 * @brief Comprueba si la cadena está definida sobre su alfabeto
 * @return true si es válida, false en caso contrario
 */
bool Chain::IsValid() const {
  if (sequence_ == "&") {
    return true;
  }
  for (char symbol : sequence_) {
    if (!alphabet_.Validation(symbol)) {
      return false;
    }
  }
  return true;
}

/**
 * @brief Devuelve la cadena invertida (Opcode 3)
 * @return Chain Cadena invertida con el mismo alfabeto
 */
Chain Chain::Reverse() const {
  if (sequence_ == "&") {
    return Chain("&", alphabet_);
  }
  std::string reversed_seq = "";
  for (int i = sequence_.length() - 1; i >= 0; --i) {
    reversed_seq += sequence_[i];
  }
  return Chain(reversed_seq, alphabet_);
}

/**
 * @brief Genera el conjunto de prefijos de la cadena (Opcode 4)
 * @return Language Lenguaje contenedor de todos los prefijos
 */
Language Chain::Prefixes() const {
  Language prefixes;
  // La cadena vacía '&' siempre es el primer prefijo
  prefixes.AddChain(Chain("&", alphabet_));

  if (sequence_ != "&") {
    for (size_t i = 1; i <= sequence_.length(); ++i) {
      std::string sub = sequence_.substr(0, i);
      prefixes.AddChain(Chain(sub, alphabet_));
    }
  }
  return prefixes;
}

/**
 * @brief Genera el conjunto de sufijos de la cadena (Opcode 5)
 * @return Language Lenguaje contenedor de todos los sufijos
 */
Language Chain::Suffixes() const {
  Language suffixes;
  // La cadena vacía '&' siempre es el primer sufijo
  suffixes.AddChain(Chain("&", alphabet_));

  if (sequence_ != "&") {
    for (size_t i = 0; i < sequence_.length(); ++i) {
      std::string sub = sequence_.substr(i);
      suffixes.AddChain(Chain(sub, alphabet_));
    }
  }
  return suffixes;
}

/**
 * @brief Compara dos cadenas alfabéticamente para ordenación en std::set
 * @param other Cadena con la que se compara
 * @return true si esta cadena es menor que other
 */
bool Chain::operator<(const Chain& other) const {
  if (Length() != other.Length()) {
    return Length() < other.Length();
  }
  return sequence_ < other.sequence_;
}
/**
 * @brief Sobrecarga del operador de salida para escribir la cadena
 * @param os Flujo de salida
 * @param chain Cadena a imprimir
 * @return std::ostream& Referencia al flujo
 */
std::ostream& operator<<(std::ostream& os, const Chain& chain) {
  os << chain.sequence_;
  return os;
}