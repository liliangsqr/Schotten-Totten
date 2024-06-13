#ifndef FRONTIERE_H
#define FRONTIERE_H

#include "Borne.h"
#include <vector>

class Frontiere {
private:
    std::vector<Borne> bornes;

public:
    Frontiere() : bornes(9) {}

    const Borne& getBorne(int i) const {
        return bornes.at(i);
    }

    int getNombreDeBornesRevendiquablesParJoueur1() const {
        int count = 0;
        for (const auto& borne : bornes) {
            if (borne.estRevendiquableParJoueur("Joueur1")) {
                count++;
            }
        }
        return count;
    }

    int getNombreDeBornesRevendiquablesParJoueur2() const {
        int count = 0;
        for (const auto& borne : bornes) {
            if (borne.estRevendiquableParJoueur("Joueur2")) {
                count++;
            }
        }
        return count;
    }
};

#endif // FRONTIERE_H
