#include <iostream>
#include <fstream>

using namespace std;

class Zadanie80{
	ifstream we;
	ofstream wy;
	int liczby[500];
	
	public:
		Zadanie80();
		~Zadanie80();
		void zadania();
		bool czyTrojkat(int, int, int);
		void zadanie1();
		void zadanie2();
		void zadanie3();
};

Zadanie80::Zadanie80() {
	we.open("dane_trojkaty.txt");
	wy.open("wyniki_trojkaty.txt");	
}

void Zadanie80::zadania() {
	if(we.good()) {
		int i=0;
		while(!we.eof()) {
			we>>liczby[i];
			i++;
		}
		this->zadanie1();
		this->zadanie2();
		this->zadanie3();
    }
}

bool Zadanie80::czyTrojkat(int a, int b, int c) {
	if((a+b>c) && (a+c>b) && (b+c>a))
		return true;
	return false;
}

void Zadanie80::zadanie1() {
	cout<<"Zadanie 1\n";
	wy<<"Zadanie 1\n";
	for(int i=0; i<500; i++) {
		int a = liczby[i];
		int b = liczby[i+1];
		int c = liczby[i+2];
		
		if(czyTrojkat(a, b, c)) {
			int d;
			if(a>b && a>c) {
				d = c;
				c = a; 
				a = d;
			} else {
				if(b>a && b>c) {
					d = c;
					c = b; 
					b = d;
				}
			}
			if(c*c == a*a + b*b) {
				cout<<a<<", "<<b<<", "<<c<<"\n";
				wy<<a<<", "<<b<<", "<<c<<"\n";
			}
		}
	}
}

void Zadanie80::zadanie2() {
	cout<<"\nZadanie 2\n";
	wy<<"\nZadanie 2\n";
	int a, b, c;
	int maxObw = 0;
	for(int i=0; i<500; i++) {
		a = liczby[i];	
		for(int j=i+1; j<500; j++) {
			b = liczby[j];	
			for(int k=j+1; k<500; k++) {
				c = liczby[k];	
				if(czyTrojkat(a, b, c)) {
					if(a+b+c>maxObw) maxObw = a+b+c;
				}			
			}
		}
	}
	cout<<maxObw<<"\n";
	wy<<maxObw<<"\n";
}

void Zadanie80::zadanie3() {
	cout<<"\nZadanie 3\n";
	wy<<"\nZadanie 3\n";
	int a, b, c;
	int ilosc = 0;
	for(int i=0; i<500; i++) {
		a = liczby[i];	
		for(int j=i+1; j<500; j++) {
			b = liczby[j];	
			for(int k=j+1; k<500; k++) {
				c = liczby[k];	
				if(czyTrojkat(a, b, c)) {
					ilosc++;
				}			
			}
		}
	}
	cout<<ilosc<<"\n";
	wy<<ilosc<<"\n";
}

Zadanie80::~Zadanie80() {
	we.close();
	wy.close();
}

int main() {
	Zadanie80 z80;
	z80.zadania();
	return 0;
}
