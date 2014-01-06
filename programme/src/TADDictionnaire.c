#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include <string.h>
#include "TADDictionnaire.h"
#include "TADElementDictionnairePrive.h"
#include "TADMot.h"
#include "TADFichierTexte.h"

/* Partie priv�e */

/**
* \see TADElementDictionnairePrive.h
*/
ElementDictionnaire ElementDico_element(char caractere, unsigned int estPresent) {
	unsigned int i;
	NoeudDictionnaire *noeud = (NoeudDictionnaire *)malloc(sizeof(NoeudDictionnaire));

	noeud->lettre = caractere;
	noeud->presence = estPresent;
	noeud->longueur = 0;
	for (i = 0; i < NB_LETTRES; ++i) {
		noeud->tableauDesElementsSuivants[i] = NULL;
	}

	return noeud;
}

/**
* \see TADElementDictionnairePrive.h
*/
void ElementDico_ajouterElementSuivant(ElementDictionnaire *e1, ElementDictionnaire e2) {
	unsigned int indice;

	indice = (*e1)->longueur;
	(*e1)->longueur = (*e1)->longueur + 1;
	(*e1)->tableauDesElementsSuivants[indice] = e2;
}

/**
* \see TADElementDictionnairePrive.h
*/
void ElementDico_supprimerElementSuivant(ElementDictionnaire *e1, unsigned int indice) {
	unsigned int i, j;

	assert(0 <= indice && indice < ElementDico_obtenirLongueurTableauDesElementsSuivants(*e1));

	/* On supprime tous les fils de l'�l�ment que l'on veut supprimer */
	for (j = 0; j < ElementDico_obtenirLongueurTableauDesElementsSuivants((*e1)->tableauDesElementsSuivants[indice]); ++j) {
		ElementDico_supprimerElementSuivant(&((*e1)->tableauDesElementsSuivants[indice]), j);
	}

	/* On supprime l'�l�ment que l'on veut supprimer et on d�cr�mente la longueur du p�re */
	free((*e1)->tableauDesElementsSuivants[indice]);

	(*e1)->longueur = (*e1)->longueur - 1;

	/* On supprime le pointeur (qui ne pointe plus vers rien) du tableau du p�re en d�calant */
	for (i = indice; i < (*e1)->longueur; ++i) {
		(*e1)->tableauDesElementsSuivants[i] = (*e1)->tableauDesElementsSuivants[i + 1];
	}
}

/**
* \see TADElementDictionnairePrive.h
*/
void ElementDico_ajouterPresence(ElementDictionnaire *e1, unsigned int presence) {
	(*e1)->presence = presence;
}

/**
* \see TADElementDictionnairePrive.h
*/
unsigned int ElementDico_obtenirLongueurTableauDesElementsSuivants(ElementDictionnaire element) {
	return element->longueur;
}

/**
* \see TADElementDictionnairePrive.h
*/
ElementDictionnaire (*ElementDico_obtenirTableauDesElementsSuivants(ElementDictionnaire element))[NB_LETTRES] {
	return &(element->tableauDesElementsSuivants);
}

/**
* \see TADElementDictionnairePrive.h
*/
char ElementDico_obtenirLettre(ElementDictionnaire element) {
	assert(element != NULL);

	return element->lettre;
}

/**
* \see TADElementDictionnairePrive.h
*/
unsigned int ElementDico_obtenirBooleen(ElementDictionnaire element) {
	assert(element != NULL);

	return element->presence;
}

/**
 * \fn unsigned int Dictionnaire_recupererUneLongueur(Fichier fichier)
 * \author Antoine Augusti
 * \brief R�cup�re la longueur du tableau des �lements suivants dans un fichier o� l'on sauvegarde le dictionnaire
 * \param Fichier fichier : le fichier contenant le dictionnaire
 * \param ElementDictionnaire e2 : l'ElementDictionnaire � ajouter
 * \warning Fonction priv�e
 */
unsigned int Dictionnaire_recupererUneLongueur(Fichier fichier) {
	char premierCaractere, DeuxiemeCaractere;
	unsigned int resultat;

	premierCaractere = FichierTexte_lireCaractere(fichier);

	/* Conversion char -> int d'apr�s http://stackoverflow.com/questions/781668/char-to-int-conversion-in-c */
	resultat = premierCaractere - '0';

	if (!FichierTexte_finFichier(fichier)) {
	
			DeuxiemeCaractere = FichierTexte_lireCaractere(fichier);
			/* On a une longueur sur 2 caract�res */
			if (isdigit(DeuxiemeCaractere))
				resultat = resultat * 10 + (DeuxiemeCaractere - '0');
				/* Longueur sur un seul caract�re, on remet la lettre dans le flux */
			else {
				FichierTexte_deplacementCurseurMoinsUn(&fichier);
			}
	}
	return resultat;
}

/**
 * \fn ElementDictionnaire Dictionnaire_chargerElementsSuivants(Fichier fichier)
 * \author Antoine Augusti
 * \brief Charge r�cursivement les �lements suivants d'un dictionnaire � partir d'un fichier o� l'on sauvegarde le dictionnaire
 * \param Fichier fichier : le fichier contenant le dictionnaire
 * \param ElementDictionnaire e2 : l'ElementDictionnaire � ajouter
 * \warning Fonction priv�e
 */
ElementDictionnaire Dictionnaire_chargerElementsSuivants(Fichier fichier) {
	char caractere;
	unsigned int booleen, i, longueur;
	ElementDictionnaire element;

	caractere = FichierTexte_lireCaractere(fichier);
	/* Conversion char -> int d'apr�s http://stackoverflow.com/questions/781668/char-to-int-conversion-in-c */
	/* Il faut v�rifier que l'on peut bien convertir pour avoir un int coh�rent */
	booleen = FichierTexte_lireCaractere(fichier) - '0';
	longueur = Dictionnaire_recupererUneLongueur(fichier);
	element = ElementDico_element(caractere, booleen);
	
	for (i = 1; i <= longueur; ++i) {
		ElementDico_ajouterElementSuivant(&element, Dictionnaire_chargerElementsSuivants(fichier));
	}

	return element;
} /* Antoine */

/**
 * \fn char Dictionnaire_booleenEnCaractere(unsigned int booleen)
 * \author Jean-Claude Bernard
 * \brief Transforme un bool�en(unsigned int) en un caract�re
 * \param unsigned int booleen : un booleen
 * \warning Fonction priv�e
 */
 char Dictionnaire_booleenEnCaractere(unsigned int booleen) {
 	/* Conversion d'un int en char ;  d'apr�s http://stackoverflow.com/questions/1114741/how-to-convert-int-to-char-c*/
 	char resultat = (char)(((int)'0') + booleen);

 	return resultat; 
 }

/**
 * \fn  void Dictionnaire_naturelEnCaractere(unsigned int longueur, char* dizaine, char* unite) 
 * \author Jean-Claude Bernard
 * \brief Transforme un naturel en un caract�re
 * \param unsigned int longueur : le naturel que l'on veut convertir
 * \param char* dizaine : le caract�re (chiffre des dizaines) que l'on veut obtenir
 * \param char* unite : le caract�re (unit�) que l'on veut obtenir
 * \warning Fonction priv�e
 */
 void Dictionnaire_naturelEnCaractere(unsigned int longueur, char* dizaine, char* unite) {
 	assert((0 <= longueur) && (longueur <= NB_LETTRES));

 	*dizaine = '0';

 	if (longueur >= 10)
 	{
 		if (longueur >= 90)
 			*dizaine = '9';
 		else if (longueur >= 80)
 			*dizaine = '8';
 		else if (longueur >= 70)
 			*dizaine = '7';
 		else if (longueur >= 60)
 			*dizaine = '6';
 		else if (longueur >= 50)
 			*dizaine = '5';
 		else if (longueur >= 40)
 			*dizaine = '4';
 		else if (longueur >= 30)
 			*dizaine = '3';
 		else if (longueur >= 20)
 			*dizaine = '2';
 		else
 			*dizaine = '1';
 	}
 	*unite = (char)(((int)'0') + (longueur % 10));
}

/**
 * \fn void Dictionnaire_sauvegarderElementsSuivants(Fichier* fichier, ElementDictionnaire elementDico)
 * \author Jean-Claude Bernard
 * \brief Sauvegarde r�cursivement les �lements suivants d'un dictionnaire dans un fichier 
 * \param Fichier* fichier : le fichier dans lequel on veut sauvegarder le dictionnaire
 * \param ElementDictionnaire elementDico : l'ElementDictionnaire � sauvegarder
 * \warning Fonction priv�e
 */
void Dictionnaire_sauvegarderElementsSuivants(Fichier* fichier, ElementDictionnaire elementDico) {
	ElementDictionnaire tableauDesElementsSuivants[NB_LETTRES];
	char dizaine, unite;
	unsigned int i, indice;

	for (indice = 0; indice < NB_LETTRES; ++indice) {
		tableauDesElementsSuivants[indice] = (*ElementDico_obtenirTableauDesElementsSuivants(elementDico))[indice];
	}

	for (i = 0; i < ElementDico_obtenirLongueurTableauDesElementsSuivants(elementDico); ++i)
	{
		FichierTexte_ecrireCaractere(fichier, ElementDico_obtenirLettre(tableauDesElementsSuivants[i]));
		FichierTexte_ecrireCaractere(fichier, Dictionnaire_booleenEnCaractere(ElementDico_obtenirBooleen(tableauDesElementsSuivants[i])));
		Dictionnaire_naturelEnCaractere(ElementDico_obtenirLongueurTableauDesElementsSuivants(tableauDesElementsSuivants[i]), &dizaine, &unite);

		if (dizaine != '0') {
			FichierTexte_ecrireCaractere(fichier, dizaine);
		}
		FichierTexte_ecrireCaractere(fichier, unite);
		Dictionnaire_sauvegarderElementsSuivants(fichier, tableauDesElementsSuivants[i]);
	}
}


/* Partie publique */

/**
* \see TADDictionnaire.h
*/
Dictionnaire Dictionnaire_dictionnaire() {
	unsigned int i;
	Dictionnaire dictionnaire;

	for (i = 0; i < NB_LETTRES; ++i) {
		dictionnaire.racines[i] = NULL;
	}

	dictionnaire.longueur = 0;

	return dictionnaire;
} /* JC */

/**
* \see TADDictionnaire.h
*/
unsigned int Dictionnaire_estVide(Dictionnaire dictionnaire) {
	return (dictionnaire.longueur == 0);
} /* Antoine */

/**
* \see TADDictionnaire.h
*/
void Dictionnaire_insererMot(Dictionnaire* dictionnaire, Mot mot) {
	unsigned int i, j, longueur, indice;
	ElementDictionnaire element, nouvelElement;
	ElementDictionnaire tableauDesElementsSuivants[NB_LETTRES];

	for (indice = 0; indice < NB_LETTRES; ++indice) {
		tableauDesElementsSuivants[indice] = (dictionnaire->racines)[indice];
	}
	longueur = dictionnaire->longueur;

	/* On ins�re le mot dans le dictionnaire */
	for (i = 1; i <= Mot_longueur(mot); ++i) {
		j = 0;
		/* On vient chercher dans notre tableau le caract�re correspondant au caract�re de notre mot */
		while (j < longueur && (ElementDico_obtenirLettre(tableauDesElementsSuivants[j]) != Mot_iemeCaractere(mot, i))) {
			j = j + 1;
		} 
		/* Si on a trouv�, on va chercher dans le tableauDesElementsSuivants de l'�l�ment, le caract�re suivant du mot */
		if (j < longueur) {
			element = tableauDesElementsSuivants[j];
		}
		/* Sinon on  ajoute l'�l�ment */
		else {
			nouvelElement = ElementDico_element(Mot_iemeCaractere(mot, i), 0);

			/* La racine n'existe pas dans le dictionnaire, on doit la cr�er */
			if (i == 1) {
				dictionnaire->racines[dictionnaire->longueur] = nouvelElement;
				dictionnaire->longueur = dictionnaire->longueur + 1;
			}
			else {
				ElementDico_ajouterElementSuivant(&element, nouvelElement);
			}
			element = nouvelElement;
		}

		/* On passe � l'�l�ment suivant pour le prochain caract�re du mot */
		for (indice = 0; indice < NB_LETTRES; ++indice) {
			tableauDesElementsSuivants[indice] = (*ElementDico_obtenirTableauDesElementsSuivants(element))[indice];
		}
		longueur = ElementDico_obtenirLongueurTableauDesElementsSuivants(element);
	}

	/* Enfin, on dit que le mot est pr�sent dans le dictionnaire */
	ElementDico_ajouterPresence(&element, 1);
}

/**
* \see TADDictionnaire.h
*/
void Dictionnaire_insererFichier(Dictionnaire* dictionnaire, char* nomFichier) {
	Fichier fichier;
	char* ligne; 

	fichier = FichierTexte_fichierTexte(nomFichier);
	FichierTexte_ouvrir(&fichier, LECTURE);
	ligne = FichierTexte_lireChaine(fichier);

	while (ligne != NULL) 
	{
		Dictionnaire_insererMot(dictionnaire, Mot_genererMot(ligne));
		free(ligne);
		if (FichierTexte_finFichier(fichier) == 0) {
			ligne = FichierTexte_lireChaine(fichier);
		}
		else
			ligne = NULL;
	}
	free(ligne);
	FichierTexte_fermer(&fichier);
} /* JC */

/**
* \see TADDictionnaire.h
*/
unsigned int Dictionnaire_estPresent(Dictionnaire dictionnaire, Mot mot) {
	unsigned int i, j, longueur, indice;
	ElementDictionnaire tableauDesElementsSuivants[NB_LETTRES];
	ElementDictionnaire element;

	for (indice = 0; indice < NB_LETTRES; ++indice) {
		tableauDesElementsSuivants[indice] = (dictionnaire.racines)[indice];
	}
	longueur = dictionnaire.longueur;

	/* V�rifions que l'on trouve le mot caract�re apr�s caract�re dans le dictionnaire */
	for (i = 1; i <= Mot_longueur(mot); ++i) {
		j = 0;
		while (j < longueur && ElementDico_obtenirLettre(tableauDesElementsSuivants[j]) != Mot_iemeCaractere(mot, i)) {
			j = j + 1;
		}
		/* On v�rfie si on est sorti du while parce qu'on est arriv� � la fin du tableau ou si on a trouv� la bonne lettre */
		if (j < longueur && ElementDico_obtenirLettre(tableauDesElementsSuivants[j]) == Mot_iemeCaractere(mot, i)) {
			element = tableauDesElementsSuivants[j];
		}
		/* Echec, le mot recherch� n'est pas dans le dictionnaire */
		else {
			return 0;
		}

		/* Tout va bien, on continue � avancer pour le prochain caract�re */
		for (indice = 0; indice < NB_LETTRES; ++indice) {
			tableauDesElementsSuivants[indice] = (*ElementDico_obtenirTableauDesElementsSuivants(element))[indice];
		}
		longueur = ElementDico_obtenirLongueurTableauDesElementsSuivants(element);
	}

	/* Si on n'a eu toujours aucune erreur, on retourne la valeur du bool�en du dernier caract�re */
	return ElementDico_obtenirBooleen(element);
} /* Antoine */

/**
* \see TADDictionnaire.h
*/
Dictionnaire Dictionnaire_charger(char* emplacement) {
	Fichier fichier;
	Dictionnaire dictionnaire;
	unsigned int longueur, i;


	dictionnaire = Dictionnaire_dictionnaire();
	fichier = FichierTexte_fichierTexte(emplacement);
	FichierTexte_ouvrir(&fichier, LECTURE);
	longueur = Dictionnaire_recupererUneLongueur(fichier);
	dictionnaire.longueur = longueur;

	for (i = 0; i < longueur; ++i) {
		dictionnaire.racines[i] = Dictionnaire_chargerElementsSuivants(fichier);
	}
	FichierTexte_fermer(&fichier);

	return dictionnaire;
} /* Antoine */

/**
* \see TADDictionnaire.h
*/
Fichier Dictionnaire_sauvegarder(Dictionnaire dictionnaire, char* emplacement) {
	Fichier fichier;
	char dizaine, unite;
	unsigned int i;

	fichier = FichierTexte_fichierTexte(emplacement);
	FichierTexte_ouvrir(&fichier, ECRITURE);
	Dictionnaire_naturelEnCaractere(dictionnaire.longueur, &dizaine, &unite);
	if (dizaine != '0') {
		FichierTexte_ecrireCaractere(&fichier, dizaine);
	}
	FichierTexte_ecrireCaractere(&fichier, unite);

	for (i = 0; i < dictionnaire.longueur; ++i)
	{
		FichierTexte_ecrireCaractere(&fichier, ElementDico_obtenirLettre(dictionnaire.racines[i]));
		FichierTexte_ecrireCaractere(&fichier, Dictionnaire_booleenEnCaractere(ElementDico_obtenirBooleen(dictionnaire.racines[i])));
		Dictionnaire_naturelEnCaractere(ElementDico_obtenirLongueurTableauDesElementsSuivants(dictionnaire.racines[i]), &dizaine, &unite);

		if (dizaine != '0') {
			FichierTexte_ecrireCaractere(&fichier, dizaine);
		}
		
		FichierTexte_ecrireCaractere(&fichier, unite);
		Dictionnaire_sauvegarderElementsSuivants(&fichier, dictionnaire.racines[i]);
	}
	FichierTexte_fermer(&fichier);

	return(fichier);
} /* JC */
