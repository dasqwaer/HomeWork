#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
  char * s = new char [200];
 char a = 64;
for (int i=0; i<201; i++){
a++;
char *p;
p=&a;
if (a==90)
{
    a=64;
}
 *(s+i)=*p;    
 }

 for (int i=25; i<201; i+=26){
 *(s+i)='\n'; 
 	
 };

 
    
    ofstream o ("File1.txt");
    if (!o)
	{
		cout << "Error open File1.txt! (ofstream)" << endl;	
	}
    o << s; 
    
	ifstream inf ("File1.txt");
 
	if (!inf)
	{
		cout << "Error open File1.txt!" << endl;	
	}
    inf >> s;
 
    ofstream o2 ("File3.txt");
    if (!o2)
	{
		cout << "Error open File3.txt! (ofstream)" << endl;	
	}
    o2 << s; 
    o2.close();
    

	ifstream inf2 ("File2.txt");
 
	if (!inf2)
	{
		cout << "Error open File2.txt!" << endl;	
	}
    inf2.getline (s,200);
        for (int i=0;i<200;i++){
            cout << s [i];
        }
    ofstream o3 ("File3.txt", ios::app);
    if (!o3)
	{
		cout << "Error open File3.txt! (ofstream)" << endl;	
	}
    o3 << s; 


 	
 
  return 0;
}