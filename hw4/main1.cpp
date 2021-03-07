//Написать программу, проверяющую что сумма двух чисел лежит 
//в пределах от 10 до 20 (включительно), 
//если да – вывести true, в противном случае – false;
#include <iostream>
int main (){
int x;
int n; 
int sum;

for (x=1,n=9;x<14;x++){

sum=x+n;
if (sum>=10&&sum<=20){
std::cout <<"If sum=" << sum << " true "<< "\n";}
else {
    std::cout <<"If sum=" << sum << " falce " <<'\n';
    x=9;
if (x=14){
    break;
}
};
};
x=1;
n=3;
sum=x+n;
if (sum>=10&&sum<=20){
std::cout <<"If sum=" << sum << " true "<< "\n";}
else {
    std::cout <<"If sum=" << sum << " falce " <<'\n';


};
}