#include<iostream>
#include<string>

using namespace std;

enum Dimensiune{ SUPERMARKET, MINIMARKET, HYPERMARKET};

class Magazin {
private:

public:
	//atributele clasei
	char* denumire = nullptr;
	string locatie = "Necunoscuta";
	int nrAngajati = 0;
	float profit = 0.0f;
	Dimensiune dimensiune = MINIMARKET;

	void afisareMagazin() {
	if (denumire != nullptr) {
		cout << endl << "Magazinul " << denumire;
	}
	else {
		cout << endl << "Magazinul Neidentificat";
	}
	cout<< " se afla la adresa "<<locatie<<", are "<<nrAngajati<<" angajati, un profit de "<<profit<<" lei si este de tipul ";
	if (dimensiune == 0) {
		cout << "SUPERMARKET";
	}
	else if (dimensiune == 1) {
		cout << "MINIMARKET";
	}
	else {
		cout << "HYPERMARKET";
	}
	}

	void modificaProfit(float noulProfit) {
		profit = noulProfit;
	}

protected:

};

void afisareMagazin(Magazin m) {
	if (m.denumire != nullptr) {
		cout << endl << "Magazinul " << m.denumire;
	}
	else {
		cout << endl << "Magazinul Neidentificat";
	}
	cout << " se afla la adresa " << m.locatie << ", are " << m.nrAngajati << " angajati, un profit de " << m.profit << " lei si este de tipul ";
	if (m.dimensiune == 0) {
		cout << "SUPERMARKET";
	}
	else if (m.dimensiune == 1) {
		cout << "MINIMARKET";
	}
	else {
		cout << "HYPERMARKET";
	}

}

void main() {
	//Magazin este clasa si magazin este obiectul
	Magazin magazin;
	magazin.denumire = new char[strlen("MegaImage") + 1];
	strcpy_s(magazin.denumire, strlen("MegaImage") + 1, "MegaImage");
	magazin.locatie = "Romana";
	magazin.nrAngajati = 5;
	magazin.profit = 17000.50f;
	magazin.dimensiune = MINIMARKET;
	magazin.afisareMagazin();

	//am apelat constructorul default
	Magazin* magazin2 = new Magazin();
	//(*magazin2).afisareMagazin();
	magazin2->afisareMagazin();

	//shallow copy
	Magazin* magazin3 = &magazin;
	magazin3->modificaProfit(100000.0f);
	Magazin * magazin4 = magazin2;
	magazin3->locatie = "Victorie";

	magazin3->afisareMagazin();
	magazin4->afisareMagazin();

	int dim = 3;
	Magazin* magazine = new Magazin[dim];
	for (int i = 0; i < dim; i++) {
		magazine[i].denumire = new char[strlen("Lidl") + 1];
		strcpy_s(magazine[i].denumire, strlen("Lidl") + 1, "Lidl");
		magazine[i].locatie = "Unirii";
		magazine[i].nrAngajati = 50;
		magazine[i].profit = 200000.50f;
		magazine[i].dimensiune = SUPERMARKET;
		afisareMagazin(magazine[i]);
	}

	//dezalocare memorie
	delete magazin.denumire;
	delete magazin2;
	for (int i = 0; i < dim; i++) {
		delete magazine[i].denumire;
	}
	delete[] magazine;
}