# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Asignatura: Computabilidad y Algoritmia
# Curso: 2º
# Práctica 2: Cadenas y Lenguajes
# Autor: Raúl Navarro Cobos
# Correo: alu0101484365@ull.edu.es
# Fecha: 22/09/2026
# Archivo Makefile: Automatización de la compilación del proyecto

# Compilador y opciones de compilación
CXX = g++
CXXFLAGS = -std=c++17 -g -Wall -Wextra -pedantic

# Nombre del ejecutable final
TARGET = p02_strings

# Archivos de código fuente y objetos
SRCS = p02_strings.cc alphabet.cc chain.cc language.cc
OBJS = $(SRCS:.cc=.o)

# Regla por defecto: compilar todo
all: $(TARGET)

# Regla para enlazar el ejecutable a partir de los objetos
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regla para compilar cada archivo .cc a un objeto .o
%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla de limpieza: borra ejecutables y archivos objeto intermediate
.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)