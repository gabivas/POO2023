#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

void parcurgereVector(int* vector, int dimensiune) {
	for (int i = 0; i < dimensiune; i++) {
		cout << endl << "Vector[" << i << "] = "<<vector[i];
	}
}

int pozitieMaxim(int* vector, int dim) {
	int pozitieMaximCautata = 0;
	for (int i = 1; i < dim; i++) {
		if (vector[pozitieMaximCautata] < vector[i]) {
			pozitieMaximCautata = i;
		}
	}
	return pozitieMaximCautata;
}
void stergereDePePozitieVector(int* &vector, int pozitieMax, int &dim) {
	int* aux = new int[dim - 1];
	int contor = 0;
	for (int i = 0; i < dim; i++) {
		if (i != pozitieMax) {
			aux[contor] = vector[i];
			contor++;
		}
	}
	//dezalocam vectorul vechi
	delete[] vector;
	vector = aux;
	dim--;
}

//tema: aceeasi functie, dar folosind transmitere prin pointer
void stergereMaximVector(int* &vector, int &dim) {
	int pozitieMax = pozitieMaxim(vector, dim);
	stergereDePePozitieVector(vector, pozitieMax, dim);
}

char* modificareInLitereMari(const char* mesaj) {
	char* mesajCuLitereMari = new char[strlen(mesaj)+1];
	strcpy(mesajCuLitereMari, mesaj);

	for (int i = 0; i < strlen(mesaj); i++) {
		if (mesajCuLitereMari[i] >= 'a' && mesajCuLitereMari[i] <= 'z') {
			mesajCuLitereMari[i] -= 32;
		}
	}
	return mesajCuLitereMari;
}

void main() {
	char adresa[20];
	char* marca;

	std::cout << std::endl << "Adresa este: ";
	std::cin.getline(adresa, 20);
	std::cout << std::endl << "Adresa este: "<<adresa;

	char buffer[50];
	std::cout << std::endl << "Marca este: ";
	cin >> buffer;

	//alocam memorie
	marca = new char[strlen(buffer) + 1];
	strcpy(marca, buffer);

	std::cout << std::endl << "Marca este: "<<marca;

	//vectori
	int* vector;
	int dimensiune = 5;

	vector = new int[dimensiune];
	for (int i = 0; i < dimensiune; i++) {
		cout << endl << "Vector[" << i << "] = ";
		cin >> vector[i];
	}

	parcurgereVector(vector, dimensiune);

	cout << endl << "Pozitie maxim: " << pozitieMaxim(vector, dimensiune);

	stergereMaximVector(vector, dimensiune);
	parcurgereVector(vector, dimensiune);

	char mesaj[] = "Seminar 02";

	char* mesajLitereMari = modificareInLitereMari(mesaj);
	cout << endl << "Mesajul este: " << mesajLitereMari;
}