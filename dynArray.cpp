#include "dynArray.h"
#include <ostream>
#include <stdexcept>

DynIntArray::DynIntArray() {
  this->size = 0;
  this->data = new int[0];
}

DynIntArray::DynIntArray(const int arr[], int size) {
  this->size = size;
  this->data = new int[size];
  for (int i = 0; i < size; i++) {
    this->data[i] = arr[i];
  }
}

DynIntArray::DynIntArray(const DynIntArray &other) {
  this->size = other.size;
  this->data = new int[other.size];
  for (int i = 0; i < size; i++) {
    data[i] = other.data[i];
  }
}

DynIntArray::~DynIntArray() { delete[] data; }

int DynIntArray::getSize() const { return size; }

void DynIntArray::push_back(int val) {
  int *ndata = new int[size + 1];
  for (int i = 0; i < size; i++) {
    ndata[i] = data[i];
  }
  delete[] data;
  ndata[size] = val;
  size = size + 1;
  data = ndata;
}

void DynIntArray::remove(int pos) {
  int *ndata = new int[size - 1];
  int j = 0;
  for (int i = 0; i < size; i++) {
    // Cuando llegué a la posición indicada no la copiará y mantendrá la
    // posición para seguir con la copia de los siguiente datos
    if (pos != i) {
      ndata[j] = data[i];
      j++;
    }
  }
  delete[] data;
  size = size - 1;
  data = ndata;
}

void DynIntArray::insert(int pos, int val) {
  int *ndata = new int[size + 1];
  int j = 0;
  for (int i = 0; i < size; i++) {
    // Cuando llegué a la posición, se la saltará y seguirá copiando los datos
    // desde la siguiente posición
    if (j == pos)
      j++;
    ndata[j] = data[i];
    j++;
  }
  delete[] data;
  // Recién agregamos el dato en su posición correspondiente
  ndata[pos] = val;
  size = size + 1;
  data = ndata;
}

// Acceso y modificación de valores en los índices del arreglo dinámico
int &DynIntArray::operator[](int index) {
  if (index < 0 || index > size) {
    throw std::out_of_range("Index out of range");
  }
  return data[index];
}

// Recordar que no se debe usar const, porque estamos modificando el arreglo
// dinámico
std::ostream &operator<<(std::ostream &os, DynIntArray &dynArray) {
  os << "{";
  for (int i = 0; i < dynArray.getSize(); i++) {
    os << dynArray[i];
    if (i < dynArray.getSize() - 1)
      os << ", ";
  }
  os << "}";
  return os;
}

DynIntArray &DynIntArray::operator=(DynIntArray &other) {
  if (this == &other) {
    return *this;
  }
  delete[] data;
  size = other.size;
  data = new int[size];
  for (int i = 0; i < other.size; i++)
    data[i] = other.data[i];
  return *this;
}
