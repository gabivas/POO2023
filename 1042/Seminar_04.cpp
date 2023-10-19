#include<iostream>

using namespace std;

class Masina {
private:
	string marca;
	const int id;
	int nrComponente;
	float* preturi;
	//nu apartine obiectelor
	static int nrMasini; 

public:
	//constructor default, 0 param
	Masina() :id(++nrMasini) {
		this->marca = "Necunoscuta";
		this->nrComponente = 0;
		this->preturi = nullptr;
		//asa nu
		//this->id = ++nrMasini;
	}

	Masina(string marca, int nrComponente, float* preturi): id(++nrMasini) {
		this->marca = marca;
		this->nrComponente = nrComponente;
		this->preturi = new float[this->nrComponente];
		//deep copy
		for (int i = 0; i < this->nrComponente; i++) {
			this->preturi[i] = preturi[i];
		}
		delete[] preturi;

		////shallow copy;
		//this->preturi = preturi;
		////nu mai dezalocam
	}

	//destructor
	~Masina() {
		cout << endl << " S-a apelat destructorul!";
		delete[] this->preturi;
	}

	void afisareMasina() {
		cout << endl << "Masina " <<
			this->marca << " , id-ul " << this->id
			<<" are " << this->nrComponente <<" componente si preturile sunt: ";
		for (int i = 0; i < this->nrComponente; i++) {
			cout << this->preturi[i] << " ";
		}
	}

	static int getNrMasini() {
		return nrMasini;
	}
};

int Masina::nrMasini = 0;

int main() {

	//se apeleaza constr default(fara param)
	Masina masina;
	masina.afisareMasina();

	Masina masina2("Renault",3, new float[3] {1000.6f, 523.4f, 124.9f});
	masina2.afisareMasina();

	Masina* masina3 = new Masina();
	masina3->afisareMasina();

	Masina* masina4 = new Masina("Ford", 2, new float[3] {100.6f, 124.9f});
	masina4->afisareMasina();

	cout << endl << Masina::getNrMasini();
	//dezalocare
	delete masina3;
	delete masina4;

}