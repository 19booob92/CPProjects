#ifndef KOSTKA_H
#define KOSTKA_H

#include "Loader.h"
#include "stdio.h"
#include "Rubik.h"
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <string>

using namespace std;
static const char moves[] = "uUlLfFbBdDrR";
static const char centerColours[] = "WYRBOG";

class Kostka{
	private:
		Scianka *Up,*Left,*Front,*Right,*Back,*Down;
		void reverseMove(int move);
		char checkIsMiddleProper(char midCol) throw (string);
	public:
		Kostka();
		Kostka(char * nazwaPliku) throw (string);
		void Uloz(int n);
		void U();
		void u();
		void L();
		void l();
		void F();
		void f();
		void R();
		void r();
		void B();
		void b();
		void D();
		void d();
		void Wypisz();
		bool CzyUlozona();
		void Ruch(char c);
		void Wymieszaj(int n);
};

char Kostka::checkIsMiddleProper(char midCol) throw (string){
	int occurs = 0;
	for (int i = 0; i < 6; i++) {
		if (midCol == centerColours[i]) {
			occurs++;	
		}
	}
	if (occurs > 1 || occurs == 0) {
		throw (string)"Nie poprawny kolor środka !!!\n";
	} else {
		return midCol;
	}
}

Kostka::Kostka(char * nazwaPliku) throw (string) {

	const int FIRST_MIDDLE = 4;
	const int SECOND_MIDDLE = 22;
	const int DIFF = 3;

	char* tab = readFile(nazwaPliku);

	Up = new Scianka(checkIsMiddleProper(tab[FIRST_MIDDLE]));
	Left = new Scianka(checkIsMiddleProper(tab[SECOND_MIDDLE]));
	Front = new Scianka(checkIsMiddleProper(tab[SECOND_MIDDLE + DIFF]));
	Right = new Scianka(checkIsMiddleProper(tab[SECOND_MIDDLE + 2*DIFF]));
	Back = new Scianka(checkIsMiddleProper(tab[SECOND_MIDDLE + 3*DIFF]));
	Down = new Scianka(checkIsMiddleProper(tab[50]));

	//sciana gorna
	for (int i = 0; i < 4; i++) {
		Up->Set(i, tab[i]);
	}
	for (int i = 4; i < 8;i++) {
		Up->Set(i, tab[i+1]);
	}


	// pierwsz linia scian L F R B
	for (int i = 0, j = 9; j < 12; j++, i++) {
		Left->Set(i, tab[j]);
	}
	for (int i = 0, j = 12; j < 15; j++, i++) {
		Front->Set(i, tab[j]);
	}
	for (int i = 0, j = 15; j < 18; j++, i++) {
		Right->Set(i, tab[j]);
	}
	for (int i = 0, j = 18; j < 21; j++, i++) {
		Back->Set(i, tab[j]);
	}

	// druga linia dla ścian L F R B (gdzie pojawiają się wyjątki)
	Left->Set(3, tab[21] ); Left->Set(4, tab[23]);
	Front->Set(3, tab[24] ); Front->Set(4, tab[26]);
	Right->Set(3, tab[27] ); Right->Set(4, tab[29]);
	Back->Set(3, tab[30] ); Back->Set(4, tab[32]);

	// trzecia linia dla ścian L F R B
	for (int i = 5, j = 33; j < 36; j++, i++) {
		Left->Set(i, tab[j]);
	}
	for (int i = 5, j = 36; j < 39; j++, i++) {
		Front->Set(i, tab[j]);
	}
	for (int i = 5, j = 39; j < 42; j++, i++) {
		Right->Set(i, tab[j]);
	}
	for (int i = 5, j = 42; j < 45; j++, i++) {
		Back->Set(i, tab[j]);
	}


	for (int i = 0, j = 45; i < 4; i++, j++) {
		Down->Set(i, tab[j]);
	}
	for (int i = 4, j = 49; i < 8; i++, j++) {
		Down->Set(i, tab[j+1]);
	}
	Wypisz();
}

Kostka::Kostka() {
	Up = new Scianka('W');
	Left = new Scianka('Y');
	Front = new Scianka('R');
	Right = new Scianka('B');
	Back = new Scianka('O');
	Down = new Scianka('G');

	Wypisz();
}

bool Kostka::CzyUlozona() {
	for (int i = 0; i < 8; i++) {
		if (Up->getMidColor() != Up->Get(i) || Front->getMidColor() != Front->Get(i) || Back->getMidColor() != Back->Get(i)) {
			return false;
		} else if (Left->getMidColor() != Left->Get(i) || Right->getMidColor() != Right->Get(i) || Down->getMidColor() != Down->Get(i)) {
			return false;
		}
	}
	return true;
}


void Kostka::U() {
	try {
		Up->ObrotC();
		Obrot(*Left, 0, 1, 2, *Front, 0, 1, 2, *Right, 0, 1, 2, *Back, 0, 1, 2 );	
	} catch (string error) {
		cout << error;
	}

}

void Kostka::u() {
	try {
		Up->ObrotAC();
		Obrot(*Back, 0, 1, 2, *Right, 0, 1, 2, *Front, 0, 1, 2, *Left, 0, 1, 2 );	
	} catch (string error) {
		cout<<error;
	}
}

void Kostka::L() {
	try {
		Left->ObrotC();
		Obrot(*Up, 0, 3, 5, *Front, 0, 3, 5, *Down, 0, 3, 5, *Back, 7, 4, 2 );	
	} catch (string error) {
		cout << error;
	}
}

void Kostka::l() {
	try {
		Left->ObrotAC();
		Obrot(*Back, 7, 4, 2, *Down, 0, 3, 5, *Front, 0, 3, 5, *Up, 0, 3, 5 );	
	} catch (string error) {
		cout << error;
	}
}

void Kostka::F() {
	try {
		Front->ObrotC();
		Obrot(*Up, 7, 6, 5, *Right, 5, 3, 0, *Down, 0, 1, 2, *Left, 2, 4, 7 );	
	} catch (string error) {
		cout << error;
	}
}

void Kostka::f() {
	try {
		Front->ObrotAC();
		Obrot(*Left, 2,4,7, *Down, 0,1,2, *Right, 5,3,0, *Up, 7,6,5);	
	} catch (string error) {
		cout << error;
	}
}

void Kostka::R() {
	try {
		Right->ObrotC();
		Obrot(*Up, 2,4,7, *Back, 5, 3,0, *Down, 2, 4, 7, *Front,2,4,7);	
	} catch (string error) {
		cout << error;
	}
}


void Kostka::r() {
	try {
		Right->ObrotAC();
		Obrot(*Front, 2,4,7, *Down, 2,4,7, *Back, 5,3,0, *Up, 2,4,7);	
	} catch (string error) {
		cout << error;
	}
}

void Kostka::B() {
	try {
		Back->ObrotC();
		Obrot(*Up, 0,1,2, *Left, 5,3,0, *Down, 7,6,5, *Right, 2,4,7);	
	} catch (string error) {
		cout << error;
	}
}

void Kostka::b() {
	try {
		Back->ObrotAC();
		Obrot(*Right, 2,4,7, *Down, 7,6,5, *Left, 5,3,0, *Up, 0,1,2);	
	} catch (string error) {
		cout << error;
	}
}

void Kostka::D() {
	try {
		Down->ObrotC();
		Obrot(*Left, 5,6,7, *Front, 5,6,7, *Right, 5, 6, 7, *Back, 5,6,7);	
	} catch (string error) {
		cout << error;
	}
}

void Kostka::d() {
	try {
		Down->ObrotAC();
		Obrot(*Back, 5,6,7, *Right, 5,6,7, *Front, 5,6,7, *Left, 5,6,7);
	} catch (string error) {
		cout << error;
	}
}

void Kostka::Wypisz() {
	printf("\n\n");
	Up->Wypisz('\t');
	printf("\n\n");
	for (int i=1; i < 4;i++) {
		Left->Wypisz(i);
		Front->Wypisz(i);
		Right->Wypisz(i);
		Back->Wypisz(i);
		printf("\n");
	}
	printf("\n");
	Down->Wypisz('\t');
	printf("\n\n");
}

void Kostka::Ruch(char x) {
	switch(x) {
		case 'U' : {
				   U();
			   } break;
		case 'u' : {
				   u();
			   } break;
		case 'L' : {
				   L();
			   } break;
		case 'l' : {
				   l();
			   } break;
		case 'F' : {
				   F();
			   } break;
		case 'f' : {
				   f();
			   } break;
		case 'R' : {
				   R();
			   } break;
		case 'r' : {
				   r();
			   } break;
		case 'B' : {
				   B();
			   } break;
		case 'b': {
				  b();
			  } break;
		case 'D': {
				  D();
			  } break;
		case 'd': {
				  d();
			  } break;
		case 'w': {
				  printf("\nWpisz ilosc ruchow \n");
				  int n = 0;
				  cin >> n;
				  Wypisz();
				  Wymieszaj(n);
				  Wypisz();
			  } break;
		case 'q': {
				  exit(0);
			  } break;
		case 's' : {
				   printf("\nWpisz ilosc ruchow \n");
				   int n = 0;
				   cin >> n;
				   Wypisz();
				   Uloz(n);
				   if (!CzyUlozona()) {
					   printf("Nie udało się ułożyć kostki w %d ruchach", n);
				   }
			   } break;
		default : {
				  exit(0);				  
			  }
	}
}

void Kostka::Wymieszaj(int n){

	for(int i=0;i<n;i++){

		int move =rand()%12;
		Ruch(moves[move]);
	}
}

int z = 0;
void Kostka::Uloz(int n){

	if (CzyUlozona()){
		return;
	} else{
		if(n==0) {
			return;
		} else{
			for(int l=0;l<12;l++){
				Ruch(moves[l]);
				Uloz(n-1);
				if(CzyUlozona()){
					z++;
					if(z==1) {
						cout<<"Potrzebne ruchy: ";
						printf("%c", moves[l]);
					} else {
						printf("%c", moves[l]);
					}
					return;
				}
				else{
					reverseMove(l);
				}
			}
		}
	}
}

void Kostka::reverseMove(int nextMove) {
	if (nextMove %2 == 0) {
		Ruch(moves[++nextMove]);
	} else {
		Ruch(moves[--nextMove]);
	}
}

#endif

