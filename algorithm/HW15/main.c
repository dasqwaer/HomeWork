
/*    Реализовать простейшую хеш-функцию. На вход функции подается строка, на выходе сумма кодов символов.
    Имеются монеты номиналом 50, 10, 5, 2, 1 коп. Напишите функцию которая минимальным количеством монет наберет сумму 98 коп. Для решения задачи используйте “жадный” алгоритм.

Результатом работы должен стать один файл с кодом на языке С, содержащий функцию main и все необходимые функции.*/
//hash------------------------------------------------
#include <stdio.h>
char str1[] = {"HELLO WORLD"};
char str2[256]; 
int  hashFuncHW (char *str)
{   
    fgets (str2, 256, stdin);
    int SUM = 0;
    printf ("Entering string:\n");
    while(*str)
    {   
        printf ("%c ", *str);
        SUM+=(int)(*str);
        str++;
    }
    printf ("\nhash: ");
    return SUM;
}
//greed----------------------------------------------
#define size 5
char nominal [size] = {50,10,5,2,1};
int number [size] = {0};
int i = 0;
int rec (int x) {  
    if (x > nominal[i]) {
        number[i]++;
        rec (x-nominal[i]);
    }
    if (x == nominal[i]) {
        return number[i]++;
    }
    if ((x < nominal [i])) {
        i++;
        rec (x);
    }
    return x;
}
int main () {
//hash-----------------------------------------------
    printf ("%i", hashFuncHW (str1));
    printf ("\nPlease, enter string for 255 symbols: \n");  
    printf ("%i\n", hashFuncHW (str2));
//greed----------------------------------------------
    printf ("The %i includes:\n",rec (98));
    printf ("50 - %i pcs.\n10 - %i pcs.\n5 - %i pcs.\n2 - %i pcs.\n1 - %i pcs.",
    number[0],number[1],number[2],number[3],number[4]);
    printf ("\n");
    i = 0;
    for (int i = 0; i < 5; i++ ) {
        number[i]=0;
    }
    printf ("The %i includes:\n",rec (549));
    printf ("50 - %i pcs.\n10 - %i pcs.\n5 - %i pcs.\n2 - %i pcs.\n1 - %i pcs.",
    number[0],number[1],number[2],number[3],number[4]);
    printf ("\n");
    i = 0;
    return 0;
}
