#include<iostream>
#include<string>

using namespace std;

//exceptie custom
class ExceptieCustom: public exception {
public:
	ExceptieCustom(const char* mesaj) :exception(mesaj) {
	}
};

//clasa de baza
class Produs {
private:
	const int id;
	string denumire;
	float pret;

public:
	static const float PRET_MINIM;
	Produs(int id, string denumire, float pret) :id(id), denumire(denumire), pret(pret) {
		//this->pret = pret;
		if (this->pret < PRET_MINIM) {
			throw ExceptieCustom("Pretul este prea mic!");
		}
	}

	virtual void afisare() {
		cout << endl<<endl << "Produs:";
		cout << endl << "Id: "<<this->id ;
		cout << endl << "Denumire: "<< this->denumire;
		cout << endl << "Pret: "<< this->pret;
	}

	//minim o metoda virtuala pura(fara implementare)
	//clasele abstracte nu se initializeaza
	//o clasa doar cu metode virtuale pure se numeste interfata
	virtual float getProcentReducere() = 0;
};

const float Produs::PRET_MINIM = 1;

//clasa derivata
class ProdusRedus : public Produs {
private:
	float procentReducere; //10->10%
public:
	ProdusRedus() :Produs(0, "", 0), procentReducere(0) {

	}

	ProdusRedus(int id, string denumire, float pret, float procent) :Produs(id, denumire, pret), procentReducere(procent) {

	}
	//override la metoda afisare din clasa Produs
	void afisare() {
		this->Produs::afisare();
		cout << endl << "Procent reducere: " << procentReducere << "%";
	}

	float getProcentReducere() {
		return this->procentReducere;
	}
};


void main() {
	/*try {
		Produs lapte(1, "Lapte", 5);
		lapte.afisare();
	}
	catch (ExceptieCustom e) {
		cout << endl << e.what();
	}*/

	ProdusRedus laptop(2, "Laptop", 4000, 10);
	//metoda afisare din clasa Produs
	laptop.Produs::afisare();
	//metoda afisare din clasa ProdusRedus
	laptop.afisare();

	cout << endl << "Vector pointeri la produse:";
	Produs* vectorProduse[4];

	//vectorProduse[0] = new Produs(1, "Paine", 5);
	//vectorProduse[1] = new Produs(2, "Peste", 20);
	vectorProduse[0] = new ProdusRedus(1, "Paine", 5, 15);
	vectorProduse[1] = new ProdusRedus(2, "Peste", 20, 12);
	vectorProduse[2] = new ProdusRedus(3, "Portocale", 7, 5);
	vectorProduse[3] = new ProdusRedus(4, "Suc", 8, 7);

	for (int i = 0; i < 4; i++) {
		vectorProduse[i]->afisare();
		cout << endl << vectorProduse[i]->getProcentReducere();
		delete vectorProduse[i];
	}
}