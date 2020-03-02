#include "Opiskelija.h"
#include "Tyontekija.h"
#include "Opettaja.h"
#include "Koulutusohjelma.h"
#include "Koulu.h"
#include "Sovellus.h"
#include <iostream>

using std::cout; using std::endl;

int main() {
	try {
		Sovellus amk("TAMK");
		amk.aja();
	}
	catch (std::exception &ex) {
		cout << "Virhe: " << ex.what() << endl;
	}
	catch (...) {
		cout << "Ohjelman ajossa tuli jokin virhe!";
	}
}