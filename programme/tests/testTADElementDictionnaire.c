#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include <string.h>
#include "TADFichierTexte.h"
#include "TADDictionnaire.h"
#include "TADElementDictionnairePrive.h"
#include "TADMot.h"

/*
Compilation : make TUdico
*/

int init_suite_success (void) {
	return 0;
}

int clean_suite_success (void) {
	return 0;
}

void test_element(void) {
	CU_ASSERT_TRUE(0);
}

void test_ajouterElementsuivant(void) {
	char c = 'c';
	char h = 'h';
	ElementDictionnaire e1 =  ElementDico_element(c, 1);
	ElementDictionnaire e2 =  ElementDico_element(h, 1);
	
	ElementDico_ajouterElementSuivant(&e1, e2);
		
	CU_ASSERT_EQUAL((*ElementDico_obtenirTableauDesElementsSuivants(e1))[0], e2);
}

void test_supprimerElementsuivant(void) {
	char c = 'c';
	char h = 'h';
	char a = 'a';
	ElementDictionnaire e1 =  ElementDico_element(c, 1);
	ElementDictionnaire e2 =  ElementDico_element(h, 1);
	ElementDictionnaire e3 =  ElementDico_element(a, 1);
	
	ElementDico_ajouterElementSuivant(&e1, e2);
	ElementDico_ajouterElementSuivant(&e1, e3);
	ElementDico_supprimerElementSuivant(&e1, 0);
		
	CU_ASSERT_EQUAL((*ElementDico_obtenirTableauDesElementsSuivants(e1))[0], e3);
}

void test_ajouterPresence(void) {
	char c = 'c';
	ElementDictionnaire e1 =  ElementDico_element(c, 1);
	CU_ASSERT_TRUE(ElementDico_obtenirBooleen(e1));
		
	ElementDico_ajouterPresence(&e1, 0);
	CU_ASSERT_FALSE(ElementDico_obtenirBooleen(e1));
}

void test_obtenirLongueurTableauDesElementsSuivants(void) {
	char c = 'c';
	char h = 'h';
	char a = 'a';
	char u = 'u';
	char v = 'v';
	char e = 'e';
	ElementDictionnaire e1 =  ElementDico_element(c, 1);
	ElementDictionnaire e2 =  ElementDico_element(h, 1);
	ElementDictionnaire e3 =  ElementDico_element(a, 1);
	ElementDictionnaire e4 =  ElementDico_element(u, 1);
	ElementDictionnaire e5 =  ElementDico_element(v, 1);
	ElementDictionnaire e6 =  ElementDico_element(e, 1);

	ElementDico_ajouterElementSuivant(&e1 ,e2);
	ElementDico_ajouterElementSuivant(&e1 ,e3);
	ElementDico_ajouterElementSuivant(&e1 ,e4);
	ElementDico_ajouterElementSuivant(&e1 ,e5);
	ElementDico_ajouterElementSuivant(&e1 ,e6);

	ElementDico_ajouterElementSuivant(&e3 ,e4);
	ElementDico_ajouterElementSuivant(&e3 ,e5);
	ElementDico_ajouterElementSuivant(&e3 ,e6);
		
	CU_ASSERT_TRUE(ElementDico_obtenirLongueurTableauDesElementsSuivants(e1) == 5);
	CU_ASSERT_TRUE(ElementDico_obtenirLongueurTableauDesElementsSuivants(e3) == 3);
	CU_ASSERT_TRUE(ElementDico_obtenirLongueurTableauDesElementsSuivants(e6) == 0);
}

void test_obtenirLettre(void) {
	char c = 'c';
	ElementDictionnaire e1 =  ElementDico_element(c, 1);
		
	CU_ASSERT_EQUAL(ElementDico_obtenirLettre(e1), c);
}

void test_obtenirBooleen(void) {
	char c = 'c';
	ElementDictionnaire e1 =  ElementDico_element(c, 1);
	ElementDictionnaire e2 =  ElementDico_element(c, 0);
		
	CU_ASSERT_TRUE(ElementDico_obtenirBooleen(e1));
	CU_ASSERT_FALSE(ElementDico_obtenirBooleen(e2));
}


int main(int argc , char** argv) {
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
		(NULL == CU_add_test(pSuite, "test_ajouterElementsuivant", test_ajouterElementsuivant))
		|| (NULL == CU_add_test(pSuite, "test_supprimerElementsuivant", test_supprimerElementsuivant))
		|| (NULL == CU_add_test(pSuite, "test_obtenirBooleen", test_obtenirBooleen))
		|| (NULL == CU_add_test(pSuite, "test_obtenirLettre", test_obtenirLettre))
		|| (NULL == CU_add_test(pSuite, "test_obtenirLongueurTableauDesElementsSuivants", test_obtenirLongueurTableauDesElementsSuivants))
		|| (NULL == CU_add_test(pSuite, "test_ajouterPresence", test_ajouterPresence))
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
	CU_cleanup_registry();
	return CU_get_error();
}
