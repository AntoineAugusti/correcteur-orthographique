#include <stdio.h>
#include <CUnit/Basic.h>
#include <string.h>
#include "TADParametres.h"

/*
Compilation : make TUparametres
*/

int init_suite_success (void) {
	return 0;
}

int clean_suite_success (void) {
	return 0;
}

void test_fixerDictionnaire(void) {
	Parametres parametre = Parametres_parametre();

	Parametres_fixerDictionnaire(&parametre, "Dico.txt");
	CU_ASSERT_STRING_EQUAL(Parametres_obtenirDictionnaire(parametre), "Dico.txt");
}

void test_fixerFichier(void) {
	Parametres parametre = Parametres_parametre();

	Parametres_fixerFichier(&parametre, "Fichier.txt");
	CU_ASSERT_STRING_EQUAL(Parametres_obtenirFichier(parametre), "Fichier.txt");
}

void test_fixerCible(void) {
	Parametres parametre = Parametres_parametre();

	Parametres_fixerCible(&parametre, "Cible.txt");
	CU_ASSERT_STRING_EQUAL(Parametres_obtenirCible(parametre), "Cible.txt");
}

void test_fixerAide(void) {
	Parametres parametre = Parametres_parametre();

	Parametres_fixerAide(&parametre, 1);
	CU_ASSERT_EQUAL(Parametres_obtenirAide(parametre), 1);
}

int main(int argc , char** argv){
	CU_pSuite pSuite = NULL;

	/* initialisation du registre de tests */ 
	if (CUE_SUCCESS != CU_initialize_registry())
		return CU_get_error() ;
	
	/* ajout d'une suite de test */
	pSuite = CU_add_suite("Tests boite noire ", init_suite_success ,clean_suite_success );
	if (NULL == pSuite) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	/* Ajout des tests à la suite de tests boite noire */
	if (
		(NULL == CU_add_test(pSuite, "Fixer Dico", test_fixerDictionnaire))
		|| (NULL == CU_add_test(pSuite, "Fixer Fichier", test_fixerFichier))
		|| (NULL == CU_add_test(pSuite, "Fixer Cible", test_fixerCible))
		|| (NULL == CU_add_test(pSuite, "Fixer Aide", test_fixerAide))
		) {
		CU_cleanup_registry() ;
		return CU_get_error() ;
	}

	/* Lancement des tests */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	printf ("\n");
	CU_basic_show_failures( CU_get_failure_list() ) ;
	printf ("\n\n");
	/* Nettoyage du registre */
	CU_cleanup_registry () ;
	return CU_get_error () ;
}