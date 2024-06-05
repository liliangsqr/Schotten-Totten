#pragma once
#include "Joueur.h"

class IA : public Joueur
{
private: 
	unsigned int pDifficulte;
public:
	unsigned int getDifficulte() { return pDifficulte; }
};

