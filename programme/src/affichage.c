#include <stdio.h>
#include <stdlib.h>
#include "affichage.h"


void IHM_afficherAide() {
	printf("Aide Asispell :\n");
	printf("	asispell -h : cette aide\n");
	printf("	asispell -d dico : correction de l'entrée standard à l'aide du dico\n");
	printf("	asispell -d dico -f fic : compléter le dictionnaire dico à l'aide des mots du fichier fic (un mot par ligne)\n");
}

void IHM_afficherResultat(int erreur, char* resultat) {
	if (erreur != 0)
		IHM_afficherErreur(erreur);
	else
		IHM_afficherCorrection(resultat);
}

void IHM_afficherCorrection(char* resultat) {
	printf("%s\n", resultat);
}

void IHM_afficherErreur(int erreur) {
	
	switch(erreur) {
		case 1 :
			printf("Au moins un caractère entré n'est pas valide.");
			break;

		case 2 :
			printf("erreur de type 2");
			break;
			 
		default :
			printf("erreur par défaut");
	}
}