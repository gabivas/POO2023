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

	bool operator>(int populatie) {
		return this->populatie > populatie;
	}

	//op negatie
	bool operator!() {
		return this->areMetrou == false;
	}

	//op functie
	int operator()() {
		return this->populatie;
	}

	//op index
	char& operator[](int pozitie) {
		if (pozitie >= 0 && pozitie < strlen(this->judet)) {
			return this->judet[pozitie];
		}
		else {
			throw "Intervalul a fost depasit.";
		}
	}

	friend void operator<<(ostream& out, Oras o) {
		out << endl << "Denumire: " << o.denumire;
		out << endl << "Populatie: " << o.populatie;
		out << endl << (o.judet != nullptr ? "Judet: " + string(o.judet) : "Judet Default");
		out << endl << (o.areMetrou ? "Are metrou" : "Nu are metrou");
	}

	friend void operator>>(istream& in, Oras& o);
};

void operator>>(istream& in, Oras& o) {
	//atrib const nu se actualizeaza
	cout << endl << "Populatie: ";
	in >> o.populatie;
	cout << endl << "Judet: ";
	if (o.judet != nullptr) {
		delete[] o.judet;
		o.judet = nullptr;
	}
	char buffer[20];
	in >> buffer;

	o.judet = new char[strlen(buffer) + 1];
	strcpy_s(o.judet, strlen(buffer) + 1, buffer);
	
	cout << endl << "Are metrou? y/n";
	string areMetrou;
	in >> areMetrou;
	o.areMetrou = (areMetrou == "y" ? true : false);
}

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

	if (orasDefault <= iasi) {
		cout << endl << "Iasi are mai multi locuitori.";
	}

	Oras timisoara("Timisoara", "Timis", 100000, false);
	Oras sibiu("Sibiu", "Sibiu", 80000, false);

	if (timisoara > 100) {
		cout << endl << "Timisoara are mai mult de 100 locuitori.";
	}

	if (!timisoara) {
		cout << endl << "Timisoara nu are metrou.";
	}

	cout << endl << "Populatia Timisoarei este: " << timisoara();

	cout << endl << "A treia litera din judet: " << timisoara[2];

	timisoara[2] = 'M';
	timisoara.afisare();

	cout << timisoara;
	cin >> timisoara;
	cout << timisoara;

	//timisoara + 10;
}