#include<iostream>

using namespace std;

class Tara {
private:
	const int cod;
	string nume;
	int nrAni;
	float* vectorPIB;
	static int nrTari;

public:
	void afisareTara() {
		cout << endl << "Tara " <<
			this->nume << ", avand codul " << this->cod << ", pe ultimii " << this->nrAni << " ani a avut urmatoarele PIB-uri:";
		for (int i = 0; i < this->nrAni; i++) {
			cout << this->vectorPIB[i] << " ";
		}
	}

	Tara() :cod(++nrTari) {
		//this->cod = 0;
		this->nrAni = 0;
		this->vectorPIB = nullptr;
		this->nume = "Default";
	}

	Tara(string nume, int nrAni, float* vector) :cod(++nrTari) {
		this->nume = nume;
		this->nrAni = nrAni;
		//asa nu
		//shallow copy
		//this->vectorPIB = vector;

		//deep copy
		this->vectorPIB = new float[this->nrAni];
		for (int i = 0; i < this->nrAni; i++) {
			this->vectorPIB[i] = vector[i];
		}
		delete[] vector;
	}

	void adaugaPIB(float PIBDeAdaugat) {
		this->nrAni++;
		float* vectorPIBActualizat = new float[this->nrAni];
		for (int i = 0; i < this->nrAni - 1; i++) {
			vectorPIBActualizat[i] = this->vectorPIB[i];
		}
		vectorPIBActualizat[this->nrAni - 1] = PIBDeAdaugat;

		delete[] this->vectorPIB;
		this->vectorPIB = vectorPIBActualizat;
	}

	~Tara() {
		cout << endl << "S-a apelat destructorul!";
		delete[] vectorPIB;
	}

	static int getNrTari() {
		return nrTari;
	}

	//get si set pentru nrAni

	int getNrAni() {
		return this->nrAni;
	}

	void setNrAni(int valoareNoua) {
		if (valoareNoua > 0) {
			this->nrAni = valoareNoua;
		}
		else {
			//throw exception();
			//throw 404;
			throw "Valoare negativa.";
		}
	}

	//get si set pentru vectorPIB

	float* getVectorPIB() {
		//asa nu
		//return this->vectorPIB;

		float* vectorDeReturnat = new float[this->nrAni];
		for (int i = 0; i < this->nrAni; i++) {
			vectorDeReturnat[i] = this->vectorPIB[i];
		}
		return vectorDeReturnat;
	}

	void setVectorPIB(float* noulVector, int nrAni) {
		//nu
		//this->vectorPIB = noulVector;
		
		setNrAni(nrAni);
		if (this->vectorPIB != nullptr) {
			delete[] this->vectorPIB;
		}
		this->vectorPIB = new float[nrAni];
		for (int i = 0; i < this->nrAni; i++) {
			this->vectorPIB[i] = noulVector[i];
		}

		delete[] noulVector;
	}
};

int Tara::nrTari = 0;

void main() {
	Tara romania;
	romania.afisareTara();

	Tara portugalia("Portugalia", 2, new float[2] {1350.6f, 1702.4f});
	portugalia.afisareTara();

	Tara* franta = new Tara("Franta", 3, new float[3] {1700.0f, 2100.0f, 2200.0f});
	franta->afisareTara();
	franta->adaugaPIB(2300.0f);
	franta->afisareTara();

	cout << endl << "Nr tari = " << Tara::getNrTari();

	try {
		franta->setNrAni(2);
	}
	catch (int cod) {
		cout << endl << cod;
	}
	catch (const char* mesaj) {
		cout << endl << mesaj;
	}
	catch (...) {
		cout << endl << "Valoare a fost negativa!";
	}

	cout << endl << franta->getNrAni();

	//dezalocare
	delete franta;
}