#include <iostream>

int array []{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};

int *prt=array;


int n=1024;
int i0;
int j0;
int * bufer = new int;

int lengh_array;
    int volume_array (int *) {
        
        int a = ( sizeof (array))/(sizeof (array [0]));
        //std::cout <<sizeof (array) << " " << sizeof (array [0]);
        return a;
    }


void out (int *prt)
{
    std::cout << "You array:"<< "\n";
for (int i=0; i<lengh_array; i++)
{
    std::cout << " " << *(prt+i);
}
std::cout << "\n";
}

void cond (){
    
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


void rav (int){
    cond ();
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

void lev (int){
    cond ();
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

int cicle (int*,int ){
std:: cout << "lengh_array = "<< lengh_array << "\n";
std:: cout << "Entered 'n' = "<< n << "\n";
if (n>=0){
    std::cout << "Array shift right" << " \n";
    rav (n);
    
}
else
{
    std::cout << "Array shift left" << " \n";
    n=-n;
    
   lev (12);
}
return 0;
}

int main (){
std::cout << "Please enter the shift "<<'\n';
std::cin >> n;

lengh_array=volume_array(array);
//cond ();
out (array);
cicle (array,n);

out (array);
//out (bufer);

    return 0;
}

