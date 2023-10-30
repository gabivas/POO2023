#include<iostream>
#include<string>

using namespace std;

class Angajat {
private:
	const int id;
	string nume;
	int varsta;
	int vechime;
	float* salariuAnual;
	static int nrAngajati;

public:
	void afisareAngajat() {
		cout << endl << "Angajatul " <<
			this->nume << " cu id-ul " << this->id << " in varsta de " << this->varsta << " ani, cu o vechime de " << this->vechime << " ani si urmatoarele salarii anuale: ";
		for (int i = 0; i < this->vechime; i++) {
			cout << this->salariuAnual[i] << " ";
		}
	}
	//const default(fara param)
	Angajat() :id(++nrAngajati) {
		//asa nu
		//this->id = 0;
		this->nume = "Necunoscut";
		this->vechime = 0;
		this->varsta = 0;
		this->salariuAnual = nullptr;
	}

	Angajat(string nume, int vechime, int varsta, float* salarii) :id(++nrAngajati) {
		this->nume = nume;
		this->vechime = vechime;
		this->varsta = varsta;

		//deep copy
		this->salariuAnual = new float[this->vechime];
		for (int i = 0; i < this->vechime; i++) {
			this->salariuAnual[i] = salarii[i];
		}
		//shallow copy
		//this->salariuAnual = salarii;

		delete[] salarii;
	}

	~Angajat() {
		cout << endl << "A fost apelat destructorul";
		delete[] this->salariuAnual;
	}

	static int getNrAngajati() {
		return nrAngajati;
	}

	// get si set pentru vechime
	int getVechime() {
		return this->vechime;
	}

	void setVechime(int valoareNoua) {
		if (valoareNoua >= 0) {
			this->vechime = valoareNoua;
		}
		else {
			//throw exception();
			throw "Vechime negativa";
			//throw 404;
		}
	}

	//get si set pentru salariuAnual
	float* getSalariuAnual() {
		//asa nu
		//shallow copy
		//return this->salariuAnual;

		//deep copy
		float* salariuAnualDeReturnat = new float[this->vechime];
		for (int i = 0; i < this->vechime; i++) {
			salariuAnualDeReturnat[i] = this->salariuAnual[i];
		}

		return salariuAnualDeReturnat;
	}

	void setSalariuAnual(float* noulVector, int nouaVechime) {
		//asa nu
		//this->salariuAnual = noulVector;
		setVechime(nouaVechime);

		if (this->salariuAnual != nullptr) {
			delete[] this->salariuAnual;
		}

		this->salariuAnual = new float[this->vechime];
		for (int i = 0; i < this->vechime; i++) {
			this->salariuAnual[i] = noulVector[i];
		}

		delete[] noulVector;
	}
};

int Angajat::nrAngajati = 0;

void main() {
	Angajat angajat;
	angajat.afisareAngajat();

	float* salarii = new float[2] {2000.5f, 3000.7f};
	Angajat* angajat2 = new Angajat("Mihai", 2, 24, salarii);
	angajat2->afisareAngajat();

	try {
		angajat2->setVechime(1);
	}
	catch (int cod) {
		cout << endl << cod;
	}
	catch (char* mesaj) {
		cout << endl << mesaj;
	}
	catch (...) {
		cout << endl << "Vechimea este negativa si nu a putut fi setata.";
	}

	cout<<endl<<"Noua vechime este: "<<angajat2->getVechime();

	angajat2->setSalariuAnual(new float[3] {5000, 7000, 8000}, 3);

	float* salAnual = angajat2->getSalariuAnual();
	for (int i = 0; i < angajat2->getVechime(); i++) {
		cout << endl << salAnual[i];
	}
	cout << endl << "Noua vechime este: " << angajat2->getVechime();

	cout << endl << "Au fost construite " <<
		Angajat::getNrAngajati() << " obiecte.";

	delete angajat2;
}