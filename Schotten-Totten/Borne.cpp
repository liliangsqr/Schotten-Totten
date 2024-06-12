#pragma once

#include "Borne.h"

bool Borne::estRevendiquableParJoueur1() const {
    Combinaison combinaisonJ1;
    for (const auto& carte : CarteJ1.getCartes()) {
        combinaisonJ1.ajouterCarte(dynamic_cast<const CarteClan&>(*carte));
    }
    return combinaisonJ1.getMeilleureCombinaison() != CombinaisonType::Aucune;
}


bool Borne::estRevendiquableParJoueur2() const {
    Combinaison combinaisonJ2;
    for (const auto& carte : CarteJ2.getCartes()) {
        combinaisonJ2.ajouterCarte(dynamic_cast<const CarteClan&>(*carte));
    }
    return combinaisonJ2.getMeilleureCombinaison() != CombinaisonType::Aucune;
}
