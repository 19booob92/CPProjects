#include "Rubik.h"
#include "Kostka.h"
#include "stdio.h"

int main() {
	Kostka* kostka = new Kostka();
	kostka->CzyUlozona();
	while (1) {
		char sign = getchar();
		if (sign == 'w') {
			kostka->U();
			kostka->Wypisz();
			kostka->CzyUlozona();
		} else if (sign == 's'){
			kostka->u();
			kostka->Wypisz();
			kostka->CzyUlozona();
		} else if (sign == 'q'){
			kostka->L();
			kostka->Wypisz();
			kostka->CzyUlozona();
		} else if (sign == 'a'){
			kostka->l();
			kostka->Wypisz();
			kostka->CzyUlozona();
		} else if (sign == 'e'){
			kostka->F();
			kostka->Wypisz();
			kostka->CzyUlozona();
		} else if (sign == 'd'){
			kostka->f();
			kostka->Wypisz();
			kostka->CzyUlozona();
		} else if (sign == 'r'){
			kostka->R();
			kostka->Wypisz();
			kostka->CzyUlozona();
		} else if (sign == 'f'){
			kostka->r();
			kostka->Wypisz();
			kostka->CzyUlozona();
		} else if (sign == 't'){
			kostka->B();
			kostka->Wypisz();
			kostka->CzyUlozona();
		} else if (sign == 'g'){
			kostka->b();
			kostka->Wypisz();
			kostka->CzyUlozona();
		} else if (sign == 'y'){
			kostka->D();
			kostka->Wypisz();
			kostka->CzyUlozona();
		} else if (sign == 'h'){
			kostka->d();
			kostka->Wypisz();
			kostka->CzyUlozona();

		} else if (sign == 'x') {
			return 0;
		}
	}
}
