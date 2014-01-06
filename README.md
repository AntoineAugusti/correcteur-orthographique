Correcteur orthographique
===========

# Coloration syntaxique dans le rapport
Pour faire une belle coloration syntaxique, il faut installer un petit plugin Python sur votre machine.

Voici la procédure à suivre :
- Télécharger la dernière version de Pygments au format .tar.gz sur https://pypi.python.org/pypi/Pygments
-  Taper les commandes suivantes :

	tar -zxvf Pygments-1.6.tar.gz
	cd Pygments-1.6
	sudo python setup.py install

# Compilation du rapport
Se positionner dans le trunk et exécuter la commande suivante dans le terminal :

	make all

Pour visionner le rapport :

	evince rapport/rapport.pdf

Et enfin, pour effacer les fichiers temporaires : 

	make clean

# Compilation du programme
Voir le fichier README dans le dossier programme