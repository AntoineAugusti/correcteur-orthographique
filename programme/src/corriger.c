#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "corriger.h"
#include "TADMot.h"
#include "TADSuperMot.h"
#include "TADDictionnaire.h"
#include "TADCorrecteurOrthographique.h"
#include "TADListeDeSuperMot.h"
#include "math.h"
#include "transtypage.h"
#include "LMSuperMot.h"
#include "affichage.h"

/**
* PRIVE
*/
int estCaractereValide(char c) {
	return (isalpha(c) || c == '-' || c == 'à' || c == 'é' || c == 'è' || c == 'ç' || c == 'ï' || c == 'É' || c == 'È' || c == 'Ç' || c == 'À' || c == 'â' || c == 'Â' || c == 'ë' || c == 'Ë' || c == 'ô' || c == 'Ô' || c == ' ' || c == 'û' || c == '\'');
}

/**
* \fn void erreurAllocationMemoire()
* \brief Affiche une erreur dans l'entrée standard lors d'une allocation mémoire qui n'a pas pu se faire
* \warning Fonction privée
*/
void erreurAllocationMemoire() {
	fprintf(stderr, "Erreur d'allocation mémoire\n");
	exit(1);
}

/* Corriger l'analyse descendante*/
void corriger(char* chaine, Dictionnaire dictionnaire) {
	unsigned int estValide, erreur;
	ListeDeSuperMot listeDeSuperMots;
	estValide = 0;
	erreur = 0;

	evaluerSaisie(&estValide, &erreur, chaine);

	if (estValide) {
		listeDeSuperMots = ListeDeSuperMot_liste();
		listeDeSuperMots = genererListeDeSuperMots(chaine, dictionnaire);
		corrigerListeDeSuperMots(&listeDeSuperMots, dictionnaire);
		afficherCorrection(listeDeSuperMots);
	}
	else
		IHM_afficherErreur(erreur);
}

/**
* \see corriger.h
*/
void evaluerSaisie(unsigned int* estValide,unsigned int* erreur, char* chaine) {
	int i = 0;
	*estValide = 1;

	while (i < strlen(chaine) && *estValide == 1) {
		if (!estCaractereValide(chaine[i])) {
			*estValide = 0;
			*erreur = 1;
		}
		i++;
	}
}

/**
* \see corriger.h
*/
char* lireChaine() {
	int max = 20;
	char c;
    // On alloue la mémoire
	char* name = (char*) malloc(max); 
	int i = 0;

	if (name == 0)
		erreurAllocationMemoire();

    // On saute les premiers espaces
	while (1) {
		c = getchar();
		if (c == EOF)
			break;
		if (!isspace(c)) {
			ungetc(c, stdin);
			break;
		}
	}

	while (1) {
		c = getchar();
        // À la fin de la chaîne on rajoute le caractère de fin
		if (c == '.' || c == EOF) {
			name[i] = '\0';
			break;
		}
		name[i] = c;
        // Le buffer est plein
		if (i == max - 1) { 
			max = max + max;
            // On crée un buffer plus grand
			name = (char*) realloc(name, max);
			if (name == 0)
				erreurAllocationMemoire();
		}
		i++;
	}

	return name;
}

/**
* \see corriger.h
*/
void corrigerListeDeSuperMots(ListeDeSuperMot* listeDeSuperMots, Dictionnaire dictionnaire) {
	int i;
	SuperMot superMotTemp;

	for (i = 1; i <= ListeDeSuperMot_longueur(*listeDeSuperMots); i++) {
		superMotTemp = ListeDeSuperMot_obtenir(*listeDeSuperMots, i);
		if (!SuperMot_obtenirValidite(superMotTemp)) {
			SuperMot_fixerListeDeCorrections(&superMotTemp, CorrecteurOrthographique_proposerMots(dictionnaire, SuperMot_obtenirMot(superMotTemp)) );
			ListeDeSuperMot_supprimer(listeDeSuperMots, i);
			ListeDeSuperMot_inserer(listeDeSuperMots, superMotTemp, i);
		}
	}
}

void afficherCorrection(ListeDeSuperMot listeDeSuperMots) {
	int i;
	SuperMot superMotTemp;

	for (i = 1; i <= ListeDeSuperMot_longueur(listeDeSuperMots); i++) {
		superMotTemp = ListeDeSuperMot_obtenir(listeDeSuperMots, i);

		/* Si le superMot courant est valide */
		if (SuperMot_obtenirValidite(superMotTemp)) {
			printf("*");
		}

		else {
			printf("& %s %d %d : ",
				Mot_obtenirContenu(SuperMot_obtenirMot(superMotTemp)), 
				ListeDeMot_longueur(SuperMot_obtenirListeDeCorrection(superMotTemp)),
				SuperMot_obtenirPosition(superMotTemp)
			);
			ListeDeMot_listeDeMotEnChaine(SuperMot_obtenirListeDeCorrection(superMotTemp));
		}
		printf("\n");
	}
}
