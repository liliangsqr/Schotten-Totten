#include "TotalTactique.h"
TotalTactique::TotalTactique() : Total()
{
	// Il reste à ajouter les cartes tactiques
    for (unsigned int itNom = 0; itNom != 9; itNom++) {
        // Carte Espion
        if (itNom == 1) {
            tas.push_back(make_unique<CarteTactique>(6, 0, itNom));
        }
        else {
            tas.push_back(make_unique<CarteTactique>(0, 0, itNom));
        }
    }

    capacite = 64;
}

void TotalTactique::Ajouter(unique_ptr<CarteTactique>&& carte)
{
    tas.push_back(move(carte));
}
