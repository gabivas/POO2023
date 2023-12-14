#include<iostream>

using namespace std;

class Camera{
private:
	float pret = 0.0f;

public:
	Camera(){}
	Camera(float pret): pret(pret){}
	float getPret() { return this->pret; }
};

class Hotel{
private:
//1:1
//Camera camera;

//1:m
Camera* vectCamere;
int nrCamere;

public:

	Hotel(int nrCamere, float* vectPreturi) {
		this->nrCamere = nrCamere;
		this->vectCamere = new Camera[this->nrCamere];
		for (int i = 0; i < this->nrCamere; i++) {
			this->vectCamere[i] = Camera(vectPreturi[i]);
		}
	}

	Camera& operator[](int pozitie) {
		if (pozitie >= 0 && pozitie < this->nrCamere) {
			return this->vectCamere[pozitie];
		}
		throw "Pozitia nu se afla in intervalul [0,pozitie)";
	}

	~Hotel() {
		if(this->vectCamere != nullptr)
		delete[] this->vectCamere;
	}

	Hotel(const Hotel& h) {
		this->nrCamere = h.nrCamere;
		if (h.vectCamere != nullptr) {
			this->vectCamere = new Camera[this->nrCamere];
			for (int i = 0; i < this->nrCamere; i++) {
				this->vectCamere[i] = h.vectCamere[i];
			}
		}
		else {
			this->vectCamere = nullptr;
		}
	}

};

void main() {
	int nrCamere = 3;
	float preturi[3]{ 200.0f, 300.0f, 700.0f };
	Hotel hotel(nrCamere, preturi);

	cout << endl << "Preturile pentru hotel:";
	for (int i = 0; i < nrCamere; i++) {
		cout << endl << "Pretul pentru camera " << i << " este:"
			<< hotel[i].getPret();
	}

	hotel[2] = 800.0f;

	Hotel hotel2 = hotel;
	cout << endl << "Preturile pentru hotel2:";
	for (int i = 0; i < nrCamere; i++) {
		cout << endl << "Pretul pentru camera " << i << " este:"
			<< hotel2[i].getPret();
	}
}