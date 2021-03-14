#include <iostream>
using namespace std;
#define T(x,y) ((sizeof(x))/(sizeof(y)))
int main () {

char *str_ptr[3] = { 
 "Programming ",
 "is ",
 "fun!"};
int array [100][100]{};

std::cout << sizeof(array) << " " << T(array,int) << "\n";
std::cout << sizeof(str_ptr) << " " << T(str_ptr,int) << "\n";

 
return 0;
}
