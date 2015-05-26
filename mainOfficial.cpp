#include "Rubik.h"
#include "Kostka.h"
#include "stdio.h"
#include <iostream>
#include <string>

int main() {

	string NAME = "rubikCube.txt";

	char *name = &NAME[0];

	//Kostka* kostka = new Kostka(name);
	Kostka* kostka = new Kostka();
	while (1) {

		const int MAX_CHAR_AMOUNT = 255;
		char input[MAX_CHAR_AMOUNT] = {'0'};
		int i = 0;

		printf("\nWpisz polecenie \n");
		cin >> input;

		while(input[i] != '\0') {
			kostka->Ruch((char) input[i]);
			i++;
		}

	}
	return 0;
}
