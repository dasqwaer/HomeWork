//Задать целочисленный массив, состоящий из элементов 0 и 1. Например: 
//[ 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 ]. Написать функцию, заменяющую в принятом
// массиве 0 на 1, 1 на 0 (** без применения if-else, switch, () ? :);
#include <iostream>
#include <numeric>

int fill_binary (int *a, int marker, int step, int lengh_array)
{
    for (int i=0; i<lengh_array; i=i+step){
        *(a+i)=marker;
    }
return *(a);
}

int invert_binary (int *a){

for (int i=0; i<27; i++){

*(a+i)=1-*(a+i);

};
std::cout << "Array was inverted" <<"\n";
return *(a);
}

void out (int *prt,int lengh_array)
{
    std::cout << "You array:"<< "\n";
for (int i=0; i<lengh_array; i++)
{
    std::cout << *(prt+i);
}
std::cout << "\n";
}

int  binary []{};
int * prt = binary;


int main () {
    
fill_binary (prt,1,1,24);//Set all value array - one.
//out (prt,24);
fill_binary (prt,0,3,24);//Set every third value - zero
//out (prt,24);
fill_binary (prt,0,5,24);//Set every fifth value - zero
out (prt,24);
invert_binary (prt);
out (prt,24);
return 0;
}




