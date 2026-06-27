#include <iostream>
#include <ostream>
#include <stdexcept>

#ifndef _DYNAMICARRAY_
#define _DYNAMICARRAY_

class DynIntArray {
private:
  int size;
  int *data;

public:
  DynIntArray();
  DynIntArray(const int arr[], int size);
  // Evitamos que si intentamos crear una copia, usamos deepcopy
  // Para copiar los datos y no el puntero, que provocaría un doble free()
  DynIntArray(const DynIntArray &other);
  ~DynIntArray();

  // métodos
  void push_back(int val);
  void remove(int pos);
  void insert(int pos, int val);

  // Métodos getters
  int getSize() const;

  // Sobrecarga de operadores
  // Acceso y un valor de un índice
  int &operator[](int index);
  DynIntArray &operator=(DynIntArray &other);
};

std::ostream &operator<<(std::ostream &os, DynIntArray &dynarr);

#endif
