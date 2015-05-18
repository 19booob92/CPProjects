#ifndef LOADER_H
#define LOADER_H

#include <iostream> 
#include <fstream> 
#include <string>

using namespace std;

char* readFile(){
	int array_size = 64; 
	char * array = new char[array_size]; 
	int position = 0; 

	ifstream fin("rubikCube.txt"); 

	if(fin.is_open()){
		while(!fin.eof() && position < array_size){
			fin.get(array[position]);
			if (array[position] <= 'Z' && array[position] >= 'A') {
				position++;
			}
		}
		array[position] = '\0'; 
	}
	else {
		cout << "Nie mozna znalesc pliku." << endl;
	}

	fin.close();

	return array;
}

#endif
