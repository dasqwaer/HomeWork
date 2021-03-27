#include <stdio.h>

unsigned int array [10] {0,1,2,3,4,65541,65542,65543,65544,65545};
void asShortPrint(unsigned* a, int len); 
int main () {
asShortPrint (array, 10);
return 0;
}
void asShortPrint(unsigned* a, int len) {
int i;
unsigned int *p =& a [0];
unsigned short *s;
s = (unsigned short*)p;

printf ("Function received following array: \n");
    for (i=0; i<len; i++) {
    printf ("%i ", a [i]);
    }
printf ("\nConverted array:\n");
    for (i=0; i<len*2; i++){
    printf ("%i ", *(s+i));
    }
}
