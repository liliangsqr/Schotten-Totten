#ifndef AFFICHAGE_H
#include "CarteClan.h"
#include "CarteTactique.h"
#include "Regles.h"
#include "Jeu.h"

// Définitions des séquences d'échappement ANSI pour différentes couleurs

#define RESET "\033[0m";
#define NOIRE "\033[30m";
#define ROUGE "\033[31m";
#define VERT "\033[32m";
#define JAUNE "\033[33m";
#define BLEU "\033[34m";
#define MAGENTA "\033[35m";
#define CYAN "\033[36m";
#define BLANC "\033[37m";
#define MARRON "\033[33m";
#define VIOLET "\033[35m";


// Gère complètement l'affichage console du projet
class Affichage
{
private:

public:

	void static ChoixMode(Regles& regles);
	void static carteClan(const CarteClan& CC);
	void static carteTactique(const CarteTactique& CT);
	void static board(Jeu& jeux);
	string static Couleurs(unsigned int CarteCouelurs);



};

#endif // AFFICHAGE_H



