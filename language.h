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
 * Archivo language.h: programa donde se declara la clase Language.
 * Historial de revisiones:
 *   21/09/2026 - Creación del código
 */

#pragma once

#include "chain.h"

#include <iostream>
#include <set>

/**
 * @brief Clase que representa un lenguaje formal
 */
class Language {
 // Métodos
 public:
  // Constructor por defecto
  Language();
  // Getter tamaño lenguaje
  size_t Size() const;
  // Insertar cadena al lenguaje
  void AddChain(const Chain& chain);
  // Sobrecarga del operador de salida
  friend std::ostream& operator<<(std::ostream& os, const Language& language);
 // Atributos
 private:
  std::set<Chain> chains_;
};