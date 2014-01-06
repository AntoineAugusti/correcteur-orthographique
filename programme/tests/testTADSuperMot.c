#include <stdio.h>
#include <CUnit/Basic.h>
#include <string.h>
#include "TADMot.h"
#include "TADListeDeMot.h"
#include "TADSuperMot.h"

/*
Compilation : make TUsupermot
*/

int init_suite_success (void) {
	return 0;
}

int clean_suite_success (void) {
	return 0;
}

void test_fixerMots(void) {
	SuperMot superMot = SuperMot_superMot();
	Mot mot = Mot_genererMot("Salut");

	SuperMot_fixerMot(&superMot, mot);

	CU_ASSERT_STRING_EQUAL(Mot_obtenirContenu(SuperMot_obtenirMot(superMot)), "Salut");
	CU_ASSERT_STRING_NOT_EQUAL(Mot_obtenirContenu(SuperMot_obtenirMot(superMot)), "Blah");
}

void test_position(void) {
	SuperMot superMot = SuperMot_superMot();

	CU_ASSERT_TRUE(SuperMot_obtenirPosition(superMot) == 1);

	SuperMot_fixerPosition(&superMot, 42);
	
	CU_ASSERT_FALSE(SuperMot_obtenirPosition(superMot) == 1);
	CU_ASSERT_TRUE(SuperMot_obtenirPosition(superMot) == 42);
}

void test_listeCorrection(void) {
	
	SuperMot superMot = SuperMot_superMot();
	CU_ASSERT_TRUE(ListeDeMot_estVide(SuperMot_obtenirListeDeCorrection(superMot)));
	
	ListeDeMot liste = ListeDeMot_liste();
	Mot mot = Mot_genererMot("Salut");
	ListeDeMot_ajouter(&liste, mot);
	SuperMot_fixerListeDeCorrections(&superMot, liste);
	CU_ASSERT_FALSE(ListeDeMot_estVide(SuperMot_obtenirListeDeCorrection(superMot)));

	SuperMot_fixerListeDeCorrections(&superMot, ListeDeMot_liste());
	CU_ASSERT_TRUE(ListeDeMot_estVide(SuperMot_obtenirListeDeCorrection(superMot)));
}

void test_validite(void) {
	SuperMot superMot = SuperMot_superMot();

	CU_ASSERT_FALSE(SuperMot_obtenirValidite(superMot));

	SuperMot_fixerValidite(&superMot, 1);
	
	CU_ASSERT_TRUE(SuperMot_obtenirValidite(superMot));

	SuperMot_fixerValidite(&superMot, 0);
	
	CU_ASSERT_FALSE(SuperMot_obtenirValidite(superMot));
}

int main(int argc , char** argv){
	CU_pSuite pSuite = NULL;

	/* initialisation du registre de tests*/ 
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
		(NULL == CU_add_test(pSuite, "SuperMot_fixerMot", test_fixerMots))
		|| (NULL == CU_add_test(pSuite, "SuperMot_position", test_position))
		|| (NULL == CU_add_test(pSuite, "SuperMot_listeCorrection", test_listeCorrection))
		|| (NULL == CU_add_test(pSuite, "SuperMot_validite", test_validite))
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
