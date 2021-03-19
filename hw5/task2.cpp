//Задать пустой целочисленный массив размером 8. Написать функцию, которая с 
//помощью цикла заполнит его значениями 1 4 7 10 13 16 19 22;
#include <iostream>


int actave [] {};
int *prt = actave;
int initial_array (int *a,int lengh_array,int first_member, int increment);
void output_array (int lengh_array,int array []);
int main (){
    std::cout << "Empty array was created:" << "\n";
output_array (8,actave);
initial_array (prt,8,1,3);
    std::cout << "Function initial_array filled  array required values:" << "\n";

output_array (8,actave);

    return 0;
}
int initial_array (int *a,int lengh_array,int first_member, int increment) {
    for ( int i =0; i< lengh_array; i++){
        
            *(a+i)=first_member;
            first_member=first_member+increment;

    };
    std::cout << "\n";
    return *a;
}
void output_array (int lengh_array,int array []) {
    for (int i=0; i<lengh_array; i++){
       array[i];
       
       std::cout << array [i] << " "; 
    };
    
}
