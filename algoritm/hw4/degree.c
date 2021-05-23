#include <stdio.h>
long long degree (int x, int y) {
    if (x==0)
        return  0;
    if (x==1)
        return 1;
    else {
         if (y == 1)
            return x;
         else
         y--;
            return x*degree (x,y);
    }
}
long long degree2 (int x, int y) {
    if (x==0)
        return  0;
    if (x==1)
        return 1;
    else {
         if (y == 0)
            return 1;
         if (y == 1)
            return x;
         if (y%2 == 0)
            return degree2 (x*x,y/2);
         else 
         y--;
            return x*degree2 (x,y);
    }
    }
void call_num () {
    int num;
    int deg;
    printf ("enter a number: ");
     scanf ("%i", &num);
    printf ("enter a degree: ");
     scanf ("%i", &deg);
    while (deg !=0){
    if (deg >= 0){
        printf ("\nresult: \n");
      //  return deg;
    }
    else 
        deg = 0;
        printf ("Negative exponentiation will be available in later versions of the program.");
    }
  //  return num, deg;
}

int main ()
{
    printf ("%lli", degree (1024,6));  
    printf ("\n");  
    printf ("%lli",degree2 (4,3));
    //printf ("%i", call_num ());
return 0;
    }
