#include<iostream>
#include<fstream>
#include<sstream>
#include<locale.h>
using namespace std;
	int hello[2];
void split(string input,char del){
	stringstream sstream(input);
	string finalWord;
	while(!sstream.eof()){
	getline(sstream,finalWord,del);
	cout<<finalWord<<endl;
	}
	//return finalWord;
}
int writingFile(string fileName){
	fstream file;
	//open file for write
	file.open(fileName,ios::out);
	file<<hello[0]<<","<<hello[1]<<","<<hello[2];
	//writing name of file in file
	file.close();
	return 0;
}
string readFile(string fileName){
	fstream file;
	string hello;
	file.open(fileName,ios::in);
	filebuf* content = file.rdbuf();
	size_t size = content->pubseekoff(0,file.end,file.in);
	content->pubseekpos(2,file.in);
	char* buffer = new char[size];
	content->sgetn(buffer,size);
	cout.write(buffer,size);
	file.close();
	return string(buffer);
}
int main(){
	split("Hello,World",','); 
	hello[0]=10;
	hello[1]=10;
	hello[2]=10;
	setlocale(LC_ALL,"portuguese");
	if (writingFile("Hello World.txt") == 0){
		cout<<"Its OK";
		cout << readFile("Hello World.txt")<<endl;
	}
	return 0;
}
