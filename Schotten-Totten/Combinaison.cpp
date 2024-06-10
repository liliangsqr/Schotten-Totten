#include "Combinaison.h"


bool Combinaison::EstSuiteDeCouleur(const vector<unique_ptr<Carte>>& cartes) {
    if (cartes.size() != 3) {
        return false;
    }
    for (size_t i = 1; i < cartes.size(); ++i) {
        if (cartes[i - 1]->getCouleur() != cartes[i]->getCouleur() - 1) {
            return false;
        }
    }

    return true;

}

bool Combinaison::EstBrelan(const vector<unique_ptr<Carte>>& cartes) {
    if (cartes.size() < 3) return false;

    map<unsigned int, int> compte;
    for (const auto& carte : cartes) {
        ++compte[carte.get()->GetValeur()];
    }

    for (const auto& [valeur, nb] : compte) {
        if (nb >= 3) {
            return true;
        }
    }

    return false;
}

bool Combinaison::EstCouleur(const TasBorne& cartes) {
    if (cartes.GetSize() < 3) return false;

    unsigned int couleur = cartes[0].getCouleur();
    for (unsigned int i = 1; i < cartes.GetSize(); ++i) {
        if (cartes[i].getCouleur() != couleur) {
            return false;
        }
    }
    return true;
}

bool Combinaison::EstSuite(const vector<unique_ptr<Carte>>& cartes) {
    if (cartes.size() < 3) return false;

    for (size_t i = 1; i < cartes.size(); ++i) {
        if (cartes[i - 1]->GetValeur() != cartes[i]->GetValeur() - 1) {
            return false;
        }
    }

    return true;
}

int Combinaison::Somme(const vector<unique_ptr<Carte>>& cartes) {
    int somme = 0;
    for (const auto& carte : cartes) {
        somme += carte->GetValeur();
    }
    return somme;
}