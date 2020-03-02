#include "Tyontekija.h"
#include "iostream"

using std::endl; using std::cin; using std::getline; using std::cout;

Tyontekija::Tyontekija(): Henkilo(), palkka_(0.0), tunnus_()
{
}

Tyontekija::Tyontekija(string etunimi, string sukunimi, string osoite, string puhelinnumero, double palkka, string tunnus): Henkilo(etunimi, sukunimi, osoite,
	puhelinnumero), palkka_(palkka), tunnus_(tunnus)
{
}

Tyontekija::Tyontekija(const Tyontekija & alkup):Henkilo(alkup), palkka_(alkup.palkka_), tunnus_(alkup.tunnus_)
{
}


Tyontekija::~Tyontekija()
{
}

Tyontekija & Tyontekija::operator=(const Tyontekija & sij)
{
	if (this != &sij)
	{
		Henkilo::operator=(sij);	// kutsutaan kantaluokan sij.oper.
		palkka_ = sij.palkka_;
		tunnus_ = sij.tunnus_;
	}
	return *this;
}

void Tyontekija::asetaPalkka(double palkka)
{
	palkka_ = palkka;
}

void Tyontekija::asetaTunnus(string tunnus)
{
	tunnus_ = tunnus;
}

double Tyontekija::annaPalkka() const
{
	return palkka_;
}

string Tyontekija::annaTunnus() const
{
	return tunnus_;
}

void Tyontekija::kysyTiedot()
{
	Henkilo::kysyTiedot();
	cout << "Anna palkka: ";
	string palkka;
	getline(cin, palkka);
	palkka_ = atof(palkka.c_str());		//muunnetaan string char-taulukoksi ja sitten atof-funktiolla doubleksi
	cout << "Anna tunnus: ";
	getline(cin, tunnus_);
}

void Tyontekija::tulosta() const
{
	Henkilo::tulosta();
	cout << "Palkka: " << palkka_ << endl << "Tunnus: " << tunnus_ << endl;
}
