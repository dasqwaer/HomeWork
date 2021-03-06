//* Написать программу, вычисляющую выражение из первого задания, 
//а переменные для неё инициализировать в другом файле


#include <iostream>

#include "file2.h"

double rez;
int main () {
  
    std:: cout <<  a << ' ' << b << '\n'; 
   
    std:: cout << c << " " << d << '\n';
    
    rez = a*(b+((double)c/d));
    
    std::cout << (c/d) << " " << rez <<'\n';
}