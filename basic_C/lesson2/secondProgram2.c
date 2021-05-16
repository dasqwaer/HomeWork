#include <stdio.h>

int main () {
int input;
char exit;
do {
    int i;
    int sum = 0;
    for ( i=0; i<10; i++){
        printf ("Please enter ten integer number: ");
        scanf ("%i", &input);
            sum+=input;
            //printf ("sum: %i\n", sum);
            if (i==9) {
            printf ("Arithmetic mean sum entered numbers: %i\n", sum/10);
            }
           
    }
    printf ("Please enter 'x' for exit or any key for continium");

    scanf ("%s",& exit);
}
while (exit !='x');



return 0;
}
