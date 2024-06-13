#ifndef FRONTIERE_H
#define FRONTIERE_H

#include "Borne.h"
#include <vector>
#include <string>
#include <algorithm>

class Frontiere
{
private:
    std::vector<Borne> bornes;

public:
    Frontiere() : bornes(9) {}


    const Borne& getBorne(int index) const {
        return bornes[index];
    }


    int getNombreDeBornesRevendiquablesParJoueur(const std::string& nomJoueur) const {
        return std::count_if(bornes.begin(), bornes.end(), [&](const Borne& borne) {
            return borne.estRevendiquableParJoueur(nomJoueur);
        });
    }


    int getNombreTotalDeBornes() const {
        return bornes.size();
    }
};

#endif // FRONTIERE_H
