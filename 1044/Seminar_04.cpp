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
			cout << this->salariuAnual[i]<<" ";
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
};

int Angajat::nrAngajati = 0;

void main() {
	Angajat angajat;
	angajat.afisareAngajat();

	float* salarii = new float[2] {2000.5f, 3000.7f};
	Angajat* angajat2 = new Angajat("Mihai",2, 24, salarii);
	angajat2->afisareAngajat();

	cout << endl << "Au fost construite "<<
		Angajat::getNrAngajati()<<" obiecte.";

	delete angajat2;
}