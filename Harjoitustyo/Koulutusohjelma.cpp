#include "Koulutusohjelma.h"
#include "Koulu.h"
#include "Tyontekija.h"
#include <iostream>
#include <algorithm>
#include <direct.h>
#include <fstream>

using std::cout; using std::cin; using std::endl; using std::ifstream; using std::ofstream;


Koulutusohjelma::Koulutusohjelma() : nimi_(), opiskelijat_(), opettajat_()
{
	
}

Koulutusohjelma::Koulutusohjelma(string nimi): nimi_(nimi), opiskelijat_(), opettajat_()
{
}


Koulutusohjelma::~Koulutusohjelma()
{
}

void Koulutusohjelma::asetaNimi(string nimi)
{
	nimi_ = nimi;
}

string Koulutusohjelma::annaNimi() const
{
	return nimi_;
}

void Koulutusohjelma::lisaaOpettaja()
{
	Opettaja ope;
	ope.kysyTiedot();
	opettajat_.push_back(ope);
	
}

void Koulutusohjelma::lisaaOpiskelija()
{
	Opiskelija opisk;
	opisk.kysyTiedot();
	opiskelijat_.push_back(opisk);
}

void Koulutusohjelma::poistaOpettaja()
{

	cout << "========POISTETAAN OPETTAJA KOULUTUSOHJELMASTA========" << endl;

	int poistettava = etsiOpettaja();

	if (poistettava >= 0) {
		opettajat_.erase(opettajat_.begin() +poistettava);
		cout << "Opettaja poistettu koulutusohjelmasta!" << endl;
	}
	else
		cout << "Valitsemallasi tunnuksella ei loydy opettajaa" << endl;
}

void Koulutusohjelma::poistaOpiskelija()
{
	cout << "========POISTETAAN OPISKELIJA KOULUTUSOHJELMASTA========" << endl;

	int poistettava = etsiOpiskelija();

	if (poistettava >= 0) {
		opiskelijat_.erase(opiskelijat_.begin() + poistettava);
		cout << "Opiskelija poistettu koulutusohjelmasta!" << endl;
	}
	else
		cout << "Valitsemallasi tunnuksella ei loydy opiskelijaa" << endl;
}

void Koulutusohjelma::tulostaOpettajat() const
{
	for (unsigned int i = 0; i < opettajat_.size(); i++)
	{
		opettajat_[i].tulosta();
	}
}

void Koulutusohjelma::tulostaOpiskelijat() const
{
	for (unsigned int i = 0; i < opiskelijat_.size(); i++)
	{
		opiskelijat_[i].tulosta();
	}
}

void Koulutusohjelma::tallennaOpettajat()
{
	ofstream kirj_koulutusOpettajat;
	kirj_koulutusOpettajat.open("opettajat.csv", ofstream::app);
	if (kirj_koulutusOpettajat.is_open()) {
		for (unsigned int i = 0; i < opettajat_.size(); i++) {
			kirj_koulutusOpettajat << opettajat_[i].annaEtunimi() << ";" << opettajat_[i].annaSukunimi() << ";"
				<< opettajat_[i].annaOsoite() << ";" << opettajat_[i].annaPuhelinnumero() << ";" << opettajat_[i].annaTunnus() << ";" << opettajat_[i].annaPalkka()
				<< ";" << opettajat_[i].annaOpetusala() << ";" << endl;
		}
		kirj_koulutusOpettajat.close();
		cout << "opettajat.csv tallennettu" << endl;
	}
	else {
		cout << "Tiedostoa ei voitu avata!" << endl;
	}
	
}

void Koulutusohjelma::tallennaOpiskelijat()
{
	
	ofstream kirj_koulutusOpiskelijat;
	kirj_koulutusOpiskelijat.open("opiskelijat.csv", ofstream::app);
	if (kirj_koulutusOpiskelijat.is_open()) {
		for (unsigned int i = 0; i < opiskelijat_.size(); i++) {
			kirj_koulutusOpiskelijat << opiskelijat_[i].annaOpiskelijanumero() << ";" << opiskelijat_[i].annaEtunimi() << ";" << opiskelijat_[i].annaSukunimi() << ";" << opiskelijat_[i].annaOsoite() << ";" <<
				opiskelijat_[i].annaPuhelinnumero() << ";" << endl;
		}
		kirj_koulutusOpiskelijat.close();;
		cout << "opiskelijat.csv tallennettu" << endl;
	}
	else
		cout << "Tiedostoa ei voitu avata!" << endl;
	
}

void Koulutusohjelma::lueOpettajat()
{
	string etunimi, sukunimi, osoite, puhelinnumero, tunnus, palkka, opetusala;
	ifstream luku_opettajat;
	luku_opettajat.open("opettajat.csv");
	if (luku_opettajat.is_open()) {
		while (luku_opettajat.peek() != EOF) {
			getline(luku_opettajat, etunimi, ';');
			getline(luku_opettajat, sukunimi, ';');
			getline(luku_opettajat, osoite, ';');
			getline(luku_opettajat, puhelinnumero, ';');
			getline(luku_opettajat, tunnus, ';');
			getline(luku_opettajat, palkka, ';');
			getline(luku_opettajat, opetusala, ';');

			double opalkka = atof(palkka.c_str());
			Opettaja tmp(etunimi, sukunimi, osoite, puhelinnumero, opalkka, tunnus, opetusala);
			opettajat_.push_back(Opettaja(tmp));
		}
		cout << "Opettajat.csv luettu" << endl;
		luku_opettajat.close();
	}
	else
		cout << "Tiedostoa ei voitu avata";
}

void Koulutusohjelma::lueOpiskelijat()
{
	string opiskelijanumero, etunimi, sukunimi, osoite, puhelinnumero;
	ifstream luku_opiskelijat;
	luku_opiskelijat.open("opiskelijat.csv");
	if (luku_opiskelijat.is_open()) {
		while (luku_opiskelijat.peek() != EOF) {
			getline(luku_opiskelijat, opiskelijanumero, ';');
			getline(luku_opiskelijat, etunimi, ';');
			getline(luku_opiskelijat, sukunimi, ';');
			getline(luku_opiskelijat, osoite, ';');
			getline(luku_opiskelijat, puhelinnumero, ';');

			Opiskelija tmp(opiskelijanumero, etunimi, sukunimi, osoite, puhelinnumero);
			opiskelijat_.push_back(Opiskelija(tmp));
		}
		cout << "Opiskelijat.csv luettu" << endl;
		luku_opiskelijat.close();
	}
	else
		cout << "Tiedostoa ei voitu avata";
}

void Koulutusohjelma::paivitaOpettaja()
{
		string nimi;
		cout << "Anna paivitettavan opettajan nimi: ";
		getline(cin, nimi);
		for (unsigned int i = 0; i < opettajat_.size(); i++) {
			while (nimi == opettajat_[i].annaEtunimi()) {
				opettajat_[i].kysyTiedot();
				cout << "Opettajan tiedot paivitetty!" << endl;
			}
		}
}

void Koulutusohjelma::paivitaOpiskelija()
{
	string opiskelijanumero;
	cout << "Anna opiskelijanumero: ";
	getline(cin, opiskelijanumero);
	for (unsigned int i = 0; i < opiskelijat_.size(); i++)
	{
		if (opiskelijanumero == opiskelijat_[i].annaOpiskelijanumero())
		{
			opiskelijat_[i].kysyTiedot();
		}
	}
}

int Koulutusohjelma::etsiOpettaja() const
{
	string tunnus;
	cout << "Anna opettajan tunnus: ";
	getline(cin, tunnus);
	for (unsigned int i = 0; i < opettajat_.size(); i++)
	{
		if (tunnus == opettajat_[i].annaTunnus())
		{
			return i;
		}
	}
	return -1;
}

int Koulutusohjelma::etsiOpiskelija() const
{
	string opiskelijanumero;
	cout << "Anna opiskelijanumero: ";
	getline(cin, opiskelijanumero);
	for (unsigned int i = 0; i < opiskelijat_.size(); i++)
	{
		if (opiskelijanumero == opiskelijat_[i].annaOpiskelijanumero())
		{
			return i;
		}
	}
	return -1;
}