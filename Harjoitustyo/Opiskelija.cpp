#include "Opiskelija.h"
#include <iostream>

using std::cout; using std::cin; using std::endl; using std::getline;

Opiskelija::Opiskelija() :Henkilo(), opiskelijanumero_()
{

}

Opiskelija::Opiskelija(string etunimi, string sukunimi, string osoite, string puhelinnumero, string opiskelijanumero) :
	Henkilo(etunimi, sukunimi, osoite, puhelinnumero), opiskelijanumero_(opiskelijanumero)
{

}

Opiskelija::Opiskelija(const Opiskelija & alkup): Henkilo(alkup), opiskelijanumero_(alkup.opiskelijanumero_)
{

}


Opiskelija::~Opiskelija()
{

}

Opiskelija & Opiskelija::operator=(const Opiskelija & sij)
{
	if (this != &sij)
	{
		Henkilo::operator=(sij);			// kutsutaan kantaluokan sij.oper.
		opiskelijanumero_ = sij.opiskelijanumero_;

		return *this;
	}
}

void Opiskelija::asetaOpiskelijanumero(string opiskelijanumero)
{
	opiskelijanumero_ = opiskelijanumero;
}

string Opiskelija::annaOpiskelijanumero() const
{
	return opiskelijanumero_;
}

void Opiskelija::kysyTiedot()
{
	Henkilo::kysyTiedot();	//kutsutaan kantaluokan rutiinia
	
	cout << "Anna opiskelijanumero: ";
	getline(cin, opiskelijanumero_);
}

void Opiskelija::tulosta() const
{
	Henkilo::tulosta();
	
	cout << "Opiskelijanumero: " << opiskelijanumero_ << endl;

}
