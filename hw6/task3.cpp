#include <fstream> 
#include <iostream> 
#include <string.h> 
using namespace std; 
int main(){ 
char word [512];
char name [512];
cout << "Enter name file: "<< "\n";
cin >> name;


cout << "Enter word find: "<< "\n";
cin >> word;


char buffer[1024]; 
ifstream input(name);
while(input.getline(buffer,1024)) { 
if(strstr(buffer, word)) {
cout << "Find word " << word << " in file" << name << " " << endl;
}
}
cout << buffer;
return 0; 
} 