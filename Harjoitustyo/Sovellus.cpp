#include "Sovellus.h"
#include "Koulu.h"
#include <iostream>
#include <string>

using std::cout; using std::cin; using std::getline; using std::string; using std::endl; using std::ofstream; using std::ifstream;

Sovellus::Sovellus(): nimi_()
{
}

Sovellus::Sovellus(string nimi): nimi_(nimi)
{
}


Sovellus::~Sovellus()
{
}

void Sovellus::asetaNimi(string nimi)
{
	nimi_ = nimi;
}

string Sovellus::annaNimi() const
{
	return nimi_;
}

void Sovellus::aja() const
{
	string valinta;
	Koulu koulu(nimi_);
	
	do {
		valinta = tulostaValikko();

		if (valinta == "1") {
			koulu.lisaaKoulutusohjelma();
		}
		else if (valinta == "2") {
			koulu.tulostaKoulutusohjelmat();
		}
		else if (valinta == "3") {
			koulu.tulostaKoulutusohjelmienMaara();
		}
		else if (valinta == "4") {
			koulu.lisaaKoulutusohjelmaanOpettaja();
		}
		else if (valinta == "5") {
			koulu.tulostaKoulutusohjelmanOpettajat();
		}
		else if (valinta == "6") {
			koulu.lisaaKoulutusohjelmaanOpiskelija();
		}
		else if (valinta == "7") {
			koulu.tulostaKoulutusohjelmanOpiskelijat();
		}
		else if (valinta == "8") {
			koulu.poistaKoulutusohjelma();
		}
		else if (valinta == "9") {
			koulu.poistaOpettaja();
		}
		else if (valinta == "10") {
			koulu.poistaOpiskelija();
		}
		else if (valinta == "11") {
			koulu.paivitaKoulutusohjelma();
		}
		else if (valinta == "12") {
			koulu.paivitaOpettaja();
		}
		else if (valinta == "13") {
			koulu.paivitaOpiskelija();
		}
		else if (valinta == "14") {
			koulu.lueTiedot();
		}
		else if (valinta == "15") {
			koulu.tallennaTiedot();
		}
		else
			cout << "Virheellinen valinta" << endl;
	}
	while 
		(valinta != "0");

	cout << "Nakemisiin!" << endl;

}

string Sovellus::tulostaValikko() const
{
	string valinta;

	cout << endl 
		<< "1) Lisaa koulutusohjelma" << endl
		<< "2) Tulosta koulutusohjelmien nimet" << endl
		<< "3) Tulosta koulutusohjelmien maara " << endl
		<< "4) Lisaa koulutusohjelmaan opettaja " << endl
		<< "5) Tulosta koulutusohjelman opettajat " << endl
		<< "6) Lisaa koulutusohjelmaan opiskelija " << endl
		<< "7) Tulosta koulutusohjelman opiskelijat " << endl
		<< "8) Poista koulutusohjelma " << endl
		<< "9) Poista opettaja " << endl
		<< "10) Poista opiskelija " << endl
		<< "11) Paivita koulutusojelman nimi " << endl
		<< "12) Paivita opettajan tiedot " << endl
		<< "13) Paivita opiskelijan tiedot " << endl
		<< "14) Lue tiedot " << endl
		<< "15) Tallenna tiedot" << endl
		<< "0) Lopeta" << endl << endl;

	cout << "Anna valinta: ";
	getline(cin, valinta);

	return valinta;
}
