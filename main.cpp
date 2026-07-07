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

  // Unir dos arreglos
  int numbers2[] = {5, 3, 1};
  DynIntArray D(numbers2, 3);
  DynIntArray E = D.merge(B);
  DynIntArray F = E.merge(B);
  DynIntArray G = E.merge(E);
  cout << E << endl;
  cout << F << endl;
  cout << G << endl;

  cout << "------------------------" << endl;
  // TEst de operadores
  DynIntArray arr(5);
  DynIntArray arr1(5);
  for (int i = 0; i < 5; i++) {
    arr[i] = i * 2;
    arr1[i] = i * 3;
  }

  cout << arr << endl;
  cout << arr1 << endl;
  DynIntArray arr2 = arr + arr1;
  cout << arr2 << endl;
  arr2.insert(3, 1);
  cout << arr2 << endl;
  // Test de errpr en caso de intentar sumar dos arreglos de diferente tamaño
  // cout << arr2 + arr << endl;
  cout << arr - arr1 << endl;
  arr2 = arr;
  cout << arr2 << endl;

  cout << "------------------------" << endl;
  int arr_1[] = {1, 2, 3, 5};
  int arr_2[] = {1, 2, 3, 5};
  int arr_3[] = {1, 2, 3, 4};
  DynIntArray ARR1(arr_1, 4);
  DynIntArray ARR2(arr_2, 4);
  DynIntArray ARR3(arr_3, 4);
  bool verify = ARR1 == ARR3;
  cout << "1==3: " << verify << endl;
  verify = ARR1 >= ARR2;
  cout << "1>=2: " << verify << endl;
  return 0;
}
