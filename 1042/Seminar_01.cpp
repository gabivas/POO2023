#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

using namespace std;

struct DatePersonale {
	char* nume;
	char* prenume;
	int varsta;
	float inaltime;
};

void afisareDatePersonale(DatePersonale date);

int sumaNumereIntregi() {
	int dimensiune = 5;
	int vectorNumere[] = { 1, 2, 3, 4, 7 };
	int suma = vectorNumere[0];
	for (int i = 1; i < dimensiune; i++) {
		//suma = suma + vectorNumere[i];
		suma += vectorNumere[i];
	}
	return suma;
}

int main() {
	DatePersonale datePersonale;
	datePersonale.varsta = 20;
	datePersonale.inaltime = 1.75f;
	//Popescu
	datePersonale.nume = new char[strlen("Popescu") + 1];
	strcpy(datePersonale.nume, "Popescu");
	datePersonale.prenume = new char[strlen("Andrei") + 1];
	//strcpy_s si care este diferenta intre strcpy si strcpy_s
	//mai are un param, dimensiunea sirului
	strcpy(datePersonale.prenume, "Andrei");

	afisareDatePersonale(datePersonale);

	delete[] datePersonale.nume;
	delete[] datePersonale.prenume;

	cout <<endl<< "Suma este: "<< sumaNumereIntregi();

	int suma = sumaNumereIntregi();
	int* suma2 = &suma;

	//dereferentiere
	cout << endl << "Suma2 este: " << *suma2;


	cout << endl << "Adresa lui suma2 este: " << suma2;
	cout << endl << "Adresa lui suma este: " << &suma;

	int* vector = nullptr;
	cout << endl << vector;
	if (vector == nullptr) {
		//ar trebui initializat
		//daca apar probleme:
		//throw "Vectorul este gol!";
	}
	if (vector != nullptr) {
		//aceasta linie nu se executa
		cout << endl << vector;
	}

	return 0;
}

void afisareDatePersonale(DatePersonale date) {
	//std::cout<<
	cout << "Datele personale sunt: nume-" << date.nume << ", prenume-" << date.prenume << ", varsta-" << date.varsta <<
		", inaltime-" << date.inaltime;
}

