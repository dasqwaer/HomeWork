#include <stdio.h>
#include <math.h>
//Task1------------------------------------------------------
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

int task1 (){
printf ("\n====================================\nWork task 1\n");
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
//tqsk 2----------------------------------------------

void initArray (int *array) {
printf ("Initializing an array\n");
int i;
int j;
    for (i=0; i<9; i++) {
        printf ("Enter %i member array: \n", i+1);
        scanf ("%i", &j);
        array [i] = j;
        
    }

}
int workArray (int *array) {
int i;
int j =0;
    for (i=0; i<9; i++) {
       
        if ((array [i])%2 > 0) {
            array [i] *=2;
            j = 1;
        }
    }
    if (j==1) {
        printf ("This array has odd members.\nArray was changed:\n");
        for (i=0; i<9; i++) {
            printf ("%i ", array [i]);
        }
    return 1;
    }
    else
return 0;
}
 
int task2 () {
printf ("\n=====================================\nWork task 2\n");
int array [9];
int i;
initArray (array);
printf ("Your was initializing following array: \n");
for (i=0; i<9; i++) {
            printf ("%i ", array [i]);
        }
printf ("\n");
workArray (array);
printf ("\nFunction workArray return %i\n", workArray(array));
return 0;
}
//task 3----------------------------------------------
void asShortPrint(unsigned* a, int len) {
int i;
unsigned int *p =& a [0];
unsigned short *s;
s = (unsigned short*)p;

printf ("\nFunction received following array: \n");
    for (i=0; i<len; i++) {
    printf ("%i ", a [i]);
    }
printf ("\nConverted array:\n");
    for (i=0; i<len*2; i++){
    printf ("%i ", *(s+i));
    }
}
int task3 (){
printf ("\n=====================================\nWork task 3\n");
unsigned int array [10]={0,1,2,3,4,65541,65542,65543,65544,65545};
    asShortPrint (array, 10);
return 0;
}

int main () {
task1 ();
task2 ();
task3 ();
return 0;
}

