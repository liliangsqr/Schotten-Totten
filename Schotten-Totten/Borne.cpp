#pragma once

#include "Borne.h"

void Borne::AjouterCarte(int joueur, unique_ptr<Carte>carte) {
    if(joueur==1){
        CarteJ1.push_back(move(carte));
    } else if (joueur ==2){
        CarteJ2.push_back(move(carte));
    }
}


bool Borne::EstSuiteDeCouleur(const vector<unique_ptr<Carte>>& cartes) {
    if(cartes.size()!=3){
        return false;
    }
    for (size_t i = 1; i < cartes.size(); ++i) {
        if (cartes[i - 1]->getCouleur() != cartes[i]->getCouleur() - 1) {
            return false;
        }
    }

    return true;

}

bool Borne::EstBrelan(const vector<unique_ptr<Carte>>& cartes) {
    if (cartes.size() < 3) return false;

    map<unsigned int, int> compte;
    for (const auto& carte : cartes) {
        ++compte[carte->getValeur()];
    }

    for (const auto& [valeur, nb] : compte) {
        if (nb >= 3) {
            return true;
        }
    }

    return false;
}

bool Borne::EstCouleur(const vector<unique_ptr<Carte>>& cartes) {
    if (cartes.size() < 3) return false;

    unsigned int couleur = cartes[0]->getCouleur();
    for (size_t i = 1; i < cartes.size(); ++i) {
        if (cartes[i]->getCouleur() != couleur) {
            return false;
        }
    }

    return true;
}

bool Borne:: EstSuite(const vector<unique_ptr<Carte>>& cartes) {
    if (cartes.size() < 3) return false;

    for (size_t i = 1; i < cartes.size(); ++i) {
        if (cartes[i - 1]->getValeur() != cartes[i]->getValeur() - 1) {
            return false;
        }
    }

    return true;
}

int Borne :: Somme(const vector<unique_ptr<Carte>>& cartes) {
    int somme = 0;
    for (const auto& carte : cartes) {
        somme += carte->getValeur();
    }
    return somme;
}