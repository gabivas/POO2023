#include<iostream>

using namespace std;

class Motor{
private:
	float putere=0.0f; //in KW
public:
	Motor() {}
	Motor(float putere) :putere(putere) {}
	float getPutere() {
		return this->putere;
	}
};

class Masina {
private:
	//o masina are un motor 1:1
	//Motor motor;
	int nrMotoare;
	//1:m, o masina are mai multe multe motoare
	Motor* vectorMotoare;

public:
	Masina(int nrMotoare, float* vector) {
		this->nrMotoare = nrMotoare;
		this->vectorMotoare = new Motor[this->nrMotoare];
		for (int i = 0; i < this->nrMotoare; i++) {
			this->vectorMotoare[i] = Motor(vector[i]);
		}
	}

	Motor& operator[](int pozitie) {
		if (pozitie >= 0 && pozitie < this->nrMotoare)
		{
			return vectorMotoare[pozitie];
		}
		throw "Pozitia in afara intervalului!";
	}

	~Masina() {
		if(vectorMotoare!= nullptr)
		delete[] vectorMotoare;
	}

	Masina(const Masina& masina) {
		this->nrMotoare = masina.nrMotoare;
		if (masina.vectorMotoare != nullptr) {
			this->vectorMotoare = new Motor[this->nrMotoare];
			for (int i = 0; i < this->nrMotoare; i++) {
				this->vectorMotoare[i] = masina.vectorMotoare[i];
			}
		}
		else {
			this->vectorMotoare = nullptr;
		}
	}
};

void main() {
	int nrMotoare = 3;
	float vectorPutereKW[3]{ 100.0f, 70.0f, 85.0f };
	Masina masina(nrMotoare, vectorPutereKW);

	for (int i = 0; i < nrMotoare; i++) {
		cout << endl << "Putere[" << i << "] = "
			<< masina[i].getPutere();
	}

	masina[1] = 75.0f;

	cout << endl << "Dupa actualizare:";
	for (int i = 0; i < nrMotoare; i++) {
		cout << endl << "Putere[" << i << "] = "
			<< masina[i].getPutere();
	}

	//const de copiere
	Masina masina2 = masina;
	cout << endl << "Masina2:";
	for (int i = 0; i < nrMotoare; i++) {
		cout << endl << "Putere[" << i << "] = "
			<< masina[i].getPutere();
	}
}