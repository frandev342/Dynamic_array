#include <initializer_list>
#include <iostream>
#ifndef _DYNAMICARRAY_
#define _DYNAMICARRAY_

class DynIntArray {
private:
  int size;
  int *data;

public:
  DynIntArray();
  DynIntArray(int size);
  DynIntArray(const int arr[], int size);
  // Evitamos que si intentamos crear una copia, usamos deepcopy
  // Para copiar los datos y no el puntero, que provocaría un doble free()
  DynIntArray(const DynIntArray &other);
  // constructor por arreglo, inicializar el objeto por arreglo (por defecto
  // enteros)
  DynIntArray(std::initializer_list<int> arr);
  DynIntArray(DynIntArray &&other) noexcept;
  ~DynIntArray();

  // métodos
  void push_back(int val);
  void remove(int pos);
  void insert(int pos, int val);
  DynIntArray merge(const DynIntArray &other);

  // Métodos getters
  int getSize() const;

  // Sobrecarga de operadores
  // Acceso y un valor de un índice
  // Sobrecarga de [] para escribir y lectura, y otra para solamente lectura
  int &operator[](int index);
  // Necesario para la sobrecarga del operador <<
  const int &operator[](int index) const;
  DynIntArray
  operator+(const DynIntArray &other) const; // SObrecarga del operador +
  DynIntArray
  operator-(const DynIntArray &other) const; // Sobrecarga del operador -
  DynIntArray &operator=(const DynIntArray &other);
  DynIntArray &
  operator=(DynIntArray &&other) noexcept; // asignación de movimiento
};

bool operator==(const DynIntArray &a, const DynIntArray &b);
bool operator>(const DynIntArray &a, const DynIntArray &b);
bool operator<(const DynIntArray &a, const DynIntArray &b);
bool operator<=(const DynIntArray &a, const DynIntArray &b);
bool operator>=(const DynIntArray &a, const DynIntArray &b);
bool operator!=(const DynIntArray &a, const DynIntArray &b);

std::ostream &operator<<(std::ostream &os, const DynIntArray &dynarr);

#endif
