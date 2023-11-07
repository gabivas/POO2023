#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

using namespace std;

class Banca {
private:
	const string nume;
	char* locatie = nullptr;
	int nrAngajati = 0;
	bool areProfit = true;

public:
	Banca() :nume("Necunoscut") {
	}

	Banca(string numeB, const char* locatie, int nrAngajati, bool areProfit) :nume(numeB) {
		//asa nu
		//this->nume = nume;
		this->areProfit = areProfit;
		this->nrAngajati = nrAngajati;
		this->locatie = new char[strlen(locatie)+1];
		memcpy(this->locatie, locatie, strlen(locatie) + 1);
	}

	void afisare() {
		cout << endl << endl << "Banca:";
		cout << endl << "Nume: " << this->nume;
		if (this->locatie != nullptr) {
			cout << endl << "Locatie: " << this->locatie;
		}
		cout << endl << "Nr angajati: " << this->nrAngajati;
		if (this->areProfit) {
			cout << endl << "Banca are profit.";
		}
		else {
			cout << endl << "Banca nu are profit.";
		}
	}

	~Banca() {
		delete[] this->locatie;
	}

	Banca(const Banca &copie) :nume(copie.nume) {
		this->areProfit = copie.areProfit;
		this->nrAngajati = copie.nrAngajati;
		//this->locatie = copie.locatie;
		if (copie.locatie != nullptr) {
			this->locatie = new char[strlen(copie.locatie) + 1];
			memcpy(this->locatie, copie.locatie, strlen(copie.locatie) + 1);
		}
		else {
			this->locatie = nullptr;
		}
	}

	void operator=(const Banca &copie) {
		//this->nume = copie.nume;
		this->nrAngajati = copie.nrAngajati;
		this->areProfit = copie.areProfit;

		if (this->locatie != nullptr) {
			delete[] this->locatie;
			this->locatie = nullptr;
		}
		//this->locatie = copie.locatie;
		if (copie.locatie != nullptr) {
			this->locatie = new char[strlen(copie.locatie) + 1];
			memcpy(this->locatie, copie.locatie, strlen(copie.locatie) + 1);
		}
		else {
			this->locatie = nullptr;
		}
		//return *this;
	}
};

void main() {
	Banca banca;
	Banca bnr("BNR", "Piata Unirii", 150, true);
	banca.afisare();
	bnr.afisare();

	Banca bcr = bnr;
	bcr.afisare();

	bcr = banca;
	bcr.afisare();

	Banca* ing = new Banca(bnr);
	Banca* alpha = new Banca(bnr);
	ing = alpha;
	ing->afisare();
}