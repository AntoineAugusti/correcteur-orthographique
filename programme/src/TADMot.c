#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include "TADMot.h"
#include "TADMotPrive.h"

/*
*	PUBLIC
*/
Mot Mot_mot() {

	Mot mot;
	mot.contenu = malloc(sizeof(char));
	mot.contenu[0] = '\0';
	mot.longueur = 0;
	
	return mot;
}

char* Mot_obtenirContenu(Mot mot) {
	return mot.contenu;
}

unsigned int Mot_longueur(Mot mot) {
	return mot.longueur;
}

Mot Mot_genererMot(char* chaine) {

	Mot mot = Mot_mot();
	for (int i = 1; i <= strlen(chaine); i++) {

		if (estLettreOuTiret(chaine[i - 1])) {
			Mot_insererCaractere(&mot, chaine[i - 1], i);
		}
		
	}

	return mot;
}

unsigned int Mot_sontEgaux(Mot mot1, Mot mot2) {

	if (mot1.longueur != mot2.longueur)
		return 0;
	else {
		if (strcmp(mot1.contenu, mot2.contenu) == 0)
			return 1;
		else
			return 0;
	}
}

void Mot_insererCaractere(Mot* mot, char c, unsigned int position) {
	assert(0 < position && position <= (Mot_longueur(*mot) + 1) && estLettreOuTiret(c));
	
	if (position == (Mot_longueur(*mot) + 1)) {

		mot->longueur = mot->longueur + 1;
		mot->contenu = realloc(mot->contenu, sizeof(char) * (mot->longueur + 1));
		mot->contenu[position - 1] = c;
		mot->contenu[position] = '\0';
	}
	else {

		for (int i = Mot_longueur(*mot) + 1; i >= (position + 1); i--) {
			Mot_modifierCaractere(mot, Mot_iemeCaractere(*mot, i - 1), i);
		}
		mot->longueur = mot->longueur + 1;
		Mot_modifierCaractere(mot, c, position);
	}	
}

void Mot_modifierCaractere(Mot* mot, char c, unsigned int position) {
	assert(0 < position && position <= (Mot_longueur(*mot) + 1) && estLettreOuTiret(c));

	mot->contenu[position - 1] = c;

	if (position == Mot_longueur(*mot) + 1)
		mot->contenu[position] = '\0';
}

void Mot_supprimerCaractere(Mot* mot, unsigned int position) {
	assert(0 < position && position <= Mot_longueur(*mot));

	char c;

	if (mot->longueur == 1 && position == 1) {
		*mot = Mot_mot();
	}
	else {
		for (int i = position; i < Mot_longueur(*mot); ++i) {
			c = Mot_iemeCaractere(*mot, i + 1);
			Mot_modifierCaractere(mot, c, i);
		}
		mot->longueur = mot->longueur - 1;
	}
	mot->contenu[Mot_longueur(*mot)] = '\0';
	mot->contenu = realloc(mot->contenu, sizeof(char) * (mot->longueur + 1));
}

char Mot_iemeCaractere(Mot mot, unsigned int position) {
	assert(0 < position && position < Mot_longueur(mot) + 1);

	return mot.contenu[position - 1];
}

Mot Mot_concatener(Mot mot1, Mot mot2) {

	return Mot_genererMot(strcat(mot1.contenu, mot2.contenu));
}

unsigned int Mot_estUnMotValide(Mot mot) {

	int i = 1;
	int res = 1;
	
	while (res && i <= Mot_longueur(mot)) {
		res = estLettreOuTiret(Mot_iemeCaractere(mot, i));
		i = i + 1;
	}

	return res;
}

void Mot_separerMots(Mot mot, unsigned int position, Mot* mot1, Mot* mot2) {
	assert(2 <= position && position <= Mot_longueur(mot));

	char c;

	*mot1 = Mot_mot();

	for (int i = 1; i < position; ++i) {
		c = Mot_iemeCaractere(mot, i);
		Mot_insererCaractere(mot1, c, i);
	}

	*mot2 = Mot_mot();
	for (int j = position; j <= Mot_longueur(mot); ++j) {
		c = Mot_iemeCaractere(mot, j);
		Mot_insererCaractere(mot2, c, j - position + 1);
	}
}

Mot Mot_sousMot(Mot mot, unsigned int debut, unsigned int longueur) {
	assert(0 < debut && 0 < longueur && (debut + longueur - 1) <= Mot_longueur(mot) && Mot_longueur(mot) != 0);

	char c;
	Mot nouveau;

	nouveau = Mot_mot();
	for (int i = debut; i < debut + longueur; ++i) {
		c = Mot_iemeCaractere(mot, i);
		Mot_insererCaractere(&nouveau, c, i - debut + 1);
	}

	return nouveau;
}

unsigned int Mot_estSousMot(Mot mot1, Mot mot2) {

	if (Mot_longueur(mot1) > Mot_longueur(mot2))
		return 0;
	else {
		if (strstr(mot2.contenu, mot1.contenu) == NULL)
			return 0;
		else
			return 1;
	}
}

unsigned int Mot_sontIdentiques(Mot* mot1, Mot* mot2) {

	return (mot1 == mot2);
}

/*
*	PRIVÉE
*/
unsigned int max(unsigned int a, unsigned int b) {

	if (a > b)
		return a;
	else
		return b;
}

unsigned int estLettreOuTiret(char c) {
	return (isalpha(c) || c == '-' || c == 'à' || c == 'é' || c == 'è' || c == 'ç' || c == 'ï' || c == 'É' || c == 'È' || c == 'Ç' || c == 'À' || c == 'â' || c == 'Â' || c == 'ë' || c == 'Ë' || c == 'ô' || c == 'Ô' || c == 'î' || c == 'ê' || c == 'û' || c == 'ü' || c == 'ä' || c == 'ö');
}
