/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 2: Cadenas y Lenguajes
 * Autor: Raúl Navarro Cobos
 * Correo: alu0101484365@ull.edu.es
 * Fecha: 20/09/2026
 * Archivo Chain.h: programa donde se declara la clase Chain
 * Historial de revisiones:
 *   20/09/2026 - Creación del código
 */

#pragma once

#include "alphabet.h"

#include <iostream>
#include <string>

class Language;

/**
 * @brief Clase que representa una cadena formal sobre un alfabeto
 */
class Chain {
 // Métodos
 public:
  // Constructor por defecto
  Chain();
  // Constructor parametrizado para asignar cadena y alfabeto
  Chain(const std::string& sequence, const Alphabet& alphabet);
  // Getter
  std::string GetSequence() const;
  Alphabet GetAlphabet() const;
  // OPCODE
  size_t Length() const; // Método 2
  Chain Reverse() const; // Método 3
  Language Prefixes() const; // Método 4
  Language Suffixes() const; // Método 5
  bool IsValid() const; // Método 6
  // Modificación
  Chain RemoveChar(char char_deleted) const; // Método 7
  // Sobrecarga del operador de salida
  friend std::ostream& operator<<(std::ostream& os, const Chain& chain);
  bool operator<(const Chain& other) const;
 // Atributos
 private:
  std::string sequence_;  // Secuencia de caracteres de la cadena
  Alphabet alphabet_;  // Alfabeto asociado a la cadena
};