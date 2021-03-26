#include <iostream>
#include <cstdio>

#define T(x,y) ((0<=(x))&&((x)<(y))?(1):(0))

int main() {
   int x;
   int y;
   bool z;
    std::cout << "Enter number x" << "\n";
    std::cin >> x;
    std::cout<< "Enter number y" << "\n";
    std::cin >> y;
    z=T(x,y);

    std::cout << std::boolalpha << z<< "\n";
    if (z==1){
    std::cout << "Nuber " << x << " includes a range from 0 to " << y; }
    else
    std::cout << "Nuber " << x << " outside a range from 0 to " << y; 
   return 0;
}


