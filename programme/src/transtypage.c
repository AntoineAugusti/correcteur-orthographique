/* Ce commentaire est utilisé pour forcer la conversion en ISO */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "transtypage.h"

char* Transtypage_entierEnChaine(unsigned int e){
	int nouveauE, indice, taille, longueur, temp, p;
	char* retour;
	nouveauE = e;
	taille = 1;
	longueur = 1;
	indice  = 0;
	while (nouveauE / longueur >= 10) {
		longueur = longueur * 10;
		taille = taille + 1;
	}

	retour = malloc(sizeof(char) * (taille + 1));

	for (p = taille; p >= 1; p--) {
		temp = nouveauE / pow(10, p - 1);
		retour[indice] = (char)(((int)'0') + temp);
		indice = indice + 1;
		nouveauE = nouveauE - temp * pow(10, p - 1);
	}

	return retour;
}