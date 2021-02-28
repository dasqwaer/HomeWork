#include <iostream>
using namespace std;
//Создать структуру данных «Поле для игры в крестики-нолики» и снабдить его всеми необходимыми свойствами


enum class TTT_simbol {
	X,
	O,
	Empty
};
struct FILD_TTT {
TTT_simbol Fild [3] [3];
};
int main (){
		
    
   TTT_simbol Fild [3] [3]  =
        {{TTT_simbol::Empty,TTT_simbol::Empty,TTT_simbol::Empty},
        {TTT_simbol::Empty,TTT_simbol::Empty,TTT_simbol::Empty},
        {TTT_simbol::Empty,TTT_simbol::Empty,TTT_simbol::Empty},};
    TTT_simbol Fild_improved [4][4] = {};

return 0;
}
