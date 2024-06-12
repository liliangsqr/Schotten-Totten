
#include "Frontiere.h"



const Borne& Frontiere::getBorne(int i) const {
    if (i < 0 || i >= bornes.size()) {
        throw std::out_of_range("Indice invalide");
    }
    return bornes[i];
}



int Frontiere::getNombreDeBornesRevendiquablesParJoueur1() const {
    int count = 0;
    for (auto it = bornes.begin(); it != bornes.end(); ++it) {
        if (it->estRevendiquableParJoueur1()) {
            count++;
        }
    }
    return count;
}

int Frontiere::getNombreDeBornesRevendiquablesParJoueur2() const {
    int count = 0;
    for (auto it = bornes.begin(); it != bornes.end(); ++it) {
        if (it->estRevendiquableParJoueur1()) {
            count++;
        }
    }
    return count;
}
