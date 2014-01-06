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

void test_dictionnaire(void) {
	CU_ASSERT_TRUE(0);
}

void test_creationElement(void) {
	ElementDictionnaire element = ElementDico_element('c', 1);

	CU_ASSERT_EQUAL(ElementDico_obtenirLettre(element), 'c');
	CU_ASSERT_TRUE(ElementDico_obtenirBooleen(element));
	CU_ASSERT_EQUAL(ElementDico_obtenirLongueurTableauDesElementsSuivants(element), 0);

	ElementDico_ajouterPresence(&element, 0);
	CU_ASSERT_FALSE(ElementDico_obtenirBooleen(element));

	ElementDico_ajouterElementSuivant(&element, ElementDico_element('a', 1));
	CU_ASSERT_EQUAL(ElementDico_obtenirLongueurTableauDesElementsSuivants(element), 1);

	ElementDico_supprimerElementSuivant(&element, 0);
	CU_ASSERT_EQUAL(ElementDico_obtenirLongueurTableauDesElementsSuivants(element), 0);
}

void test_estVide(void) {
	/* On crée un dictionnaire d et on regarde si il est vide */
	Dictionnaire d = Dictionnaire_dictionnaire();
	CU_ASSERT_TRUE(Dictionnaire_estVide(d));

	/* On crée un mot qu'on insère dans le dictionnaire d et on regarde si il n'est pas vide */	
	Mot m = Mot_genererMot("Salut");
	Dictionnaire_insererMot(&d, m);
	CU_ASSERT_FALSE(Dictionnaire_estVide(d));
}

void test_insererMot(void) {	
	Mot m = Mot_genererMot("Salut");	
	Mot m2 = Mot_genererMot("Bonjour");
	Mot m3 = Mot_genererMot("Salutations");
	Mot m4 = Mot_genererMot("Zebre");
	Mot m5 = Mot_genererMot("Pique-nique");

	for (int i = 1; i <= 4; ++i)
	{
		Dictionnaire d =  Dictionnaire_dictionnaire();
		CU_ASSERT_TRUE(Dictionnaire_estVide(d));

		if (i == 1) {
			Dictionnaire_insererMot(&d, m);
			Dictionnaire_insererMot(&d, m2);
			Dictionnaire_insererMot(&d, m3);
			Dictionnaire_insererMot(&d, m4);
			Dictionnaire_insererMot(&d, m5);
		}
		else if (i == 2) {
			Dictionnaire_insererMot(&d, m3);
			Dictionnaire_insererMot(&d, m);
			Dictionnaire_insererMot(&d, m4);
			Dictionnaire_insererMot(&d, m5);
			Dictionnaire_insererMot(&d, m2);
		}
		else if (i == 3) {
			Dictionnaire_insererMot(&d, m4);
			Dictionnaire_insererMot(&d, m);
			Dictionnaire_insererMot(&d, m3);
			Dictionnaire_insererMot(&d, m2);
			Dictionnaire_insererMot(&d, m5);
		}
		else if (i == 4) {
			Dictionnaire_insererMot(&d, m5);
			Dictionnaire_insererMot(&d, m4);
			Dictionnaire_insererMot(&d, m3);
			Dictionnaire_insererMot(&d, m2);
			Dictionnaire_insererMot(&d, m);
		}

		CU_ASSERT_TRUE(Dictionnaire_estPresent(d, m));
		CU_ASSERT_TRUE(Dictionnaire_estPresent(d, m2));
		CU_ASSERT_TRUE(Dictionnaire_estPresent(d, m3));
		CU_ASSERT_TRUE(Dictionnaire_estPresent(d, m4));
		CU_ASSERT_TRUE(Dictionnaire_estPresent(d, m5));
		CU_ASSERT_FALSE(Dictionnaire_estVide(d));
	}
}

void test_insererFichier(void) {
	/* On crée un fichierTexte qu'on ouvre en écriture */
	Fichier f = FichierTexte_fichierTexte("tests/testTADDictionnaire.txt");
	FichierTexte_ouvrir(&f, ECRITURE);
	/* On écrit 'a' dans le fichier et on ferme le fichier */
	FichierTexte_ecrireCaractere(&f, 'a');
	FichierTexte_fermer(&f);

	/* On crée un dictionnaire et deux Mots */
	Dictionnaire d = Dictionnaire_dictionnaire();
	Mot m = Mot_genererMot("a");
	Mot m1 = Mot_genererMot("b");

	/* On insère le fichier créé avant dans le dictionnaire */
	Dictionnaire_insererFichier(&d, "tests/testTADDictionnaire.txt");

	/* On vérifie qu'il n'est pas vide, qu'il contient le mot correspondant au caractère et qu'il ne contient pas le mot qui ne correspond pas au caractère */
	CU_ASSERT_FALSE(Dictionnaire_estVide(d));
	CU_ASSERT_TRUE(Dictionnaire_estPresent(d, m));
	CU_ASSERT_FALSE(Dictionnaire_estPresent(d, m1));

	/* On insère un fichier comportant 3 mots, on vérifie que le dictionnaire contient les 3 mots */
	Dictionnaire d3 = Dictionnaire_dictionnaire();
	Mot m2 = Mot_genererMot("Bonjour");
	Mot m3 = Mot_genererMot("Monsieur");
	Mot m4 = Mot_genererMot("Aurevoir");

	Dictionnaire_insererFichier(&d3, "tests/testTADDictionnaire5.txt");

	CU_ASSERT_TRUE(Dictionnaire_estPresent(d3, m2));
	CU_ASSERT_TRUE(Dictionnaire_estPresent(d3, m3));
	CU_ASSERT_TRUE(Dictionnaire_estPresent(d3, m4));
	CU_ASSERT_FALSE(Dictionnaire_estVide(d3));
	
	Dictionnaire d4 = Dictionnaire_dictionnaire();
	Dictionnaire_insererFichier(&d4, "tests/testTADDictionnaire7.txt");
	CU_ASSERT_TRUE(d4.longueur == 10);

	/* On sauvegarde le dictionnaire */
	Dictionnaire_sauvegarder(d4, "tests/testTADDictionnaire8.txt");

	/* On charge un dictionnaire sérialisé et on insère un fichier contenant des mots, on vérifie si l'ensemble 
	des mots est contenu dans le dictionnaire */
	Dictionnaire d5 = Dictionnaire_charger("tests/testTADDictionnaire8.txt");
	Dictionnaire_insererFichier(&d5, "tests/testTADDictionnaire9.txt");

	CU_ASSERT_TRUE(Dictionnaire_estPresent(d5, Mot_genererMot("Bonjour")));
	CU_ASSERT_TRUE(Dictionnaire_estPresent(d5, Mot_genererMot("Monsieur")));
	CU_ASSERT_TRUE(Dictionnaire_estPresent(d5, Mot_genererMot("Comment")));
	CU_ASSERT_TRUE(Dictionnaire_estPresent(d5, Mot_genererMot("allez")));
	CU_ASSERT_TRUE(Dictionnaire_estPresent(d5, Mot_genererMot("vous")));
	CU_ASSERT_TRUE(Dictionnaire_estPresent(d5, Mot_genererMot("et")));
	CU_ASSERT_TRUE(Dictionnaire_estPresent(d5, Mot_genererMot("votre")));
	CU_ASSERT_TRUE(Dictionnaire_estPresent(d5, Mot_genererMot("Femme")));
	CU_ASSERT_TRUE(Dictionnaire_estPresent(d5, Mot_genererMot("merveilleusement")));
	CU_ASSERT_TRUE(Dictionnaire_estPresent(d5, Mot_genererMot("bien")));
	CU_ASSERT_TRUE(Dictionnaire_estPresent(d5, Mot_genererMot("malheureusement")));
	CU_ASSERT_TRUE(Dictionnaire_estPresent(d5, Mot_genererMot("Aurevoir")));
	CU_ASSERT_TRUE(Dictionnaire_estPresent(d5, Mot_genererMot("ça")));
	CU_ASSERT_TRUE(Dictionnaire_estPresent(d5, Mot_genererMot("va")));
	CU_ASSERT_TRUE(Dictionnaire_estPresent(d5, Mot_genererMot("été")));
	CU_ASSERT_TRUE(Dictionnaire_estPresent(d5, Mot_genererMot("sommes")));
	CU_ASSERT_TRUE(Dictionnaire_estPresent(d5, Mot_genererMot("bientôt")));
	CU_ASSERT_TRUE(Dictionnaire_estPresent(d5, Mot_genererMot("élève")));
	CU_ASSERT_TRUE(Dictionnaire_estPresent(d5, Mot_genererMot("noël")));
	CU_ASSERT_TRUE(Dictionnaire_estPresent(d5, Mot_genererMot("ççdçççéeééé")));

	Dictionnaire dicoASI = Dictionnaire_dictionnaire();
	Dictionnaire_insererFichier(&dicoASI, "tests/dico-ref-ascii.txt");
	Dictionnaire_sauvegarder(dicoASI, "tests/dico.dico");
}

void test_charger(void) {
	Fichier f = FichierTexte_fichierTexte("tests/testTADDictionnaire3.txt");
	FichierTexte_ouvrir(&f, ECRITURE);
	FichierTexte_ecrireCaractere(&f, '1');
	FichierTexte_ecrireCaractere(&f, 'S');
	FichierTexte_ecrireCaractere(&f, '0');
	FichierTexte_ecrireCaractere(&f, '1');
	FichierTexte_ecrireCaractere(&f, 'a');
	FichierTexte_ecrireCaractere(&f, '0');
	FichierTexte_ecrireCaractere(&f, '1');
	FichierTexte_ecrireCaractere(&f, 'l');
	FichierTexte_ecrireCaractere(&f, '1');
	FichierTexte_ecrireCaractere(&f, '0');
	FichierTexte_fermer(&f);
	
	Dictionnaire d = Dictionnaire_charger("tests/testTADDictionnaire3.txt");
	Mot mot = Mot_genererMot("Sal");

	CU_ASSERT_TRUE(Dictionnaire_estPresent(d, mot));

	Dictionnaire d2 = Dictionnaire_dictionnaire();
	Mot m2 = Mot_genererMot("Bonjour");
	Mot m3 = Mot_genererMot("Monsieur");
	Mot m4 = Mot_genererMot("Aurevoir");

	Dictionnaire_insererFichier(&d2, "tests/testTADDictionnaire5.txt");
	Dictionnaire_sauvegarder(d2, "tests/testTADDictionnaire6.txt");

	Dictionnaire d3 = Dictionnaire_charger("tests/testTADDictionnaire6.txt");

	CU_ASSERT_TRUE(Dictionnaire_estPresent(d3, m2));
	CU_ASSERT_TRUE(Dictionnaire_estPresent(d3, m3));
	CU_ASSERT_TRUE(Dictionnaire_estPresent(d3, m4));

	Dictionnaire d4 = Dictionnaire_charger("tests/testTADDictionnaire8.txt");
	CU_ASSERT_TRUE(Dictionnaire_estPresent(d4, Mot_genererMot("Bonjour")));
	CU_ASSERT_TRUE(Dictionnaire_estPresent(d4, Mot_genererMot("Monsieur")));
	CU_ASSERT_TRUE(Dictionnaire_estPresent(d4, Mot_genererMot("Comment")));
	CU_ASSERT_TRUE(Dictionnaire_estPresent(d4, Mot_genererMot("allez")));
	CU_ASSERT_TRUE(Dictionnaire_estPresent(d4, Mot_genererMot("vous")));
	CU_ASSERT_TRUE(Dictionnaire_estPresent(d4, Mot_genererMot("et")));
	CU_ASSERT_TRUE(Dictionnaire_estPresent(d4, Mot_genererMot("votre")));
	CU_ASSERT_TRUE(Dictionnaire_estPresent(d4, Mot_genererMot("Femme")));
	CU_ASSERT_TRUE(Dictionnaire_estPresent(d4, Mot_genererMot("merveilleusement")));
	CU_ASSERT_TRUE(Dictionnaire_estPresent(d4, Mot_genererMot("bien")));
	CU_ASSERT_TRUE(Dictionnaire_estPresent(d4, Mot_genererMot("malheureusement")));
	CU_ASSERT_TRUE(Dictionnaire_estPresent(d4, Mot_genererMot("Aurevoir")));

	Dictionnaire d5 = Dictionnaire_dictionnaire();
	Dictionnaire_insererFichier(&d5, "tests/testTADDictionnaire9.txt");

	CU_ASSERT_TRUE(Dictionnaire_estPresent(d5, Mot_genererMot("ça")));
	CU_ASSERT_TRUE(Dictionnaire_estPresent(d5, Mot_genererMot("va")));
	CU_ASSERT_TRUE(Dictionnaire_estPresent(d5, Mot_genererMot("été")));
	CU_ASSERT_TRUE(Dictionnaire_estPresent(d5, Mot_genererMot("sommes")));
	CU_ASSERT_TRUE(Dictionnaire_estPresent(d5, Mot_genererMot("bientôt")));
	CU_ASSERT_TRUE(Dictionnaire_estPresent(d5, Mot_genererMot("élève")));
	CU_ASSERT_TRUE(Dictionnaire_estPresent(d5, Mot_genererMot("noël")));
	CU_ASSERT_TRUE(Dictionnaire_estPresent(d5, Mot_genererMot("ççdçççéeééé")));

	Dictionnaire_sauvegarder(d5, "tests/testTADDictionnaire10.txt");

	Dictionnaire d6 = Dictionnaire_charger("tests/testTADDictionnaire10.txt");
	CU_ASSERT_TRUE(Dictionnaire_estPresent(d6, Mot_genererMot("ça")));
	CU_ASSERT_TRUE(Dictionnaire_estPresent(d6, Mot_genererMot("va")));
	CU_ASSERT_TRUE(Dictionnaire_estPresent(d6, Mot_genererMot("été")));
	CU_ASSERT_TRUE(Dictionnaire_estPresent(d6, Mot_genererMot("sommes")));
	CU_ASSERT_TRUE(Dictionnaire_estPresent(d6, Mot_genererMot("bientôt")));
	CU_ASSERT_TRUE(Dictionnaire_estPresent(d6, Mot_genererMot("élève")));
	CU_ASSERT_TRUE(Dictionnaire_estPresent(d6, Mot_genererMot("noël")));
	CU_ASSERT_TRUE(Dictionnaire_estPresent(d6, Mot_genererMot("ççdçççéeééé")));

}

void test_sauvegarder(void) {
	Dictionnaire d = Dictionnaire_dictionnaire();
	Mot m = Mot_genererMot("Sal");
	Dictionnaire_insererMot(&d, m);

	Fichier f = FichierTexte_fichierTexte("tests/testTADDictionnaire1.txt");
	FichierTexte_ouvrir(&f, ECRITURE);
	FichierTexte_ecrireCaractere(&f, '1');
	FichierTexte_ecrireCaractere(&f, 'S');
	FichierTexte_ecrireCaractere(&f, '0');
	FichierTexte_ecrireCaractere(&f, '1');
	FichierTexte_ecrireCaractere(&f, 'a');
	FichierTexte_ecrireCaractere(&f, '0');
	FichierTexte_ecrireCaractere(&f, '1');
	FichierTexte_ecrireCaractere(&f, 'l');
	FichierTexte_ecrireCaractere(&f, '1');
	FichierTexte_ecrireCaractere(&f, '0');
	FichierTexte_fermer(&f);

	Dictionnaire_sauvegarder(d, "tests/testTADDictionnaire2.txt");
	FichierTexte_ouvrir(&f, LECTURE);
	Fichier f2 = FichierTexte_fichierTexte("tests/testTADDictionnaire2.txt");
	FichierTexte_ouvrir(&f2, LECTURE);
	char *ligne1 = FichierTexte_lireChaine(f);
	char *ligne2 = FichierTexte_lireChaine(f2);

	CU_ASSERT_TRUE(strcmp(ligne1, ligne2) == 0);

	free(ligne1);
	free(ligne2);

	FichierTexte_fermer(&f);
	FichierTexte_fermer(&f2);
	
	Mot m1 = Mot_genererMot("Salut");
	Dictionnaire_insererMot(&d, m1);
	Dictionnaire_sauvegarder(d, "tests/testTADDictionnaire2.txt");

	Fichier f3 = FichierTexte_fichierTexte("tests/testTADDictionnaire4.txt");
	FichierTexte_ouvrir(&f3, ECRITURE);
	FichierTexte_ecrireCaractere(&f3, '1');
	FichierTexte_ecrireCaractere(&f3, 'S');
	FichierTexte_ecrireCaractere(&f3, '0');
	FichierTexte_ecrireCaractere(&f3, '1');
	FichierTexte_ecrireCaractere(&f3, 'a');
	FichierTexte_ecrireCaractere(&f3, '0');
	FichierTexte_ecrireCaractere(&f3, '1');
	FichierTexte_ecrireCaractere(&f3, 'l');
	FichierTexte_ecrireCaractere(&f3, '1');
	FichierTexte_ecrireCaractere(&f3, '1');
	FichierTexte_ecrireCaractere(&f3, 'u');
	FichierTexte_ecrireCaractere(&f3, '0');
	FichierTexte_ecrireCaractere(&f3, '1');
	FichierTexte_ecrireCaractere(&f3, 't');
	FichierTexte_ecrireCaractere(&f3, '1');
	FichierTexte_ecrireCaractere(&f3, '0');
	FichierTexte_fermer(&f3);

	FichierTexte_ouvrir(&f3, LECTURE);
	Fichier f4 = FichierTexte_fichierTexte("tests/testTADDictionnaire2.txt");
	FichierTexte_ouvrir(&f4, LECTURE);
	char *ligne3 = FichierTexte_lireChaine(f3);
	char *ligne4 = FichierTexte_lireChaine(f4);

	CU_ASSERT_TRUE(strcmp(ligne3, ligne4) == 0);

	free(ligne3);
	free(ligne4);

	FichierTexte_fermer(&f3);
	FichierTexte_fermer(&f4);

	Mot m2 = Mot_genererMot("Bonjour");
	Dictionnaire_insererMot(&d, m2);
	Dictionnaire_sauvegarder(d, "tests/testTADDictionnaire2.txt");

	Fichier f5 = FichierTexte_fichierTexte("tests/testTADDictionnaire4.txt");
	FichierTexte_ouvrir(&f5, ECRITURE);
	FichierTexte_ecrireCaractere(&f5, '2');
	FichierTexte_ecrireCaractere(&f5, 'S');
	FichierTexte_ecrireCaractere(&f5, '0');
	FichierTexte_ecrireCaractere(&f5, '1');
	FichierTexte_ecrireCaractere(&f5, 'a');
	FichierTexte_ecrireCaractere(&f5, '0');
	FichierTexte_ecrireCaractere(&f5, '1');
	FichierTexte_ecrireCaractere(&f5, 'l');
	FichierTexte_ecrireCaractere(&f5, '1');
	FichierTexte_ecrireCaractere(&f5, '1');
	FichierTexte_ecrireCaractere(&f5, 'u');
	FichierTexte_ecrireCaractere(&f5, '0');
	FichierTexte_ecrireCaractere(&f5, '1');
	FichierTexte_ecrireCaractere(&f5, 't');
	FichierTexte_ecrireCaractere(&f5, '1');
	FichierTexte_ecrireCaractere(&f5, '0');
	FichierTexte_ecrireCaractere(&f5, 'B');
	FichierTexte_ecrireCaractere(&f5, '0');
	FichierTexte_ecrireCaractere(&f5, '1');
	FichierTexte_ecrireCaractere(&f5, 'o');
	FichierTexte_ecrireCaractere(&f5, '0');
	FichierTexte_ecrireCaractere(&f5, '1');
	FichierTexte_ecrireCaractere(&f5, 'n');
	FichierTexte_ecrireCaractere(&f5, '0');
	FichierTexte_ecrireCaractere(&f5, '1');
	FichierTexte_ecrireCaractere(&f5, 'j');
	FichierTexte_ecrireCaractere(&f5, '0');
	FichierTexte_ecrireCaractere(&f5, '1');
	FichierTexte_ecrireCaractere(&f5, 'o');
	FichierTexte_ecrireCaractere(&f5, '0');
	FichierTexte_ecrireCaractere(&f5, '1');
	FichierTexte_ecrireCaractere(&f5, 'u');
	FichierTexte_ecrireCaractere(&f5, '0');
	FichierTexte_ecrireCaractere(&f5, '1');
	FichierTexte_ecrireCaractere(&f5, 'r');
	FichierTexte_ecrireCaractere(&f5, '1');
	FichierTexte_ecrireCaractere(&f5, '0');
	FichierTexte_fermer(&f5);

	FichierTexte_ouvrir(&f5, LECTURE);
	Fichier f6 = FichierTexte_fichierTexte("tests/testTADDictionnaire2.txt");
	FichierTexte_ouvrir(&f6, LECTURE);
	char *ligne5 = FichierTexte_lireChaine(f5);
	char *ligne6 = FichierTexte_lireChaine(f6);

	CU_ASSERT_TRUE(strcmp(ligne5, ligne6) == 0);

	free(ligne5);
	free(ligne6);

	FichierTexte_fermer(&f5);
	FichierTexte_fermer(&f6);

	FichierTexte_ouvrir(&f6, LECTURE);
	CU_ASSERT_TRUE((FichierTexte_lireCaractere(f6) - '0') == d.longueur);
}

void test_estPresent(void) {
	Dictionnaire d = Dictionnaire_dictionnaire();
	Mot m = Mot_genererMot("Salut");
	Mot m2 = Mot_genererMot("Bonjour");

	Dictionnaire_insererMot(&d, m);
	CU_ASSERT_TRUE(Dictionnaire_estPresent(d, m))
	CU_ASSERT_FALSE(Dictionnaire_estPresent(d, m2));

	Dictionnaire_insererMot(&d, m2);
	CU_ASSERT_TRUE(Dictionnaire_estPresent(d, m))
	CU_ASSERT_TRUE(Dictionnaire_estPresent(d, m2));
}

int main(int argc , char** argv) {
	CU_pSuite pSuite = NULL;

	/* Initialisation du registre de tests*/ 
	if (CUE_SUCCESS != CU_initialize_registry())
		return CU_get_error() ;

	/* Ajout d'une suite de test */
	pSuite = CU_add_suite("Tests boite noire ", init_suite_success ,clean_suite_success );
	if (NULL == pSuite) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	/* Ajout des tests à la suite de tests boite noire */
	if (
		(NULL == CU_add_test(pSuite, "test_creationElement", test_creationElement))
		|| (NULL == CU_add_test(pSuite, "Dictionnaire_estVide", test_estVide))
		|| (NULL == CU_add_test(pSuite, "test_insererMot", test_insererMot))
		|| (NULL == CU_add_test(pSuite, "test_insererFichier", test_insererFichier))
		|| (NULL == CU_add_test(pSuite, "test_charger", test_charger))
		|| (NULL == CU_add_test(pSuite, "test_estPresent", test_estPresent))
		|| (NULL == CU_add_test(pSuite, "test_sauvegarder", test_sauvegarder)) 
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