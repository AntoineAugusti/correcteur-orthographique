#include <stdio.h>
#include <stdlib.h>
#include "TADCorrecteurOrthographique.h"
#include "TADCorrecteurOrthographiquePrive.h"
#include "TADMot.h"
#include "TADDictionnaire.h"
#include "TADListeDeMot.h"
#define NB_LETTRES_ALPHABET 26

/**
* \see TADCorrecteurOrthographique.h
*/
ListeDeMot CorrecteurOrthographique_proposerMots(Dictionnaire dictionnaire, Mot mot) {
	return CorrecteurOrthographique_motsExacts(CorrecteurOrthographique_possibilitesMots(mot), dictionnaire);;
}

/**
* \see TADCorrecteurOrthographiquePrive.h
*/
ListeDeMot CorrecteurOrthographique_possibilitesMots(Mot mot) {
	/* Déclarations */
	ListeDeMot liste, liste2, liste3, liste4;
	unsigned int i;

	/* Corps */
	liste = CorrecteurOrthographique_genererMotsParSuppression(mot);
	liste2 = CorrecteurOrthographique_genererMotsParRemplacement(mot);
	liste3 = CorrecteurOrthographique_genererMotsParInsertion(mot);
	liste4 = CorrecteurOrthographique_genererMotsParInversion(mot);

	for (i = 1; i <= ListeDeMot_longueur(liste2); i++) {
		ListeDeMot_ajouter(&liste, ListeDeMot_obtenir(liste2, i));
	}
	for (i = 1; i <= ListeDeMot_longueur(liste3); i++) {		
		ListeDeMot_ajouter(&liste, ListeDeMot_obtenir(liste3, i));
	}
	for (i = 1; i <= ListeDeMot_longueur(liste4); i++) {		
		ListeDeMot_ajouter(&liste, ListeDeMot_obtenir(liste4, i));
	}

	return liste;
}

ListeDeMot CorrecteurOrthographique_genererMotsParInversion(Mot mot) {
	/* Déclarations */
	ListeDeMot listeDeMots;
	Mot motTemp;
	char c;
	unsigned int i;

	/* Corps */
	listeDeMots = ListeDeMot_liste();
	for (i = 1; i <= Mot_longueur(mot) - 1; i++) {
		motTemp = Mot_genererMot(Mot_obtenirContenu(mot));
		c = Mot_iemeCaractere(mot, i);
		Mot_modifierCaractere(&motTemp, Mot_iemeCaractere(mot, i + 1), i);
		Mot_modifierCaractere(&motTemp, c, i + 1);
		ListeDeMot_inserer(&listeDeMots, motTemp, 1);
	}
	return listeDeMots;
}

/**
* \see TADCorrecteurOrthographiquePrive.h
*/
ListeDeMot CorrecteurOrthographique_genererMotsParSuppression(Mot mot) {
	/* Déclarations */
	ListeDeMot listeDeMots;
	Mot motTemp;
	unsigned int i;

	/* Corps */
	listeDeMots = ListeDeMot_liste();
	if (Mot_longueur(mot) >= 2) {
		for (i = 1; i <= Mot_longueur(mot); i++) {
			motTemp = Mot_genererMot(Mot_obtenirContenu(mot));
			Mot_supprimerCaractere(&motTemp, i);
			ListeDeMot_inserer(&listeDeMots, motTemp, 1);
		}
	}
	return listeDeMots;
}

/**
* \see TADCorrecteurOrthographiquePrive.h
*/
ListeDeMot CorrecteurOrthographique_genererMotsParRemplacement(Mot mot) {
	/* Déclarations */
	char lettre[NB_LETTRES_ALPHABET];
	ListeDeMot listeDeMots;	
	Mot motTemp;
	unsigned int i, j;

	/* Corps */
	listeDeMots = ListeDeMot_liste();
	lettre[0] = 'a';

	/* Initiatilisation du tableau de lettres */
	for (i = 1; i < NB_LETTRES_ALPHABET; i++) {
		lettre[i] = lettre[i - 1] + 1;
	}

	for (i = 1; i <= Mot_longueur(mot); i++) {
		for (j = 0; j < NB_LETTRES_ALPHABET; j++) {
			motTemp = Mot_genererMot(Mot_obtenirContenu(mot));
			Mot_modifierCaractere(&motTemp, lettre[j], i);
			ListeDeMot_inserer(&listeDeMots, motTemp, 1);
		}
	}

	return listeDeMots;
}

/**
* \see TADCorrecteurOrthographiquePrive.h
*/
ListeDeMot CorrecteurOrthographique_genererMotsParInsertion(Mot mot) {
	/* Déclarations */
	char lettre[NB_LETTRES_ALPHABET];
	ListeDeMot listeDeMots;	
	Mot motTemp;
	unsigned int i, j;

	/* Corps */
	listeDeMots = ListeDeMot_liste();
	lettre[0] = 'a';

	/* Initiatilisation du tableau de lettres */
	for (i = 1; i < NB_LETTRES_ALPHABET; i++) {
		lettre[i] = lettre[i - 1] + 1;  
	}

	for (i = 1; i <= Mot_longueur(mot) + 1 ; i++) {
		for (j = 0; j < NB_LETTRES_ALPHABET; j++) {
			motTemp = Mot_genererMot(Mot_obtenirContenu(mot));
			Mot_insererCaractere(&motTemp, lettre[j], i);
			ListeDeMot_inserer(&listeDeMots, motTemp, 1);
		}
	}

	return listeDeMots;
	
}

/**
* \see TADCorrecteurOrthographiquePrive.h
*/
ListeDeMot CorrecteurOrthographique_motsExacts(ListeDeMot listeDeMots, Dictionnaire dictionnaire) {
	/* Déclarations */
	Mot mot;
	ListeDeMot listeFinale;
	unsigned int i;

	/* Corps */
	listeFinale = ListeDeMot_liste();
	for (i = 1; i <= ListeDeMot_longueur(listeDeMots); i++) {
		mot = ListeDeMot_obtenir(listeDeMots, i);
		if (Dictionnaire_estPresent(dictionnaire, mot) && !ListeDeMot_estPresent(listeFinale, mot)) {
			ListeDeMot_ajouter(&listeFinale, mot);
		}
	}

	return listeFinale;
}