#pragma once
#include "Koulutusohjelma.h"
#include <string>
#include <vector>

using std::vector; using std::string;

class Koulu
{
public:
	Koulu();
	Koulu(string nimi);
	~Koulu();
	void asetaNimi(string nimi);
	string annaNimi() const;
	void lisaaKoulutusohjelma();
	void poistaKoulutusohjelma();
	void lisaaKoulutusohjelmaanOpettaja();
	void tulostaKoulutusohjelmanOpettajat() const;
	void lisaaKoulutusohjelmaanOpiskelija();
	void tulostaKoulutusohjelmanOpiskelijat() const;
	void tulostaKoulutusohjelmat() const;
	void tulostaKoulutusohjelmienMaara() const;

	void poistaOpettaja();
	void poistaOpiskelija();

	void paivitaKoulutusohjelma();
	void paivitaOpettaja();
	void paivitaOpiskelija();

	void tallennaKoulutusohjelmat();
	void lueKoulutusohjelmat();

	void lueTiedot();
	void tallennaTiedot();
	
private:
	int etsiKoulutusohjelma() const;
	
	string nimi_;
	vector<Koulutusohjelma> koulutusohjelmat_;
};

