#include<iostream>
#include<string>

using namespace std;

enum Stare
{
	NOU=1, UTILIZAT =2
};

class TelefonMobil {
public:
	//variabile accesibile
	char* model = nullptr;
	int memorie = 0;
	float procentBaterie = 0.0f;
	string firma = "Anonim";
	Stare stare = NOU;

	void actualizeazaMemorie(int nouaMemorie) {
		memorie = nouaMemorie;
	}

	//metoda
	void afisareTelefonMobil() {
		cout << endl << "Telefonul mobil " << firma << " este de model ";
		if (model != nullptr)
			cout << model;
		cout<<", memoria este de " << memorie << ", procentul bateriei este de " << procentBaterie << " %. Starea telefonului este: ";
		if (stare == 1) {
			cout << "NOU";
		}
		else {
			cout << "UTILIZAT";
		}
	}

private:
	//variabile inaccesibile din exterior
//protected:

};

//functie
void afisareTelefonMobil(TelefonMobil t) {
	cout << endl << "Telefonul mobil " << t.firma << " este de model ";
	if (t.model != nullptr)
		cout << t.model;
	cout << ", memoria este de " << t.memorie << ", procentul bateriei este de " << t.procentBaterie << " %. Starea telefonului este: ";
	if (t.stare == 1) {
		cout << "NOU";
	}
	else {
		cout << "UTILIZAT";
	}
}

void main() {
	//!!!telefon este un obiect
	//un obiect este o instanta a clasei
	TelefonMobil telefon;
	telefon.firma = "Apple";
	telefon.memorie = 128;
	telefon.model = new char[strlen("IPhone 15") + 1];
	strcpy_s(telefon.model, strlen("IPhone 15") + 1, "IPhone 15");
	telefon.procentBaterie = 57.0f;
	telefon.stare = NOU;

	telefon.afisareTelefonMobil();

	//Pointer la obiect
	TelefonMobil* telefon2;
	telefon2 = new TelefonMobil();
	telefon2->procentBaterie = 80.0f;
	telefon2->afisareTelefonMobil();
	//(*telefon2).afisareTelefonMobil();

	cout << endl << "telefon ocupa" << sizeof(telefon);

	//shallow copy
	TelefonMobil* telefon3 = &telefon;

	TelefonMobil* telefon4 = telefon2;

	telefon3->afisareTelefonMobil();
	telefon4->afisareTelefonMobil();
	telefon4->actualizeazaMemorie(64);
	telefon4->afisareTelefonMobil();

	//vector de obiecte(telefoane)
	int dimensiune = 3;
	TelefonMobil* telefoane = new TelefonMobil[dimensiune];
	for (int i = 0; i < dimensiune; i++) {
		telefoane[i].firma = "Firma Anonim";
		telefoane[i].memorie = 128;
		telefoane[i].model = new char[strlen("IPhone 15") + 1];
		strcpy_s(telefoane[i].model, strlen("IPhone 15") + 1, "IPhone 15");
		telefoane[i].procentBaterie = 57.0f;
		telefoane[i].stare = NOU;
	}

	//Afisare vector
	cout << endl<<endl << "Afisare vector:";
	for (int i = 0; i < dimensiune; i++) {
		afisareTelefonMobil(telefoane[i]);
	}

	//dezalocam memorie
	for (int i = 0; i < dimensiune; i++) {
		delete telefoane[i].model;
	}
	delete[] telefoane;
	delete telefon.model;

}