#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

void parcurgereVector(int dim, int* vector) {
	cout << endl << "Parcurgere vector:";
	for (int i = 0; i < dim; i++) {
		cout << endl << "Vector[" << i << "] ="<<vector[i];
	}
}

int pozitieMaximInVector(int* vector, int dimensiune) {
	int iMax = 0;
	for (int i = 1; i < dimensiune; i++) {
		if (vector[i] > vector[iMax]) {
			iMax = i;
		}
	}
	return iMax;
}

void stergereDePePozitieDinVector(int*  &vector, int &dimensiune, int pozitieMaxim) {
	int* temp = new int[dimensiune - 1];
	int contor = 0;
	for (int i = 0; i < dimensiune; i++) {
		if (i != pozitieMaxim) {
			temp[contor] = vector[i];
			contor++;
		}
	}
	//dezalocam
	delete[] vector;
	vector = temp;
	dimensiune--;
}

//transmitere param prin referinta
void stergereMaximVector(int* &vector, int &dimensiune) {
	int pozitieMaxim = pozitieMaximInVector(vector, dimensiune);
	stergereDePePozitieDinVector(vector, dimensiune,pozitieMaxim);
}

//tema: aceeasi functie, dar cu transmitere param prin pointer

char* transformareInLitereMari(const char* sir) {

	char* sirCuLitereMari = new char[strlen(sir) + 1];
	strcpy(sirCuLitereMari, sir);

	for (int i = 0; i < strlen(sir); i++) {
		if (sirCuLitereMari[i] >= 'a' && sirCuLitereMari[i] <= 'z') {
			sirCuLitereMari[i] -= 32;
		}
	}
	return sirCuLitereMari;
}

void main() {
	char denumire[20];
	std::cout << std::endl << "Denumire: ";
	//std::cin.getline(denumire, 20);
	//std::cout << std::endl << "Denumire: "<<denumire;

	char* cnp;

	char buffer[20];
	std::cout << std::endl << "Cnp: ";
	//cin >> buffer;
	//cnp = new char[strlen(buffer) + 1];
	//strcpy_s(cnp, strlen(buffer) + 1, buffer);
	//strcpy(cnp, buffer);

	//std::cout << std::endl << "Cnp: "<<cnp;

	//Vectori

	int* vector;
	int dimensiune = 10;

	vector = new int[dimensiune];

	//citim de la tastatura vectorul
	for (int i = 0; i < dimensiune; i++) {
		cout << endl << "Vector[" << i << "] = ";
		cin >> vector[i];
	}

	//parcurgem vectorul
	parcurgereVector(dimensiune, vector);

	//pozitia pe care se afla maximul
	cout << endl << "Pozitia pe care se afla maximul este: " << pozitieMaximInVector(vector, dimensiune);

	stergereMaximVector(vector, dimensiune);

	parcurgereVector(dimensiune, vector);

	stergereDePePozitieDinVector(vector, dimensiune, 0);

	parcurgereVector(dimensiune, vector);

	char sir[] = "Hello world";
	char* sirLitereMari = transformareInLitereMari(sir);
	cout << endl << "Sir modificat: " << sirLitereMari;

	//dezalocare
	delete[] vector;
	delete[] sirLitereMari;
}