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
		this->locatie = new char[strlen(locatie) + 1];
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

	Banca(const Banca& copie) :nume(copie.nume) {
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

	void operator=(const Banca& copie) {
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

	void operator*=(int multiplicator) {
		this->nrAngajati *= multiplicator;
	}

	bool operator<=(const Banca& banca)
	{
		return this->nrAngajati <= banca.nrAngajati;
	}

	bool operator>(const Banca& banca)
	{
		return this->nrAngajati > banca.nrAngajati;
	}

	//op negatie
	bool operator!() {
		return this->nrAngajati == 0;
	}

	//operator functie
	int operator()(int valoare) {
		return this->nrAngajati + valoare;
	}

	//operatorul index
	char& operator[](int index) {
		if (index >= 0 && index < strlen(this->locatie)) {
			return this->locatie[index];
		}
		else {
			throw "Indexul nu se afla in intervalul corespunzator";
		}
	}

	friend void operator<<(ostream& out, Banca b ) {
		out << endl << "Nr angajati: " << b.nrAngajati;
		out << endl << "Nume: " << b.nume;
		out << endl << (b.areProfit ? "Are profit" : "Nu are profit");
		out << endl << (b.locatie!= nullptr ? "Locatie: " + string(b.locatie) : "Locatie default");
	}

	friend void operator>>(istream& in, Banca& b);
};

void operator>>(istream& in, Banca& b) {
	//atributele const(nume) nu se modifica
	cout << endl << "Nr angajati: ";
	in >> b.nrAngajati;
	cout << endl << "Locatie: ";
	if (b.locatie != nullptr) {
		delete[] b.locatie;
		b.locatie = nullptr;
	}
	char buffer[50];
	in >> buffer;
	b.locatie = new char[strlen(buffer) + 1];
	strcpy_s(b.locatie, strlen(buffer) + 1, buffer);
	cout << endl << "Are profit? y/n";
	string areProfit;
	in >> areProfit;
	b.areProfit = (areProfit == "y" ? true : false);
}

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

	Banca bt("BT", "Romana", 20, true);
	Banca brd("BRD", "Unirii", 30, true);

	bt *= 2;
	bt.afisare();

	if (brd <= bt) {
		cout << endl << "Brd are mai putini angajati sau un numar egal.";
	}
	else {
		cout << endl << "Brd are mai multi angajati";
	}

	if (brd > bt) {
		cout << endl << "Brd are mai multi angajati.";
	}
	else {
		cout << endl << "Brd are mai putini angajati sau un numar egal";
	}

	if (!brd) {
		cout << endl << "Brd nu are angajati";
	}

	cout<<endl<<"Operator functie: "<<brd(3);

	cout << endl << "A doua litera este:" << brd[1];

	brd[1] = 'm';
	brd.afisare();

	cout << brd;
	cin >> brd;
	cout << brd;

	//brd + 10;
	//10 + brd;
	//cout << brd;
}