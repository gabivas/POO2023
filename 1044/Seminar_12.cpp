#include<iostream>
using namespace std;

class Papusa {
private:
	float pret= 0.0f;
public:
	Papusa() {}
	Papusa(float pret) :pret(pret) {}
	float getPret() { return this->pret; }
};

class CasaPapusi {
private:
	//relatie 1:1
	//Papusa papusa;

	//relatia 1:m
	Papusa* vectorPapusi;
	int nrPapusi;
public:
	CasaPapusi(int nrPapusi, float* vectPreturi) {
		this->nrPapusi = nrPapusi;
		this->vectorPapusi = new Papusa[this->nrPapusi];
		for (int i = 0; i < this->nrPapusi; i++) {
			this->vectorPapusi[i] = Papusa(vectPreturi[i]);
		}
	}

	~CasaPapusi() {
		if(vectorPapusi!= nullptr)
		delete[] vectorPapusi;
	}

	Papusa& operator[](int index) {
		if (index >= 0 && index < this->nrPapusi) {
			return vectorPapusi[index];
		}
		throw "Indexul nu se afla in intervalul corect";
	}

	CasaPapusi(const CasaPapusi& cp) {
		this->nrPapusi = cp.nrPapusi;
		if (cp.vectorPapusi != nullptr) {
			this->vectorPapusi = new Papusa[this->nrPapusi];
			for (int i = 0; i < this->nrPapusi; i++) {
				this->vectorPapusi[i] = cp.vectorPapusi[i];
			}
		}
		else {
			this->vectorPapusi = nullptr;
		}
	}
};

void main() {
	int nrPapusi = 4;
	float vectPreturi[4]{ 20.0f, 40.0f, 95.0f, 75.0f };
	CasaPapusi casaPapusi(nrPapusi, vectPreturi);

	cout << endl << "Afisare preturi din Casa de Papusi:";
	for (int i = 0; i < nrPapusi; i++) {
		cout << endl << "Pret papusa de pe pozitia " << i << ": "
			<< casaPapusi[i].getPret();
	}

	casaPapusi[0] = 25.0f;

	CasaPapusi cp = casaPapusi;
	cout << endl << "Afisare preturi din Casa de Papusi cp:";
	for (int i = 0; i < nrPapusi; i++) {
		cout << endl << "Pret papusa de pe pozitia " << i << ": "
			<< cp[i].getPret();
	}
}
