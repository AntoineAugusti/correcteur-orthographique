#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "TADMot.h"
#include "TADListeDeMotPrive.h"
#include "TADListeDeMot.h"

/* On respecte la conception du TAD Liste : un tableau et une longueur */

/*
*	PUBLIC
*/
ListeDeMot ListeDeMot_liste() {
	ListeDeMot l;
	l.tableau = NULL;
	l.tableau = malloc(sizeof(Mot));
	l.longueur = 0;
	
	return l;
}

int ListeDeMot_estVide(ListeDeMot liste) {
	return (liste.longueur == 0);
}

unsigned int ListeDeMot_longueur(ListeDeMot liste) {
	return liste.longueur;
}

void ListeDeMot_ajouter(ListeDeMot *liste, Mot mot) {
	liste->longueur = liste->longueur + 1;
	liste->tableau = realloc(liste->tableau, sizeof(Mot) * liste->longueur);
	liste->tableau[liste->longueur - 1] = mot;
}

Mot ListeDeMot_obtenir(ListeDeMot liste, unsigned int indice) {
	assert(1 <= indice && indice <= ListeDeMot_longueur(liste));

	return liste.tableau[indice - 1];
}

void ListeDeMot_supprimer(ListeDeMot* liste, unsigned int indice) {
	assert(1 <= indice && indice <= ListeDeMot_longueur(*liste));
	
	ListeDeMot_decalerAGauche(liste, indice);
	liste->longueur = liste->longueur - 1;
	liste->tableau = realloc(liste->tableau, sizeof(Mot) * liste->longueur);
}

void ListeDeMot_inserer(ListeDeMot *liste, Mot mot, unsigned int indice) {
	assert(1 <= indice && indice <= ListeDeMot_longueur(*liste) + 1);

	liste->longueur = liste->longueur + 1;
	liste->tableau = realloc(liste->tableau, sizeof(Mot) * liste->longueur);
	ListeDeMot_decalerADroite(liste, indice);
	liste->tableau[indice - 1] = mot;
}

void ListeDeMot_listeDeMotEnChaine(ListeDeMot liste) {
	int i;

	for(i = 1; i <= ListeDeMot_longueur(liste); i++){
		printf("%s ", Mot_obtenirContenu(ListeDeMot_obtenir(liste, i)));
	}
}

void ListeDeMot_liberer(ListeDeMot *liste){
	free(liste->tableau);
}

unsigned int ListeDeMot_estPresent(ListeDeMot liste, Mot mot){
	unsigned int i, res;

	i = 1;
	res = 0;

	while (!res && i <= ListeDeMot_longueur(liste)) {
		res = Mot_sontEgaux(ListeDeMot_obtenir(liste, i), mot);
		i++;
	}

	return res;
}


/*
*	PRIVÉE
*/
void ListeDeMot_decalerADroite(ListeDeMot *liste, unsigned int indice) {
	/* Déclarations */
	unsigned int i;

	/* Corps */
	for (i = liste->longueur - 1; i >= indice; i--) {
		liste->tableau[i] = liste->tableau[i-1];
	}
}

void ListeDeMot_decalerAGauche(ListeDeMot *liste, unsigned int indice) {
	/* Déclarations */
	unsigned int i;

	/* Déclarations */
	for (i = indice - 1; i < liste->longueur; i++) {
		liste->tableau[i] = liste->tableau[i + 1];
	}
}
