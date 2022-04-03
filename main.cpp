#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

class Zadanie81{
	ifstream we1;
	ifstream we2;
	ofstream wy;
	int t[100][6];
	int tr[100][6];
	
	public:
		Zadanie81();
		~Zadanie81();
		void zadania();
		void zadanie1();
		void zadanie2();
		void zadanie3();
		void zadanie4();
		void zadanie5();
};

Zadanie81::Zadanie81() {
	we1.open("wspolrzedne.txt");
	we2.open("wspolrzedneTR.txt");
	wy.open("wyniki.txt");	
}

void Zadanie81::zadania() {
	int i=0;
	int j=0;
	if(we1.good()) {
		while(!we1.eof()) {
			if(j==6) {
				j=0;
				i++;	
			}  
			we1>>t[i][j];
			j++;
		}
    }
    if(we2.good()) {
		while(!we2.eof()) {
			if(j==6) {
				j=0;
				i++;	
			}  
			we2>>t[i][j];
			j++;
		}
    }
    this->zadanie1();
    this->zadanie2();
    this->zadanie3();
    this->zadanie4();
    this->zadanie5();
}

void Zadanie81::zadanie1() {
	int ilosc=0;
	for(int i=0; i<100; i++) {
		if(t[i][0]>0 && t[i][1]>0 && t[i][2]>0 && t[i][3]>0 && t[i][4]>0 && t[i][5]>0) {
			ilosc++;	
		}
	}
	cout<<"Zadanie 1: "<<ilosc<<"\n";
	wy<<"Zadanie 1: "<<ilosc<<"\n";
}

void Zadanie81::zadanie2() {
	int ilosc=0;
	for(int i=0; i<100; i++) {
		if ((t[i][3]-t[i][1])*(t[i][4]-t[i][2]) == (t[i][5]-t[i][3])*(t[i][2]-t[i][0])) {
			ilosc++;
		}
	}
	cout<<"Zadanie 2: "<<ilosc<<"\n";
	wy<<"Zadanie 2: "<<ilosc<<"\n";
}

void Zadanie81::zadanie3() {
	int wspolrzedne[6];
	float max=0;
	for(int i=0; i<100; i++) {
		float bok1 = sqrt((tr[i][0]-tr[i][2])*(tr[i][0]-tr[i][2])+(tr[i][1]-tr[i][3])*(tr[i][1]-tr[i][3]));
		float bok2 = sqrt((tr[i][4]-tr[i][0])*(tr[i][4]-tr[i][0])+(tr[i][5]-tr[i][1])*(tr[i][5]-tr[i][1]));
		float bok3 = sqrt((tr[i][4]-tr[i][2])*(tr[i][4]-tr[i][2])+(tr[i][5]-tr[i][3])*(tr[i][5]-tr[i][3]));
		float obwod = bok1+bok2+bok3;
		if(obwod>max) {
			for(int j=0; j<6; j++)
				wspolrzedne[j] = tr[i][j];
			max = obwod;
		}
	}
	cout<<"Zadanie 3: A("<<wspolrzedne[0]<<","<<wspolrzedne[1]<<"), B("<<wspolrzedne[2]<<","<<wspolrzedne[3]<<"), C("<<wspolrzedne[4]<<","<<wspolrzedne[4]<<") "<<max<<"\n";
	wy<<"Zadanie 3: A("<<wspolrzedne[0]<<","<<wspolrzedne[1]<<"), B("<<wspolrzedne[2]<<","<<wspolrzedne[3]<<"), C("<<wspolrzedne[3]<<","<<wspolrzedne[4]<<") "<<max<<"\n";
}

void Zadanie81::zadanie4() {
	int ilosc=0;
	for(int i=0; i<100; i++) {
		float bok1 = (tr[i][0]-tr[i][2])*(tr[i][0]-tr[i][2])+(tr[i][1]-tr[i][3])*(tr[i][1]-tr[i][3]);
		float bok2 = (tr[i][4]-tr[i][0])*(tr[i][4]-tr[i][0])+(tr[i][5]-tr[i][1])*(tr[i][5]-tr[i][1]);
		float bok3 = (tr[i][4]-tr[i][2])*(tr[i][4]-tr[i][2])+(tr[i][5]-tr[i][3])*(tr[i][5]-tr[i][3]);
		if((bok1==bok2+bok3)||(bok2==bok1+bok3)||(bok3==bok1+bok2)) {
			ilosc++;
		}
	}
	cout<<"Zadanie 4: "<<ilosc<<"\n";
	wy<<"Zadanie 4: "<<ilosc<<"\n";
}

void Zadanie81::zadanie5() {
	cout<<"Zadanie 5: \n";
	wy<<"Zadanie 5: \n";
	int ilosc=0;
	for(int i=0; i<100; i++) {
		int x = tr[i][0]+tr[i][4]-tr[i][2];
		int y = tr[i][1]+tr[i][5]-tr[i][3];
		if (x == y) {
			ilosc++;
			cout<<"("<<tr[i][0]<<","<<tr[i][1]<<"), ("<<tr[i][2]<<","<<tr[i][3]<<"), ("<<tr[i][4]<<","<<tr[i][5]<<"), ("<<x<<","<<y<<");\n";
			wy<<"("<<tr[i][0]<<","<<tr[i][1]<<"), ("<<tr[i][2]<<","<<tr[i][3]<<"), ("<<tr[i][4]<<","<<tr[i][5]<<"), ("<<x<<","<<y<<");\n";
		}
	}
	cout<<"Ilosc - "<<ilosc;
	wy<<"Ilosc - "<<ilosc;
}

Zadanie81::~Zadanie81() {
	we1.close();
	we2.close();
	wy.close();
}

int main() {
	Zadanie81 z81;
	z81.zadania();
	return 0;
}
