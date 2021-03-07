#include <iostream>
using namespace std;

int main()
{
    int i, m, year_c; 
    std::cout << "Введите год: ";
    std:: cin >>  year_c;
    int year = year_c;
    
    for (i = 1; year>0; year=year%4) 
    {
        i++;
        year = year%4; 
      if (1<year)
       {};
       
       m=year%4;
       
       break;
       
    }
    
    
if (i==1){
          std::cout << "Incorrect value  year ";
       }
       else
       {if ((!(year_c%100!=0)||m!=0)&&(year_c%400!=0)){ 
    std::cout << "Введённый год не является високосным " << "\n";         
       }
       else
       std::cout << "Введённый год високосный " <<"\n";}
       
    return 0;
}