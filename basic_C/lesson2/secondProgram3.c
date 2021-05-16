#include <stdio.h>

int main () {
int input;
char exit;
do {
    printf ("Please enter integer positive number no more than a thousand: ");
    scanf ("%i", &input);

    if (input>0&&input<1000) {
    printf ("The number is range from 0 to 1000\n");
    }
    else {
    continue;
    }
    int i;
    int sum = 0;
    int j = 0;
    for ( i=1; i<input; i++){
        
            sum=i%input;
            if (sum%2==0)
            {
                if (j>0)
                 {
                    printf (", ");
                 }  
            printf ("%i", sum);
            j++;
           
        }
        
    }
    
    printf ("\nPlease enter 'x' for exit or any key for continium");

    scanf ("%s",& exit);
    continue;
}
while (exit !='x');



return 0;
}
