#ifndef TOTALCLASSIQUE_H
#define TOTALCLASSIQUE_H
#include "Total.h"
class TotalClassique : public Total
{
	// Attributs
	// vector<unique_ptr<Carte>> tas
	// unsigned int capacite

public :
	// Constructeurs

	// Constructeur par défaut, remplis le paquet avec toutes les cartes clan
	TotalClassique() : Total() { capacite = 54; }

	// Méthodes

	vector<unique_ptr<Carte>> GetTas() { return tas; }
};

#endif TOTALCLASSIQUE_H