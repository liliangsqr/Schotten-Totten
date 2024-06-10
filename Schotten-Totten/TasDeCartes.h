#ifndef TASDECARTES_H
#define TASDECARTES_H

#include <vector>
#include <memory>
#include <random> // Pour random_device et mt19937
#include <algorithm> // Pour shuffle
#include "Carte.h"

using namespace std;

template<class T>
class TasDeCartes
{
protected :
    // Attributs
    vector<unique_ptr<T>> tas;
    unsigned int capacite;

    // Le constructeur en protected emp�che une instanciation directe de TasBorne
    TasDeCartes() = default;

    // Constructeurs
public :
    // M�thodes

    // M�lange le tas al�atoirement
    void Melanger()
    {
        random_device rd;
        mt19937 g(rd());
        shuffle(tas.begin(), tas.end(), g);
    }

    // Ajoute/move une carte en RVALUE sur le haut du tas
    void Ajouter(unique_ptr<T>&& carte)
    {
        tas.push_back(move(carte));
    }

    // Retourne une r�f�rence const vers le T � la position index afin de seulement la consulter
    // Attention on doit pas pouvoir faire delete sur l'adresse de la valeur retourn�e
    const T& operator[](unsigned int index) const
    {
        if (index >= tas.size()) {
            throw out_of_range("Index hors limites");
        }
        return *tas[index];
    }

    unsigned int GetCapacite() const { return capacite; }
};

#endif TASDECARTES_H