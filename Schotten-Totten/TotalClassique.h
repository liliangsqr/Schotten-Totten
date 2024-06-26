#ifndef TOTALCLASSIQUE_H
#define TOTALCLASSIQUE_H
#include "Total.h"

// Repr�sente tout le paquet de cartes pour le mode classique, ne sert qu'� distribuer al�atoirement les cartes en d�but de partie
class TotalClassique : public Total
{
	// Attributs
	// vector<unique_ptr<Carte>> tas
	// unsigned int capacite

public :
	// Constructeurs

	// Constructeur par d�faut, remplis le paquet avec toutes les cartes clan
	TotalClassique() : Total() { capacite = 54; }

	// M�thodes

	const vector<unique_ptr<Carte>>& GetTas() { return tas; }
};

#endif TOTALCLASSIQUE_H
