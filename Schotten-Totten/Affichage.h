#ifndef AFFICHAGE_H
#include "CarteClan.h"
#include "CarteTactique.h"

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

class Affichage
{
private:

public:

	unsigned int static ChoixMode();
	void static carteClan(const CarteClan& CC);
	void static carteTactique(const CarteTactique& CT);
	void static debutJeu();
	void static board();
	string static Couleurs(unsigned int CarteCouelurs);



};

#endif // AFFICHAGE_H



