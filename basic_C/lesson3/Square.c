#include <stdio.h>
#include <math.h>

int calcSquare (int a, int b, int c, double *x1, double *x2){
double D;
if (a==0) {
    printf ("This is not a quadratic equation!!\n");
    if (b==0) {
        printf ("There are no roots, this is not an equation!!\n");
        return -1;
    }
    *x1=(-c)/b;
    return 0;
    
}
D = sqrt (b*b-4*a*c);
if (D>0){

    *x1=((-b)+D)/(2*a);
    *x2=((-b)-D)/(2*a);
    return 1;
}
if (D==0){
    *x1=*x2=(-b)/(2*a);
    return 0;
}

    return -1;

} 

int main (){
double x1;
double x2;
double * px1, * px2;
px1 = &x1;
px2 = &x2;
int output;
printf ("Value variables before the change: Х1= %f  Х2= %f\n", x1, x2);
output = calcSquare (-1,0,3,px1,px2);
printf ("Funcroots of the equationtion calcSquere return: %i\n", output);
printf ("Roots of the equation: %f %f ", x1, x2);
return 0;
}
