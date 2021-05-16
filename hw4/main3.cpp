#include <iostream>

unsigned const x =5;
unsigned const y =4;
unsigned sum;

int main ()
{

    sum = x+y;
    if (x==10||y==10||sum==10){
    bool ifconst = true;
    
   std::cout<< std::boolalpha << ifconst;}
   else {
       bool ifconst = false;
   std::cout<< std::boolalpha << ifconst;
   };

}