#ifndef __TAD_MOT_PRIVE__
#define __TAD_MOT_PRIVE__
#include "TADMot.h"
/**
* \fn unsigned int max(unsigned int a, unsigned int b);
* \brief Retour le maximum entre deux int
* \param int a : premier integer
* \param int b : deuxi�me integer
* \return le plus grand des deux
* \author Thibaud Dauce
*/
unsigned int max(unsigned int a, unsigned int b);

/**
* \fn unsigned int estLettreOuTiret(char c);
* \brief Test d'un caract�re
* \param char c : le caract�re a tester
* \return vrai si le caract�re pass� en param�tre est valide
* \author Thibaud Dauce
*/
unsigned int estLettreOuTiret(char c);

#endif