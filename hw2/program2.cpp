#include <iostream>
using namespace std;
//Создать массив, способный содержать значения такого перечисления и инициализировать его.

enum class TTT_simbol {
	X,
	O,
	Empty
};
TTT_simbol Fild [3] [3];
int main (){
		
    
   TTT_simbol Fild [3] [3]  =
        {{TTT_simbol::Empty,TTT_simbol::Empty,TTT_simbol::Empty},
        {TTT_simbol::Empty,TTT_simbol::Empty,TTT_simbol::Empty},
        {TTT_simbol::Empty,TTT_simbol::Empty,TTT_simbol::Empty},};
  
return 0;
}
