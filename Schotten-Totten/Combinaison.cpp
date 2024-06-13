#include <vector>
#include <algorithm>
#include "Carte.h"
#include "Combinaison.h"



bool Combinaison:: comparerCartes(const Carte& a, const Carte& b) {
    return a.getValeur() < b.getValeur();
}

bool Combinaison::estSuiteDeCouleur() const {
    if (cartes.size() < 3) return false;
    vector<Carte> sortedCartes = cartes;
    sort(sortedCartes.begin(), sortedCartes.end(), comparerCartes);
    return sortedCartes[0].getCouleur() == sortedCartes[1].getCouleur() &&
           sortedCartes[1].getCouleur() == sortedCartes[2].getCouleur() &&
           sortedCartes[0].getValeur() + 1 == sortedCartes[1].getValeur() &&
           sortedCartes[1].getValeur() + 1 == sortedCartes[2].getValeur();
}

bool Combinaison::estSuite() const {
    if (cartes.size() < 3) return false;
    vector<Carte> sortedCartes = cartes;
    sort(sortedCartes.begin(), sortedCartes.end(), comparerCartes);
    return sortedCartes[0].getValeur() + 1 == sortedCartes[1].getValeur() &&
           sortedCartes[1].getValeur() + 1 == sortedCartes[2].getValeur();
}


bool Combinaison::estBrelan() const {
    if (cartes.size() < 3) return false;
    return cartes[0].getValeur() == cartes[1].getValeur() &&
           cartes[1].getValeur() == cartes[2].getValeur();
}

bool Combinaison::estCouleur() const {
    if (cartes.size() < 3) return false;
    return cartes[0].getCouleur() == cartes[1].getCouleur() &&
           cartes[1].getCouleur() == cartes[2].getCouleur();
}


bool Combinaison::estSomme() const {
    if (cartes.size() < 3) return false;
    int somme = cartes[0].getValeur() + cartes[1].getValeur() + cartes[2].getValeur();
    return somme <= 9;
}

void Combinaison::ajouterCarte(const Carte& carte) {
    cartes.push_back(carte); // Push back fait une copie de carte
}

CombinaisonType Combinaison::getMeilleureCombinaison() const {
    if (estSuiteDeCouleur()) return CombinaisonType::SuiteDeCouleur;
    if (estBrelan()) return CombinaisonType::Brelan;
    if (estCouleur()) return CombinaisonType::Couleur;
    if (estSuite()) return CombinaisonType::Suite;
    if (estSomme()) return CombinaisonType::Somme;
    return CombinaisonType::Aucune;
}