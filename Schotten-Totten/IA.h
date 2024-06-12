#ifndef IA_H
#define IA_H

#include "Joueur.h"

class IA : public Joueur
{
private: 
	unsigned int pDifficulte;
public:
	unsigned int getDifficulte() { return pDifficulte; }
};

#endif