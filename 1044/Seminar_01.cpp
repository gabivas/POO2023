#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

struct GrupaStudenti {
	int nrStudenti;
	char* nume;
	float medie;
};

void afisareGrupaStudenti(GrupaStudenti grupaStud);

int sumaNrIntregi() {
	int dimensiune = 5;
	int vector[] = { 3,5,7,9,11 };
	int suma = vector[0];
	for (int i = 1; i < dimensiune; i++) {
		//suma = suma + vector[i];
		suma += vector[i];
	}
	return suma;
}

int main() {
	GrupaStudenti grupa;
	grupa.nrStudenti = 26;
	grupa.medie = 6.72f;
	grupa.nume = new char[strlen("Gr1044") + 1];
	strcpy(grupa.nume, "Gr1044");
	//strcpy_s(grupa.nume, strlen("Gr1044") + 1, "Gr1044");

	//apel functie afisareGrupaStudenti
	afisareGrupaStudenti(grupa);

	delete[] grupa.nume;

	int suma = sumaNrIntregi();
	cout <<endl<< "Suma nr intregi este: " << suma;

	int* adresaSuma = &suma;

	cout << endl << "Adresa pentru suma: " << &suma;
	cout << endl << "Adresa pentru adresaSuma: " << adresaSuma;

	//dereferentiere
	cout << endl << "Suma nr intregi este: " << *adresaSuma;

	int* vector = nullptr;
	if (vector == nullptr) {
		//throw "Vector null";
		cout << endl << vector;
	}
	else {
		//nu se executa
		cout << endl << " Vectorul nu este null";
	}

	return 0;
}

void afisareGrupaStudenti(GrupaStudenti grupaStud) {
	cout << endl << "Grupa " << grupaStud.nume << " are " << grupaStud.nrStudenti << " studenti si media este de " << grupaStud.medie;
}