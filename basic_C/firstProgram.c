#include <stdio.h>
/*File name is firstProgram.c
Run file name is Hello
Autor is Ilya Gulyaev
Text Editor is Xed 
Compilator is gcc
*/
int main ()
{
int a = 10;
printf("Hello world!\n");
printf("This is a new row\n");
printf ("%i\n", a);
printf ("Переменная 'a' хранится по адресу: %p\n", &a);
int input;
printf ("Введите число: ");
scanf ("%i",&input);
printf ("Выводим 'input': %i\n",input);
printf ("Выводим квадрат 'input': %i\n",input*input);
float Ui = 45;
float R1 = 36;
float R2 = 4;
float Uo;

Uo = Ui * (R1 / (R2 + R1));
printf ("Uo = %f\n",Uo);
Uo=40.5;
Ui=(Uo*(R2+R1))/R1;
printf ("Ui = %f\n",Ui);
R1=(Uo/Ui)*(R2+R1);
printf ("R1 = %f\n",R1);
R2=(Ui*R1-Uo*R1)/Uo;
printf ("R2 = %f\n",R2);
return 0;
}
