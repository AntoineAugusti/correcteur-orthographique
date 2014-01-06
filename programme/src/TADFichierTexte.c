#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include "TADFichierTexte.h"
#define NB_LETTRES_MAX 100

Fichier FichierTexte_fichierTexte(char* nomDuFichier) {
	Fichier fichier;
	fichier.file = NULL;
	fichier.nom = nomDuFichier;
	
	return fichier;
}

void FichierTexte_ouvrir(Fichier *fichier, Mode mode) {
	assert(!FichierTexte_estOuvert(*fichier));

	if (mode == ECRITURE) {
			fichier->file = fopen(fichier->nom, "w+");
			fichier->mode = mode;
	}
	else if (mode == LECTURE) {
			fichier->file = fopen(fichier->nom, "r");
			fichier->mode = mode;
	}
	else printf("pas le bon mode\n");

}

void FichierTexte_fermer(Fichier *fichier) {
	if (FichierTexte_estOuvert(*fichier)) {
		fclose(fichier->file);
		fichier->file = NULL;
	}
}

unsigned int FichierTexte_estOuvert(Fichier fichier) {
	return fichier.file != NULL;
}

Mode FichierTexte_mode(Fichier fichier) {
	return fichier.mode;
}

unsigned int FichierTexte_finFichier(Fichier fichier) {
	/* Déclarations */
	unsigned int resultat;
	/* Préconditions */
	assert((fichier.mode == LECTURE) && FichierTexte_estOuvert(fichier));

	resultat = (fgetc(fichier.file)==EOF);  
	fseek(fichier.file, -1, SEEK_CUR);
/*	FichierTexte_deplacementCurseurMoinsUn(&fichier);
*/
	return (resultat);
}

void FichierTexte_ecrireChaine(Fichier *fichier, char* chaine) {
	assert(FichierTexte_estOuvert(*fichier) && (FichierTexte_mode(*fichier) == ECRITURE));	
	fputs(chaine, fichier->file);
}

char* FichierTexte_lireChaine(Fichier fichier) {
	assert(FichierTexte_estOuvert(fichier) && (FichierTexte_mode(fichier) == LECTURE) && !FichierTexte_finFichier(fichier));

	char* chaine = malloc(NB_LETTRES_MAX * sizeof(char) +1 );
	fgets(chaine, NB_LETTRES_MAX, fichier.file);
	return chaine;
}

void FichierTexte_ecrireCaractere(Fichier *fichier, char caractere) {
	assert(FichierTexte_estOuvert(*fichier) && (FichierTexte_mode(*fichier) == ECRITURE));
	fputc(caractere, fichier->file);
}

char FichierTexte_lireCaractere(Fichier fichier) {
	assert(FichierTexte_estOuvert(fichier) && (FichierTexte_mode(fichier) == LECTURE) && !FichierTexte_finFichier(fichier));
	return fgetc(fichier.file);
}

void FichierTexte_deplacementCurseurMoinsUn(Fichier *fichier) {
	assert(FichierTexte_estOuvert(*fichier) && (FichierTexte_mode(*fichier) == LECTURE));
	fseek(fichier->file,-1, SEEK_CUR );
}

unsigned int FichierTexte_existe(char* emplacement) {
	if (access(emplacement, F_OK ) != -1)
		return 1;
	else
		return 0;
}

unsigned int FichierTexte_nombreDeCaractere(Fichier fichier){
	/* Déclarations */
	unsigned int resultat;
	char caractereTemp;
	
	/* Corps */
	resultat = 0;
	while (!FichierTexte_finFichier(fichier)) {
		caractereTemp = FichierTexte_lireCaractere(fichier);
		if (!FichierTexte_estUnRetourChariot(caractereTemp))
			resultat = resultat + 1;
	}
	return resultat;
}

unsigned int FichierTexte_estUnRetourChariot(char caractere){
	return (caractere == '\n');
}