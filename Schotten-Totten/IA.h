#ifndef IA_H
#define IA_H

#include "Joueur.h"

// Repr�sente un joueur contr�l� par l'ordinateur, a un comportement hasardeux
class IA : public Joueur
{
private: 
	unsigned int pDifficulte;
public:
	unsigned int getDifficulte() { return pDifficulte; }
};

#endif