//* Написать функцию, в которую передается не пустой одномерный целочисленный
// массив, функция должна вернуть истину если в массиве есть место, в котором 
//сумма левой и правой части массива равны. Примеры: 
//checkBalance([1, 1, 1, || 2, 1]) → true, 
//checkBalance ([2, 1, 1, 2, 1]) → false, 
//checkBalance ([10, || 1, 2, 3, 4]) → true.
// Абстрактная граница показана - ||, эти символы в массив не входят.
#include <iostream>

int array [] {10,1,2,3,4,2,8,2};
//int *prt = array ;
int lengh_array;
    int volume_array (int *) {
        
        int a = ( sizeof (array))/(sizeof (array [0]));
        //std::cout <<sizeof (array) << " " << sizeof (array [0]);
        return a;
    }
    
bool marker=0;
int fun (int array []) {
        
        int i=0;
        int sum=0;
    std::cout << "Was passed array: ";
    do {
         sum = sum + array [i];
         std::cout << array [i] << " " ;
         i++;
}  while  (i !=volume_array (array));

std::cout << "\n" << "Summa all member array: "  <<  sum << "\n" ;
       
std::cout << "Entered array: ";     
        int lsum=0;
        
        for (int i = 0; i < lengh_array; i++){

         lsum = lsum + array [i];
                      std::cout << array [i] << " ";

         if (sum-lsum==lsum)
         {
             int a = lengh_array-i;
             int t=i;
             std::cout << "|| ";
            for (int i =1;i< a; i++){
             std::cout  << array [i+t] << " "; 
             
             //std::cout << " " << i << " " << i << " " << sum;
             }
             marker=1;
            break;
         }
        
         
        }
        
    return i;
    }

int main () {
    int (*p1) (int *);
    p1 = volume_array;
    lengh_array = p1(array);
    fun ( array);
std::cout << std::boolalpha << marker;

return 0;

}
