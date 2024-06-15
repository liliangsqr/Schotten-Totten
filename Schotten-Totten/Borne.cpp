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
    // VOIR TODO DANS LE .H
    return tasSontTousPleins();
}
