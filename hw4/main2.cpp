//Написать программу, проверяющую, является ли некоторое
 //число - натуральным простым. Простое число - это число, 
 //которое делится без остатка только на единицу и себя само.
#include <iostream>

int main ()
{
    unsigned x,n,z;
    z=2;
    std::cout << "enter a number:" << "\n";
    std::cin >> x;
    std::cout << "you entered the number:"<< x << "\n";

for (n=2;n<x;n++){
    if (x%n==0){
        z = 0;
        break;
    }
    
};
if (z==0){
std::cout << "this number is not a prime number";}
else {
    std::cout << "this number is a prime number";};


}