#include "Opettaja.h"
#include <string>
#include <iostream>


using std::cout; using std::cin; using std::endl; using std::getline;

Opettaja::Opettaja()
{
}

Opettaja::Opettaja(string etunimi, string sukunimi, string osoite, string puhelinnumero, double palkka, string tunnus, string opetusala): 
	Tyontekija (etunimi, sukunimi, osoite, puhelinnumero, palkka, tunnus), opetusala_(opetusala)
{
}

Opettaja::Opettaja(const Opettaja & alkup): Tyontekija(alkup), opetusala_(alkup.opetusala_)
{
}


Opettaja::~Opettaja()
{
}

Opettaja & Opettaja::operator=(const Opettaja & sij)
{
	if (this != &sij)
	{
		Tyontekija::operator=(sij);
		opetusala_ = sij.opetusala_;
	}

	return *this;
}

void Opettaja::asetaOpetusala(string opetusala)
{
	opetusala_ = opetusala;
}

string Opettaja::annaOpetusala() const
{
	return opetusala_;
}

void Opettaja::kysyTiedot()
{
	Tyontekija::kysyTiedot();
	cout << "Anna opetusala: ";
	getline(cin, opetusala_);
}

void Opettaja::tulosta() const
{
	Tyontekija::tulosta();

	cout <<"Opetusala: " << opetusala_ << endl;
}
