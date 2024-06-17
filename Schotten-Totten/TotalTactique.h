#ifndef TOTALTACTIQUE_H
#define TOTALTACTIQUE_H
#include "Total.h"
#include "CarteTactique.h"
#include <memory>

// Représente tout le paquet de cartes pour le mode tactique, ne sert qu'à distribuer aléatoirement les cartes en début de partie
class TotalTactique : public Total
{
	// Attributs
	// vector<unique_ptr<Carte>> tas
	// unsigned int capacite

public:
	// Constructeurs

	// Constructeur par défaut, remplis le paquet avec toutes les cartes clan puis les cartes tactiques
	TotalTactique();

	// Méthodes

	// N'accepte que des cartes tactiques, effectue un move car carte doit être une RVALUE
	void Ajouter(unique_ptr<CarteTactique>&& carte);

};

#endif TOTALTACTIQUE_H