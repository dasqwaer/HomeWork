//Написать программу, вычисляющую выражение a * (b + (c / d)) и 
//выводящую результат с плавающей точкой, где a, b, c, d – целочисленные константы;

#include <iostream>
const int a = 4;
const int b = 2;
const int c = 1;
const short d = 3;
double rez;
int main () {
  
    std:: cout <<  a << ' ' << b << '\n'; 
   
    std:: cout << c << " " << d << '\n';
    
    rez = a*(b+((double)c/d));// !??? У меня вопрос почему только пять троек после точки?
    
    std::cout << (c/d) << " " << rez <<'\n';
}