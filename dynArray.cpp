#include "dynArray.h"
#include <cstddef>
#include <initializer_list>
#include <ostream>
#include <stdexcept>

DynIntArray::DynIntArray() {
  this->size = 0;
  this->data = new int[0];
}

DynIntArray::DynIntArray(int size) {
  this->size = size;
  this->data = new int[size];
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

// Instanciar por arreglo
DynIntArray::DynIntArray(std::initializer_list<int> arr) {
  size = arr.size();
  data = new int[size];
  size_t i = 0;
  for (const int &x : arr) {
    data[i] = x;
    i++;
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

// Implementación de Merge: Unir dos arreglos dinámicos
DynIntArray DynIntArray::merge(const DynIntArray &other) {
  int numbers[size + other.size], i;
  for (i = 0; i < size; i++) {
    numbers[i] = data[i];
  }
  for (i = 0; i < other.size; i++) {
    numbers[size + i] = other.data[i];
  }
  DynIntArray newArr(numbers, size + other.size);
  return newArr;
}

// Versión constante para objetos constantes, permitirá solo lectura
const int &DynIntArray::operator[](int index) const {
  if (index < 0 || index > size) {
    throw std::out_of_range("Index out of range");
  }
  return data[index];
}

// VErsión normal, permitirá lectura y escritura
int &DynIntArray::operator[](int index) {
  if (index < 0 || index > size) {
    throw std::out_of_range("Index out of range");
  }
  return data[index];
}

// Recién implemente el constructor por tamaño, así que recién empieza su uso
DynIntArray DynIntArray::operator+(const DynIntArray &other) const {
  if (size != other.size) {
    throw std::invalid_argument("Arrays must have the same size to be added");
  }
  DynIntArray result(size);
  for (int i = 0; i < size; i++) {
    result[i] = data[i] + other[i];
  }
  return result;
}

// Sobrecarga del operador -
DynIntArray DynIntArray::operator-(const DynIntArray &other) const {
  if (size != other.size) {
    throw std::invalid_argument("Arrays must have the same size to be added");
  }
  DynIntArray result(size);
  for (int i = 0; i < size; i++) {
    result[i] = data[i] - other[i];
  }
  return result;
}

// Recordar que no se debe usar const, porque estamos modificando el arreglo
// dinámico
std::ostream &operator<<(std::ostream &os, const DynIntArray &dynArray) {
  os << "{";
  for (int i = 0; i < dynArray.getSize(); i++) {
    os << dynArray[i];
    if (i < dynArray.getSize() - 1)
      os << ", ";
  }
  os << "}";
  return os;
}

// SObrecarga del operador de asignación
DynIntArray &DynIntArray::operator=(const DynIntArray &other) {
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

bool operator==(const DynIntArray &a, const DynIntArray &b) {
  if (a.getSize() != b.getSize())
    return false;
  for (int i = 0; i < a.getSize(); i++) {
    if (a[i] != b[i]) {
      return false;
    }
  }
  return true;
}

bool operator!=(const DynIntArray &a, const DynIntArray &b) {
  if (a.getSize() != b.getSize())
    return true;
  for (int i = 0; i < a.getSize(); i++) {
    if (a[i] != b[i]) {
      return true;
    }
  }
  return false;
}
bool operator>(const DynIntArray &a, const DynIntArray &b) {
  if (a.getSize() != b.getSize())
    return a.getSize() > b.getSize();
  for (int i = 0; i < a.getSize(); i++) {
    if (a[i] != b[i]) {
      return a[i] > b[i];
    }
  }
  return false;
}
bool operator>=(const DynIntArray &a, const DynIntArray &b) {
  if (a.getSize() != b.getSize())
    return a.getSize() > b.getSize();
  for (int i = 0; i < a.getSize(); i++) {
    if (a[i] != b[i]) {
      return a.getSize() >= b.getSize();
    }
  }
  return true;
}
bool operator<(const DynIntArray &a, const DynIntArray &b) {
  if (a.getSize() != b.getSize())
    return b.getSize() > a.getSize();
  for (int i = 0; i < a.getSize(); i++) {
    if (a[i] != b[i]) {
      return b[i] > a[i];
    }
  }
  return false;
}
bool operator<=(const DynIntArray &a, const DynIntArray &b) {
  if (a.getSize() != b.getSize())
    return b.getSize() > a.getSize();
  for (int i = 0; i < a.getSize(); i++) {
    if (a[i] != b[i]) {
      return b.getSize() >= a.getSize();
    }
  }
  return true;
}
