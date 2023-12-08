#include<iostream>
#include<string>

using namespace std;

class ExceptieCustom : public exception{
public:
	ExceptieCustom(const char* mesaj) :exception(mesaj) {

	}
};

class Facultate {
protected:
	const int id;
	string denumire;
	int nrStudenti;

public:
	static const int NR_STUD_MIN;
	Facultate(int id, string denumire, int nrStudenti) :id(id), denumire(denumire), nrStudenti(nrStudenti) {
		if (nrStudenti < NR_STUD_MIN) {
			throw ExceptieCustom("Nr studentilor este prea mic!");
		}
	}

	virtual void afisare() {
		cout << endl<<endl << "Afisare facultate:";
		cout << endl << "Id:"<<this->id;
		cout << endl << "Denumire:"<<this->denumire;
		cout << endl << "Nr stud:"<<this->nrStudenti;

	}

	//clasa abstracta = exista cel putin o metoda virtuala pura(nu exista comportament)
	//acum clasa facultate este clasa abstracta
	//cls abstracte nu se intializeaza
	virtual void getNrStudenti() = 0;

};
const int Facultate::NR_STUD_MIN = 10;

class Departament : public Facultate {
private:
	string numeDirector;
public:
	Departament() :Facultate(0, "", 10), numeDirector("") {
	}

	Departament(int id, string denumire, int nrStudenti, string numeDirector) :Facultate(id, denumire, nrStudenti), numeDirector(numeDirector) {}

	//override la metoda din clasa de baza
	void afisare() {
		this->Facultate::afisare();
		cout << endl << "Nume director" << this->numeDirector;
	}

	void getNrStudenti(){
		cout<<endl<< this->nrStudenti;
	}
};

void main() {
	/*try {
		Facultate csie(1, "CSIE", 3000);
		csie.afisare();
	}
	catch (ExceptieCustom e) {
		cout << endl << e.what();
	}*/

	Departament dep(1, "CSIE", 3000, "Director");
	//apel metoda din clasa de baza
	dep.Facultate::afisare();
	//apel metoda din clasa derivata
	dep.afisare();

	cout << endl << "Vector facultati:";
	Facultate* vectorFacultati[3];

	//vectorFacultati[0] = new Facultate(1, "CSIE", 3000);
	//up casting
	vectorFacultati[0] = new Departament(1, "CSIE", 3000, "Director CSIE");
	vectorFacultati[1] = new Departament(2, "MK", 2000, "Director MK");
	vectorFacultati[2] = new Departament(3, "REI", 2500, "Director REI");

	for (int i = 0; i < 3; i++) {
		vectorFacultati[i]->afisare();
		vectorFacultati[i]->getNrStudenti();
		delete vectorFacultati[i];
	}
}