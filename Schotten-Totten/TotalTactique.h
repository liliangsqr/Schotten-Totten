#ifndef TOTALTACTIQUE_H
#define TOTALTACTIQUE_H
#include "Total.h"
#include "CarteTactique.h"
#include <memory>

// Repr�sente tout le paquet de cartes pour le mode tactique, ne sert qu'� distribuer al�atoirement les cartes en d�but de partie
// /!\  Attention la classe TotalTactique est fausse pour l'instant, ne pas utiliser telle quelle
class TotalTactique : public Total
{
	// Attributs
	// vector<unique_ptr<Carte>> tas
	// unsigned int capacite

public:
	// Constructeurs

	// Constructeur par d�faut, remplis le paquet avec toutes les cartes clan puis les cartes tactiques
	TotalTactique();

	// M�thodes

	// N'accepte que des cartes tactiques, effectue un move car carte doit �tre une RVALUE
	void Ajouter(unique_ptr<CarteTactique>&& carte);

};

#endif TOTALTACTIQUE_H