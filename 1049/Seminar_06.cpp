#define _CRT_SECURE_NO_WARINIGS
#include<iostream>
#include<string>

using namespace std;

class Oras {
private:
	const string denumire;
	char* judet = nullptr;
	int populatie = 0;
	bool areMetrou = false;

public:
	Oras() :denumire("Default") {
		//this->denumire = "Bucuresti";
	}

	void afisare() {
		cout << endl << "Oras:";
		cout << endl << "Denumire: " << this->denumire;
		if (this->judet != nullptr) {
			cout << endl << "Judet: " << this->judet;
		}
		cout << endl << "Populatie: " << this->populatie;
		if (this->areMetrou) {
			cout << endl << "Orasul are metrou.";
		}
		else {
			cout << endl << "Orasul nu are metrou.";
		}

	}

	Oras(string denumireO, const char* judet, int populatie, bool areMetrou) :denumire(denumireO) {
		this->populatie = populatie;
		this->areMetrou = areMetrou;
		//this->denumire = denumireO;
		this->judet = new char[strlen(judet) + 1];
		memcpy(this->judet, judet, strlen(judet) + 1);
	}

	Oras(const Oras& copie) :denumire(copie.denumire) {
		//this->denumire = copie.denumire;
		this->areMetrou = copie.areMetrou;
		this->populatie = copie.populatie;
		this->judet = new char[strlen(copie.judet) + 1];
		memcpy(this->judet, copie.judet, strlen(copie.judet) + 1);
	}

	void operator=(const Oras& copie) {
		//this->denumire = copie.denumire;
		this->areMetrou = copie.areMetrou;
		this->populatie = copie.populatie;
		if (this->judet != nullptr) {
			delete[] this->judet;
			this->judet = nullptr;
		}

		if (copie.judet != nullptr) {
			this->judet = new char[strlen(copie.judet) + 1];
			memcpy(this->judet, copie.judet, strlen(copie.judet) + 1);
		}
	}
	void operator+=(int populatieDeAdaugat) {
		this->populatie += populatieDeAdaugat;
	}

	bool operator<=(const Oras& oras) {
		return this->populatie <= oras.populatie;
	}

};
int main() {
	Oras orasDefault;
	Oras cluj("Cluj-Napoca", "Cluj", 286598, false);
	orasDefault.afisare();
	cluj.afisare();

	Oras iasi = cluj;
	iasi.afisare();

	iasi = orasDefault;
	iasi.afisare();

	iasi += 100000;
	iasi.afisare();

	if ( orasDefault <= iasi) {
		cout << endl << "Iasi are mai multi locuitori.";
	}

}