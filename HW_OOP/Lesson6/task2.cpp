#include <iostream>  

std::ostream& endll (std::ostream& __os)
{
    __os.put(__os.widen('\n'));
    __os.put(__os.widen('\n'));
    __os.flush();
    return __os;
}
int main() {   
	std::cout << "Old" << std::endl << "endl" << "\n";
	std::cout << "New" << endll << "endl";
}
