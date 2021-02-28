#include <iostream>
using namespace std;
//Создать и инициализировать переменные пройденных типов данных
int main (){
	short s = 1;
	int i = 150000;
	unsigned u = 139;
	long l = i*5;
	long long ll = l*100;
	char c = 'F';
	float f = 3.88;
	double d = f*15;
cout << "Tip var 'short', value: " << s << "\n"; 
cout << "Tip var 'int', value: " << i << "\n"; 
cout << "Tip var 'unsigned' (or unsigned int), value: " << u<< "\n"; 
cout << "Tip var 'long' (or long int), value: " << l << "\n"; 
cout << "Tip var 'long' long (or long long int), value: " << ll << "\n";  
cout << "Tip var 'char', value: " << c << "\n"; 
cout << "Tip var 'float', value: " << f << "\n"; 
cout << "Tip var 'double', value: " << d << "\n"; 

return 0;
}


