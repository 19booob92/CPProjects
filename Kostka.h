#ifndef KOSTKA_H
#define KOSTKA_H

#include "stdio.h"
#include "Rubik.h"
#include <cstdlib>
using namespace std;
class Kostka{
	private:
		Scianka *Up,*Left,*Front,*Right,*Back,*Down;
	public:
		Kostka();
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
	Obrot(*Up, 0, 3, 5, *Front, 0, 3, 5, *Down, 0, 3, 5, *Back, 2, 4, 7 );	
}

void Kostka::l() {
	Left->ObrotAC();
	Obrot(*Back, 2, 4, 7, *Down, 0, 3, 5, *Front, 0, 3, 5, *Up, 0, 3, 5 );	
}

void Kostka::F() {
	Front->ObrotC();
	Obrot(*Up, 5, 6, 7, *Left, 2, 4, 7, *Right, 0, 3, 5, *Down, 0, 1, 2 );	
}

void Kostka::f() {
	Front->ObrotAC();
	Obrot(*Down, 0,1,2, *Right, 0, 3, 5, *Left, 2, 4, 7, *Up, 5,6,7);	
}

void Kostka::R() {
	Right->ObrotC();
	Obrot(*Up, 2,4,7, *Back, 0, 3,5, *Down, 2, 4, 7, *Front,2,4,7);	
}

void Kostka::r() {
	Right->ObrotAC();
	Obrot(*Front, 2,4,7, *Down, 2,4,7, *Back, 0,3,5, *Up, 2,4,7);	
}

void Kostka::B() {
	Back->ObrotC();
	Obrot(*Up, 0,1,2, *Left, 0,3,5, *Down, 5,6,7, *Right, 2,4,7);	
}

void Kostka::b() {
	Back->ObrotAC();
	Obrot(*Right, 2,4,7, *Down, 5,6,7, *Left, 0,3,5, *Up, 0,1,2);	
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
