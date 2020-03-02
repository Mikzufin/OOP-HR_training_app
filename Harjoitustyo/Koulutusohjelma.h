#pragma once
#include "Opettaja.h"
#include "Opiskelija.h"
#include <string>
#include <vector>

using std::vector; using std::string;

class Koulutusohjelma
{
public:
	Koulutusohjelma();
	Koulutusohjelma(string nimi);
	~Koulutusohjelma();

	void asetaNimi(string nimi);
	string annaNimi() const;

	void lisaaOpettaja();
	void lisaaOpiskelija();

	void poistaOpettaja();
	void poistaOpiskelija();

	void tulostaOpettajat() const;
	void tulostaOpiskelijat() const;

	void tallennaOpettajat();
	void tallennaOpiskelijat();

	void lueOpettajat();
	void lueOpiskelijat();

	void paivitaOpettaja();
	void paivitaOpiskelija();

private:
	int etsiOpettaja() const;
	int etsiOpiskelija() const;

	string nimi_;
	vector<Opiskelija> opiskelijat_;
	vector<Opettaja> opettajat_;
};

