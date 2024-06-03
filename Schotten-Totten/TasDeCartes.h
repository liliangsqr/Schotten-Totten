#pragma once
#include <vector>
#include <algorithm>
#include <memory>
#include "Carte.h"

using namespace std;

class TasDeCartes
{
protected :
    // Attributs
    vector<unique_ptr<Carte>> tas;

    // Constructeurs
public :
    // M�thodes

    // M�lange le tas al�atoirement
    void Melanger() { random_shuffle(tas.begin(), tas.end()); }

    // Ajoute/move une carte en RVALUE sur le haut du tas
    void Ajouter(unique_ptr<Carte>&& carte)
    {
        tas.push_back(move(carte));
    }

    // Retourne une r�f�rence const vers la carte � la position index afin de seulement la consulter
    // Attention on doit pas pouvoir faire delete sur l'adresse de la valeur retourn�e
    const Carte& operator[](unsigned int index)
    {
        return *tas[index];
    }
};
