#include <iostream>
using namespace std;
#define T(x,y) (p[x][y])
int main() {
  int **p;
  int *ptr;
  p = new int*[5]; 
  if (!p) {
    cout << "Ошибка выделения памяти.\n";
    return 1;
  }
   for (int i = 0; i < 5; i++) {          
    p[i] = new int [i + 1];}
    for (int i = 0; i < 5; i++) {
    cout << "Введите числа" << "(" << i + 1 << ")" << ":";
    for (int j = 0; j < i + 1; j++) { 
      cin >> p[i][j];
    }
    }
  
  for (int i = 0; i < 5; i++)   { 
cout << "Это целое, на которое указывает p[" << i << "] : ";
for (int j = 0; j < i + 1; j++) {
cout << p[i][j] << "\n";
  }}
  ptr=&p[1][1];
  cout << *ptr << " " << p[1][1] << " " << T(1,1);
for (int i = 0; i < 5; i++) {
 
  delete [] p[i];
 
} return 0;
}
