#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
  string *s= new string;
 
 	// ifstream используется для чтения содержимого файлов.
	// Мы попытаемся прочитать содержимое файла File1.txt
	ifstream inf("File1.txt");
 
	// Если мы не можем открыть файл для чтения его содержимого,
	if (!inf)
	{
		// то выводим следующее сообщение об ошибке и выполняем функцию exit()
		cerr << "Uh oh, File1.txt could not be opened for reading!" << endl;
		exit(1);
	}
 ofstream outf("File2.txt", ios::app);
	// Пока есть, что читать,
	while (inf)
	{
		// то перемещаем то, что можем прочитать, в строку, а затем выводим эту строку на экран
		//string strInput;
		getline(inf, *s);
		cout << *s << "\n";
        outf << *s << "\n";
	}
 	// Передаем флаг ios:app, чтобы сообщить fstream, что мы собираемся добавить свои данные к уже существующим данным файла.
	// Мы не собираемся перезаписывать файл.
	// Нам не нужно передавать флаг ios::out, поскольку ofstream по умолчанию работает в режиме ios::out
	

    
	
 
  return 0;
}