#ifndef __TAD_ELEMENT_DICTIONNAIRE__
#define __TAD_ELEMENT_DICTIONNAIRE__

#define NB_LETTRES 96

typedef struct NoeudDictionnaire* ElementDictionnaire;

typedef struct NoeudDictionnaire {
  char lettre;
  unsigned int presence;
  unsigned int longueur;
  ElementDictionnaire tableauDesElementsSuivants[NB_LETTRES];
} NoeudDictionnaire;


/**
 * \fn ElementDictionnaire ElementDico_element(char caractere, unsigned int estPresent);
 * \author Antoine Augusti
 * \brief Cr�e un ElementDictionnaire
 * \param char caractere : la lettre concern�e
 * \param unsigned int estPresent : indique si la lettre est pr�sente ou non
 * \return retourne l'ElementDictionnaire cr��
 */
ElementDictionnaire ElementDico_element(char caractere, unsigned int estPresent);

/**
 * \fn void ElementDico_ajouterElementSuivant(ElementDictionnaire *e1, ElementDictionnaire e2);
 * \author Jean-Claude Bernard
 * \brief Ajoute un ElementDictionnaire suivant � l'ElementDictionnaire e1
 * \param ElementDictionnaire e1 : le premier ElementDictionnaire auquel on va ajouter e2
 * \param ElementDictionnaire e2 : l'ElementDictionnaire � ajouter
 */
void ElementDico_ajouterElementSuivant(ElementDictionnaire *e1, ElementDictionnaire e2);

/**
 * \fn void ElementDico_supprimerElementSuivant(ElementDictionnaire *e1, unsigned int indice);
 * \author Antoine Augusti
 * \brief Supprime l'ElementDictionnaire suivant donn�, selon l'indice donn�
 * \param ElementDictionnaire e1 : l'ElementDictionnaire o� l'on va supprimer le pointeur vers l'ElementDictionnaire suivant
 * \param unsigned int indice : l'indice du pointeur vers ElementDictionnaire � supprimer
 * \warning assert(0 <= indice && indice < ElementDico_obtenirLongueurTableauDesElementsSuivants(*e1))
 */
void ElementDico_supprimerElementSuivant(ElementDictionnaire *e1, unsigned int indice);

/**
 * \fn void ElementDico_ajouterPresence(ElementDictionnaire *e1, unsigned int presence);
 * \author Jean-Claude Bernard 
 * \brief Fixe la pr�sence de l'ElementDictictionnaire donn�
 * \param ElementDictionnaire e1 : l'ElementDictionnaire o� l'on va fixer la pr�sence
 * \param unsigned int presence : le booleen vrai(1) ou faux(0)
 */
void ElementDico_ajouterPresence(ElementDictionnaire *e1, unsigned int presence);

/**
 * \fn ElementDictionnaire (*ElementDico_obtenirTableauDesElementsSuivants(ElementDictionnaire element))[NB_LETTRES];
 * \author Jean-Claude Bernard
 * \brief Retourne le tableau des ElementDictionnaire suivants
 * \param ElementDictionnaire element : l'ElementDictionnaire auquel on s'int�resse
 * \param ElementDictionnaire tableauDesElementsSuivants[NB_LETTRES] : le tableau des ElementDictionnaire suivant
 */
ElementDictionnaire (*ElementDico_obtenirTableauDesElementsSuivants(ElementDictionnaire element))[NB_LETTRES];

/**
 * \fn unsigned int ElementDico_obtenirLongueurTableauDesElementsSuivants(ElementDictionnaire element);
 * \author Antoine Augusti
 * \brief Retourne la longueur du tableau des ElementDictionnaire suivants
 * \param ElementDictionnaire element : l'ElementDictionnaire auquel on s'int�resse
 * \return la taille du tableau des ElementDictionnaire suivants
 */
unsigned int ElementDico_obtenirLongueurTableauDesElementsSuivants(ElementDictionnaire element);

/**
 * \fn char ElementDico_obtenirLettre(ElementDictionnaire element);
 * \author Antoine Augusti
 * \brief Retourne la lettre de l'ElementDictionnaire actuel
 * \param ElementDictionnaire element : l'ElementDictionnaire auquel on s'int�resse
 * \return la lettre de l'ElementDictionnaire courant
 */
char ElementDico_obtenirLettre(ElementDictionnaire element);

/**
 * \fn unsigned int ElementDico_obtenirBooleen(ElementDictionnaire element);
 * \author Antoine Augusti
 * \brief Indique si la lettre est pr�sente pour l'ElementDictionnaire actuel
 * \param ElementDictionnaire element : l'ElementDictionnaire auquel on s'int�resse
 * \return vrai si pr�sent, faux sinon
 */
unsigned int ElementDico_obtenirBooleen(ElementDictionnaire element);

#endif