#ifndef KOSTKA_H
#define KOSTKA_H

#include "Loader.h"
#include "stdio.h"
#include "Rubik.h"
#include <cstdlib>
using namespace std;
class Kostka{
	private:
		Scianka *Up,*Left,*Front,*Right,*Back,*Down;
	public:
		Kostka();
		Kostka(char * nazwaPliku);
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
};

Kostka::Kostka(char * nazwaPliku) {

	const int FIRST_MIDDLE = 4;
	const int SECOND_MIDDLE = 22;
	const int DIFF = 3;

	char* tab = readFile(nazwaPliku);

	Up = new Scianka(tab[FIRST_MIDDLE]);
	Left = new Scianka(tab[SECOND_MIDDLE]);
	Front = new Scianka(tab[SECOND_MIDDLE + DIFF]);
	Right = new Scianka(tab[SECOND_MIDDLE + 2*DIFF]);
	Back = new Scianka(tab[SECOND_MIDDLE + 3*DIFF]);
	Down = new Scianka(tab[50]);

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
			printf("Kostka nie została jeszcze ułożona");
			return false;
		}
		if (Left->getMidColor() != Left->Get(i) || Right->getMidColor() != Right->Get(i) || Down->getMidColor() != Down->Get(i)) {
			printf("Kostka nie została jeszcze ułożona");
			return false;
		}
	}
	printf("Gratulacje, ułożyłeś kostkę");
	return true;
}

void Kostka::U() {
	Up->ObrotC();
	Obrot(*Left, 0, 1, 2, *Front, 0, 1, 2, *Right, 0, 1, 2, *Back, 0, 1, 2 );	
}

void Kostka::u() {
	Up->ObrotAC();
	Obrot(*Back, 0, 1, 2, *Right, 0, 1, 2, *Front, 0, 1, 2, *Left, 0, 1, 2 );	
}

void Kostka::L() {
	Left->ObrotC();
	Obrot(*Up, 0, 3, 5, *Front, 0, 3, 5, *Down, 0, 3, 5, *Back, 7, 4, 2 );	
}

void Kostka::l() {
	Left->ObrotAC();
	Obrot(*Back, 7, 4, 2, *Down, 0, 3, 5, *Front, 0, 3, 5, *Up, 0, 3, 5 );	
}

void Kostka::F() {
	Front->ObrotC();
	Obrot(*Up, 7, 6, 5, *Right, 5, 3, 0, *Down, 0, 1, 2, *Left, 2, 4, 7 );	
}

void Kostka::f() {
	Front->ObrotAC();
	Obrot(*Left, 2,4,7, *Down, 0,1,2, *Right, 5,3,0, *Up, 7,6,5);	
}

void Kostka::R() {
	Right->ObrotC();
	Obrot(*Up, 2,4,7, *Back, 5, 3,0, *Down, 2, 4, 7, *Front,2,4,7);	
}

void Kostka::r() {
	Right->ObrotAC();
	Obrot(*Front, 2,4,7, *Down, 2,4,7, *Back, 5,3,0, *Up, 2,4,7);	
}

void Kostka::B() {
	Back->ObrotC();
	Obrot(*Up, 0,1,2, *Left, 5,3,0, *Down, 7,6,5, *Right, 2,4,7);	
}

void Kostka::b() {
	Back->ObrotAC();
	Obrot(*Right, 2,4,7, *Down, 7,6,5, *Left, 5,3,0, *Up, 0,1,2);	
}

void Kostka::D() {
	Down->ObrotC();
	Obrot(*Left, 5,6,7, *Front, 5,6,7, *Right, 5, 6, 7, *Back, 5,6,7);	
}

void Kostka::d() {
	Down->ObrotAC();
	Obrot(*Back, 5,6,7, *Right, 5,6,7, *Front, 5,6,7, *Left, 5,6,7);	
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
				   Wypisz();
				   CzyUlozona();
			   } break;
		case 'u' : {
				   u();
				   Wypisz();
				   CzyUlozona();
			   } break;
		case 'L' : {
				   L();
				   Wypisz();
				   CzyUlozona();
			   } break;
		case 'l' : {
				   l();
				   Wypisz();
				   CzyUlozona();
			   } break;
		case 'F' : {
				   F();
				   Wypisz();
				   CzyUlozona();
			   } break;
		case 'f' : {
				   f();
				   Wypisz();
				   CzyUlozona();
			   } break;
		case 'R' : {
				   R();
				   Wypisz();
				   CzyUlozona();
			   } break;
		case 'r' : {
				   r();
				   Wypisz();
				   CzyUlozona();
			   } break;
		case 'B' : {
				   B();
				   Wypisz();
				   CzyUlozona();
			   } break;
		case 'b': {
				  b();
				  Wypisz();
				  CzyUlozona();
			  } break;
		case 'D': {
				  D();
				  Wypisz();
				  CzyUlozona();
			  } break;
		case 'd': {
				  d();
				  Wypisz();
				  CzyUlozona();
			  } break;
		case 'q': {
			  } 
			  default : {
				exit(0);				  
			  }
	}
}

#endif
