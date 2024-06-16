#include "Combinaison.h"

bool Combinaison::comparerCartes(const Carte& a, const Carte& b) {
    return a.getValeur() < b.getValeur();
}

bool Combinaison::estSuiteDeCouleur() const {
    const size_t minSize = Regles::getInstance().getTailleMinCombinaison();
    if (cartes.size() < minSize) return false;
    std::vector<Carte> sortedCartes = cartes;
    std::sort(sortedCartes.begin(), sortedCartes.end(), comparerCartes);
    for (size_t i = 1; i < sortedCartes.size(); ++i) {
        if (sortedCartes[i].getCouleur() != sortedCartes[i - 1].getCouleur() ||
            sortedCartes[i].getValeur() != sortedCartes[i - 1].getValeur() + 1) {
            return false;
        }
    }
    return true;
}

bool Combinaison::estSuite() const {
    const size_t minSize = Regles::getInstance().getTailleMinCombinaison();
    if (cartes.size() < minSize) return false;
    std::vector<Carte> sortedCartes = cartes;
    std::sort(sortedCartes.begin(), sortedCartes.end(), comparerCartes);
    for (size_t i = 1; i < sortedCartes.size(); ++i) {
        if (sortedCartes[i].getValeur() != sortedCartes[i - 1].getValeur() + 1) {
            return false;
        }
    }
    return true;
}

unsigned int Combinaison::getValSomme() const
{
    unsigned int somme = 0;
    for (const Carte& carte : cartes) {
        somme += carte.getValeur();
    }
    return somme;
}

bool Combinaison::estBrelan() const {
    const size_t minSize = Regles::getInstance().getTailleMinCombinaison();
    if (cartes.size() < minSize) return false;
    for (size_t i = 0; i < cartes.size() - 2; ++i) {
        if (cartes[i].getValeur() == cartes[i + 1].getValeur() &&
            cartes[i + 1].getValeur() == cartes[i + 2].getValeur()) {
            return true;
        }
    }
    return false;
}

bool Combinaison::estCouleur() const {
    const size_t minSize = Regles::getInstance().getTailleMinCombinaison();
    if (cartes.size() < minSize) return false;
    for (size_t i = 1; i < cartes.size(); ++i) {
        if (cartes[i].getCouleur() != cartes[i - 1].getCouleur()) {
            return false;
        }
    }
    return true;
}

void Combinaison::ajouterCarte(const Carte& carte) {
    if (cartes.size() < Regles::getInstance().getCapaciteMaxTasBorne()) {
        cartes.push_back(carte); // push_back fait une copie
    }
    else {
        throw std::runtime_error("Vous essayez d'ajouter trop de cartes à la combinaison");
    }
}

CombinaisonType Combinaison::getMeilleureCombinaison() const {
    if (estSuiteDeCouleur()) {
        return CombinaisonType::SuiteDeCouleur;
    }
    else if (estBrelan()) {
        return CombinaisonType::Brelan;
    }
    else if (estCouleur()) {
        return CombinaisonType::Couleur;
    }
    else if (estSuite()) {
        return CombinaisonType::Suite;
    }
    else {
        return CombinaisonType::Somme;
    }
}


size_t Combinaison::getTaille() const {
    return cartes.size();
}
