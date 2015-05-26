#ifndef SCIANA_H
#define SCIANA_H

#include <string>
#include "stdio.h"
#include <sstream>

using namespace std;

class Scianka {
	private:
		char *Tab;
		char *TabCopy;
		const char KolorSrodka;
		const static int MIDDLE_IDX = 4;
		void shiftRight();
		void shiftLeft();
		void fillArrayToPrint();
	public:
		void ObrotC();
		void ObrotAC();

		friend void Obrot(Scianka &A,int a1,int a2,int a3,Scianka &B,int b1,int b2,int b3,Scianka &C,int c1,int c2,int c3,Scianka &D,int d1,int d2,int d3) throw (string);

		Scianka(char kolor) : KolorSrodka(kolor) {
			TabCopy = new char[8];
			Tab = new char[8];

			for (int i = 0; i < 8; i++) {
				TabCopy[i] = KolorSrodka;
				TabCopy[i] = KolorSrodka;
			}
			fillArrayToPrint();
		}

		~Scianka() {
			delete [] Tab;
		}

		void Wypisz(int x) {
			switch(x) {
				case 1 :  {
						  printf(" ");
						  for (int j = 0; j < 3; j++) {
							  printf("%c ", Tab[j]);
						  }
					  };
					  break;
				case 2 : {
						 printf(" ");
						 printf("%c %c %c ", Tab[3],KolorSrodka,Tab[4]);
					 };
					 break;
				case 3 : {
						 printf(" ");
						 for (int j = 5; j < 8; j++) {
							 printf("%c ", Tab[j]);
						 }
					 }; 
					 break;
				default : {

					  }; 
					  break;
			}
		}
		
		char getMidColor() {
			return KolorSrodka;
		}			

		void Wypisz(char tabulator) {
			printf("%c %c %c %c \n",tabulator, Tab[0], Tab[1], Tab[2]);
			printf("%c %c %c %c \n",tabulator, Tab[3], KolorSrodka, Tab[4]);
			printf("%c %c %c %c ",tabulator, Tab[5], Tab[6], Tab[7]);
		}

		void Set(int x, char sign) {
			switch(x) {
				case 0 : TabCopy[0] = sign;
				break;
				case 1 : TabCopy[1] = sign;
				break;
				case 2 : TabCopy[2] = sign;
				break;
				case 3 : TabCopy[7] = sign;
				break;
				case 4 : TabCopy[3] = sign;
				break;
				case 5 : TabCopy[6] = sign;
				break;
				case 6 : TabCopy[5] = sign;
				break;
				case 7 : TabCopy[4] = sign;
				break;
			}
			Tab[x] = sign;
		}

		void SetSimple(int x, char sign) throw (int){
			if (x > sizeof(Tab)/sizeof(Tab[0]) || x < 0 || x > sizeof(TabCopy)/sizeof(TabCopy[0])) {
				throw x;
			}
			TabCopy[x] = Tab[x] = sign;
		}
		
		char Get(int x) throw (int){
			if (x > sizeof(Tab)/sizeof(Tab[0]) || x < 0) {
				throw x;
			}
			return Tab[x];
		}
};

void Obrot(Scianka &A,int a1,int a2,int a3,Scianka &B,int b1,int b2,int b3,Scianka &C,int c1,int c2,int c3,Scianka &D,int d1,int d2,int d3) throw(string){
	try {
	char tmpCol1 = B.Get(b1);

	B.Set(b1, A.Get(a1));

	char tmpCol2 = C.Get(c1);

	C.Set(c1, tmpCol1);
	tmpCol1 = D.Get(d1);
	D.Set(d1, tmpCol2);
	A.Set(a1, tmpCol1);



	tmpCol1 = B.Get(b2);

	B.Set(b2, A.Get(a2));

	tmpCol2 = C.Get(c2);

	C.Set(c2, tmpCol1);
	tmpCol1 = D.Get(d2);
	D.Set(d2, tmpCol2);
	A.Set(a2, tmpCol1);



	tmpCol1 = B.Get(b3);

	B.Set(b3, A.Get(a3));

	tmpCol2 = C.Get(c3);

	C.Set(c3, tmpCol1);
	tmpCol1 = D.Get(d3);
	D.Set(d3, tmpCol2);
	A.Set(a3, tmpCol1);
	} catch (int wrongInd) {
		ostringstream result;
		result << "Podano zly index dla getter' a lub setter' a, zły index to : " << wrongInd;
		throw result.str();
	}
}


void Scianka::ObrotAC() {
	for (int i = 0; i < 2; i++) {
		shiftRight();

		fillArrayToPrint();
	}
}

void Scianka::ObrotC() {
	for (int i = 0; i < 2; i++) {
		shiftLeft();

		fillArrayToPrint();
	}
}


void Scianka::fillArrayToPrint() {

	Tab[0] = TabCopy[0];
	Tab[1] = TabCopy[1];
	Tab[2] = TabCopy[2];
	Tab[3] = TabCopy[7];
	Tab[4] = TabCopy[3];
	Tab[5] = TabCopy[6];
	Tab[6] = TabCopy[5];
	Tab[7] = TabCopy[4];	

}

void Scianka::shiftRight() {
	char tmp;
	for (int j = 0; j < 7; j++) {
		tmp = TabCopy[j+1];
		TabCopy[j+1] = TabCopy[j];
		TabCopy[j]=tmp;
	}
}

void Scianka::shiftLeft() {
	char tmp;
	for (int j = 7; j > 0; j--) {
		tmp = TabCopy[j-1];
		TabCopy[j-1] = TabCopy[j];
		TabCopy[j]=tmp;
	}
}	

#endif
