#ifndef TASDECARTES_H
#define TASDECARTES_H

#include <vector>
#include <algorithm>
#include <memory>
#include "Carte.h"
using namespace std;

template<class T>
class TasDeCartes
{
protected :
    // Attributs
    vector<unique_ptr<T>> tas;
    unsigned int capacite;

    // Constructeurs
public :
    // Méthodes

    // Mélange le tas aléatoirement
    void Melanger();

    // Ajoute/move une carte en RVALUE sur le haut du tas
    void Ajouter(unique_ptr<T>&& carte)
    {
        tas.push_back(move(carte));
    }

    // Retourne une référence const vers la carte à la position index afin de seulement la consulter
    // Attention on doit pas pouvoir faire delete sur l'adresse de la valeur retournée
    const T& operator[](unsigned int index)
    {
        return *tas[index];
    }
};

#endif TASDECARTES_H