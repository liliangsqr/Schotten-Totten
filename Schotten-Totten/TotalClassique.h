#pragma once
#include "Total.h"
class TotalClassique : public Total
{
	// Attributs
	// vector<unique_ptr<Carte>> tas

public :
	// Constructeurs

	// Constructeur par d�faut, remplis le paquet avec toutes les cartes clan
	TotalClassique() : Total() { }

	// M�thodes

	vector<unique_ptr<Carte>> GetTas() { return tas; }
};

