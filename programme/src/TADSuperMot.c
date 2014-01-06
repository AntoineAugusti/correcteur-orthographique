/* Ce commentaire est utilisé pour forcer la conversion en ISO */
#include <stdio.h>
#include <stdlib.h>
#include "TADSuperMot.h"
#include "TADMot.h"
#include "TADListeDeMot.h"

SuperMot SuperMot_superMot() {
	SuperMot superMot;

	superMot.mot = Mot_mot();
	superMot.position = 1;
	superMot.listeDeCorrections = ListeDeMot_liste();
	superMot.valide = 0;

	return superMot;
}

Mot SuperMot_obtenirMot(SuperMot superMot) {
	return superMot.mot;
}

void SuperMot_fixerMot(SuperMot* superMot, Mot mot) {
	(*superMot).mot = mot;
}

unsigned int SuperMot_obtenirPosition(SuperMot superMot) {
	return superMot.position;
}

void SuperMot_fixerPosition(SuperMot* superMot, unsigned int position) {
	(*superMot).position = position;
}

ListeDeMot SuperMot_obtenirListeDeCorrection(SuperMot superMot) {
	return superMot.listeDeCorrections;
}

void SuperMot_fixerListeDeCorrections(SuperMot* superMot, ListeDeMot corrections) {
	(*superMot).listeDeCorrections = corrections;
}

int SuperMot_obtenirValidite(SuperMot superMot) {
	return superMot.valide;
}

void SuperMot_fixerValidite(SuperMot* superMot, int estValide) {
	(*superMot).valide = estValide;
}