#include <iostream>
using namespace std;
//Создать объединение и структуру с битовыми флагами указывающими какого типа значение в данный момент содержится в объединении
union test {
    short s;
	int i;
	unsigned u;
	long l;
	long long ll;
	char c;
	float f;
	double d;
};
struct bit_flags {
    test val;
    bool is_short :1;
	bool is_int :1;
	bool is_unsigned :1;
	bool is_long :1;
	bool is_longlong :1;
	bool is_char :1;
	bool is_float :1;
	bool is_double :1;
};
int main (){
	bit_flags x;
    x.val.u = 12;
    x.is_short = 0;
    x.is_int = 0;
    x.is_unsigned = 1;
    x.is_long = 0;
	x.is_longlong = 0;
	x.is_char = 0;
	x.is_float = 0;
	x.is_double = 0;

return 0;
}
