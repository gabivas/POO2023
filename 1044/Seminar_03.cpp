#include<iostream>
#include<string>

using namespace std;

enum Combustibil { BENZINA=1, MOTORINA=2, ELECTRIC=3};

class Masina {
private:

public:
	char* culoare = nullptr;
	string marca = "Neidentificata";
	int nrKm = 0;
	float pret = 0.0f;
	Combustibil combustibil = BENZINA;

	void actualizareKm(int nrKmActuali) {
		nrKm = nrKmActuali;
	}

	void afisareMasina() {
		cout << endl << "Masina " << marca << " de culoare ";
		if (culoare != nullptr)
			cout << culoare;
		else {
			cout << "Neidentificata";
		}
		cout<< " are " << nrKm << " km, a fost cumparata la pretul de " << pret << " euro. Combustibilul este ";
		if (combustibil == 1) {
			cout << "BENZINA";
		}
		else if (combustibil == 2) {
			cout << "MOTORINA";
		}
		else {
			cout << "ELECTRIC";
		}
	}

protected:

};

void afisareMasina(Masina m) {
	cout << endl << "Masina " << m.marca << " de culoare ";
	if (m.culoare != nullptr)
		cout << m.culoare;
	else {
		cout << "Neidentificata";
	}
	cout << " are " << m.nrKm << " km, a fost cumparata la pretul de " << m.pret << " euro. Combustibilul este ";
	if (m.combustibil == 1) {
		cout << "BENZINA";
	}
	else if (m.combustibil == 2) {
		cout << "MOTORINA";
	}
	else {
		cout << "ELECTRIC";
	}
}

void main() {
	//Masina este clasa, masina este obiectul
	Masina masina;
	masina.culoare = new char[strlen("Negru") + 1];
	strcpy_s(masina.culoare, strlen("Negru") + 1, "Negru");
	masina.marca = "Dacia";
	masina.nrKm = 0;
	masina.pret = 6000.0f;
	masina.combustibil = BENZINA;

	masina.afisareMasina();

	//constructorul default
	Masina* masina2 = new Masina();
	masina2->nrKm = 1000;
	masina2->afisareMasina();
	//echivalente
	//(*masina2).afisareMasina();

	//shallow copy
	Masina* masina3 = &masina;

	Masina* masina4 = masina2;

	masina3->afisareMasina();
	masina4->actualizareKm(700);
	masina4->afisareMasina();
	masina2->afisareMasina();

	int dimensiune = 5;
	Masina* masini = new Masina[dimensiune];
	for (int i = 0; i < dimensiune; i++) {
		masini[i].culoare = new char[strlen("Gri") + 1];
		strcpy_s(masini[i].culoare, strlen("Gri") + 1, "Gri");
		masini[i].marca = "Ford";
		masini[i].nrKm = 50;
		masina.pret = 15000.0f;
		masini[i].combustibil = ELECTRIC;
	}

	for (int i = 0; i < dimensiune; i++) {
		afisareMasina(masini[i]);
	}

	//dezalocare memorie
	delete masina2;
	delete masina.culoare;
	for (int i = 0; i < dimensiune; i++) {
		delete masini[i].culoare;
	}
	delete[] masini;

}