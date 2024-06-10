#pragma once
#include "Carte.h"
#include "TasBorne.h"
#include "vector"
#include "map"

class Combinaison
{
    bool EstSuiteDeCouleur(const vector<unique_ptr<Carte>>& cartes);
    bool EstBrelan(const vector<unique_ptr<Carte>>& cartes);
    bool EstCouleur(const TasBorne& cartes);
    bool EstSuite(const vector<unique_ptr<Carte>>& cartes);
    int Somme(const vector<unique_ptr<Carte>>& cartes);
};

