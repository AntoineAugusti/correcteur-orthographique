# Installation de CUnit et Doxygen
Taper la commande suivante dans un terminal :
	sudo apt-get install libcunit1 libcunit1-dev libcunit1-doc doxygen

# Utilisation du makefile
Pour la compilation de l'ex�cutable, des tests et de la documentation :

	make all

Pour la compilation de l'ex�cutable seul :

	make exe

Pour la compilation des tests seuls :

	make tests

Pour la compilation de la documentation seule :

	make doc

Pour la compilation et l'ex�cution des tests unitaires :

	make exetests

Pour le nettoyage du r�pertoire :

	make clean

Des commandes plus sp�cifiques pour la compilation et les tests unitaires de chaque module existent. Voir le makefile pour avoir les commandes.

# Dictionnaire de r�f�rence
Le dictionnaire de la langue fran�aise utilisable par notre correcteur orthographique est g�n�r� � partir du fichier dictionnaires/dico-ref-ascii.txt. Un dictionnaire vide est disponible � partir du fichier dictionnaires/vide.dico.

Pour le remplir avec le dictionnaire fran�ais : ./bin/asispell -d dictionnaires/vide.dico -f dictionnaires/dico-ref-ascii.txt

# Notes sur l'encodage
Ce programme a �t� con�u pour �tre ex�cut� dans un terminal utilisant l'encodage Western (ISO-8859-15). Tout autre encodage peut g�n�rer un comportement non d�sir�.

Pour changer l'encodage du terminal sous Ubuntu, rendez-vous dans le menu "Terminal" de votre terminal puis "Choix du jeu de caract�res" puis s�lectionnez l'encodage ISO-8859-15.