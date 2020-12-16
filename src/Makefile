# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Informática Básica
#
# @author Daniel Méndez
# @date 16 Dic 2020
# @brief A Makefile for cripto.cc program

CXX = g++
CXXFLAGS = -std=c++14 -g -Wall

.PHONY: all clean

all: cripto

cripto: cripto_functions.o cripto.o
	$(CXX) $(CXXFLAGS) -o $@ $^ 
	$(CXX) $(CXXFLAGS) -c $<

clean :
	rm -f cripto *.o
	rm -rf *~ basura b i