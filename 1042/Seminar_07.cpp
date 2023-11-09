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

	Biblioteca(string adresa, const char* denumire, int nrCarti, bool esteInchisa) :adresa(adresa), nrCarti(nrCarti) {
		this->esteInchisa = esteInchisa;
		this->denumire = new char[strlen(denumire) + 1];
		memcpy(this->denumire, denumire, strlen(denumire) + 1);
	}

	void afisare() {
		cout << endl << endl << "Afisare biblioteca: ";
		cout << endl << "Adresa: " << this->adresa;
		if (this->denumire != nullptr)
			cout << endl << "Denumire: " << this->denumire;
		cout << endl << "Nr carti: " << this->nrCarti;
		if (esteInchisa)
			cout << endl << "Biblioteca este inchisa!";
		else {
			cout << endl << "Biblioteca este deschisa!";
		}
	}

	//constructor de copiere
	Biblioteca(const Biblioteca& copie) : adresa(copie.adresa) {
		//nu se poate, adresa este const
		//this->adresa = copie.adresa;
		this->denumire = new char[strlen(copie.denumire) + 1];
		memcpy(this->denumire, copie.denumire, strlen(copie.denumire) + 1);
		this->esteInchisa = copie.esteInchisa;
		this->nrCarti = copie.nrCarti;
	}

	//supraincarcare operator =
	void operator=(const Biblioteca& copie)
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

	bool operator<(const Biblioteca& copie) {
		return this->nrCarti < copie.nrCarti;
	}

	bool operator!() {
		return this->nrCarti == 0;
	}

	float operator()(int nrLuni) {
		if (nrLuni != 0)
			return this->nrCarti / nrLuni;
		else return 0;
	}
	float operator()() {
		return this->nrCarti / 12;
	}

	char& operator[](int index) {
		if(index>=0 && index<strlen(this->denumire))
		return this->denumire[index];
		else {
			throw "Index in afara intervalului";
		}
	}

	//postincrementare
	//int operator++(int ceva) {
	//	return this->nrCarti++;
	//}

	//void operator++() {
	//	this->nrCarti++;
	//}

	friend void operator<<(ostream& out, Biblioteca b) {
		out << endl << "Adresa: " << b.adresa;
		out << endl << "Nr carti: " << b.nrCarti;
		out << endl << (b.esteInchisa ? "Este inchisa" : "Este deschisa");
		out << endl << (b.denumire != nullptr ? "Denumire: "+string(b.denumire) : "Denumire default");
	}

	friend void operator>>(istream& in, Biblioteca& b);
};

void operator>>(istream& in, Biblioteca& b) {
	cout << endl << "Nr carti: ";
	in >> b.nrCarti;
	cout << endl << "Este inchisa? y/n";
	string esteInchisa;
	in >> esteInchisa;
	if (esteInchisa == "y") {
		b.esteInchisa = true;
	}
	else {
		b.esteInchisa = false;
	}

	if (b.denumire != nullptr) {
		delete[] b.denumire;
		b.denumire = nullptr;
	}
	cout << endl << "Denumire: ";
	char buffer[50];
	in >> buffer;
	b.denumire = new char[strlen(buffer) + 1];
	strcpy_s(b.denumire, strlen(buffer) + 1, buffer);
}

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

	Biblioteca bib1("Universitate", "Biblioteca", 12000, false);
	Biblioteca bib2("Unirii", "Biblioteca", 15000, false);
	cout << endl << endl;
	if (bib1 < bib2) {
		cout << endl << "Bib1 are mai putine carti.";
	}
	else {
		cout << endl << "Bib1 are mai multe carti sau numar egal.";
	}

	if (!bib1) {
		cout << endl << "Bib1 are 0 carti";
	}

	bool esteDeschis = true;
	if (!esteDeschis) {
	//mesaj la consola
	}

	cout << endl <<"Media: "<< bib1(12);
	cout << endl <<"Media: "<< bib1();
	cout << endl <<"Caracter de pe pozitia 1 din bib1: "<< bib1[1];
	bib1[1] = 'B';
	bib1.afisare();

	cout << endl << "Bib1";
	cout << bib1;
	//cin >> bib1;

	//bib1++;

	//int a = 5;
	//int b = ++a;
	//int b = a++;
	cout << bib1;
}