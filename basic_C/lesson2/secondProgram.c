#include <stdio.h>

int main () {
int input;
char exit;
do {printf ("Please enter integer number: ");
scanf ("%i", &input);

if (input>0&&input<=100) {
printf ("The number is range from 0 to 100\n");
}
else {
printf ("The number is not range from 0 to 100\n");
}
printf ("Please enter 'x' for exit or any key for continium");

scanf ("%s",& exit);
}
while (exit !='x');



//char y = "The number is range from 0 to 100";
//char n = "The number is not range from 0 to 100";
//char output;
//output = (input>0&&input<=100)?y:n;
//printf ("The number is range from 0 to 100");
return 0;
}
