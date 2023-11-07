#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

using namespace std;

class Biblioteca {
private:
	const string adresa;
	char* denumire = nullptr;
	int nrCarti = 0;
	bool esteInchisa = false;
public:
	
	Biblioteca() : adresa("Piata Romana") {
		//this->adresa = "Piata Romana";
	}

	Biblioteca(string adresa, const char* denumire, int nrCarti, bool esteInchisa) :adresa(adresa), nrCarti(nrCarti){
		this->esteInchisa = esteInchisa;
		this->denumire = new char[strlen(denumire) + 1];
		memcpy(this->denumire, denumire, strlen(denumire) + 1);
	}

	void afisare() {
		cout << endl<<endl << "Afisare biblioteca: ";
		cout << endl << "Adresa: " << this->adresa;
		if(this->denumire !=nullptr)
		cout << endl << "Denumire: " << this->denumire;
		cout << endl << "Nr carti: " << this->nrCarti;
		if (esteInchisa)
			cout << endl << "Biblioteca este inchisa!";
		else {
			cout << endl << "Biblioteca este deschisa!";
		}
	}

	//constructor de copiere
	Biblioteca(const Biblioteca& copie) : adresa(copie.adresa){
		//nu se poate, adresa este const
		//this->adresa = copie.adresa;
		this->denumire = new char[strlen(copie.denumire) + 1];
		memcpy(this->denumire, copie.denumire, strlen(copie.denumire) + 1);
		this->esteInchisa = copie.esteInchisa;
		this->nrCarti = copie.nrCarti;
	}

	//supraincarcare operator =
	void operator=(const Biblioteca &copie)
	{//nu copiem constantele
		this->nrCarti = copie.nrCarti;
		this->esteInchisa = copie.esteInchisa;
		if (this->denumire) {
			delete[] this->denumire;
			this->denumire = nullptr;
		}
		if (copie.denumire) {
			this->denumire = new char[strlen(copie.denumire) + 1];
			memcpy(this->denumire, copie.denumire, strlen(copie.denumire) + 1);
		}
		else {
			this->denumire = nullptr;
		}

		//return *this;
	}

	void operator*=(int nrCarti) {
		this->nrCarti *= nrCarti;
		//return *this;
	}

	bool operator<=(const Biblioteca& copie)
	{
		return this->nrCarti <= copie.nrCarti;
	}

};

void main() {
	Biblioteca biblioteca1;
	Biblioteca biblioteca2("Piata Unirii", "Biblioteca Centrala", 10000, false);

	biblioteca1.afisare();
	biblioteca2.afisare();

	Biblioteca biblioteca3 = biblioteca2;
	biblioteca3.afisare();

	biblioteca3 = biblioteca1;
	biblioteca3.afisare();

	biblioteca2 *= 3;
	biblioteca2.afisare();

	if (biblioteca2 <= biblioteca3) {
		cout << endl << "Biblioteca2 are mai putine carti sau acelasi nr";
	}
	else {
		cout << endl << "Biblioteca2 are mai multe carti";
	}
	
}