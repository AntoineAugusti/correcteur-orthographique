#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "TADSuperMot.h"
#include "TADListeDeSuperMot.h"
#include "TADListeDeSuperMotPrive.h"

/* On respecte la conception du TAD Liste : un tableau et une longueur */

/*
*	PUBLIC
*/
ListeDeSuperMot ListeDeSuperMot_liste() {
	ListeDeSuperMot l;

	l.tableau = NULL;
	l.tableau = malloc(sizeof(SuperMot));
	l.longueur = 0;
	
	return l;
}

int ListeDeSuperMot_estVide(ListeDeSuperMot liste) {
	return (liste.longueur == 0);
}

unsigned int ListeDeSuperMot_longueur(ListeDeSuperMot liste) {
	return liste.longueur;
}

void ListeDeSuperMot_ajouter(ListeDeSuperMot *liste, SuperMot superMot) {
	
	liste->longueur = liste->longueur + 1;
	liste->tableau = realloc(liste->tableau, sizeof(SuperMot) * liste->longueur);
	liste->tableau[liste->longueur - 1] = superMot;
}

SuperMot ListeDeSuperMot_obtenir(ListeDeSuperMot liste, unsigned int indice) {
	assert(1 <= indice && indice <= ListeDeSuperMot_longueur(liste));
	
	return liste.tableau[indice - 1];
}

void ListeDeSuperMot_supprimer(ListeDeSuperMot* liste, unsigned int indice) {
	assert(1 <= indice && indice <= ListeDeSuperMot_longueur(*liste));
	
	ListeDeSuperMot_decalerAGauche(liste, indice);
	liste->longueur = liste->longueur - 1;
	liste->tableau = realloc(liste->tableau, sizeof(SuperMot) * liste->longueur);
}

void ListeDeSuperMot_inserer(ListeDeSuperMot *liste, SuperMot superMot, unsigned int indice) {
	assert(1 <= indice && indice <= ListeDeSuperMot_longueur(*liste) + 1);
	
	liste->longueur = liste->longueur + 1;
	liste->tableau = realloc(liste->tableau, sizeof(SuperMot) * liste->longueur);
	ListeDeSuperMot_decalerADroite(liste, indice);
	liste->tableau[indice - 1] = superMot;
}

void ListeDeSuperMot_liberer(ListeDeSuperMot *liste){
	free(liste->tableau);
}
/*
*	PRIVÉE
*/
void ListeDeSuperMot_decalerADroite(ListeDeSuperMot *liste, unsigned int indice) {
	unsigned int i;

	for (i = liste->longueur - 1; i >= indice; i--) {
		liste->tableau[i] = liste->tableau[i - 1];
	}
}

void ListeDeSuperMot_decalerAGauche(ListeDeSuperMot *liste, unsigned int indice) {
	unsigned int i;

	for (i = indice - 1; i < liste->longueur; i++) {
			liste->tableau[i] = liste->tableau[i + 1];
	}
}