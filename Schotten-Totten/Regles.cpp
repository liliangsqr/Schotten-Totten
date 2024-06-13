#include "Regles.h"

Regles::Regles(unsigned int initNbJoueurs, vector<string> iniModesJeu = { "Classique","Tactique" })
{
	pNbJoueur = initNbJoueurs;
	pModesJeu = iniModesJeu;
}
