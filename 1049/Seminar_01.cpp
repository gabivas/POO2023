#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

struct Masina {
	char* marca;
	char* culoare;
	int anFabricatie;
	float capacitateMotor;
};

void afisareMasina(Masina masina);

int suma() {
	int vector[] = { 10, 7, 23, 15, 700 };
	int suma = vector[0];
	int dimensiune = 5;
	for (int i = 1; i < dimensiune; i++) {
		suma += vector[i];
	}
	return suma;
}

int main() {
	Masina masina;
	masina.marca = new char[strlen("Audi") + 1];
	strcpy(masina.marca, "Audi");
	masina.culoare = new char[strlen("Negru") + 1];
	strcpy_s(masina.culoare, strlen("Negru") + 1, "Negru");
	masina.anFabricatie = 2023;
	masina.capacitateMotor = 2.5f;

	afisareMasina(masina);

	//dezalocare pentru a evita memory leaks
	delete[] masina.culoare;
	delete[] masina.marca;

	int sumaNr = suma();
	cout << endl << "Suma este: " << sumaNr;

	int* adresaSuma = &sumaNr;

	cout << endl << "Adresa este: " << &sumaNr;
	cout << endl << "Adresa este: " << adresaSuma;

	//dereferentiere
	cout << endl << "Valoarea din adresaSuma este: " << *adresaSuma;

	int* pointer = nullptr;
	cout << endl << pointer;
	if (pointer == nullptr) {
		//throw "Vector nealocat";
	}
	else {
		//codul nu ajunge sa fie executat aici
		cout << endl << "Vector alocat dinamic";
	}

	return 0;
}

void afisareMasina(Masina masina) {
	cout << endl << " Masina " << masina.marca <<
		" are culoarea " << masina.culoare << ", a fost fabricata in anul " << masina.anFabricatie << ", are o capacitate de " << masina.capacitateMotor<<" cm cubi.";
}