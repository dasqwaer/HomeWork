
#include <stdio.h>
#include <math.h>
int main ()
{
    unsigned x,n,z;
    z=2;
    printf ("enter a number:\n");
    scanf ("%i", &x);
    printf ("you entered the number: %i\n", x);

for (n=2;n<= sqrt(x);n++){
    
    if (x%n==0){
       
        z = 0;
        break;
    }

};
if (z==0){
printf ( "this number is not a prime number");}
else {
    printf ("this number is a prime number");};


}
