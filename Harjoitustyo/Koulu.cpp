#include "Koulu.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <set>
#include <string>
#include <fstream>
#include <direct.h>

using std::cout; using std::getline; using std::cin; using std::endl; using std::vector; using std::set; using std::ofstream; using std::ifstream;

Koulu::Koulu(): nimi_(), koulutusohjelmat_()
{
}

Koulu::Koulu(string nimi): nimi_(), koulutusohjelmat_()
{
}


Koulu::~Koulu()
{
}

void Koulu::asetaNimi(string nimi)
{
	nimi_ = nimi;
}

string Koulu::annaNimi() const
{
	return nimi_;
}

void Koulu::lisaaKoulutusohjelma()
{
	string nimi;
	cout << "Anna koulutusohjelman nimi: ";
	getline(cin, nimi);
	koulutusohjelmat_.push_back(Koulutusohjelma(nimi));
}

void Koulu::poistaKoulutusohjelma()
{	
	cout << "========POISTETAAN KOULUTUSOHJELMAA!========" << endl;
	cout << "Valitse poistettava koulutusohjelma: " << endl;
	tulostaKoulutusohjelmat();
	int poistettava = etsiKoulutusohjelma();

	if (poistettava >= 0) {
		koulutusohjelmat_.erase(koulutusohjelmat_.begin() + poistettava);			//Jos palautettu arvon on nolla tai suurempi, suoritetaan poisto
		cout << "Koulutusohjelma poistettu!" << endl;
	}
	else 
		cout << endl << "Poistettavaa koulutusohjelmaa ei loytynyt!" << endl;		//Jos "etsiKoulutusohjelma();" palauttaa arvon -1
	
}

void Koulu::lisaaKoulutusohjelmaanOpettaja()
{
	int indeksi = etsiKoulutusohjelma();
	if (indeksi >= 0)
	{
		koulutusohjelmat_[indeksi].lisaaOpettaja();
	}
	else
		cout << "Koulutusohjelmaa ei loytynyt! " << endl;
}

void Koulu::lisaaKoulutusohjelmaanOpiskelija()
{
	int indeksi = etsiKoulutusohjelma();
	if (indeksi >= 0)
	{
		koulutusohjelmat_[indeksi].lisaaOpiskelija();		
	}
	else
		cout << "Koulutusohjelmaa ei loytynyt! " << endl;	
}

void Koulu::tulostaKoulutusohjelmanOpiskelijat() const
{
	int indeksi = etsiKoulutusohjelma();
	if (indeksi >= 0)
	{
		koulutusohjelmat_[indeksi].tulostaOpiskelijat();
	}
	else
		cout << "Koulutusohjelmaa ei loytynyt! " << endl;
}

void Koulu::tulostaKoulutusohjelmat() const
{
	cout << endl << "Koulutusohjelmat: " << endl;
	for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++)
	{
		cout << koulutusohjelmat_[i].annaNimi() << endl;
	}
}

void Koulu::tulostaKoulutusohjelmienMaara() const
{
	cout << koulutusohjelmat_.size() << endl;
}

void Koulu::poistaOpettaja()
{
	int indeksi = etsiKoulutusohjelma();
	if (indeksi >= 0)
	{
		koulutusohjelmat_[indeksi].poistaOpettaja();
	}
	else
		cout << "Koulutusohjelmaa ei loytynyt! " << endl;
}

void Koulu::poistaOpiskelija()
{
	int indeksi = etsiKoulutusohjelma();
	if (indeksi >= 0)
	{
		koulutusohjelmat_[indeksi].poistaOpiskelija();
	}
	else
		cout << "Koulutusohjelmaa ei loytynyt! " << endl;
}

void Koulu::paivitaKoulutusohjelma()
{
	string uusinimi;
	cout << "======== Muutetaan koulutusohjelman nimi ========" << endl;
	int indeksi = etsiKoulutusohjelma();

	cout << "Anna uusi nimi: ";
	getline(cin, uusinimi);

	if (indeksi >= 0) {
		for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++) {
			koulutusohjelmat_[indeksi].asetaNimi(uusinimi);
		}
	}
	else
		cout << "Muutettavaa koulutusohjelmaa ei loytynyt" << endl;
	
}

void Koulu::paivitaOpettaja()
{
	cout << "======== Paivitetaan opettajan tietoja ========" << endl;

	int indeksi = etsiKoulutusohjelma();
	
	if (indeksi >= 0) {
		koulutusohjelmat_[indeksi].paivitaOpettaja();
	}
	else
		cout << "Koulutusohjelmaa ei loytynyt!" << endl;
}

void Koulu::paivitaOpiskelija()
{
	cout << "======== Paivitetaan opiskelijan tietoja ========" << endl;

	int indeksi = etsiKoulutusohjelma();

	if (indeksi >= 0) {
		koulutusohjelmat_[indeksi].paivitaOpiskelija();
	}
	else
		cout << "Koulutusohjelmaa ei loytynyt!" << endl;
}

void Koulu::tallennaKoulutusohjelmat()
{
	ofstream kirj_koulutusOhjelmat;
	kirj_koulutusOhjelmat.open("koulutusohjelmat.csv");
	if (kirj_koulutusOhjelmat.is_open()) {
		for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++) {
			kirj_koulutusOhjelmat << koulutusohjelmat_[i].annaNimi() << ";";
		}
		kirj_koulutusOhjelmat.close();
		cout << "koulutusohjelmat.csv tallennettu" << endl; 
	}
	else
		cout << "Tiedostoa ei voitu avata!" << endl;
}

void Koulu::lueKoulutusohjelmat()
{
	string nimi;
	ifstream luku_koulutusOhjelmat;
	luku_koulutusOhjelmat.open("koulutusohjelmat.csv");
	if (luku_koulutusOhjelmat.is_open()) {
		while (luku_koulutusOhjelmat.peek() != EOF) {
			getline(luku_koulutusOhjelmat, nimi, ';');
			koulutusohjelmat_.push_back(Koulutusohjelma(nimi));
		}
		cout << "Koulutusohjelmat.csv luettu" << endl;
		luku_koulutusOhjelmat.close();
	}
	else
		cout << "Tiedostoa ei voitu avata";
}

void Koulu::lueTiedot()
{
	lueKoulutusohjelmat();

	//lue opettajat ja opiskelijat

	for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++) {
		koulutusohjelmat_[i].lueOpettajat();
		koulutusohjelmat_[i].lueOpiskelijat();
	}

}

void Koulu::tallennaTiedot()
{
	tallennaKoulutusohjelmat();

	for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++) {
		koulutusohjelmat_[i].tallennaOpettajat();
	}

	for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++) {
		koulutusohjelmat_[i].tallennaOpiskelijat();
	}
	
}

int Koulu::etsiKoulutusohjelma() const
{
	string nimi;
	cout << "Anna koulutusohjelman nimi: ";
	getline(cin, nimi);
	for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++)
	{
		if (nimi == koulutusohjelmat_[i].annaNimi())
		{
			return i;
		}
	}
	return -1; //ei löytynyt
}

void Koulu::tulostaKoulutusohjelmanOpettajat() const
{
	int indeksi = etsiKoulutusohjelma();
	if (indeksi >= 0)
	{
		koulutusohjelmat_[indeksi].tulostaOpettajat();
	}
	else
		cout << "Koulutusohjelmaa ei loytynyt! " << endl;
}
