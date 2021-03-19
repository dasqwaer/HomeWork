#include <iostream>

#include "function.h"
using FistFuncPrt = void(*)(int *prt,int lengh_array);
int main () {
FistFuncPrt p1 = homework5::out;
int array []{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};

int *prt=array;
p1 (prt,19);

    return 0;
}