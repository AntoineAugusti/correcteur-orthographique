#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LMSuperMot.h"
#include "TADMot.h"
#include "TADSuperMot.h"
#include "TADListeDeMot.h"
#include "TADListeDeSuperMot.h"
#include "TADDictionnaire.h"

/* Partie privée*/
/* Le doublons ne sont pas possible en C */
unsigned int cestLettreOuTiret(char c) {
	return (isalpha(c) || c == '-' || c == 'à' || c == 'é' || c == 'è' || c == 'ç' || c == 'ï' || c == 'É' || c == 'È' || c == 'Ç' || c == 'À' || c == 'â' || c == 'Â' || c == 'ë' || c == 'Ë' || c == 'ô' || c == 'Ô');
}

/* Partie publique */

ListeDeSuperMot genererListeDeSuperMots(char* chaine, Dictionnaire dictionnaire){
	return separerMots(chaine, dictionnaire);
}

ListeDeSuperMot separerMots(char* chaine, Dictionnaire dictionnaire) {
	unsigned int i;
	ListeDeSuperMot listeRetour;
	Mot motTemp;
	SuperMot superMotTemp;

	motTemp = Mot_mot();
	listeRetour = ListeDeSuperMot_liste();
	for (i = 0; i <= strlen(chaine); i++) {
		
		/* On stocke le mot rencontré */
		if (cestLettreOuTiret(chaine[i])) {
			Mot_insererCaractere(&motTemp, chaine[i], Mot_longueur(motTemp) + 1);
		}
		else {
			/* Arrivé sur un caractère autre que de l'alphabet, le mot précédent va être inséré dans la liste */
			if (Mot_longueur(motTemp) != 0) {
				SuperMot_fixerMot(&superMotTemp, motTemp);
				SuperMot_fixerPosition(&superMotTemp, i - (strlen(Mot_obtenirContenu(motTemp))) + 1);
				SuperMot_fixerValidite(&superMotTemp, verifieValidite(motTemp, dictionnaire));
				ListeDeSuperMot_ajouter(&listeRetour, superMotTemp);
			}
			/* Une fois inséré, on vide le mot */
			motTemp = Mot_mot();
		}
	}

	return listeRetour;
}

int verifieValidite(Mot mot, Dictionnaire dictionnaire) {
	return Dictionnaire_estPresent(dictionnaire, mot);
}