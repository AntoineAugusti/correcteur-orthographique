#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "TADParametres.h"
#include "TADDictionnaire.h"
#include "affichage.h"
#include "corriger.h"

/**
* \fn Parametre formaterParametres(unsigned int nbParametres, char* parametres) {
* \brief Renvoie une structure param�tre permettant de savoir facilement quelles sont les options pass�es
* \param unsigned int nbParametres : le nombre de param�tres
* \param char* parametres : la liste de param�tres pass�s
* \return Parametre parametre
* \author �tienne Batise
*/
Parametres formaterParametres(unsigned int nbParametres, char* const* parametres) {
	int optch;
	char format[] = "hd:f:";
	Parametres parametre;

	parametre = Parametres_parametre();
	while ((optch = getopt(nbParametres, parametres, format)) != -1) {
		switch (optch) {
			case 'h':
				Parametres_fixerAide(&parametre, 1);
			break;

			case 'd':
				Parametres_fixerDictionnaire(&parametre, optarg);
			break;

			case 'f':
				Parametres_fixerFichier(&parametre, optarg);
			break;
		}
	} 

	return parametre;
}

/**
* \fn void executerProgramme(Parametre parametre)
* \brief Execute le programme en fonction des champs de parametre remplies
* \param Parametre parametre : la structure dans les champs permettent de lancer tell ou tel sous programme
* \author �tienne Batise
*/
void executerProgramme(Parametres parametre) {
	Dictionnaire d;
	char* entreeStandard;

	d = Dictionnaire_dictionnaire();

	if ((Parametres_obtenirAide(parametre) == 1)) { //|| ((Parametres_obtenirFichier(parametre) != NULL) && (Parametres_obtenirDictionnaire(parametre) != NULL) && (Parametres_obtenirCible(parametre) != NULL) ) ) {
		IHM_afficherAide();
	}
	else {

		/* Si on a un fichier et un dictionnaire, on compl�te le dictionnaire d�j� s�rialis� */
		if ((Parametres_obtenirFichier(parametre) != NULL) && (Parametres_obtenirDictionnaire(parametre) != NULL)) {
			if (FichierTexte_existe(Parametres_obtenirDictionnaire(parametre))) {
				if (FichierTexte_existe(Parametres_obtenirFichier(parametre))) {
					d = Dictionnaire_charger(Parametres_obtenirDictionnaire(parametre));
					Dictionnaire_insererFichier(&d, Parametres_obtenirFichier(parametre));
					Dictionnaire_sauvegarder(d, Parametres_obtenirDictionnaire(parametre));

					printf("Le fichier %s a bien �t� ajout� au dictionnaire %s.\n", Parametres_obtenirFichier(parametre), Parametres_obtenirDictionnaire(parametre));
				}
				else
					printf("Erreur : le fichier %s demand� n'existe pas.\n", Parametres_obtenirFichier(parametre));
			}
			else
				printf("Erreur : le dictionnaire %s demand� n'existe pas.\n", Parametres_obtenirDictionnaire(parametre));
		}
		else {
			entreeStandard = lireChaine();
			Parametres_fixerCible(&parametre, entreeStandard);
			
			/* On effectue la correction avec le dictionnaire d�j� s�rialis� */
			if ((Parametres_obtenirCible(parametre) != NULL) && (Parametres_obtenirDictionnaire(parametre) != NULL)) {
				if (FichierTexte_existe(Parametres_obtenirDictionnaire(parametre))) {
					d = Dictionnaire_charger(Parametres_obtenirDictionnaire(parametre));
					corriger(Parametres_obtenirCible(parametre), d);
				}
				else
					printf("Erreur : le dictionnaire %s demand� n'existe pas.\n", Parametres_obtenirDictionnaire(parametre));

			}
			free(entreeStandard);
		}

	}
}

int main(int argc, char *argv[]) {
	Parametres parametres;

	parametres = formaterParametres(argc, argv);
	executerProgramme(parametres);

	return 0;
}