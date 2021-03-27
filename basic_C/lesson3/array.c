#include <stdio.h>

int array [9];

void initArray (int *) {
printf ("Initializing an array\n");
int i;
int j;
    for (i=0; i<9; i++) {
        printf ("Enter %i member array: \n", i+1);
        scanf ("%i", &j);
        array [i] = j;
        
    }

}
int workArray (int *) {
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
 
int main () {
int i;
initArray (array);
printf ("Your was initializing following array: \n");
for (i=0; i<9; i++) {
            printf ("%i ", array [i]);
        }
printf ("\n");
workArray (array);
printf ("Function workArray return %i\n", workArray(array));
return 0;
}
