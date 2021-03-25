#include <stdio.h>

int main () {
int input;
char exit;
do {
    printf ("Please enter integer positive number no more than a thirty-six: ");
    scanf ("%i", &input);

    if (input>0&&input<=36) {
    printf ("The number is range from 0 to 36\n");
    }
    else {
    continue;
    }
    int i;
    int d = 0;
    int j = 0;
    for ( i=0; i<input; i++)
        {
            for (j=1; j<input-i; j++)
            printf (" ");
             for (j=i*2; j>=0; j--) {
             printf ("^");}
             printf ("\n");
              // printf ("^%s", (input%d==0)?"":"\n");          
        }  
           
        
    
    
    printf ("\nPlease enter 'x' for exit or any key for continium");

    scanf ("%s",& exit);
    continue;
}
while (exit !='x');



return 0;
}
