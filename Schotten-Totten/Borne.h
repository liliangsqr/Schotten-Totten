#ifndef BORNE_H
#define BORNEH

#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include "Carte.h"
#include "TasBorne.h"
#include "ModeCombat.h"

using namespace std ;

class Borne {
    // Attributs
private:
    TasDeCartes<ModeCombat> OnTop;
    TasBorne CarteJ1;
    TasBorne CarteJ2;

public:
    // Constructeurs

    Borne() = default;

    // Méthodes

    string GetInfo() const {
        string info = "Borne Info:\n";
        info += "OnTop size: " + to_string(OnTop.GetCapacite()) + "\n";
        info += "CarteJ1 size: " + to_string(CarteJ1.GetSize()) + "\n";
        info += "CarteJ2 size: " + to_string(CarteJ2.GetSize()) + "\n";
        return info;
    }

    void AjouterCarte(int joueur, unique_ptr<Carte>&& carte);
    bool EstSuiteDeCouleur(const vector<unique_ptr<Carte>>& cartes);
    bool EstBrelan(const vector<unique_ptr<Carte>>& cartes);
    bool EstCouleur(const TasBorne& cartes);
    bool EstSuite(const vector<unique_ptr<Carte>>& cartes);
    int Somme(const vector<unique_ptr<Carte>>& cartes);
};

#endif