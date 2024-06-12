#include "Borne.h"

bool Borne::estRevendiquableParJoueur(Joueur joueur) const {
    Combinaison combinaisonJ;
    for (const auto& carte : tasJoueurs.at(joueur.getNom()).getCartes()) {
        combinaisonJ.ajouterCarte(*carte);
    }
    return combinaisonJ.getMeilleureCombinaison() != CombinaisonType::Aucune;
}
