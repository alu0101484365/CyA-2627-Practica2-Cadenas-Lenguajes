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
 * Archivo alphabet.h: programa donde se declara la clase Alphabet
 * Historial de revisiones:
 *   20/09/2026 - Creación del código
 */

#pragma once

#include <iostream>
#include <set>

/**
 * @brief Clase que representa un alfabeto
 */
class Alphabet {
  // Métodos
 public:
  // Constructor
  Alphabet();
  // Getter tamaño
  size_t Size() const;
  // Guardar lenguaje
  void AddSymbol(char symbol);
  // Validación
  bool Validation(char symbol) const;
  // Sobrecarga del operador de salida
  friend std::ostream& operator<<(std::ostream& os, const Alphabet& alphabet);
  // Atributos
 private:
  std::set<char> symbols_;
};