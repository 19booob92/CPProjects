#include "Rubik.h"
#include "Kostka.h"
#include "stdio.h"

int main() {
	Kostka* kostka = new Kostka();
	kostka->CzyUlozona();
	while (1) {
		char sign = getchar();
		if (sign == 'U') {
			kostka->U();
			kostka->Wypisz();
			kostka->CzyUlozona();
		} else if (sign == 'u'){
			kostka->u();
			kostka->Wypisz();
			kostka->CzyUlozona();
		} else if (sign == 'L'){
			kostka->L();
			kostka->Wypisz();
			kostka->CzyUlozona();
		} else if (sign == 'l'){
			kostka->l();
			kostka->Wypisz();
			kostka->CzyUlozona();
		} else if (sign == 'F'){
			kostka->F();
			kostka->Wypisz();
			kostka->CzyUlozona();
		} else if (sign == 'f'){
			kostka->f();
			kostka->Wypisz();
			kostka->CzyUlozona();
		} else if (sign == 'R'){
			kostka->R();
			kostka->Wypisz();
			kostka->CzyUlozona();
		} else if (sign == 'r'){
			kostka->r();
			kostka->Wypisz();
			kostka->CzyUlozona();
		} else if (sign == 'B'){
			kostka->B();
			kostka->Wypisz();
			kostka->CzyUlozona();
		} else if (sign == 'b'){
			kostka->b();
			kostka->Wypisz();
			kostka->CzyUlozona();
		} else if (sign == 'D'){
			kostka->D();
			kostka->Wypisz();
			kostka->CzyUlozona();
		} else if (sign == 'd'){
			kostka->d();
			kostka->Wypisz();
			kostka->CzyUlozona();

		} else if (sign == 'q') {
			return 0;
		}
	}
}
