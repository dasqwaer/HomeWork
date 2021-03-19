#include <iostream>
# include "function.h"
namespace homework5 {
void out (int *prt,int lengh_array)
{
    std::cout << "You array:"<< "\n";
for (int i=0; i<lengh_array; i++)
{
    std::cout << *(prt+i);
}
std::cout << "\n";
}
int invert_binary (int *a){

for (int i=0; i<27; i++){

*(a+i)=1-*(a+i);

};
std::cout << "Array was inverted" <<"\n";
return *(a);
}
int fill_binary (int *a, int marker, int step, int lengh_array)
{
    for (int i=0; i<lengh_array; i=i+step){
        *(a+i)=marker;
    }
return *(a);
}
void output_array (int lengh_array,int array []) {
    for (int i=0; i<lengh_array; i++){
       array[i];
       
       std::cout << array [i] << " "; 
    };
    
}

int initial_array (int *a,int lengh_array,int first_member, int increment) {
    for ( int i =0; i< lengh_array; i++){
        
            *(a+i)=first_member;
            first_member=first_member+increment;

    };
    std::cout << "\n";
    return *a;
}

int volume_array (int *p) {
        
        int a =  sizeof (p);
        //std::cout <<sizeof (array) << " " << sizeof (array [0]);
        return a;
}

int fun (int array [],int lengh_array,int marker) {
        
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

void cond (int n,int lengh_array,int i0){
    
    if (n!=1){
        if (n>lengh_array){
        i0=n%lengh_array;
         }
        else {
        i0=n;
        } 
        //i0=(i0>(lengh_array-i0)?(lengh_array-i0):i0);
        //std::cout << i0 << "\n";
        }
    else {
        i0=1;
    }
    
   //out (array);
    
}


void rav (int, int lengh_array,int i0, int bufer [], int *prt){
    cond (3,4,0);
    int j = lengh_array;
    int jn;
   
    for (int i=lengh_array;i>lengh_array-i0;i--){
   
        bufer [i]=*(prt+i-1);
       
    }
    for (int i=lengh_array-i0; i>=0; i--){
    
            *(prt+j)=*(prt+i);
             jn=j--;
            //std::cout << i;
        }
   for (int i =lengh_array; i>(lengh_array-i0); i--){
      jn--; 
       *(prt+jn)=bufer[i];
        
    }
};

void lev (int, int lengh_array,int i0, int j0, int bufer [], int *prt){
    cond (3,5,0);
    int j = j0;
    int jn;
    for (int i =0; i< i0; i++){
       bufer [i]=*(prt+i);
   }
    for (int i=i0; i<lengh_array; i++){
    
            *(prt+j)=*(prt+i);
             jn=j++;
           // std::cout << i;
        }
   for (int i =0; i<i0; i++){
       jn++; 
       *(prt+jn)=bufer[i];
        
    }
};


int cicle (int*prt,int n, int*array, int lengh_array){
std:: cout << "lengh_array = "<< lengh_array << "\n";
std:: cout << "Entered 'n' = "<< n << "\n";
if (n>=0){
    std::cout << "Array shift right" << " \n";
   // rav (n);
    
}
else
{
    std::cout << "Array shift left" << " \n";
    n=-n;
    
   lev (5,5,5,5,array,prt);
}
return 0;
}


template <typename... Types>

void invert (Types... ts) {
	(std::cout << ... << !ts);
}

}