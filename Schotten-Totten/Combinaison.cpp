#include <vector>
#include <algorithm>
#include "CarteClan.h"
#include "Combinaison.h"



bool CombinaisonCartes:: estSuiteDeCouleur() {
        if (cartes.size() < 3) return false;
        sort(cartes.begin(), cartes.end(), [](const CarteClan &a, const CarteClan &b) {
            return a.getValeur() < b.getValeur();
        });
        return cartes[0].getCouleur() == cartes[1].getCouleur() &&
               cartes[1].getCouleur() == cartes[2].getCouleur() &&
               cartes[0].getValeur() + 1 == cartes[1].getValeur() &&
               cartes[1].getValeur() + 1 == cartes[2].getValeur();
    }

bool CombinaisonCartes::estBrelan() {
        if (cartes.size() < 3) return false;
        return cartes[0].getValeur() == cartes[1].getValeur() &&
               cartes[1].getValeur() == cartes[2].getValeur();
    }

bool CombinaisonCartes::  estCouleur() {
        if (cartes.size() < 3) return false;
        return cartes[0].getCouleur() == cartes[1].getCouleur() &&
               cartes[1].getCouleur() == cartes[2].getCouleur();
    }

bool CombinaisonCartes:: estSuite() {
        if (cartes.size() < 3) return false;
        sort(cartes.begin(), cartes.end(), [](const CarteClan &a, const CarteClan &b) {
            return a.getValeur() < b.getValeur();
        });
        return cartes[0].getValeur() + 1 == cartes[1].getValeur() &&
               cartes[1].getValeur() + 1 == cartes[2].getValeur();
    }

bool CombinaisonCartes:: estSomme() {
        if (cartes.size() < 3) return false;
        int somme = cartes[0].getValeur() + cartes[1].getValeur() + cartes[2].getValeur();
        return somme <= 9;
    }


void CombinaisonCartes:: ajouterCarte(const CarteClan &carte) {
        cartes.push_back(carte);
    }

CombinaisonType CombinaisonCartes:: getMeilleureCombinaison() {
        if (estSuiteDeCouleur()) return CombinaisonType::SuiteDeCouleur;
        if (estBrelan()) return CombinaisonType::Brelan;
        if (estCouleur()) return CombinaisonType::Couleur;
        if (estSuite()) return CombinaisonType::Suite;
        if (estSomme()) return CombinaisonType::Somme;
        return CombinaisonType::Aucune;
    }
};
