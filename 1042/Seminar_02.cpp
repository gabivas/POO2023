#include<iostream>

using namespace std;
//pozitie maxim in vector
int pozitieMaximVector(int* vector, int dim) {
	int pozitieMax = 0;
	for (int i = 1; i < dim; i++) {
		if (vector[pozitieMax] < vector[i]) {
			pozitieMax = i;
		}
	}
	return pozitieMax;
}

void stergereElementVectorDePePozitie(int** vector, int* dim, int pozitie) {
	int* aux = new int[*dim - 1];
	int j = 0;
	for (int i = 0; i < *dim; i++) {
		if (i != pozitie) {
			aux[j] = (*vector)[i];
			j++;
		}
	}
	delete[] *vector;
	(*dim)--;
	*vector = aux;
	//vector = &aux;
}

//stergem maximul din vector
//transmitere parametri prin pointer
//dupa apel vector va avea elemente updatate
void stergereMaximVector(int** vector, int* dim){
	//parametrii se folosesc doar dereferentiati in functie
	int pozitieMaxim = pozitieMaximVector(*vector, *dim);
	stergereElementVectorDePePozitie(vector, dim, pozitieMaxim);
}

//tema: aceeasi functie, dar transmitere prin referinta

void afisareVector(int* vector, int dim) {
	cout << endl << "Parcurgere vector";
	for (int i = 0; i < dim; i++) {
		cout << endl <<"Vector["<<i<<"] = "<< vector[i];
	}
}

char* toUpperCase(const char sir[]) {
	char* sirCuLitereMari = new char[strlen(sir) + 1];
	strcpy_s(sirCuLitereMari, strlen(sir) + 1, sir);
	for (int i = 0; i < strlen(sirCuLitereMari); i++) {
		if (sirCuLitereMari[i] >= 'a' && sirCuLitereMari[i] <= 'z')
		{
			sirCuLitereMari[i] -= 32;
		}
	}
	return sirCuLitereMari;
}

void main() {
	char vectorDeCaractere[20];
	char *nume;

	std::cout << "Citim de la tastatura urmatorul sir:";
	//se citesc si spatiile
	//std::cin.getline(vectorDeCaractere, 20);
	//std::cout << "Sirul este:" << vectorDeCaractere;

	//citim nume
	//folosim un buffer
	char buffer[50];
	cout << endl << "Numele este:";
	//cin >> buffer;

	//alocam memorie
	nume = new char[strlen(buffer) + 1];
	strcpy_s(nume, strlen(buffer) + 1, buffer);

	//cout << endl << "Am citit de la tast numele "<<nume;

	//vectori
	int* vector;
	int dimensiune = 6;
	cout << endl << "Citire vector de la tastatura:"<<endl;

	//alocare
	vector = new int[dimensiune];
	for (int i = 0; i < dimensiune; i++) {
		cout << "Vector[" << i << "] = ";
		cin >> vector[i];
	}

	afisareVector(vector, dimensiune);
	cout << endl << "Pozitia maximului este: " << pozitieMaximVector(vector, dimensiune);

	stergereMaximVector(&vector, &dimensiune);
	afisareVector(vector, dimensiune);

	char sirCaractere[] = "Abc";
	cout << endl << toUpperCase(sirCaractere);
}