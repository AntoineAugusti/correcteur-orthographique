/* Ce commentaire est utilisé pour forcer la conversion en ISO */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "TADParametres.h"

Parametres Parametres_parametre(){
	Parametres p;

	p.dictionnaire = NULL;
	p.fichier = NULL;
	p.cible = NULL;
	p.aide = 0;
	return p;
}

void Parametres_fixerDictionnaire(Parametres* p, char* nomDuDico){
	(*p).dictionnaire = nomDuDico;
}

void Parametres_fixerFichier(Parametres* p, char* nomDuFichier){
	(*p).fichier = nomDuFichier;
}

void Parametres_fixerCible(Parametres* p, char* nomDeLaCible){
	(*p).cible = nomDeLaCible;
}

void Parametres_fixerAide(Parametres* p, int presenceDuH){
	(*p).aide = presenceDuH;
}

char* Parametres_obtenirDictionnaire(Parametres p){
	return p.dictionnaire;
}

char* Parametres_obtenirFichier(Parametres p){
	return p.fichier;
}

int Parametres_obtenirAide(Parametres p){
	return p.aide;
}

char* Parametres_obtenirCible(Parametres p){
	return p.cible;
}