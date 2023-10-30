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

	Masina(string marca, int nrComponente, float* preturi) : id(++nrMasini) {
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
			<< " are " << this->nrComponente << " componente si preturile sunt: ";
		for (int i = 0; i < this->nrComponente; i++) {
			cout << this->preturi[i] << " ";
		}
	}

	static int getNrMasini() {
		return nrMasini;
	}

	//get si set pentru nrComponente

	int getNrComponente() {
		return this->nrComponente;
	}

	void setNrComponente(int nouaValoare) {
		//validari
		if (nouaValoare > 0) {
			this->nrComponente = nouaValoare;
		}
		else {
			//throw "Valoarea este negativa sau egala cu 0";
			//throw 404;
			throw exception();
		}
	}

	//get si set pentru preturi
	void setPreturi(int nrComponente, float* preturiNoi) {
		//shallow copy
		//asa nu
		//this->preturi = preturiNoi;

		setNrComponente(nrComponente);

		if(this->preturi != nullptr)
		delete[] this->preturi;

		this->preturi = new float[this->nrComponente];
		for (int i = 0; i < this->nrComponente; i++) {
			this->preturi[i] = preturiNoi[i];
		}

		delete[] preturiNoi;
		
	}

	float* getPreturi() {
		//asa nu
		//return this->preturi;

		float* preturiDeReturnat = new float[this->nrComponente];
		for (int i = 0; i < this->nrComponente; i++) {
			preturiDeReturnat[i] = this->preturi[i];
		}
		return preturiDeReturnat;
	}
};

int Masina::nrMasini = 0;

int main() {

	//se apeleaza constr default(fara param)
	Masina masina;
	masina.afisareMasina();

	Masina masina2("Renault", 3, new float[3] {1000.6f, 523.4f, 124.9f});
	masina2.afisareMasina();

	Masina* masina3 = new Masina();
	masina3->afisareMasina();

	Masina* masina4 = new Masina("Ford", 2, new float[2] {100.6f, 124.9f});
	masina4->afisareMasina();

	cout << endl << Masina::getNrMasini();

	try {
		masina4->setNrComponente(0);
	}
	catch (const char* mesaj) {
		cout << endl << mesaj;
	}
	catch (int cod) {
		cout << endl << cod;
	}
	catch (...) {
		cout << endl << "Noua valoare nu poate fi salvata";
	}

	cout << endl << "Noul nr componente pentru masina4: " << masina4->getNrComponente();

	masina4->setPreturi(3,new float[3] {10000.0f, 20000.0f, 30000.0f});

	float* preturiMasini4 = masina4->getPreturi();
	for (int i = 0; i < masina4->getNrComponente(); i++) {
		cout << endl << preturiMasini4[i];
	}
	masina4->afisareMasina();

	//dezalocare
	delete masina3;
	delete masina4;

}