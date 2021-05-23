#include <stdio.h>
int convertingDecToBe (int x) {
    if (x==0){
        return  0;
    }
    else {
        char buf [2];
        convertingDecToBe (x/2);
        sprintf (buf, "%i", x%2);  
        printf (buf, 6); //Здесь вопрос после запятой, что нужно указывать? Почему работает с любым числом? 
        return 0;
    }
}
void convertingDecToBe2 (int n) {
        if (n>=2)
        convertingDecToBe2 (n/2);
        printf ("%i", n%2);
    }
int call_num () {
    int num;
    printf ("enter a number: ");
     scanf ("%i", &num);
    while (num != 0){
    if (num > 0){
        printf ("\nbinary: \n");
        return num;
    }
    else 
        num = 0;
        printf ("enter a positive number: ");
    }
    return 0;
}

int main ()
{
    convertingDecToBe (call_num());  
    printf ("\n");  
    convertingDecToBe2 (call_num());

return 0;
    }


