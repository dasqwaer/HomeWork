#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
  string *s;
 
 	// ifstream используется для чтения содержимого файлов.
	// Мы попытаемся прочитать содержимое файла File1.txt
	ifstream inf("File1.txt");
 
	// Если мы не можем открыть файл для чтения его содержимого,
	if (!inf)
	{
		// то выводим следующее сообщение об ошибке
		cout << "Uh oh, File1.txt could not be opened for reading!" << endl;
		
	}
 ofstream outf("File3.txt");
	
	// Если мы не можем создать файл для записи в него,
	if (!outf)
	{
		// то выводим следующее сообщение об ошибке
		cout << "Uh oh, File3.txt could not be opened for writen!" << endl;
		
	}
    // Пока есть, что читать,
	while (inf)
	{
		// то перемещаем то, что можем прочитать, в строку, а затем выводим эту строку на экран
		
		getline(inf, s[0]);
		cout << s[0] << "\n";
        outf << s[0] << "\n";
	}
 	ifstream inf2("File2.txt");
 
	// Если мы не можем открыть файл для чтения его содержимого,
	if (!inf2)
	{
		// то выводим следующее сообщение об ошибке
		cout << "Uh oh, File2.txt could not be opened for reading!" << endl;
		
	}
 ofstream outf2("File3.txt",ios::app);
		// Если мы не можем создать файл для записи в него,
	if (!outf2)
	{
		// то выводим следующее сообщение об ошибке
		cout << "Uh oh, File3.txt could not be opened for writen!" << endl;
		
	}
    // Пока есть, что читать,
	while (inf2)
	{
		// то перемещаем то, что можем прочитать, в строку, а затем выводим эту строку на экран
		
		getline(inf2, s[1]);
		cout << s[1] << "\n";
        outf << s[1] << "\n";
	}
	

    
	
 
  return 0;
}