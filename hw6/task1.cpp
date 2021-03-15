	
#include <iostream>
#include <fstream>

 
int main()
{
	using namespace std;
 

	// Create File1.txt
	ofstream outf("File1.txt");
 if (!outf){
    std::cout << "Failed to create out file!\n";
}
	
 
	// Write two string (~100) in File1.txt
	outf << "String #1!_0123456789_0123456789_0123456789_0123456789_0123456789_0123456789_0123456789" << endl;
	outf << "String #2!_0123456789_0123456789_0123456789_0123456789" << endl;
    
    // Create File2.txt
	ofstream outf2 ("File2.txt");
 if (!outf2){
    std::cout << "Failed to create out file!\n";
}
	
 
	// Write one string (~50) in File1.txt and one string (~70) in File2.txt
	outf << "Some code!_0123456789_0123456789_0123456789_0123456789_0123456789_0123456789" << endl;
	outf2 << "Some code!_0123456789_0123456789_0123456789_0123456789_0123456789_0123456789_0123456789" << endl;
 
	return 0;
 
}