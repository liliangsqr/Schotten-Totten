#ifndef TOTALTACTIQUE_H
#define TOTALTACTIQUE_H
#include "Total.h"
class TotalTactique : public Total
{
	// Attributs
	// vector<unique_ptr<Carte>> tas

public:
	// Constructeurs

	// Constructeur par défaut, remplis le paquet avec toutes les cartes clan puis les cartes tactiques
	TotalTactique();
};

#endif TOTALTACTIQUE_H