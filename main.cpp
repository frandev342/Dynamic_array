#include "dynArray.h"
#include <iostream>
#include <ostream>

using namespace std;

int main() {
  DynIntArray A;
  cout << A.getSize() << endl;
  int numbers[5] = {1, 2, 3, 4, 5};
  DynIntArray B(numbers, 5);

  // Usando un constructor de copia evitamos el double free()
  // provocado por constructor con parámetros, que copia el puntero y no los
  // valores
  DynIntArray C = B;
  cout << C.getSize() << endl;

  // Método remove, getsize, push_back
  C.remove(3);
  cout << C.getSize() << endl;
  C.push_back(10);
  C.insert(0, 9);

  // Sobrecarga del operador de inserción
  cout << C << endl;
  // SObrecarga del operador de acceso a un valor de un índice
  cout << C[2] << endl;
  C = A;
  cout << C << endl;
  return 0;
}
