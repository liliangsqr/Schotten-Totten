#include "Borne.h"

bool Borne::tasSontTousPleins() const
{
    for (const auto& itMap : tasJoueurs) {
        // Si le tas n'est pas rempli au maximum
        if (itMap.second.GetSizeTas() != Regles::getInstance().getCapaciteMaxTasBorne()) {
            return false;
        }
    }

    // Tous les tas sont remplis au maximum
    return true;
}

bool Borne::estRevendicableParJoueur(shared_ptr<Joueur> joueur) const
{
    // VOIR TODO DANS LE .H, pour l'instant on fait ça
    if (!tasSontTousPleins()) {
        return false;
    }

    // Création des combinaisons
    map<shared_ptr<Joueur>, Combinaison> combinaisons;
    for (const auto& itMap : tasJoueurs) {
        shared_ptr<Joueur> joueur = itMap.first;
        Combinaison comb;
        for (const auto& carte : itMap.second.getCartes()) {
            comb.ajouterCarte(*carte);
        }
        combinaisons[joueur] = comb;
    }

    // On trouve le joueur qui a la meilleure combinaison
    shared_ptr<Joueur> meilleurJoueur = nullptr;
    CombinaisonType meilleureCombinaison = CombinaisonType::Aucune;
    unsigned int meilleureSomme = 0;

    for (auto it = combinaisons.begin(); it != combinaisons.end(); ++it) {
        shared_ptr<Joueur> joueur = it->first;
        Combinaison comb = it->second;
        CombinaisonType type = comb.getMeilleureCombinaison();
        unsigned int somme = comb.getValSomme();

        // Comparaison des combinaisons
        if (type > meilleureCombinaison || (type == meilleureCombinaison && somme > meilleureSomme)) {
            meilleurJoueur = joueur;
            meilleureCombinaison = type;
            meilleureSomme = somme;
        }
    }

    // Si le joueur avec la meilleure combinaison est celui passé en paramètres alors on renvoie true
    return (meilleurJoueur == joueur);
}
