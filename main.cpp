#include<iostream>
#include<fstream>
#include<locale.h>
using namespace std;
int writingFile(string namefile){
	fstream file;
	//open file for write
	file.open(namefile,ios::out);
	file<<namefile;
	//writing name of file in file
	file.close();
	return 0;
}
int main(){
	setlocale(LC_ALL,"portuguese");
	if (writingFile("Hello World.txt") == 0){
		cout<<"Its OK"; 	 
	}
	return 0;
}
