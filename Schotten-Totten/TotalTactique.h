#ifndef TOTALTACTIQUE_H
#define TOTALTACTIQUE_H
#include "Total.h"
#include "CarteTactique.h"
#include <memory>

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

	const CarteTactique& operator[](unsigned int index) const
	{
		if (auto carteRet = dynamic_cast<CarteTactique*>(tas[index].get())) {
			return *carteRet;
		}
	}
};

#endif TOTALTACTIQUE_H