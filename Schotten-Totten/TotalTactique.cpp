#include "TotalTactique.h"
TotalTactique::TotalTactique() : Total()
{
    // Il reste à ajouter les cartes tactiques
    for (unsigned int itNom = 0; itNom != 9; itNom++) {
        // Carte Espion
        if (itNom == 1) {
            std::unique_ptr<Carte> carte = std::make_unique<CarteTactique>(7, 0, ("nomtest"));
            tas.push_back(std::move(carte));
        }
        else {
            std::unique_ptr<Carte> carte = std::make_unique<CarteTactique>(0, 0, "nomtest");
            tas.push_back(std::move(carte));
        }
    }

    capacite = 64;
}

void TotalTactique::Ajouter(unique_ptr<CarteTactique>&& carte)
{
    tas.push_back(move(carte));
}
